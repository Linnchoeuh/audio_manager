/**
 ** @file wave_get_tracks.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

typedef struct s_fill_wave_audio_cache
{
	size_t i;
	size_t k;
	size_t j;
	size_t bloc;
}				t_fill_wave_audio_cache;

void fill_wave_audio(t_wave_header w_header,
					 int8_t **track,
					 int8_t *data,
					 long data_len)
{
	t_fill_wave_audio_cache c;
	size_t byte_track_len;
	size_t byte_chnl_bloc;
	size_t bloc_track_len;

	byte_track_len = data_len / w_header.channels;
	byte_chnl_bloc = (w_header.byte_per_bloc / w_header.channels);
	bloc_track_len = byte_track_len / byte_chnl_bloc;

	c.i = 0;
	while (c.i < bloc_track_len)
	{
		c.k = 0;
		c.bloc = c.i * w_header.byte_per_bloc;
		while (c.k < w_header.channels)
		{
			c.j = 0;
			if (track[c.k] != NULL)
			{
				while (c.j < byte_chnl_bloc)
				{
					track[c.k][c.i * byte_chnl_bloc + c.j] =
					data[c.bloc + c.k * byte_chnl_bloc + c.j];
					c.j++;
				}
			}
			c.k++;
		}
		c.i++;
	}
}

int8_t **wave_get_track(int fd,
					   t_wave_header w_header)
{
	long data_len;
	int8_t *data;
	int8_t **track;

	data_len = w_header.file_size - w_header.data_size;

	data = malloc(data_len);
	if (read(fd, data, data_len) != data_len)
		return (NULL);
	track = adm_new_track(data_len / w_header.channels, w_header.channels);
	if (track == NULL)
		return (NULL);
	fill_wave_audio(w_header, track, data, data_len);
	free(data);
	return (track);
}