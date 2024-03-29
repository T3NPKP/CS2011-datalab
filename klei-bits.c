/* 
 * CS:APP Data Lab 
 * 
 * Kepei Lei klei
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
  // 4 - 4
  int constant = 0xAA; //10101010 in binary
  int result = constant;
  //2
  result = result + (result << 8); //1010101010101010
  //2+2
  result = result + (result << 16); //final results
  return result;
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
  // 4 - 5
  // Only Tmin + Tmin and 0 + 0 = 0
  return !((x + x) | !x);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // 7 - 7
  //1
  int sameOnes = x & y;
  //1+3
  int sameZeros = ~x & ~y;
  //1+3+3
  return (~sameOnes & ~sameZeros);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // 7 - 7
  //1
  int xIsZero = !x; //0 if x is not zero, 1 if x is zero
  //1+2
  int mask = ~xIsZero + 1; // 0xffffffff if x is zero, 0x0 if x is not zero
  //1+2+4
  return (y & ~mask) | (z & mask);
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
  // 15 - 46

  //Holders
  int temp = x;

  /* Make the digits right of the most significant bit all 1
   * eg: 96 -> 0x7f
   *     Tmin -> 0xffffffff */
  //2 * 5
  temp = temp | temp >> 1;
  temp = temp | temp >> 2;
  temp = temp | temp >> 4;
  temp = temp | temp >> 8;
  temp = temp | temp >> 16;

  // When it's negative, (~temp >> 1) always gives 0x0, to counter that, use ^ (1 << 31)
  //2 * 5 + 5
  return temp & ((~temp >> 1) ^ (1 << 31));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  // 7 - 7
  //6
  //             isNegative   mask for the right n numbers
  int temp = x + ((x >> 31) & ~(~0 << n));
  //6 + 1
  return temp >> n;
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  // 2 - 3
  return !(x >> 31);
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x7fffffff (saturate to TMax)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
  // 9 - 10
  // 2
  int twice = x << 1;
  int tMin = 1 << 31;
  // 2 + 2
  int isOverflow = (twice ^ x) >> 31; //0x0 if not overflow, 0xffffffff if overflow
  // 2 + 2 + 5
  /* The idea is that if it overflows, this algorithm generate 0x7fffffff. If it underflows, it generates 0x80000000
   * To do that, we take a look at the sign. If twice is positive (aka possible underflow), we do not flip the bits
   * If twice is negative (aka possible overflow) we flip the bits. In both case, we need to flip the sign bit
   *                            flip the digits if it overflows, do not if underflows
   *                            xor tMin to get the correct sign (overflow makes sign bit 0, underflow makes it 1) */
  return twice ^ (isOverflow & (twice ^ (twice >> 31) ^ tMin));
          // Gosh I went all the way around to save two operations.......
        // Here's the original one just for fun (it is way easier to understand)
            // 1
        //  int twice = x << 1;
            // 1 + 1
        //  int sign = x >> 31; //0x0 if positive, 0xffffffff if negative
            // 1 + 1 + 4
        //  int maxOrMin = ((~0) << 31) + ~sign;
            // 1 + 1 + 4 + 2
        //  int flipped = (twice ^ x) >> 31; //0x0 if not overflow, 0xffffffff if overflow
            // 1 + 1 + 4 + 2 + 4
        //  return (twice & (~flipped)) | (flipped & maxOrMin);
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  // 8 - 12
  // This one is really abstract so I will just offer the truth table:
  // 2
  int minus = ~x + y;  //y - x - 1 >= 0
  // 2 + 1
  int diffSign = x ^ y;  //sign bit == 1 if it's different sign
  /*                  differentSign == 1 and minus ^ y == 1
   *                  it's either an underflow (minus >= 0, which means x >= y) or x < y
   *                      otherwise, it's either an overflow (minus < 0, which means x < y) or x >= y */
  // 2 + 1 + 5
  return !((minus ^ ((minus ^ y) & diffSign)) >> 31);
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // 7 - 7
    /*  The idea of this method is to use 0x39 - x and x - 0x30
          both of them have to be positive to be AsciiDigit
     */
    // 2
    int up = x + (~ 0x2f);  //x - 0x30
    // 2 + 2
    int low = 0x3a + ( ~ x); //0x39 - x
    // 2 + 2 + 2
    x = (up | low) >> 31;  //Set up the sign
    // 2 + 2 + 2 + 1
    return !x;
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x) {
  // 11
  // 4
  int fourths = x >> 2;
  int remainder = x & 3;
  int negative = x >> 31 & 3;

  // 4 + 7
                                      //remainder * 3              + 3 if negative
  return fourths + (fourths << 1) + ((remainder + (remainder << 1) + negative) >> 2);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  //floor log 2 is the same as find the position of the left most bit (so very similar to greatest bit pos
  int sixteen, eight, four, two, one;
  int temp = x;
  // The sixteen, eight, four, two, and one are place holders, will explain later
  sixteen = (!!(temp >> 16)) << 4; //To check if the number needs at least 16 bits
  temp = temp >> sixteen; //If it needs 16 bits, right shift 16 bits to take them out. Else don't move
  eight = (!!(temp >> 8)) << 3; //Same as before, instead this time it is 8 bits and so on
  temp = temp >> eight;
  four = (!!(temp >> 4)) << 2;
  temp = temp >> four;
  two = (!!(temp >> 2)) << 1;
  temp = temp >> two;
  one = (!!(temp >> 1));
  temp = temp >> one;
  return (sixteen + eight + four + two + one);
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  // 3
  // 2
  unsigned check = (uf & 0x7fffffff) > 0x7f800000; //Check if uf is NaN
  if (check) {
    return uf;
  }
  //2 + 1
  return uf ^ 0x80000000;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  // 21
  // 1
  int frac, round;
  int sign = x & 0x80000000;
  int exp = 158; // 158 == 127 + 31
  int tmp;
  // 1 + 5
  //x == 0, return 0
  if (!x) return 0;
  //x == negative max, simply return -1 * (2^31)
  if (x == 0x80000000) return (0x80000000 ^ (exp << 23));
  //get the absolute value of x
  if (sign) x = -x;
  tmp = x;
  // 1 + 5 + 4
  //find out the exp expected (every zero on the left means one less exp needed
  while (!(tmp & 0x80000000)) {
    tmp <<= 1;
    exp -= 1;
  }
  // 1 + 5 + 4 + 7
  frac = (tmp & 0x7fffffff) >> 8; //Since float has a 1 by default, we can take out the first bit and shift 8 bits to the right to take out the insignificant bits (31 - 23 = 8)
  round = (tmp & 0x80 && ((tmp & 0x7F) || frac & 1));
  // 1 + 5 + 4 + 7 + 4
  return (sign + (exp << 23) + frac + round);
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {

  //uf == 0, return itself
  if((uf << 1) == 0) return uf;
  //uf == NaN, return itself
  if(((uf>>23) & 0xff) == 0xff) return uf;
  //When it's a small value, but not quite zero
  if(((uf>>23) & 0xff) == 0x00) {
    return (uf & 0x80000000) | (uf<<1);
  }
  //Otherwise, Add 1 to exp
  return uf + (1<<23);
}
