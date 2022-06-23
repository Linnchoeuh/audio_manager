/**
 ** @file adm_strnlen.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_libstd.h"

size_t adm_strnlen(const char *s,
					size_t	   n)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < n)
		++i;
	return (i);
}

