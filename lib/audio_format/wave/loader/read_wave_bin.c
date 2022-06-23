/**
 ** @file read_wave_bin.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

t_wave_data *read_wave_bin(int fd)
{
	t_wave_data *wave;

	wave = new_wave_data();
	if (wave == NULL)
		return (NULL);
	if (!read_wave_bin_header(fd, wave))
	{
		delete_wave_data(wave);
		return (NULL);
	}
	if (!check_wave_header(&wave->header))
	{
		delete_wave_data(wave);
		return (NULL);
	}
	if (!read_wave_bin_extra_data(fd, wave))
	{
		delete_wave_data(wave);
		return (NULL);
	}
	if (!read_wave_bin_audio(fd, wave))
	{
		delete_wave_data(wave);
		return (NULL);
	}
	return (wave);
}