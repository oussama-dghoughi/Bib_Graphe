#include "chip8.h"

int Init_Systeme(struct Chip8* chip8) {
	// créer la RAM
	chip8->ram = Ram_init();
	if (chip8->ram == NULL) {
		return 1;
	}
	
	// Allocation et initialisation du speaker
    chip8->speaker = malloc(sizeof(struct Speaker));
    int  h_p= Speaker_init(chip8->speaker);
    if (h_p == 1) {
        return 1;
    }
	
	// Allocation et initialisation du display
	chip8->display = malloc(sizeof(struct Display));
    int  screen= Display_init(chip8->display, 15);
    if (screen== 1) {
        return 1;
    }


	// Allocation et initialisation du keyboard
    chip8->keyboard = malloc(sizeof(struct Keyboard));
    int clavier = Keyboard_init(chip8->keyboard);
    if (clavier == 1) {
        return 1;
    }
	// Allocation et initialisation du processeur
	struct Processeur * processeur = Processeur_init(chip8->ram,chip8->display,chip8->keyboard,chip8->speaker);
	chip8->processeur = processeur;
	

	uint8_t val;
	uint16_t addr;
	// Les adresses des 16 sprites prédéfinies
	uint16_t Sp_Addr[] = {0x0000,0x0005,0x000A,0x000F,0x0014,0x0019,0x001E,0x0023,0x0028,0x002D,0x0032,0x0037,0x003C,0x0041,0x0046,0x004B};
	
	for (int i = 0; i < 16; ++i) {
		// Initialisation du sprite
        int res = Sprite_init(&chip8->sprites[i], 5);
        if (res != 0) {
            return 1;
        }
		
		// On appelle la fonction correspondant au sprite prédéfini
		switch (i) {
            case 0:
				sprite_0(&chip8->sprites[i]);
				break;
            case 1:
				sprite_1(&chip8->sprites[i]);	
				break;
			case 2: 
				sprite_2(&chip8->sprites[i]);
				break;
			case 3:
				sprite_3(&chip8->sprites[i]); 
				break;
			case 4: 
				sprite_4(&chip8->sprites[i]);
				break;
			case 5: 
				sprite_5(&chip8->sprites[i]); 
				break;
			case 6:
				sprite_6(&chip8->sprites[i]); 
				break;
			case 7: 
				sprite_7(&chip8->sprites[i]); 
				break;
			case 8: 
				sprite_8(&chip8->sprites[i]); 
				break;
			case 9: 
				sprite_9(&chip8->sprites[i]); 
				break;
			case 10:
				sprite_A(&chip8->sprites[i]); 
				break;
			case 11: 
				sprite_B(&chip8->sprites[i]); 
				break;
			case 12: 
				sprite_C(&chip8->sprites[i]); 
				break;
			case 13: 
			sprite_D(&chip8->sprites[i]); 
			break;
			case 14: 
				sprite_E(&chip8->sprites[i]); 
				break;
			case 15: 
				sprite_F(&chip8->sprites[i]); 	
				break;
        }
		
		
		for (int j = 0; j < Sprite_length(&chip8->sprites[i]);j++) {
			Sprite_get(&chip8->sprites[i],j,&val);
			addr = Sp_Addr[i] + j;
            Ram_write(chip8->ram, addr, val);
        }
	}
	return 0;
}



void Delete_Systeme(struct Chip8* Chip8) {
	// Désallocation 
	Ram_delete(Chip8->ram);
	 Speaker_destroy(Chip8->speaker);
	 Keyboard_destroy(Chip8->keyboard);
    Display_destroy(Chip8->display);
	Processeur_delete(Chip8->processeur);
	free(Chip8);
}

int Load_Rom(struct Chip8* chip8, char * rom) {
	// Ouverture du fichier rom
	FILE * file = fopen(rom, "rb");
    if (file == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier test.\n");
        return 1;
    }
	
	uint8_t read_byte;
	uint16_t address = 512; // Rien dans la RAM avant l'adresse 512 (sauf sprites prédéfinies)
	
	// On lit dans le fichier des paquets de 1 octet qu'on stocke dans la RAM
	while (fread(&read_byte, sizeof(uint8_t), 1, file) == 1) {
		Ram_write(chip8->ram, address, read_byte);
		++address;
	}
	
	// Fermeture du fichier ROM
	fclose(file);
	
	
	chip8->processeur->pc_reg = 512;
	return 0;
}


int Machine_Loop(struct Chip8* chip8 ,uint32_t * fetch_decode_execute_time,uint32_t * timers_time,uint32_t * display_time,int *running) {
        
        const unsigned int delay_fetch_decode_execute = 2; 
        const unsigned int delay_timers = 16; 
        const unsigned int delay_display = 33; 
        
        
        uint32_t current_time = SDL_GetTicks();
        
        
        if (current_time - *fetch_decode_execute_time >= delay_fetch_decode_execute) {
                int res = fetch_decode_execute(chip8->processeur);
                if (res == 1) {
                        return 1;
                }
                *fetch_decode_execute_time = current_time; 
        }
        
        
        current_time = SDL_GetTicks();
		
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
					case SDL_QUIT:
						*running = 0; 
						break;
					default:
					break;
        }	
    }

        
        
        if (current_time - *timers_time >= delay_timers) {
                update_timers(chip8->processeur);
                *timers_time = current_time; 
        }
        
        
        current_time = SDL_GetTicks();
        
        
        if (current_time - *display_time >= delay_display) {
                int res2 = Display_update(chip8->display);
                if (res2 == 1) {
                        return 1;
                }
                *display_time = current_time; 
        }
        
        return 0;
}
