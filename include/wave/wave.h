/**
 ** @file wave.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef __WAVE_H__
#define __WAVE_H__

#include "audio_manager.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>

#define HEADER_SIZE 44

typedef struct s_wave_header
{
	char file_type_bloc_id[4];
	uint32_t file_size;
	char format_id[4];
	char id[4];
	uint32_t bloc_size;
	uint16_t audio_format;
	uint16_t channels;
	uint32_t sample_rate;
	uint32_t byte_per_second;
	uint16_t byte_per_bloc;
	uint16_t bits_per_sample;
	char data_bloc_id[4];
	uint32_t data_size;
} t_wave_header;

typedef struct s_wave_data
{
	t_wave_header header; // The data of the wave header you opened
	void *extra_data;
	size_t extra_data_size; // The byte size of the extra data
	void *audio;
	size_t audio_size; // The byte size of the audio
} t_wave_data;

t_wave_data *new_wave_data(void);

void delete_wave_data(t_wave_data *wave_data);

bool check_wave_header(t_wave_header *w_header);

t_adm_audio *load_wave_audio(char *file_name);

t_wave_data *read_wave_bin(int fd);

bool read_wave_bin_header(int fd,
						  t_wave_data *wave_data);

bool read_wave_bin_extra_data(int fd,
							  t_wave_data *wave_data);

bool read_wave_bin_audio(int fd,
						 t_wave_data *wave_data);

int8_t **decode_wave_audio(t_wave_data *wave_data);

/**
 ** @brief Print in STDOUT a wave header.
 **
 ** @param header A filled data (t_wave_header).
 **/
void print_wave_header(t_wave_header *header);

void print_wave_extra_data(t_wave_data *wave_data);

#endif /*		__WAVE_H__		*/
