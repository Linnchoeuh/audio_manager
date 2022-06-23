/**
 ** @file read_wave_bin_audio.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

bool read_wave_bin_audio(int fd,
						 t_wave_data *wave_data)
{
	ssize_t size;

	size = wave_data->header.file_size - wave_data->header.data_size;

	wave_data->audio = malloc(size);
	if (read(fd, wave_data->audio, size) != size)
		return (false);
	wave_data->audio_size = size;
	return (true);
}