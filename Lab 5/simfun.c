// Eric Mow
char mem[256];
char x[4]; //registers
char pc; //program counter

char mem_copy[256]; //copy
char x[4]; //registers

#include <stdio.h>


main() {
	reset(); //set all variables to 0)
	load(); //load program into memory)
	sim();
	dump();
}

void load() {
	char ch; int p = 0;
	while ( ch = scanf("%c", &ch))
		mem[p] = ch;
		p++;
	for(int i =0; i<256; i++) 
		mem_copy[i] = mem[i];
}

#define BRA 0
#define BZ 1
#define LD 2
#define LDI 3
#define ST 4
#define ADD 5
#define NEG 6
#define HLT 7

void sim() {
	while(1) {
		char inst = mem[pc];
		pc++;
		int fun = inst >> 5;
		int r = mem[pc]&0x3;//pick out correct bits for R and S
		int s = mem[pc]&0xC>>2;
		char imm = mem[pc]&0x0F; //did i sign extend right?
		if (fun == BRA) {
			pc = imm;
		}
		else if (fun == BZ) {
			if (x[1] == 0) {
                pc = pc + imm;
            }
		}
        else if (fun == LD) {
            x[r] = mem[x[s]];
		}
        else if (fun == LDI) {
			x[0] = imm;
		}
        else if (fun == ST) {
            mem[x[s]] = x[r];
		}
        else if (fun == ADD) {
            x[r] = x[r] + x[s];
		}
        else if (fun == NEG) {
            x[r] = x[r] - x[r];
		}
        else if (fun == HLT) {
			break;
		}
// halt will break();
	}

}

void dump() {
    printf("/simfun < asm.out");
    printf("HLT encountered at PC = %c", pc);
    printf("PC: 0 --> %c", pc);
    printf("X0: 0 --> %c", x[0]);
    printf("X1: 0 --> %c", x[1]);
    printf("X2: 0 --> %c", x[2]);
    printf("X3: 0 --> %c", x[3]);
}
// building simfun 
// /simfun < square.bin