/**
 ** @file adm_16bit_resampler.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_resample.h"

int8_t *adm_16bit_resampler(t_adm *adm,
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
	double k_plus;
	double coef;
	double coef_denominator;
	ssize_t num_interval;

	i = 0;
	k = 0;
	new_byte_len = new_track_size / adm->data.channels;
	new_nb_chunk = new_byte_len / adm->data.chunk_size;
	resampled_data = malloc(new_byte_len);
	cast = track;
	while (i < new_nb_chunk)
	{
		k_plus = k + sample_rate_ratio;
		num_interval = cast[(size_t) k_plus] - cast[(size_t) k];
		coef_denominator = ((size_t) k_plus) - ((size_t) k) + 1;
		coef = (k_plus - ((size_t) k)) / coef_denominator;
		resampled_data[i] = cast[(size_t) k] + (num_interval * coef);
		k += sample_rate_ratio;
		i++;
	}
	return ((int8_t*) resampled_data);
}