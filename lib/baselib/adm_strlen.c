/*
** *****************************************************************************
** lenny.vigeon
** lenny.vigeon <lenny.vigeon@student-station>
**
** adm_strlen.c - 2022
**
** *****************************************************************************
*/

#include "adm_baselib.h"

size_t adm_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}