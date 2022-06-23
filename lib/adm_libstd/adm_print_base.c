/**
 ** @file adm_print_base.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_libstd.h"

#define 	MAX_BASE 36

int	adm_print_base(ssize_t	nbr,
				   int	base)
{
  char	c;
  int	count;
  char nums[MAX_BASE] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  if (base >= MAX_BASE)
	return (-1);
  if (nbr < 0)
	{
	  nbr = -nbr;
	  write(STDOUT_FILENO, "-", 1);
	}
  c = nums[nbr % base];
  count = 1;
  if (nbr > base - 1)
	count += adm_print_base(nbr / base, base);
  write(STDOUT_FILENO, &c, 1);
  return (count);
}
