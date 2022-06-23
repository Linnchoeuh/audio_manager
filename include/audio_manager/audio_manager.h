/**
 ** @file audio_manager.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef			__AUDIO_MANAGER_H__
#define			__AUDIO_MANAGER_H__

#include		<fcntl.h>
#include		<stdint.h>
// #include    <unistd.h>
// #include    <stdbool.h>

// #include    "bitwise.h"

// #include    <stdio.h>

#include	"adm_global.h"
#include    "bitwise.h"
#include	"adm_libstd.h"
#include	"adm_struct.h"
#include	"adm_resample.h"
#include	"bfx.h"

// LIB AUDIO DECODER
#include "wave.h"

t_adm_audio *adm_new_adm_audio(void);

void adm_delete_adm_audio(t_adm_audio *adm_audio);

t_adm_audio *adm_load_audio(char *file_name);

int adm_get_file_format(char *file_name);

int8_t **adm_new_track(size_t byte_len,
					   size_t nb_channels);

void adm_delete_track(int8_t **track);

void adm_print_struct(t_adm_audio *adm);

#endif /*		__AUDIO_MANAGER_H__		*/