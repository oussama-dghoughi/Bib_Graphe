#ifndef CHIP8_H
#define CHIP8_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include "Ram.h"
#include "processeur.h"
#include "display.h"
#include "misc/error.h"
#include "keyboard/keyboard.h"
#include "speaker.h"
#include "sprite.h"
#include "sp.h"


/* 
	Définition de la structure Chip8 qui représente 
	l'émulateur Chip8
*/
struct Chip8 {
	struct Processeur * processeur;// Pointeur vers le processeur
	struct RAM * ram;// Pointeur vers la RAM
	struct Display * display;// Pointeur vers screen
	struct Keyboard * keyboard;// Pointeur vers clavier
	struct Speaker * speaker;// Pointeur vers speaker
	struct Sprite sprites[16];// Tableau de sprites
};


/*
	 Fonction pour initialiser le système Chip8
*/
int Init_Systeme(struct Chip8* chip);

/*
	 Fonction pour supprimer le système Chip8
*/
void Delete_Systeme(struct Chip8* chip);

/*
	Fonction pour charger une ROM dans le système Chip8
*/
int Load_Rom(struct Chip8* chip, char * rom);

/*
	Fonction pour exécuter la boucle principale de la machine Chip8
	Vérification si tous les délais sont écoulées
*/
int Machine_Loop(struct Chip8* chip,uint32_t * temps_fde,uint32_t * temps_timers,uint32_t * temps_display ,int *running);

#endif