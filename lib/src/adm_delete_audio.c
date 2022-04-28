/**
 ** @file adm_delete_audio.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio_manager.h"

void adm_delete_audio(t_adm *adm)
{
	adm_delete_track(adm->track);
	free(adm);
}