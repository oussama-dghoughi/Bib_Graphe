#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "sprite.h"
#include "sp.h"



// Initialise et ajoute les données du sprite
 void init_and_add_sprite(struct Sprite *sprite, const uint8_t *data, size_t size) {
    // Parcourt les données du sprite et les ajoute au sprite
    for (size_t i = 0; i < size; i++) {
        Sprite_add(sprite, data[i]);
    }
}




/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite 0
        * Initialise et ajoute les données du sprite
 */


int sprite_0(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x90, 0x90, 0x90, 0xF0};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite 1
        * Initialise et ajoute les données du sprite
 */

int sprite_1(struct Sprite *sprite) {
    const uint8_t data[] = {0x20, 0x60, 0x20, 0x20, 0x70};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite 2
        * Initialise et ajoute les données du sprite
 */

int sprite_2(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x10, 0xF0, 0x80, 0xF0};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite 3
        * Initialise et ajoute les données du sprite
 */

int sprite_3(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x10, 0xF0, 0x10, 0xF0};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite 4
        * Initialise et ajoute les données du sprite
 */

int sprite_4(struct Sprite *sprite) {
    const uint8_t data[] = {0x90, 0x90, 0xF0, 0x10, 0x10};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite 5
        * Initialise et ajoute les données du sprite
 */

int sprite_5(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x80, 0xF0, 0x10, 0xF0};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite 6
        * Initialise et ajoute les données du sprite
 */

int sprite_6(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x80, 0xF0, 0x90, 0xF0};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite 7
        * Initialise et ajoute les données du sprite
 */

int sprite_7(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x10, 0x20, 0x40, 0x40};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}
/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite 8
        * Initialise et ajoute les données du sprite
 */

int sprite_8(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x90, 0xF0, 0x90, 0xF0};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite 9
        * Initialise et ajoute les données du sprite
 */


int sprite_9(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x90, 0xF0, 0x10, 0xF0};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite A
        * Initialise et ajoute les données du sprite
 */

int sprite_A(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x90, 0xF0, 0x90, 0x90};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite B
        * Initialise et ajoute les données du sprite
 */


int sprite_B(struct Sprite *sprite) {
    const uint8_t data[] = {0xE0, 0x90, 0xE0, 0x90, 0xE0};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite C
        * Initialise et ajoute les données du sprite
 */

int sprite_C(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x80, 0x80, 0x80, 0xF0};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite D
        * Initialise et ajoute les données du sprite
 */

int sprite_D(struct Sprite *sprite) {
    const uint8_t data[] = {0xE0, 0x90, 0x90, 0x90, 0xE0};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite E
        * Initialise et ajoute les données du sprite
 */

int sprite_E(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x80, 0xF0, 0x80, 0xF0};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}

/*
    Initialisation et ajout des valeurs hexadécimales des sprites:

        * Données hexadécimales du sprite F
        * Initialise et ajoute les données du sprite
 */


int sprite_F(struct Sprite *sprite) {
    const uint8_t data[] = {0xF0, 0x80, 0xF0, 0x80, 0x80};
    init_and_add_sprite(sprite, data, sizeof(data));
    return 0;
}





