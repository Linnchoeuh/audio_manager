/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@csr-pi03.ecole-89.com>
** Ecole 89 - 14/02/2022 10:00:00
**
** - adm_strcasecmp.c -
**
** *****************************************************************************
*/

#include "adm_baselib.h"

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

