/**
 ** @file check_wave_header.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "wave.h"

bool check_wave_header(t_wave_header *w_header)
{
	if (adm_strncmp(w_header->file_type_bloc_id, "RIFF", 4) != 0)
		return (false);
	if (adm_strncmp(w_header->format_id, "WAVE", 4) != 0)
		return (false);
	return (true);
}