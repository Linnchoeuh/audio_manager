/**
 ** @file delete_adm_audio.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio_manager.h"

void adm_delete_adm_audio(t_adm_audio *adm_audio)
{
	if (adm_audio == NULL)
		return;
	if (adm_audio->track != NULL)
		adm_delete_track(adm_audio->track);
	free(adm_audio);
}