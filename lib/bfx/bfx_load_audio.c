/**
 ** @file bfx_load_audio.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "bfx.h"

t_bunny_effect *bfx_load_audio(char *file_name,
							   bool use_fast_resampler)
{
	t_adm_audio *adm;
	size_t i;
	size_t bound;
	int8_t *stock;
	t_bunny_effect *fx;

	if ((adm = adm_load_audio(file_name)) == NULL)
		return (NULL);
	if ((fx = bunny_new_effect(adm->duration.t_sec * 2)) == NULL)
	{
		adm_delete_adm_audio(adm);
		return (NULL);
	}
	adm_print_struct(adm);
	// fuse_channel_to_mono(wave);
	(use_fast_resampler) ? adm_fast_resample(adm, fx->sample_per_second) :
							adm_resample(adm, fx->sample_per_second);
	stock = (void*) fx->sample;
	i = 0;
	bound = (adm->data.track_size / adm->data.channels) - adm->data.chunk_size;
	while (i < bound)
	{
		stock[i] =
		adm->track[0][i];
		i++;
	}
	adm_delete_adm_audio(adm);
	return (fx);
}