#include "system.h"
#include "C:\Users\oksta\OneDrive\Documents\5A\ESN11\software\bsp\drivers\inc\altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_sys_init.h"
#include "alt_types.h"
#include "io.h"
#include "unistd.h"
#include <stdio.h>
#include "sys/alt_irq.h"

volatile __uint16_t adresse = 0x0001;
volatile __uint32_t time = 50000;
volatile __uint16_t val;

static void irqhandler(void* context, alt_u32 id)
{
	val = IORD_ALTERA_AVALON_PIO_DATA(PIOBP_BASE);
	if (val & 0x000F)
	{
		time = val * 100000 + 50000;
	}
	if ((val & 0x0080)==0)
	{
		adresse = 0x01;
		IOWR_ALTERA_AVALON_PIO_DATA(PIOLED_BASE, adresse);

		for (int i = 0; i < 16; i++)
		{
			IOWR_ALTERA_AVALON_PIO_DATA(PIOLED_BASE, adresse);
			usleep(time);
			if (i < 7)
			{
				adresse = adresse << 1;
			}
			else
			{
				adresse = adresse >> 1;
			}

		}
	}
	
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIOBP_BASE, 0x8F);
}
int main(void)
{
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIOBP_BASE, 0x8F);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIOBP_BASE, 0x8F);
	alt_irq_register(PIOBP_IRQ, NULL, (void*)irqhandler);
	while (1)
	{
	}
}