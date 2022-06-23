/**
 ** @file wave_print_header.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

static void print_wave_header_part1(t_wave_header *header)
{
	write(STDOUT_FILENO, "File Type Bloc ID : ", 20);
	write(STDOUT_FILENO, header->file_type_bloc_id, 4);
	write(STDOUT_FILENO, "\nFile Size         : ", 22);
	adm_print_base(header->file_size, 10);
	write(STDOUT_FILENO, "\nFormat ID         : ", 22);
	write(STDOUT_FILENO, header->format_id, 4);
	write(STDOUT_FILENO, "\nID                : ", 22);
	write(STDOUT_FILENO, header->id, 4);
}

static void print_wave_header_part2(t_wave_header *header)
{
	write(STDOUT_FILENO, "\nBloc Size         : ", 22);
	adm_print_base(header->bloc_size, 10);
	write(STDOUT_FILENO, "\nAudio Format      : ", 22);
	adm_print_base(header->audio_format, 10);
	write(STDOUT_FILENO, "\nChannels          : ", 22);
	adm_print_base(header->channels, 10);
	write(STDOUT_FILENO, "\nSample Rate       : ", 22);
	adm_print_base(header->sample_rate, 10);
	write(STDOUT_FILENO, "\nBytes Per Second  : ", 22);
	adm_print_base(header->byte_per_second, 10);
	write(STDOUT_FILENO, "\nByte Per Bloc     : ", 22);
	adm_print_base(header->byte_per_bloc, 10);
	write(STDOUT_FILENO, "\nBits Per Sample   : ", 22);
	adm_print_base(header->bits_per_sample, 10);
	write(STDOUT_FILENO, "\nData Bloc ID      : ", 22);
	write(STDOUT_FILENO, header->data_bloc_id, 4);
	write(STDOUT_FILENO, "\nData Size         : ", 22);
	adm_print_base(header->data_size, 10);
}

void print_wave_header(t_wave_header *header)
{
	print_wave_header_part1(header);
	print_wave_header_part2(header);
	write(STDERR_FILENO, "\n", 1);
}