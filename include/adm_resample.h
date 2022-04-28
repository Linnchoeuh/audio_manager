/**
 ** @file adm_resample.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef			__AUDIO_MANAGER_RESAMPLE_H__
#define			__AUDIO_MANAGER_RESAMPLE_H__

#include	"audio_manager.h"

typedef int8_t *(*f_resampler_func)(t_adm *adm,
									void *track,
									size_t new_track_size,
									double sample_rate_ratio);

bool adm_resample(t_adm *adm,
				  size_t new_sample_rate);

bool adm_fast_resample(t_adm *adm,
					   size_t new_sample_rate);

int8_t *adm_16bit_resampler(t_adm *adm,
							void *track,
							size_t new_track_size,
							double sample_rate_ratio);

int8_t *adm_16bit_fast_resampler(t_adm *adm,
								 void *track,
								 size_t new_track_size,
								 double sample_rate_ratio);

#endif