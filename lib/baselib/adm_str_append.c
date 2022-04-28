/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89 - 14/02/2022 10:00:00
**
** adm_str_append.c - 2022
**
** *****************************************************************************
*/

#include "adm_baselib.h"

bool adm_str_append(char **target,
				   		char *merge)
{
	char *new_str;

	if ((new_str = adm_str_fuse(*target, merge)) == NULL)
		return (false);
	free(*target);
	*target = new_str;
	return (true);
}