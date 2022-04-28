/*
** *****************************************************************************
** lenny.vigeon
** lenny.vigeon <lenny.vigeon@student-station>
**
** adm_strnlen.c - 2022
**
** *****************************************************************************
*/

#include "adm_baselib.h"

size_t adm_strnlen(const char *s,
					size_t	   n)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < n)
		++i;
	return (i);
}

