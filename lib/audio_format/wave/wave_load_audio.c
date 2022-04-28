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

static bool check_and_fill_wave_header(int fd,
								t_wave_header *w_header,
								char *file_name)
{
	if (!wave_get_header(fd, w_header))
	{
		wave_load_audio_puts("Unable to read the file header: ", file_name);
		return (false);
	}
	if (adm_strncmp(w_header->format_id, "WAVE", 4) != 0)
	{
		wave_load_audio_puts("Wrong format id: ", file_name);
		return (false);
	}
	return (true);
}

static void go_to_audio_data_start_byte(int fd,
									   t_wave_header w_header)
{
	char buffer[w_header.data_size - HEADER_SIZE];

	read(fd, buffer, w_header.data_size - HEADER_SIZE);
}

static void wave_set_duration(t_wave_header w_header,
							  t_adm_duration *duration)
{
	size_t byte_track_len;
	size_t byte_chnl_bloc;

	byte_track_len = (w_header.file_size - w_header.data_size) / w_header.channels;
	byte_chnl_bloc = (w_header.byte_per_bloc / w_header.channels);

	duration->t_sec =
		((double) byte_track_len / (double) byte_chnl_bloc)
							/ (double) w_header.sample_rate;
	duration->hour = (size_t) duration->t_sec / 3600;
	duration->min = (size_t) duration->t_sec / 60;
	duration->sec = (size_t) duration->t_sec % 60;
	duration->ms = duration->t_sec - (size_t) duration->t_sec;
}

t_adm *wave_load_audio(char *file_name)
{
	int fd;
	t_adm *adm;
	t_wave_header w_header;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (wave_load_audio_puts("Can't open file: ", file_name));
	if (!check_and_fill_wave_header(fd, &w_header, file_name))
		return (NULL);
	go_to_audio_data_start_byte(fd, w_header);
	wave_print_header(&w_header);
	adm = malloc(sizeof(t_adm));
	if (adm == NULL)
		return (NULL);
	adm->data.track_size = (w_header.file_size - w_header.data_size);
	adm->data.channels = w_header.channels;
	adm->data.sample_rate = w_header.sample_rate;
	adm->data.chunk_size = w_header.byte_per_bloc / w_header.channels;
	adm->track = wave_get_track(fd, w_header);
	close(fd);

	wave_set_duration(w_header, &adm->duration);
	return (adm);
}