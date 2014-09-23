#include "types.h"

#ifndef HAVE_ICORE
x10_boolean icore_is_on_icore(void)
{
	return false;
}

void icore_init_fmm(void)
{
}

void icore_init_sift(void)
{
}

void icore_fmm(float *in0, float *in1, float *res)
{
	X10_UNUSED(in0);
	X10_UNUSED(in1);
	X10_UNUSED(res);
}

float icore_sift(float *in0, float *in1)
{
	X10_UNUSED(in0);
	X10_UNUSED(in1);
	return 0.0f;
}
#else
#include "icore.h"
#include "fmm_HW_02.h"
#include "sift_HW_02.h"

x10_boolean icore_is_on_icore(void)
{
	unsigned asr17 = 0;
	__asm__ __volatile__("rd %%asr17, %[_asr17]\n"
	                     : [_asr17] "=r" (asr17));
	return asr17 & (1 << 25);
}

void icore_init_fmm(void)
{
	icore_load_si_micro_program(fmm_HW_02_num_steps, fmm_HW_02_words_per_vlcw, WORDS_IN_VLCW_LINE, 0, fmm_HW_02_vlcws[0]);
	icore_si_state_update(0, SI_FMM, 1, 0, fmm_HW_02_num_steps);
}

void icore_init_sift(void)
{
	icore_load_si_micro_program(sift_HW_02_num_steps, sift_HW_02_words_per_vlcw, WORDS_IN_VLCW_LINE, 0, sift_HW_02_vlcws[0]);
	icore_si_state_update(0, SI_SIFT, 1, 0, sift_HW_02_num_steps);
}

#define MATRIX_SIZE (32 * 32)

void icore_fmm(float *in0, float *in1, float *res)
{
	float *matrix0    = (float *)(ICORE_TLM_START + 0x2000);
	float *matrix1    = (float *)(ICORE_TLM_START + 0x4000);
	float *dst_matrix = (float *)(ICORE_TLM_START + 0x6000);
	const unsigned span_skip_stride = 0x01080000;

	memcpy(matrix0, in0, MATRIX_SIZE * sizeof(float));
	memcpy(matrix1, in1, MATRIX_SIZE * sizeof(float));
	memset(dst_matrix, 0, MATRIX_SIZE * sizeof(float));

	__asm__ __volatile__("sigrp 0x0, %g0, %g0");

	unsigned x = 0;
	for (unsigned i = 0; i < 32; ++i) {
		float *m0 = &matrix0[i * 32];
		for (unsigned j = 0; j < 8; ++j) {
			float *m1  = &matrix1[j * 4];
			float *dst = &dst_matrix[x];
			x += 4;

			__asm__ __volatile__("fmm %[_src_matrix0], %[_src_matrix1], %[_res_matrix], %[_agu]"
				:
				: [_agu] "r" (span_skip_stride),
				  [_src_matrix0] "r" (m0),
				  [_src_matrix1] "r" (m1),
				  [_res_matrix] "r" (dst)
				);
		}
	}

	memcpy(res, dst_matrix, MATRIX_SIZE * sizeof(float));
}

#define VECTOR_SIZE 128

float icore_sift(float *in0, float *in1)
{
	float* vector0 = (float *)(ICORE_TLM_START + 0x2000);
	float* vector1 = (float *)(ICORE_TLM_START + 0x4000);
	float* result  = (float *)(ICORE_TLM_START + 0x6000);
	const unsigned span_skip_stride = 0x00100010;

	memcpy(vector0, in0, VECTOR_SIZE * sizeof(float));
	memcpy(vector1, in1, VECTOR_SIZE * sizeof(float));
	memset(result, 0, 4 * sizeof(float));

	__asm__ __volatile__("sigrp 0x0, %g0, %g0");
	__asm__ __volatile__("sift %[_src_vector0], %[_src_vector1], %[_res], %[_agu]"
		:
		: [_agu] "r" (span_skip_stride),
		  [_src_vector0] "r" (vector0),
		  [_src_vector1] "r" (vector1),
		  [_res] "r" (result)
		);

	return *result;
}

#endif
