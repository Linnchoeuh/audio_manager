/**
 ** @file adm_struct.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef			__AUDIO_MANAGER_STRUCT_H__
#define			__AUDIO_MANAGER_STRUCT_H__

#include	"audio_manager.h"

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

typedef struct	s_adm
{
	t_audio_data data;
	t_adm_duration duration;
	int8_t **track;
}				t_adm;

typedef t_adm *(*audio_format_decoder)(char *file_name);

#endif