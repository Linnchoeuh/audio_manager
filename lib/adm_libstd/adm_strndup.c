/**
 ** @file adm_strndup.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_libstd.h"

char *adm_strndup(const char	*s,
				size_t	n)
{
	char	 *str;
	size_t i;

	i = 0;
	if ((str = malloc(adm_strnlen(s, n) + 1)) == NULL)
		return (NULL);
	while (s[i] != '\0' && i < n)
	{
		str[i] = s[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}