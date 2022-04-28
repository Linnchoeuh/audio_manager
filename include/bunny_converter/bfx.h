/**
 ** @file bfx.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef			__BFX_H__
#define			__BFX_H__

#include <lapin.h>
#include "audio_manager.h"

t_bunny_effect *bfx_load_audio(char *file_name,
							   bool use_fast_resampler);

#endif