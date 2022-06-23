/**
 ** @file print_wave_extra_data.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

void print_wave_extra_data(t_wave_data *wave_data)
{
	write(STDOUT_FILENO, "\nExtra Data         : ", 22);
	write(STDOUT_FILENO, wave_data->extra_data, wave_data->extra_data_size);
	write(STDOUT_FILENO, "\n", 1);
}