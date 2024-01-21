#include "system.h"
#include "C:\Users\oksta\OneDrive\Documents\5A\ESN11\software\bsp\drivers\inc\altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_sys_init.h"
#include "alt_types.h"
#include "io.h"
#include "unistd.h"

int main(void)
{
	int adresse = 0b00000001;
		while (1)
		{
			IOWR_ALTERA_AVALON_PIO_DATA(PIOLED_BASE, adresse);
			usleep(500000);
			if (adresse == 0b10000000)
			{
				adresse = 0b00000001;
			}
			else
			{
				adresse = adresse << 1;
			}
		}
	
}