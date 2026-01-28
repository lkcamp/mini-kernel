#include <stdint.h>
#include <stdint.h>
#include <stddef.h>
#include <kernel/printf.h>

#define SYSCON_ADDR 0x100000
void poweroff(void) {
	*(uint64_t *)SYSCON_ADDR = 0x7777;
}

uint64_t csr_mstatus_read();
void kmain(void)
{
	char buf[64];
	print("Hello world!\r\n");
	printk("test!\r\n");
	printk("test int: %d\r\n", 12345);
	printk("test hex: 0x%x\r\n", 12345);

	while (1) {

	}
	return;
}
