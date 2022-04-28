/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89
**
** - delete_wave_struct.c -
**
** This function free a t_wave struct
** the paramater will be set at NULL and the function returns NULL
** *****************************************************************************
*/

#include "wave.h"

void *delete_wave_struct(t_wave *wave)
{
	size_t i;

	if (wave == NULL)
		return (NULL);
	if (wave->track != NULL)
	{
		i = 0;
		while (i < wave->header.channels)
		{
			(wave->track[i] != NULL) ? bunny_free(wave->track[i]) : 0;
			i++;
		}
		bunny_free(wave->track);
	}
	bunny_free(wave);
	wave = NULL;
	return (NULL);
}