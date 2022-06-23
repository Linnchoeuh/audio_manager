/**
 ** @file adm_load_audio.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio_manager.h"

static void *adm_file_open_error(char *file_name)
{
	write(STDOUT_FILENO, "File not found : ", 17);
	adm_puts(file_name);
	write(STDOUT_FILENO, "\n", 1);
	return (NULL);
}

t_adm_audio *adm_load_audio(char *file_name)
{
	int fd;
	int format_id;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (adm_file_open_error(file_name));
	format_id = adm_get_file_format(file_name);
	if (format_id == F_UNKNOWN)
	{
		adm_puts(file_name);
		write(STDOUT_FILENO, " : Unsupported file format.\n", 28);
		return (NULL);
	}
	if (AUDIO_FORMAT_DECODER[format_id] == NULL)
		return (NULL);
	return (AUDIO_FORMAT_DECODER[format_id](file_name));
}