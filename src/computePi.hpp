#pragma once

// ------------------------------------------------------------------
//
// Adapted From: http://stackoverflow.com/questions/5905822/function-to-find-the-nth-digit-of-pi
// Other references:
//		http://bellard.org/pi/pi_n2/pi_n2.html
//		https://web.archive.org/web/20150627225748/http://en.literateprograms.org/Pi_with_the_BBP_formula_%28Python%29
//
// ------------------------------------------------------------------
/*
* Computation of the n'th decimal digit of \pi with very little memory.
* Written by Fabrice Bellard on January 8, 1997.
*
* We use a slightly modified version of the method described by Simon
* Plouffe in "On the Computation of the n'th decimal digit of various
* transcendental numbers" (November 1996). We have modified the algorithm
* to get a running time of O(n^2) instead of O(n^3log(n)^3).
*
* This program uses mostly integer arithmetic. It may be slow on some
* hardwares where integer multiplications and divisons must be done
* by software. We have supposed that 'int' has a size of 32 bits. If
* your compiler supports 'long long' integers of 64 bits, you may use
* the integer version of 'mul_mod' (see HAS_LONG_LONG).
*/

/* uncomment the following line to use 'long long' integers */
/* #define HAS_LONG_LONG */

//#ifdef HAS_LONG_LONG
#define mul_mod(a,b,m) (( (long long) (a) * (long long) (b) ) % (m))
//#else
//	#define mul_mod(a,b,m) std::fmod( (double) a * (double) b, m)
//#endif

unsigned int computePiDigit(int n);
unsigned long long piDigitHex(unsigned long long n);