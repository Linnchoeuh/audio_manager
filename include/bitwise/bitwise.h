/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@stu018.cst.bunny.local>
** Ecole 89 - 24/01/2022 10:00:00
**
** - BitWise.h -
**
** *****************************************************************************
*/

#ifndef		__BITWISE_H__
#define		__BITWISE_H__

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#define BITSET(data, bit_nbr) ((data) | (1 << (bit_nbr)))

#define BITRESET(data, bit_nbr) ((data) & ~(1 << (bit_nbr)))

#define BITGET(data, bit_nbr) ((data) >> (bit_nbr) & 1)

#define BITREV(data, bit_nbr) ((BITGET((data), (bit_nbr))) ? \
								BITRESET((data), (bit_nbr)) : \
								BITSET((data), (bit_nbr)))

#define BITSETTO(data, bit_nbr, value) ((value) ? \
								BITSET((data), (bit_nbr)) : \
								BITRESET((data), (bit_nbr)))

void print_binary(void *data,
				  int bitlen,
				  char *separation,
				  char *end);

bool std_bitget(void *data,
				size_t bit_nbr);

void *std_bitsetto(void *data,
				   size_t bit_nbr,
				   bool binary);

void write_bit_in(void *dest,
				  void *src,
				  long dest_bit_size,
				  long src_bit_size);

#endif /* __BITWISE_H__ */