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

#include    "bitwise.h"
#include	"adm_baselib.h"
#include	"adm_struct.h"
#include	"adm_resample.h"
#include	"bfx.h"

// LIB AUDIO DECODER
#include "wave.h"

typedef enum	e_audio_format
{
	F_UNKNOWN = -1,
	F_RIFF_WAVE,
	F_fLaC,
	F_ID3,
	F_NB_TOTAL
}				t_audio_format;

#define FORMAT_ID_LEN 4
#define NB_BIT_IN_BYTE 8

#define FILE_FORMAT ({char *file_format[F_NB_TOTAL]; \
file_format[F_RIFF_WAVE] = "RIFF"; \
file_format[F_fLaC] = "fLaC"; \
file_format[F_ID3] = "ID3"; \
file_format;})

#define AUDIO_FORMAT_DECODER ({audio_format_decoder func[F_NB_TOTAL] =	\
	{wave_load_audio, NULL, NULL}; func;})

t_adm *adm_load_audio(char *file_name);

void adm_delete_audio(t_adm *adm);

int adm_get_file_format(char *file_name);

int8_t **adm_new_track(size_t byte_len,
					   size_t nb_channels);

void adm_delete_track(int8_t **track);



#endif /*		__AUDIO_MANAGER_H__		*/