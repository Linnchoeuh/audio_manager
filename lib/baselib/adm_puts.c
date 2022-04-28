/**
 ** @file adm_puts.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_baselib.h"

ssize_t	adm_puts(const char *str)
{
	return (adm_fdputs(STDERR_FILENO, str));
}