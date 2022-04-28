/**
 ** @file adm_new_track.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio_manager.h"

int8_t **adm_new_track(size_t byte_len,
					   size_t nb_channels)
{
	size_t i;
	int8_t **new_track;

	new_track = malloc(sizeof(int8_t*) * (nb_channels + 1));
	if (new_track == NULL)
		return (NULL);
	i = 0;
	while (i < nb_channels)
	{
		new_track[i] = malloc(byte_len);
		if (new_track[i] == NULL)
		{
			adm_delete_track(new_track);
			return (NULL);
		}
		i++;
	}
	new_track[i] = NULL;
	return (new_track);
}