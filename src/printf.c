#include <stdarg.h>
#include <stdarg.h>
#include <stddef.h>
#include <kernel/printf.h>

// TODO: we need to implement some sort of locking/buffering mechanism
// in order to avoid interleaved prints across harts. we will purposefully
// ignore this for now

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

static char *digits = "0123456789abcdef";
static char *number(char *str, size_t size, int number, int base)
{
	// this is taken from linux's implementation.
	// haven't really looked into the reasoning for
	// choosing 3 specifically
	char tmp[32] = {0};
	size_t i = 0;
	while (number > 0) {
		tmp[i++] = digits[number % base];
		number /= base;
	}

	while (i-- > 0) {
		*str++ = tmp[i];
	}

	return str;
}

// this is roughly inspired by kernel/printk/printk.c
// within the linux kernel

enum fmt_state {
	FMT_STATE_NONE,
	FMT_STATE_PERCENTAGE,
	FMT_STATE_NUMBER,
};

struct fmt {
	char *str;
	enum fmt_state state;
};

static void vsnprintf(char *buf, size_t size, const char *fmt_str, va_list args)
{
	size_t i;
	struct fmt fmt = { .str = fmt_str, .state = FMT_STATE_NONE };
	char *str = buf;
	while (*fmt.str != '\0' && size > 1) {
		switch (fmt.state) {
		case FMT_STATE_NONE: {
			if (*fmt.str == '%') {
				fmt.str++;
				fmt.state = FMT_STATE_PERCENTAGE;
				continue;
			} else {
				*str++ = *fmt.str++;
				continue;
			}
		}
		case FMT_STATE_PERCENTAGE: {
			if (*fmt.str == 'd') {
				fmt.str++;
				int n = va_arg(args, int);
				str = number(str, size, n, 10);
			} else if (*fmt.str == 'x') {
				fmt.str++;
				int n = va_arg(args, int);
				str = number(str, size, n, 16);
			}
			fmt.state = FMT_STATE_NONE;
		}
		}
	}

	*str = '\0';
}

char g_buf[512];
void printk(const char *fmt_str, ...)
{
	va_list args;
	va_start(args, fmt_str);
	vsnprintf(g_buf, 256, fmt_str, args);
	print(g_buf);
}
