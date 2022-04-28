/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@student-station>
** Ecole 89
**
** - change_channel_number.c -
**
** change the amount of audio channel by the given one
** *****************************************************************************
*/

#include "wave.h"

bool change_channel_number(t_wave *w,
						   uint16_t new_nb_of_channels)
{
	if (new_nb_of_channels == w->header.channels)
		return (true);
	if (new_nb_of_channels > w->header.channels)
		return (true);
	return (true);
}