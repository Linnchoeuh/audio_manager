/**
 ** @file adm_str_append.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_libstd.h"

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