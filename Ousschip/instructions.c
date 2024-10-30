
#include "instruction.h"


/******************************** 00E0 ************************************/
int CLS(struct Processeur * processeur) {
	Display_CLS(processeur->display);
	return 0;
}

/******************************** 00EE ************************************/

int RET(struct Processeur * processeur) {
    processeur->pc_reg = processeur->Stack[processeur->sp_reg];
    processeur->sp_reg--;
    return 0;
}

/******************************** 1nnn ************************************/

int JP(struct Processeur * processeur,uint16_t nnn) {
    processeur->pc_reg = nnn;
    return 0;
}

/******************************** 2nnn ************************************/

int CALL(struct Processeur * processeur,uint16_t nnn) {
    processeur->sp_reg++;
	processeur->Stack[processeur->sp_reg] = processeur->pc_reg;
    processeur->pc_reg = nnn;
    return 0;
}

/******************************** 3xkk ************************************/

int SE_VX(struct Processeur * processeur,uint8_t x,uint8_t kk) {
    if (processeur->V[x] == kk) {
        processeur->pc_reg += 2;
    }
    return 0;
}

/******************************** 4xkk ************************************/

int SNE_VX(struct Processeur * processeur,uint8_t x,uint8_t kk) {
    if (processeur->V[x] != kk) {
        processeur->pc_reg += 2;
    }
    return 0;
}

/******************************** 5xy0 ************************************/

int SE_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y) {
    if (processeur->V[x] == processeur->V[y]) {
        processeur->pc_reg += 2;
    }
    return 0;
}

/******************************** 6xkk ************************************/

int LD_VX(struct Processeur * processeur,uint8_t x,uint8_t kk) {
    processeur->V[x] = kk;
    return 0;
}

/******************************** 7xkk ************************************/

int ADD_VX(struct Processeur * processeur,uint8_t x,uint8_t kk) {
    processeur->V[x] = processeur->V[x] + kk;
    return 0;
}

/******************************** 8xy0 ************************************/

int LD_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y) {
    processeur->V[x] = processeur->V[y];
    return 0;
}

/******************************** 8xy1 ************************************/

int OR(struct Processeur * processeur,uint8_t x,uint8_t y) {
    processeur->V[x] = (processeur->V[x] | processeur->V[y]);
    return 0;
}

/******************************** 8xy2 ************************************/

int AND(struct Processeur * processeur,uint8_t x,uint8_t y) {
    processeur->V[x] = (processeur->V[x] & processeur->V[y]);
    return 0;
}

/******************************** 8xy3 ************************************/

int XOR(struct Processeur * processeur,uint8_t x,uint8_t y) {
    processeur->V[x] = (processeur->V[x] ^ processeur->V[y]);
    return 0;
}

/******************************** 8xy4 ************************************/

int ADD_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y) {
    uint8_t val = processeur->V[x];
	uint16_t sum = val + processeur->V[y];
	processeur->V[x] += processeur->V[y];
    if (sum > 0xFF) {
        processeur->V[15] = 1;
    }
    else {
        processeur->V[15] = 0;
    }
    return 0;
}

/******************************** 8xy5 ************************************/

int SUB_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y) {
	uint8_t val = processeur->V[x];
	processeur->V[x] -= processeur->V[y];
    if (val >= processeur->V[y]) {
        processeur->V[15] = 1;
    }
    else {
        processeur->V[15] = 0;
    }
    return 0;
}

/******************************** 8xy6 ************************************/

int SHR_VX(struct Processeur * processeur,uint8_t x,uint8_t y) {
	uint8_t destination_val = processeur->V[x];
	processeur->V[x] >>= 1;
    if ((destination_val & 0x01) == 0x01) {
        processeur->V[15] = 1;
    }
    else {
        processeur->V[15] = 0;
    }
    return 0;
}

/******************************** 8xy7 ************************************/

int SUBN_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y) {
    uint8_t val = processeur->V[y];
	processeur->V[x] = processeur->V[y] - processeur->V[x];
    if (val > processeur->V[x]) {
        processeur->V[15] = 1;
    }
    else {
        processeur->V[15] = 0;
    }
    return 0;
}

/******************************** 8xyE ************************************/

int SHL_VX(struct Processeur * processeur,uint8_t x,uint8_t y) {
	uint8_t shift_val = processeur->V[x];
	processeur->V[x] <<= 1;
    if ((shift_val & 0x80) == 0x80) {
        processeur->V[15] = 1;
    }
    else {
        processeur->V[15] = 0;
    }
    return 0;
}

