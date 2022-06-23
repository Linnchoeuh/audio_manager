/**
 ** @file adm_strlen.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_libstd.h"

size_t adm_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}