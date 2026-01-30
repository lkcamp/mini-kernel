#ifndef __CSR_H__
#define __CSR_H__

#include <stdint.h>

#define CSR_MSTATUS_MPP_MASK 0x

#define csr_read(csr)					\
({							\
	register uint64_t __v;				\
	__asm__ __volatile__ ("csrr %0, " #csr		\
			: "=r" (__v)			\
			:				\
			: "memory");			\
	__v;						\
})

#define csr_write(csr, val)				\
({							\
	register uint64_t __v = (uint64_t) val;		\
	__asm__ __volatile__ ("csrw " #csr ", %0"	\
		 :					\
		 : "rK" (__v)				\
		 : "memory");				\
})

#endif
