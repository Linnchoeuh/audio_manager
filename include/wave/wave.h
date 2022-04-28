/**
 ** @file wave.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef			__WAVE_H__
#define			__WAVE_H__

#include	"audio_manager.h"

#include	<fcntl.h>
#include    <unistd.h>
#include    <stdbool.h>
#include	<stdint.h>

#define HEADER_SIZE 44

#pragma			pack(2)
typedef struct		s_wave_header
{
  char file_type_bloc_id[4];
  uint32_t		file_size;
  char format_id[4];
  char id[4];
  uint32_t		bloc_size;
  uint16_t    audio_format;
  uint16_t    channels;
  uint32_t		sample_rate;
  uint32_t		byte_per_second;
  uint16_t    byte_per_bloc;
  uint16_t    bits_per_sample;
  char			data_bloc_id[4];
  uint32_t		data_size;
}			t_wave_header;
#pragma			pack()

t_adm *wave_load_audio(char *file_name);

bool wave_get_header(int fd,
					 t_wave_header *w_header);

int8_t **wave_get_track(int fd,
						t_wave_header w_header);


int8_t **wave_new_track(size_t byte_track_len,
						uint16_t channels);

void wave_print_header(t_wave_header *header);

// t_bunny_effect *load_wave_bunny_fx(char *file_name);



// void *delete_wave_struct(t_wave *wave);

// int8_t **new_track(size_t byte_track_len,
// 				   uint16_t channels);

// bool wave_resample_16bit(t_wave *wave,
// 				   		 size_t sample_rate);

// typedef void	(*t_bit_resampler)(t_wave *wave,
// 				  	   void *track,
// 				  	   void *ntrack,
// 						 double ratio);


#endif /*		__WAVE_H__		*/


