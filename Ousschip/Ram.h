#ifndef CHIP_H_INCLUDED
#define CHIP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define Size 4096 
#define PROG_END 0xFFF


/*
    Structure représentant la RAM
    Contient un tableau d'octets pour stocker les données.
*/

struct RAM {
    uint8_t * Tab;
};


/*
    Initialise et retourne un pointeur vers une nouvelle instance de la structure RAM.
    Alloue de la mémoire pour la RAM et son tableau de données.
*/
struct RAM * Ram_init();

/*
    Libère la mémoire allouée pour la structure RAM.
*/
void Ram_delete(struct RAM * ram);

/*
    Lit un octet à partir de l'adresse spécifiée dans la RAM.
    Si l'adresse est valide, renvoie la valeur à cette adresse, sinon renvoie 0.
*/
uint8_t Ram_read(struct RAM * ram, uint16_t add);

/*
    Écrit une valeur dans la RAM à l'adresse spécifiée.
    Si l'adresse est valide, écrit la valeur à cette adresse.
*/
void Ram_write(struct RAM * ram, uint16_t add, uint8_t val);



#endif // CHIP_H_INCLUDED