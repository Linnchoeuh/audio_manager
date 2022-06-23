/**
 ** @file adm_new_adm_audio.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio_manager.h"

t_adm_audio *adm_new_adm_audio(void)
{
	t_adm_audio *adm;

	adm = malloc(sizeof(t_adm_audio));
	if (adm == NULL)
		return (NULL);
	adm_memset(&adm->data, 0, sizeof(t_audio_data));
	adm_memset(&adm->duration, 0, sizeof(t_adm_duration));
	adm->track = NULL;
	return (adm);
}