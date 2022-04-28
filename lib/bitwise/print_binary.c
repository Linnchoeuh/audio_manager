/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@stu018.cst.bunny.local>
** Ecole 89 - 24/01/2022 10:00:00
**
** - BitShake -
**
** The binary value given in data
** Be careful the len is not by bytes but by bits.
** *****************************************************************************
*/

#include "bitwise.h"

static size_t print_binary_strlen(char *separation)
{
	size_t i;

	i = 0;
	while (separation[i] != 0)
		i++;
	return (i);
}

static void recursive_part(void *data,
					int i,
				  	int bitlen,
				  	char *separation)
{
	char c;
	char *casted_data;

	if (i >= bitlen)
		return;
	recursive_part(data, i + 1, bitlen, separation);
	casted_data = (char *) data;
	c = BITGET(casted_data[i / 8], i % 8) + '0';
	write(STDOUT_FILENO, &c, 1);
	if (i != 0 && i % 8 == 0)
		write(STDOUT_FILENO, separation, print_binary_strlen(separation));
}

void print_binary(void *data,
				  int bitlen,
				  char *separation,
				  char *end)
{
	recursive_part(data, 0, bitlen, separation);
	write(STDOUT_FILENO, end, print_binary_strlen(end));
}
