#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Ram.h"
#include "processeur.h"
#include "display/display.h"
#include "misc/error.h"
#include "keyboard/keyboard.h"
#include "speaker/speaker.h"
#include "display/sprite.h"
#include "chip8.h"
#include <SDL2/SDL.h>

int main(int argc, char** argv)
{
	// Vérification du nombre d'arguments
    if (argc != 2) {
		fprintf(stderr, "Unexpected number of arguments.\n");
		fprintf(stderr, "Usage: chip8lator <test.ch8>\n");
		return 1;
	}
	
	// Initialisation de SDL
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO)) {
		errcode = SDL;
	}
		
	else {
		printf("The SDL library has been initialized successfully.\n");
		
		// Allocation de la structure 
		struct Chip8 * chip8 = malloc(sizeof(struct Chip8));

		// Initialisation du système Chip8
		if (!Init_Systeme(chip8)) {
			printf("The CHIP 8 chip8lator is ready.\n");
				
				// Chargement de la ROM
				if (!Load_Rom(chip8,argv[1])) {
					printf("The ROM <%s> has been loaded.\n",argv[1]);
					printf("Run...\n");
					
					// Initialisation des variables pour gérer les délais
					uint32_t temps_fetch_decode_execute = SDL_GetTicks();
					uint32_t temps_timers = SDL_GetTicks();
					uint32_t temps_display = SDL_GetTicks();

					int running =1 ;

					// Boucle principale de la machine
					while (running){
					
						if(Machine_Loop(chip8,&temps_fetch_decode_execute,&temps_timers,&temps_display,&running)!=0){
							fprintf(stderr, "An error occurred during the machine loop.\n");
							break;
						}
				}
				// Suppression du système Chip8
				Delete_Systeme(chip8);
		}
		// Fermeture de SDL
		SDL_Quit();
	}
	// Gestion des erreurs et sortie du programme
	if (errcode != QUIT) {
		fprintf(stderr,"The program has terminated abnormally (errcode=%s)\n",errorstr());
		return 1;
	}

    return 0;
}
}