#ifndef PROCESSEUR_H_INCLUDED
#define PROCESSEUR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "display/display.h"
#include "misc/error.h"
#include "keyboard/keyboard.h"
#include "speaker/speaker.h"
#include "display/sprite.h"
#include "Ram.h"
#include "instruction.h"

#define S_SIZE 16 
#define V_REG 16 


// Structure représentant le processeur
struct Processeur {
    uint8_t * V; // Les 16 registres 8 bits
    uint16_t I_reg; // Le registre 16-bit
    uint16_t * Stack;// La Stack pour stocker les adresses
    uint8_t sp_reg; //stack pointer
    uint16_t pc_reg;//counter program
    uint8_t delay_timer ; // Delay Timer
    uint8_t sound_timer ; // Sound Timer  
    struct RAM * ram; // Pointeur vers la RAM
	struct Display * display; // Pointeur vers screen
	struct Keyboard * keyboard; // Pointeur vers clavier
	struct Speaker * speaker; // Pointeur vers speaker
};


/* 

    Initialise et retourne un pointeur vers
    une nouvelle instance de la structure Processeur

*/
struct Processeur * Processeur_init();

/*

     Libère la mémoire allouée 
     pour la structure Processeur

*/
void Processeur_delete(struct Processeur * processeur);


/*

    Fonction pour récupérer, décoder et 
    exécuter les instructions

 */
int fetch_decode_execute(struct Processeur * processeur);

/*
    Fonction pour mettre en á jours delay et sound
 
*/ 

void update_timers(struct Processeur * processeur);


#endif // PROCESSEUR_H_INCLUDED