/**
 ** @file decode_wave_audio.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

// typedef struct s_fill_wave_audio_cache
// {
// 	size_t i;
// 	size_t k;
// 	size_t j;
// 	size_t bloc;
// }				t_fill_wave_audio_cache;

// void fill_wave_audio(t_wave_header w_header,
// 					 int8_t **track,
// 					 int8_t *data,
// 					 long data_len)
// {
// 	t_fill_wave_audio_cache c;
// 	size_t byte_track_len;
// 	size_t byte_chnl_bloc;
// 	size_t bloc_track_len;

// 	byte_track_len = data_len / w_header.channels;
// 	byte_chnl_bloc = (w_header.byte_per_bloc / w_header.channels);
// 	bloc_track_len = byte_track_len / byte_chnl_bloc;

// 	c.i = 0;
// 	while (c.i < bloc_track_len)
// 	{
// 		c.k = 0;
// 		c.bloc = c.i * w_header.byte_per_bloc;
// 		while (c.k < w_header.channels)
// 		{
// 			c.j = 0;
// 			if (track[c.k] != NULL)
// 			{
// 				while (c.j < byte_chnl_bloc)
// 				{
// 					track[c.k][c.i * byte_chnl_bloc + c.j] =
// 					data[c.bloc + c.k * byte_chnl_bloc + c.j];
// 					c.j++;
// 				}
// 			}
// 			c.k++;
// 		}
// 		c.i++;
// 	}
// }

int8_t **decode_wave_audio(t_wave_data *wave_data)
{
	int8_t **track;
	int8_t *audio;
	size_t i;
	size_t k;
	size_t byte_pos;
	size_t track_size;
	size_t byte_per_sample;

	track_size = wave_data->audio_size / wave_data->header.channels;
	track = adm_new_track(track_size, wave_data->header.channels);
	if (track == NULL)
		return (NULL);
	byte_per_sample = (wave_data->header.byte_per_bloc /
					   wave_data->header.channels);
	i = 0;
	audio = wave_data->audio;
	while (i < wave_data->header.channels)
	{
		k = 0;
		while ((k * byte_per_sample) < track_size)
		{
			byte_pos = (k * wave_data->header.byte_per_bloc) +
					   (i * byte_per_sample);
			adm_memcpy(&track[i][k * byte_per_sample], &audio[byte_pos],
					   byte_per_sample);
			k++;
		}
		i++;
	}
	return (track);
}