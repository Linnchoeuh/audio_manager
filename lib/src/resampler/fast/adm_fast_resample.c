/**
 ** @file adm_fast_resample.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "adm_resample.h"

bool adm_fast_resample(t_adm_audio *adm,
					   size_t new_sample_rate)
{
	void *tmp_addr;
	size_t i;
	size_t new_track_size;
	double sample_rate_ratio;
	f_resampler_func resampler;

	if (adm->data.sample_rate == new_sample_rate)
		return (true);
	sample_rate_ratio =
		(double) adm->data.sample_rate / (double) new_sample_rate;
	new_track_size =
		adm->data.track_size / sample_rate_ratio;
	i = 0;
	resampler = adm_16bit_fast_resampler;
	while (adm->track[i] != NULL)
	{
		tmp_addr = adm->track[i];
		adm->track[i] = resampler(adm, adm->track[i],
								  new_track_size, sample_rate_ratio);
		if (adm->track[i] == NULL)
			return (false);
		free(tmp_addr);
		i++;
	}
	adm->data.sample_rate = new_sample_rate;
	adm->data.track_size = new_track_size;
	return (true);
}