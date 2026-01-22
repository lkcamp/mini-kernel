#include <stdint.h>
#include <stddef.h>
#include <stdint.h>

char *uart = (char *)0x10000000;
void putchar(char c)
{
	*uart = c;
	return;
}

void print(const char *str)
{
	while (*str != '\0') {
		putchar(*str);
		str++;
	}
	return;
}

#define SYSCON_ADDR 0x100000
void poweroff(void) {
	*(uint64_t *)SYSCON_ADDR = 0x7777;
}

void kmain(void)
{
	print("Hello world!\r\n");
	while (1) {

	}
	return;
}
