/**
 ** @file adm_str_chain_fuse.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_baselib.h"

char *adm_str_chain_fuse(ssize_t len, ...)
{
	char *new_str;
	char *get_str;
	ssize_t i;
	va_list ap;

	if (len == 0)
		return (adm_strdup(""));
	va_start(ap, len);
	if ((new_str = adm_strdup((char*) va_arg(ap, char*))) == NULL)
		return (NULL);
	i = 1;
	while ((len == -1 || i < len) &&
		(get_str = (char*) va_arg(ap, char*)) != NULL)
	{
		adm_str_append(&new_str, get_str);
		i++;
	}
	va_end(ap);
	return (new_str);
}