/**
 ** @file adm_fputs.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_libstd.h"

ssize_t	adm_fdputs(int fd,
				   const char *str)
{
	return (write(fd, str, adm_strlen(str)));
}