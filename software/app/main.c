#include "system.h"
#include "C:\Users\oksta\OneDrive\Documents\5A\ESN11\software\bsp\drivers\inc\altera_avalon_pio_regs.h"

int main(void)
{
	IOWR_ALTERA_AVALON_PIO_DATA(PIOLED_BASE, 0x01);
}