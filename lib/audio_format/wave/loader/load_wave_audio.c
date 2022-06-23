/**
 ** @file wave_load_audio.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

static void *wave_load_audio_puts(char *message,
								  char *file_name)
{
	write(STDERR_FILENO, "WAVE LOADER: ", 14);
	adm_fdputs(STDERR_FILENO, message);
	adm_fdputs(STDERR_FILENO, file_name);
	write(STDERR_FILENO, "\n", 1);
	return (NULL);
}

static void wave_set_audio_data(const t_wave_header *w_header,
								t_audio_data *data)
{
	data->track_size = (w_header->file_size - w_header->data_size);
	data->channels = w_header->channels;
	data->sample_rate = w_header->sample_rate;
	data->chunk_size = w_header->byte_per_bloc / w_header->channels;
}

static void wave_set_duration_data(const t_wave_header *w_header,
								   t_adm_duration *duration)
{
	size_t byte_track_len;
	size_t byte_chnl_bloc;

	byte_track_len = (w_header->file_size - w_header->data_size) / w_header->channels;
	byte_chnl_bloc = (w_header->byte_per_bloc / w_header->channels);

	duration->t_sec =
		((double)byte_track_len / (double)byte_chnl_bloc) / (double)w_header->sample_rate;
	duration->hour = (size_t)duration->t_sec / 3600;
	duration->min = (size_t)duration->t_sec / 60;
	duration->sec = (size_t)duration->t_sec % 60;
	duration->ms = duration->t_sec - (size_t)duration->t_sec;
}

t_adm_audio *load_wave_audio(char *file_name)
{
	int fd;
	t_adm_audio *adm;
	t_wave_data *wave;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (wave_load_audio_puts("Can't open file: ", file_name));
	wave = read_wave_bin(fd);
	close(fd);
	if (wave == NULL)
		return (wave_load_audio_puts("File corrupted: ", file_name));
	adm = adm_new_adm_audio();
	if (adm == NULL)
		return (NULL);
	wave_set_audio_data(&wave->header, &adm->data);
	wave_set_duration_data(&wave->header, &adm->duration);
	adm->track = decode_wave_audio(wave);
	delete_wave_data(wave);
	return (adm);
}