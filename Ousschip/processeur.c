#include "processeur.h"

struct Processeur * Processeur_init(struct RAM* ram, struct Display* display, struct Keyboard* keyboard, struct Speaker* speaker) {
	// Vérifie si tous les composants nécessaires sont correctement alloués
	if (ram == NULL || display == NULL || keyboard == NULL || speaker == NULL) {
        return NULL; // Si l'un des composants est manquant, retourne NULL
    }
	
	// Allocation et initialisation du processeur
    struct Processeur * processeur = malloc(sizeof(struct Processeur));
    
	processeur->V = malloc(V_REG*sizeof(uint8_t)); // Les 16 registres 8 bits
    processeur->I_reg = 0; // Le registre 16-bit
    processeur->Stack   = malloc(S_SIZE*sizeof(uint16_t)); // La Stack    pour stocker les adresses
    processeur->sp_reg = 0; // L'adresse du haut de la Stack   
    processeur->pc_reg = 0; // L'adresse de l'instruction à aller chercher dans la RAM
    processeur->sound_timer = 0; // Sound Timer
    processeur->delay_timer = 0; // Delay Timer
    processeur->ram = ram;//Pointeurs vers Ram
	processeur->display = display;//Pointeurs vers screen
	processeur->keyboard = keyboard;//Ponteur vers clavier
	processeur->speaker = speaker;//Pointurs vers speaker
	
	return processeur;
}



void Processeur_delete(struct Processeur * processeur) {
	
    free(processeur->V);
    free(processeur->Stack );
    free(processeur);
}



int fetch_decode_execute(struct Processeur * processeur) {
	// Récupération dans la RAM des 2 octets correspondant à l'instruction
    uint8_t P1;
    uint8_t P2;
    P1 = Ram_read(processeur->ram,processeur->pc_reg);
    P2 = Ram_read(processeur->ram,processeur->pc_reg+1);
	
	// Conversion des 2 octets en une instruction de 16 bits
	uint16_t instruction = (uint16_t)P1 << 8 | P2;

	
    processeur->pc_reg += 2;
	
	// Décode et exécute l'instruction en fonction de son opcode

    if ((instruction & 0xFFFF) == 0x00E0) {
        CLS(processeur);
    }

    else if ((instruction & 0xFFFF) == 0x00EE) {
         RET(processeur);
    }

    else if ((instruction & 0xF000) == 0x1000) {
         JP(processeur,instruction & 0x0FFF);
    }

    else if ((instruction & 0xF000) == 0x2000) {
         CALL(processeur,instruction & 0x0FFF);
    }

    else if ((instruction & 0xF000) == 0x3000) {
         SE_VX(processeur,(instruction & 0x0F00)>>8,P2);
    }

    else if ((instruction & 0xF000) == 0x4000) {
         SNE_VX(processeur,(instruction & 0x0F00)>>8,P2);
    }

    else if ((instruction & 0xF00F) == 0x5000) {
         SE_VX_VY(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4);
    }

    else if ((instruction & 0xF000) == 0x6000) {
         LD_VX(processeur,(instruction & 0x0F00)>>8,P2);
    }

    else if ((instruction & 0xF000) == 0x7000) {
        ADD_VX(processeur,(instruction & 0x0F00)>>8,P2);
    }

    else if ((instruction & 0xF00F) == 0x8000) {
         LD_VX_VY(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4);
    }

    else if ((instruction & 0xF00F) == 0x8001) {
         OR(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4);
    }

    else if ((instruction & 0xF00F) == 0x8002) {
        AND(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4);
    }

    else if ((instruction & 0xF00F) == 0x8003) {
         XOR(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4);
    }

    else if ((instruction & 0xF00F) == 0x8004) {
         ADD_VX_VY(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4);
    }

    else if ((instruction & 0xF00F) == 0x8005) {
        SUB_VX_VY(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4);
    }

    else if ((instruction & 0xF00F) == 0x8006) {
        SHR_VX(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4);
    }

    else if ((instruction & 0xF00F) == 0x8007) {
         SUBN_VX_VY(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4);
    }

    else if ((instruction & 0xF00F) == 0x800E) {
        SHL_VX(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4);
    }

    else if ((instruction & 0xF00F) == 0x9000) {
            SNE_VX_VY(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4);
    }

    else if ((instruction & 0xF000) == 0xA000) {
         LD_I_ADDR(processeur,instruction & 0xFFF);
    }

    else if ((instruction & 0xF000) == 0xB000) {
        JP_V0_ADDR(processeur,instruction & 0x0FFF);
    }

    else if ((instruction & 0xF000) == 0xC000) {
         RND_VX(processeur,(instruction & 0x0F00)>>8,P2);
    }
	
	else if ((instruction & 0xF000) == 0xD000) {
		DRW_VX_VY(processeur,(instruction & 0x0F00)>>8,(instruction & 0x00F0)>>4,instruction & 0x000F);
	}
	
	else if ((instruction & 0xF0FF) == 0xE09E) {
         SKP_VX(processeur,(instruction & 0x0F00)>>8);
    }
	
	else if ((instruction & 0xF0FF) == 0xE0A1) {
        SKNP_VX(processeur,(instruction & 0x0F00)>>8);
    }
	
	else if ((instruction & 0xF0FF) == 0xF007) {
         LD_VX_DT(processeur,(instruction & 0x0F00)>>8);
    }
	
	else if ((instruction & 0xF0FF) == 0xF00A) {
         LD_VX_K(processeur,(instruction & 0x0F00)>>8);
    }
	
	else if ((instruction & 0xF0FF) == 0xF015) {
         LD_DT_VX(processeur,(instruction & 0x0F00)>>8);
    }
	
	else if ((instruction & 0xF0FF) == 0xF018) {
        LD_ST_VX(processeur,(instruction & 0x0F00)>>8);
    }

    else if ((instruction & 0xF0FF) == 0xF01E) {
         ADD_I_VX(processeur,(instruction & 0x0F00)>>8);
    }
	
	else if ((instruction & 0xF0FF) == 0xF029) {
         LD_F_VX(processeur,(instruction & 0x0F00)>>8);
    }

    else if ((instruction & 0xF0FF) == 0xF033) {
         LD_B_VX(processeur,(instruction & 0x0F00)>>8);
    }

    else if ((instruction & 0xF0FF) == 0xF055) {
        LD_I_VX(processeur,(instruction & 0x0F00)>>8);
    }

    else if ((instruction & 0xF0FF) == 0xF065) {
        LD_VX_I(processeur,(instruction & 0x0F00)>>8);
    }
	
	return 0;// Retourne 0 pour indiquer que l'exécution s'est terminée sans erreur
}



void update_timers(struct Processeur * processeur) {
	
    
	if (processeur->sound_timer != 0) {
		processeur->sound_timer--;
	}
    
    
	if (processeur->delay_timer != 0) {
		processeur->delay_timer--;
	}
	
	
}