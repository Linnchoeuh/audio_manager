/**
 ** @file write_bit_in.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "bitwise.h"

void write_bit_in(void *dest,
				  void *src,
				  long dest_bit_size,
				  long src_bit_size)
{
	long i;

	i = 0;
	while (i < src_bit_size &&
		   (i < dest_bit_size || dest_bit_size == -1))
	{
		dest = std_bitsetto(dest, i, std_bitget(src, i));
		i++;
	}
}