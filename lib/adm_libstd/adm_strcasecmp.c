/**
 ** @file adm_strcasecmp.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_libstd.h"

int	adm_strcasecmp(const char	*a,
					const char	*b)
{
	size_t i;

	i = 0;
	while (ADM_TOLOWER(a[i]) == ADM_TOLOWER(b[i]) &&
	    	a[i] != 0 && b[i] != 0)
		++i;
  	return (ADM_TOLOWER(a[i]) - ADM_TOLOWER(b[i]));
}

