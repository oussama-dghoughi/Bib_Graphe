#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H



#include "processeur.h"
#include "display/display.h"
#include "Ram.h"
#include "sprite.h"
#include "keyboard/keyboard.h"


/* 
    Définition d'un alias pour le pointeur vers 
    la structure Processeur
*/
typedef struct Processeur * processeur;

/* 
   Instruction  pour effacer l'écran
*/
int CLS(struct Processeur * processeur);


/* 
   Instruction  pour retourner d'une sous-routine
*/
int RET(struct Processeur * processeur);


/* 
   Instruction  pour sauter à l'adresse nnn
*/
int JP(struct Processeur * processeur,uint16_t nnn);


/* 
   Instruction pour appeler une sous-routine à l'adresse nnn
*/
int CALL(struct Processeur * processeur,uint16_t nnn);


/* 
   Instruction  pour sauter à une adresse
    déterminée par la combinaison de x et kk
*/
int SE_VX(struct Processeur * processeur,uint8_t x,uint8_t kk);


/* 
    Instruction  pour sauter à l'adresse nnn
    si la valeur de Vx n'est pas égale à kk
*/
int SNE_VX(struct Processeur * processeur,uint8_t x,uint8_t kk);


/* 
    Instruction  pour sauter à l'adresse nnn
    si la valeur des registres Vx et Vy est égale à kk 
*/
int SE_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y);


/* 
    Instruction  pour sauter à l'adresse nnn
    si la valeur des registres Vx et Vy est égale à kk 
*/
int LD_VX(struct Processeur * processeur,uint8_t x,uint8_t kk);


/* 
    pour charger une valeur constante kk dans le registre Vx
*/
int ADD_VX(struct Processeur * processeur,uint8_t x,uint8_t kk);


/* 
    instruction pour ajouter une constante kk au registre Vx
*/
int LD_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y);


/* 
     instruction pour effectuer une opération logique OR entre les valeurs de Vx et Vy
    et stocker le résultat dans Vx
*/

int OR(struct Processeur * processeur,uint8_t x,uint8_t y);


/* 
    instruction pour effectuer une opération logique AND 
   entre les valeurs de Vx et Vy et stocker le résultat dans Vx
*/
int AND(struct Processeur * processeur,uint8_t x,uint8_t y);


/* 
   instruction pour effectuer une opération logique XOR entre les valeurs de Vx
*/
int XOR(struct Processeur * processeur,uint8_t x,uint8_t y);


/* 
    instruction pour ajouter la valeur de Vy à Vx
    et stocker le résultat dans Vx
*/
int ADD_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y);


/* 
    intructionpour soustraire la valeur de Vy de Vx
    et stocker le résultat dans Vx
*/
int SUB_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y);


/* 
    instruction Fonction pour décaler les bits de la valeur de Vx vers la droite 
    et stocker le bit de retenue dans VF
*/
int SHR_VX(struct Processeur * processeur,uint8_t x,uint8_t y);


/* 
    instruction pour soustraire la valeur de Vy de Vx avec emprunt 
    et stocker le résultat dans Vx
*/
int SUBN_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y);


/* 
    instruction pour décaler les bits de la valeur de Vx vers la gauche 
    et stocker le bit de retenue dans VF
*/
int SHL_VX(struct Processeur * processeur,uint8_t x,uint8_t y);


/* 
    instruction pour sauter à l'adresse nnn si la valeur du registre Vx 
    n'est pas égale à celle stockée dans Vy
*/
int SNE_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y);


/* 
    instruction pour charger l'adresse nnn dans le registre I
*/
int LD_I_ADDR(struct Processeur * processeur,uint16_t nnn);


/*
    instruction pour sauter à l'adresse nnn+offset 
    si la valeur de Vx est égale à kk
*/
int JP_V0_ADDR(struct Processeur * processeur,uint16_t nnn);


/*
    instruction pour générer un nombre aléatoire entre 0 et 255, 
    puis effectuer un ET logique avec la valeur kk
    et stocker le résultat dans Vx
*/
int RND_VX(struct Processeur * processeur,uint8_t x,uint8_t kk);


/*
    instruction pour afficher un sprite à l'écran 
    à la position définie par les valeurs de Vx et Vy
*/
int DRW_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y,uint8_t n);


/*
   instruction pour sauter à l'adresse nnn 
    si la touche correspondant à la valeur de Vx est pressée
*/
int SKP_VX(struct Processeur * processeur,uint8_t x);


/*
     instruction pour sauter à l'adresse nnn 
    si la touche correspondant à la valeur de Vx n'est pas pressée
*/
int SKNP_VX(struct Processeur * processeur,uint8_t x);


/*
    instruction pour sauter à l'adresse nnn 
    si la touche correspondant à la valeur de Vx n'est pas pressée
*/
int LD_VX_DT(struct Processeur * processeur,uint8_t x);


/*
    instruction pour mettre en pause le programme 
    jusqu'à ce qu'une touche soit pressée,
     puis stocker sa valeur dans Vx
*/
int LD_VX_K(struct Processeur * processeur,uint8_t x);


/*
    instruction pour définir la valeur du timer à la valeur de Vx
*/
int LD_DT_VX(struct Processeur * processeur,uint8_t x);


/*
    instruction pour définir la valeur du timer à la valeur de Vx
*/
int LD_ST_VX(struct Processeur * processeur,uint8_t x);


/*
    instruction pour ajouter la valeur de Vx à l'adresse I et stocker le résultat dans I
*/
int ADD_I_VX(struct Processeur * processeur,uint8_t x);


/*
    instruction pour charger le sprite représentant le caractère Vx 
    dans la mémoire vidéo à l'adresse I
*/
int LD_F_VX(struct Processeur * processeur,uint8_t x);


/*
    instruction pour convertir la valeur du registre Vx en décimal 
    et stocker chaque chiffre dans les adresses I, I+1 et I+2
*/
int LD_B_VX(struct Processeur * processeur,uint8_t x);


/*
    instruction stocker les valeurs des registres V0 à Vx dans la mémoire 
    à partir de l'adresse stockée dans I
*/
int LD_I_VX(struct Processeur * processeur,uint8_t x);


/*
    instruction charger des valeurs depuis 
    la mémoire dans les registres V0 à Vx
*/
int LD_VX_I(struct Processeur * processeur,uint8_t x);


#endif /*INSTRUCTIONS_H */