/**
 ** @file adm_16bit_fast_resampler.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_resample.h"

int8_t *adm_16bit_fast_resampler(t_adm *adm,
								 void *track,
								 size_t new_track_size,
								 double sample_rate_ratio)
{
	int16_t *cast;
	int16_t *resampled_data;
	size_t new_byte_len;
	size_t new_nb_chunk;
	size_t i;
	double k;

	i = 0;
	k = 0;
	new_byte_len = new_track_size / adm->data.channels;
	new_nb_chunk = new_byte_len / adm->data.chunk_size;
	resampled_data = malloc(new_byte_len);
	cast = track;
	while (i < new_nb_chunk)
	{
		resampled_data[i] = cast[(size_t) k];
		k += sample_rate_ratio;
		i++;
	}
	return ((int8_t*) resampled_data);
}