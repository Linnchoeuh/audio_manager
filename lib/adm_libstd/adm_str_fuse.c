/**
 ** @file adm_str_fuse.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_libstd.h"

char *adm_str_fuse(char *str1,
					char *str2)
{
  	char *fuse_str;
	size_t i;
	size_t k;
	size_t target_len;
	size_t new_len;

	target_len = adm_strlen(str1);
	new_len = target_len + adm_strlen(str2);
	if ((fuse_str = malloc(new_len + 1)) == NULL)
		return (false);
	i = 0;
	while (str1[i] != '\0')
	{
		fuse_str[i] = str1[i];
		i++;
	}
	k = 0;
	while (i < new_len)
	{
		fuse_str[i] = str2[k];
		i++;
		k++;
	}
	fuse_str[i] = '\0';
  	return (fuse_str);
}