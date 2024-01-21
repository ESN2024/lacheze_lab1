#include "system.h"
#include "C:\Users\oksta\OneDrive\Documents\5A\ESN11\software\bsp\drivers\inc\altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_sys_init.h"
#include "alt_types.h"
#include "io.h"
#include "unistd.h"
#include "stdio.h"
#include "sys/alt_irq.h"

volatile int adresse = 0x01;

static void irqhandler(void* context, alt_u32 id)
{
	adresse = 0x01;
	IOWR_ALTERA_AVALON_PIO_DATA(PIOLED_BASE, adresse);

	for (int i = 0; i < 16; i++)
	{
		IOWR_ALTERA_AVALON_PIO_DATA(PIOLED_BASE, adresse);
		usleep(500000);
		if (i < 7)
		{
			adresse = adresse << 1;
		}
		else
		{
			adresse = adresse >> 1;
		}
		
	}
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIOBP_BASE, 0x80);
}
int main(void)
{
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIOBP_BASE, 0x80);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIOBP_BASE, 0x80);
	alt_irq_register(PIOBP_IRQ, NULL, (void *) irqhandler);
	while (1)
	{
	}
}