/**
 ** @file adm_delete_track.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio_manager.h"

void adm_delete_track(int8_t **track)
{
	size_t i;

	if (track == NULL)
		return;
	i = 0;
	while (track[i] != NULL)
	{
		free(track[i]);
		i++;
	}
	free(track);
}