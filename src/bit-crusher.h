/*

Bit Crusher DSP module

License: GPLv3 (https://github.com/unclechu/lv2-ladspa-bit-crusher/blob/master/LICENSE)
Author: Viacheslav Lotsmanov

*/

#ifndef BIT_CRUSHER_H
#define BIT_CRUSHER_H

#define BIT_CRUSHER_MAX_BIT_TYPE int32_t
#define BIT_CRUSHER_MAX_DOWNSAMPLE_TYPE uint8_t

#include <inttypes.h>

typedef struct {
	BIT_CRUSHER_MAX_DOWNSAMPLE_TYPE sample_counter;
	float last_sample;
} Bit_crusher_state;

void bit_crusher_init_state(Bit_crusher_state *state);

void bit_crusher_process(
	Bit_crusher_state *state,

	uint32_t n_samples,

	// audio ports
	const float *input,
	float *output,

	// knobs
	const float drive,
	const uint8_t bit_depth,
	const uint8_t downsampling,
	const float dry,
	const float wet,
	const uint8_t invert_wet_phase);

#endif
