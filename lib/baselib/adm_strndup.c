/*
** *****************************************************************************
** lenny.vigeon
** lenny.vigeon <lenny.vigeon@student-station>
**
** adm_strndup.c - 2022
**
** *****************************************************************************
*/

#include "adm_baselib.h"

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