/**
*** Copyright (C) 1985-2007 Intel Corporation.  All rights reserved.
***
*** The information and source code contained herein is the exclusive
*** property of Intel Corporation and may not be disclosed, examined
*** or reproduced in whole or in part without explicit written authorization
*** from the company.
***
**/

/*
 * nmmintrin.h
 *
 * Principal header file for Intel(R) Core(TM) 2 Duo processor
 * SSE4.2 intrinsics.
 */

#pragma once
#ifndef __midl
#ifndef _INCLUDED_NMM
#define _INCLUDED_NMM

#if defined(_M_CEE_PURE)
        #error ERROR: EMM intrinsics not supported in the pure mode!
#else

#include <smmintrin.h>


#if __cplusplus
extern "C" {
#endif

/*
 * These defines are used to determine the kind of units to be compared
 */
#define SIDD_UBYTE_OPS                0x00
#define SIDD_UWORD_OPS                0x01
#define SIDD_SBYTE_OPS                0x02
#define SIDD_SWORD_OPS                0x03


/*
 * These defines are used to determine the comparison operation
 */
#define SIDD_CMP_EQUAL_ANY            0x00
#define SIDD_CMP_RANGES               0x04
#define SIDD_CMP_EQUAL_EACH           0x08
#define SIDD_CMP_EQUAL_ORDERED        0x0C


/*
 * These defines are used to determine the polarity
 */
#define SIDD_POSITIVE_POLARITY        0x00
#define SIDD_NEGATIVE_POLARITY        0x10
#define SIDD_MASKED_POSITIVE_POLARITY 0x20
#define SIDD_MASKED_NEGATIVE_POLARITY 0x30


/*
 * These defines are used in _mm_cmpXstri()
 */
#define SIDD_LEAST_SIGNIFICANT        0x00
#define SIDD_MOST_SIGNIFICANT         0x40

/*
 * These defines are used _mm_cmpXstrm()
 */
#define SIDD_BIT_MASK                 0x00
#define SIDD_UNIT_MASK                0x40


/*
 * Intrinsics for text/string processing.
 */
 
    extern __m128i _mm_cmpistrm (__m128i a, __m128i b, const int mode);
    extern int     _mm_cmpistri (__m128i a, __m128i b, const int mode);

    extern __m128i _mm_cmpestrm (__m128i a, int la, __m128i b, int lb, const int mode);
    extern int     _mm_cmpestri (__m128i a, int la, __m128i b, int lb, const int mode);

/*
 * Intrinsics for text/string processing and reading values of EFlags.
 */

    extern int     _mm_cmpistrz (__m128i a, __m128i b, const int mode);
    extern int     _mm_cmpistrc (__m128i a, __m128i b, const int mode);
    extern int     _mm_cmpistrs (__m128i a, __m128i b, const int mode);
    extern int     _mm_cmpistro (__m128i a, __m128i b, const int mode);
    extern int     _mm_cmpistra (__m128i a, __m128i b, const int mode);

    extern int     _mm_cmpestrz (__m128i a, int la, __m128i b, int lb, const int mode);
    extern int     _mm_cmpestrc (__m128i a, int la, __m128i b, int lb, const int mode);
    extern int     _mm_cmpestrs (__m128i a, int la, __m128i b, int lb, const int mode);
    extern int     _mm_cmpestro (__m128i a, int la, __m128i b, int lb, const int mode);
    extern int     _mm_cmpestra (__m128i a, int la, __m128i b, int lb, const int mode);

/*
 * Packed integer 64-bit comparison, zeroing or filling with ones
 * corresponding parts of result
 */

    extern __m128i _mm_cmpgt_epi64(__m128i val1, __m128i val2);

/*
 * Calculate a number of bits set to 1
 */

    extern int _mm_popcnt_u32(unsigned int v);

#if defined(_M_X64)
    extern __int64 _mm_popcnt_u64(unsigned __int64 v);
#endif

/*
 * Accumulate CRC32 (polynomial 0x11EDC6F41) value
 */

    extern unsigned int _mm_crc32_u8 (unsigned int crc, unsigned char v);
    extern unsigned int _mm_crc32_u16(unsigned int crc, unsigned short v);
    extern unsigned int _mm_crc32_u32(unsigned int crc, unsigned int v);

#if defined(_M_X64)
    extern unsigned __int64 _mm_crc32_u64(unsigned __int64 crc, unsigned __int64 v);
#endif

#if defined __cplusplus
}; /* End "C" */
#endif /* __cplusplus */

#endif /* defined(_M_CEE_PURE) */

#endif
#endif /* _INCLUDED_NMM */
