/**
 ** @file delete_wave_data.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

void delete_wave_data(t_wave_data *wave_data)
{
	if (wave_data == NULL)
		return;
	if (wave_data->extra_data != NULL)
		free(wave_data->extra_data);
	if (wave_data->audio != NULL)
		free(wave_data->audio);
	free(wave_data);
}