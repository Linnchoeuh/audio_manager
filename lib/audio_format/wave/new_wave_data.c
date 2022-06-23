/**
 ** @file new_wave_data.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

t_wave_data *new_wave_data(void)
{
	t_wave_data *wave;

	wave = malloc(sizeof(t_wave_data));
	if (wave == NULL)
		return (NULL);
	adm_memset(&wave->header, 0, sizeof(t_wave_header));
	wave->extra_data = NULL;
	wave->extra_data_size = 0;
	wave->audio = NULL;
	wave->audio_size = 0;
	return (wave);
}