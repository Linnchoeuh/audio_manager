/**
 ** @file adm_global.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_global.h"

const audio_format_decoder AUDIO_FORMAT_DECODER[F_NB_TOTAL] = {
	load_wave_audio,
	NULL,
	NULL
};

const char *FILE_FORMAT[F_NB_TOTAL] = {
	"RIFF",
	"fLaC",
	"ID3"
};