/******************************** 9xy0 ************************************/

int SNE_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y) {
    if (processeur->V[x] != processeur->V[y]) {
        processeur->pc_reg += 2;
    }
    return 0;
}

/******************************** Annn ************************************/

int LD_I_ADDR(struct Processeur * processeur,uint16_t nnn) {
    processeur->I_reg = nnn;
    return 0;
}

/******************************** Bnnn ************************************/

int JP_V0_ADDR(struct Processeur * processeur,uint16_t nnn) {
    processeur->pc_reg = nnn + processeur->V[0];
    return 0;
}

/******************************** Cxkk ************************************/

int RND_VX(struct Processeur * processeur,uint8_t x,uint8_t kk) {
    int rand_number = rand() % 256;
    uint8_t low_byte = (uint8_t)rand_number;
    processeur->V[x] = (low_byte & kk);
    return 0;
}

/******************************** Dxkk ************************************/

int DRW_VX_VY(struct Processeur * processeur,uint8_t x,uint8_t y,uint8_t n) {
	
    uint8_t val;
	struct Sprite * sprite = malloc(sizeof(struct Sprite));
	
	Sprite_init(sprite,n);
	
	for (int i = 0;i<n;i++) {
		val = Ram_read(processeur->ram,processeur->I_reg+i);
		Sprite_add(sprite,val);
	}
	
	Display_DRW(processeur->display,sprite,processeur->V[x],processeur->V[y],&processeur->V[15]);
	
	
	Sprite_destroy(sprite);
	free(sprite);
	return 0;
}

/******************************** Ex9E ************************************/

int SKP_VX(struct Processeur * processeur,uint8_t x) {
	unsigned int keyb = 0;
	keyb = Keyboard_get(processeur->keyboard,processeur->V[x]);
	if (keyb == 1) {
		processeur->pc_reg += 2;
	}
	return 0;
}

/******************************** ExA1 ************************************/

int SKNP_VX(struct Processeur * processeur,uint8_t x) {
	unsigned int keyb = 0;
	keyb = Keyboard_get(processeur->keyboard,processeur->V[x]);
	if (keyb == 0) {
		processeur->pc_reg += 2;
	}
	return 0;
}

/******************************** FX07 ************************************/

int LD_VX_DT(struct Processeur * processeur,uint8_t x) {
	processeur->V[x] = processeur->delay_timer;
	return 0;
}

/******************************** Fx0A ************************************/

int LD_VX_K(struct Processeur * processeur,uint8_t x) {
	Keyboard_wait(processeur->keyboard,&processeur->V[x]);
	return 0;
}

/******************************** Fx15 ************************************/

int LD_DT_VX(struct Processeur * processeur,uint8_t x) {
	processeur->delay_timer = processeur->V[x];
	return 0;
}

/******************************** Fx18 ************************************/

int LD_ST_VX(struct Processeur * processeur,uint8_t x) {
	processeur->sound_timer = processeur->V[x];
	return 0;
}

/******************************** Fx1E ************************************/

int ADD_I_VX(struct Processeur * processeur,uint8_t x) {
    processeur->I_reg = processeur->I_reg + processeur->V[x];
    return 0;
}

/******************************** Fx29 ************************************/

int LD_F_VX(struct Processeur * processeur,uint8_t x) {
	processeur->I_reg =  5 * processeur->V[x];
	return 0;
}

/******************************** Fx33 ************************************/

int LD_B_VX(struct Processeur * processeur,uint8_t x) {
    uint8_t centaines = processeur->V[x] / 100;
    Ram_write(processeur->ram,processeur->I_reg,centaines);
	
    uint8_t dizaines = (processeur->V[x] - centaines*100) / 10;
    Ram_write(processeur->ram,processeur->I_reg+1,dizaines);
	
    uint8_t unites = (processeur->V[x] - centaines*100 - dizaines*10);
    Ram_write(processeur->ram,processeur->I_reg+2,unites);
	
    return 0;
}

/******************************** Fx55 ************************************/

int LD_I_VX(struct Processeur * processeur,uint8_t x) {
    for (int i =0;i<=x;i++) {
        Ram_write(processeur->ram,processeur->I_reg+j,processeur->V[i]);
    }
    return 0;
}

/******************************** Fx65 ************************************/

int LD_VX_I(struct Processeur * processeur,uint8_t x) {
    for (int i=0;i<=x ;i++) {
        processeur->V[i] = Ram_read(processeur->ram,processeur->I_reg+i);
    }
    return 0;
}


