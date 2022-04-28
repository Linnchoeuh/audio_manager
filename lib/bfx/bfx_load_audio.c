/**
 ** @file bfx_load_audio.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "bfx.h"

// void fuse_channel_to_mono(t_wave *wave)
// {
// 	int8_t **ntrack;
// 	int16_t *single_track;
// 	int16_t *track;
// 	ssize_t average;
// 	size_t i;
// 	size_t k;

// 	ntrack = new_track(wave->byte_track_len, 1);
// 	single_track = (void*) ntrack[0];
// 	i = 0;
// 	// printf("%ld\n", wave->bit_track_len);
// 	while (i < wave->bloc_track_len)
// 	{
// 		k = 0;
// 		average = 0;
// 		while (k < wave->header.channels)
// 		{
// 			track = (void*) wave->track[k];
// 			average += track[i];
// 			k++;
// 		}
// 		single_track[i] = (double) average / (double) wave->header.channels;
// 		// (i % 10000 == 0) ? printf("%ld\n", i) : 0;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < wave->header.channels)
// 	{
// 		bunny_free(wave->track[i]);
// 		i++;
// 	}
// 	bunny_free(wave->track);
// 	wave->track = ntrack;
// 	wave->header.byte_per_bloc = (double) wave->header.byte_per_bloc
// 						  * (1 / (double) wave->header.channels);
// 	wave->header.channels = 1;
// }

t_bunny_effect *bfx_load_audio(char *file_name,
							   bool use_fast_resampler)
{
	t_adm *adm;
	size_t i;
	size_t bound;
	int8_t *stock;
	t_bunny_effect *fx;

	if ((adm = adm_load_audio(file_name)) == NULL)
		return (NULL);
	if ((fx = bunny_new_effect(adm->duration.t_sec)) == NULL)
		return (NULL);
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
	adm_delete_audio(adm);
	return (fx);
}