/**
 ** @file wave_get_header.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

/*
static bool wave_bool_strncmp(const char *s1,
				  const char *s2,
				  int len)
{
	int i;
	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	return (true);
}
*/

bool wave_get_header(int fd,
					 t_wave_header *w_header)
{
	if (read(fd, w_header, HEADER_SIZE) != HEADER_SIZE)
		return (false);
	return (true);
}