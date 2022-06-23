/**
 ** @file adm_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef	__AUDIO_MANAGER_STRUCT_H__
#define	__AUDIO_MANAGER_STRUCT_H__

#include "unistd.h"
#include "stdint.h"

#define FORMAT_ID_LEN 4
#define NB_BIT_IN_BYTE 8

typedef enum	e_audio_format
{
	F_UNKNOWN = -1,
	F_RIFF_WAVE,
	F_fLaC,
	F_ID3,
	F_NB_TOTAL
}				t_audio_format;

typedef struct	s_adm_duration
{
  int hour;
  int min;
  int sec;
  double ms;
  double t_sec;
}               t_adm_duration;

typedef struct	s_audio_data
{
	size_t chunk_size;
	size_t channels;
  	size_t sample_rate;
	size_t track_size;
}				t_audio_data;

typedef struct	s_adm_audio
{
	t_audio_data data;
	t_adm_duration duration;
	int8_t **track;
}				t_adm_audio;

typedef t_adm_audio *(*audio_format_decoder)(char *file_name);

#endif