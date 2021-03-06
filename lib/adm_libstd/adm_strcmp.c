/**
 ** @file adm_strcmp.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_libstd.h"

int	adm_strcmp(const char *str1,
				const char *str2)
{
	int i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0')
		i++;
	return (str2[i] - str1[i]);
}

