/**
 ** @file adm_resample.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef			__AUDIO_MANAGER_RESAMPLE_H__
#define			__AUDIO_MANAGER_RESAMPLE_H__

#include <stdlib.h>
#include <stdbool.h>

#include	"adm_struct.h"

typedef int8_t *(*f_resampler_func)(t_adm_audio *adm,
									void *track,
									size_t new_track_size,
									double sample_rate_ratio);

/**
 ** @brief Resample an audio to
 ** the given sample rate in the parameter.
 ** Slower than [adm_fast_resample] but better result.
 **
 ** @param adm The audio you want to resample.
 ** @param new_sample_rate The new sample rate.
 ** @return true on success and
 **	false on failure.
 **/
bool adm_resample(t_adm_audio *adm,
				  size_t new_sample_rate);


/**
 ** @brief Resample an audio to
 ** the given sample rate in the parameter.
 ** Faster than [adm_resample] but
 ** the audio is sharper at the hearing.
 **
 ** @param adm The audio you want to resample.
 ** @param new_sample_rate The new sample rate.
 ** @return true on success and
 **	false on failure.
 **/
bool adm_fast_resample(t_adm_audio *adm,
					   size_t new_sample_rate);

int8_t *adm_16bit_resampler(t_adm_audio *adm,
							void *track,
							size_t new_track_size,
							double sample_rate_ratio);

int8_t *adm_16bit_fast_resampler(t_adm_audio *adm,
								 void *track,
								 size_t new_track_size,
					  			 double sample_rate_ratio);

#endif