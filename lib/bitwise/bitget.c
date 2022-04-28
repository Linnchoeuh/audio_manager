/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@stu018.cst.bunny.local>
** Ecole 89 - 24/01/2022 10:00:00
**
** - Bitget -
**
** Get the requested bit in data
** the difference beetween the macro and this function is
** it can search in a whole pointer and not only a byte.
** *****************************************************************************
*/

#include	"bitwise.h"

bool std_bitget(void *data,
				 size_t bit_nbr)
{
	char *tmp;
	size_t pos;
	size_t bit;

	tmp = (char*) data;
	pos = bit_nbr / 8;
	bit = bit_nbr % 8;
	return (BITGET(tmp[pos], bit));
}