/**
 ** @file read_wave_bin_header.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

#include <stdio.h>

bool read_wave_bin_header(int fd,
						  t_wave_data *wave_data)
{

	if (read(fd, &wave_data->header, HEADER_SIZE) != HEADER_SIZE)
		return (false);
	return (true);
}