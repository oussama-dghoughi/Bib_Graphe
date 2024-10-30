#include "Ram.h"

struct RAM * Ram_init() {
	// Allocation de la RAM et son Tab de 4096 cases d'un octet
    struct RAM * ram = malloc(sizeof(struct RAM));
    ram->Tab = malloc(Size * sizeof(uint8_t));
    return ram;
}



// Libère la mémoire allouée pour la structure RAM
void Ram_delete(struct RAM * ram) {
	// Libère la mémoire allouée pour le tableau de données et la structure RAM elle-même
    free(ram->Tab);
    free(ram);
}

uint8_t Ram_read(struct RAM * ram, uint16_t add) {
	// Vérifie si l'adresse est valide
    if (add <= PROG_END) {
        return ram->Tab[add];
    }
    else{
       return 0x000;  // Adresse invalide, retourne 0x000 
    } 
}

void Ram_write(struct RAM * ram, uint16_t add, uint8_t val) {
	// Vérifie si l'adresse est valide
    if (add <= PROG_END) {
        ram->Tab[add] = val;
    }
}