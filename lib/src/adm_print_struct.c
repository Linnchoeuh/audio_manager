/**
 ** @file adm_print_struct.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "audio_manager.h"

void adm_print_struct_data(t_audio_data data)
{
	write(STDOUT_FILENO, "-- DATA --", 10);
	write(STDOUT_FILENO, "\n\tChunk Size : ", 15);
	adm_print_base(data.chunk_size, 10);
	write(STDOUT_FILENO, " Byte(s)", 8);
	write(STDOUT_FILENO, "\n\tChannels : ", 13);
	adm_print_base(data.channels, 10);
	write(STDOUT_FILENO, "\n\tSample Rate : ", 16);
	adm_print_base(data.sample_rate, 10);
	write(STDOUT_FILENO, "\n\tTrack Size : ", 15);
	adm_print_base(data.track_size, 10);
	write(STDOUT_FILENO, " Byte(s)", 8);
	write(STDOUT_FILENO, "\n", 1);
}

void adm_print_struct_duration(t_adm_duration duration)
{
	write(STDOUT_FILENO, "Duration : ", 11);
	adm_print_base(duration.hour, 10);
	write(STDOUT_FILENO, " h ", 3);
	adm_print_base(duration.min, 10);
	write(STDOUT_FILENO, " m ", 3);
	adm_print_base(duration.sec, 10);
	write(STDOUT_FILENO, " s | Total : ", 13);
	adm_print_base(duration.t_sec, 10);
	write(STDOUT_FILENO, " seconds\n", 9);
}

void adm_print_struct(t_adm_audio *adm)
{
	adm_print_struct_data(adm->data);
	adm_print_struct_duration(adm->duration);
	write(STDOUT_FILENO, "\n", 1);
}