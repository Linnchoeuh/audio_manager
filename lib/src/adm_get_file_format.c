/**
 ** @file adm_get_file_format.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio_manager.h"

static int check_format(char *format)
{
	int i;
	int len;

	i = 0;
	while (i < F_NB_TOTAL)
	{
		len = adm_strnlen(FILE_FORMAT[i], FORMAT_ID_LEN);
		if (adm_strncmp(format, FILE_FORMAT[i], len) == 0)
			return (i);
		i++;
	}
	return (F_UNKNOWN);
}

int adm_get_file_format(char *file_name)
{
	int fd;
	int bytes;
	char format[FORMAT_ID_LEN];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes = read(fd, format, FORMAT_ID_LEN);
	close(fd);
	if (bytes != FORMAT_ID_LEN)
		return (F_UNKNOWN);
	// printf("%c%c%c%c %d,%d,%d,%d\n",
	// 			format[0], format[1], format[2], format[3],
	// 			format[0], format[1], format[2], format[3]);
	return (check_format(format));
}