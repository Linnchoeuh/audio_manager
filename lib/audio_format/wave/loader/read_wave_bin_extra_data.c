/**
 ** @file read_wave_bin_extra_data.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

bool read_wave_bin_extra_data(int fd,
							  t_wave_data *wave_data)
{
	ssize_t size;

	size = wave_data->header.data_size - HEADER_SIZE;
	wave_data->extra_data = malloc(size);
	if (wave_data->extra_data == NULL)
		return (false);
	if (read(fd, wave_data->extra_data, size) != size)
		return(false);
	wave_data->extra_data_size = size;
	return (true);
}