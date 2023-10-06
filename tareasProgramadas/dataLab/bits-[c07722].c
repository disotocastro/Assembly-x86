/* 
 * CS:APP Data Lab 
 * 
 * <Juan Diego Soto Castro, juan.sotocastro>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
/* Copyright (C) 1991-2023 Free Software Foundation, Inc.
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
   <https://www.gnu.org/licenses/>.  */
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

//1
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */

int bitAnd(int x, int y) {
	/*
	* De Morgan's law:
	* ~(P^Q) == (~Pv~Q)
	* 
	*  (P^Q) == ~(~Pv~Q) 
	*/ 
   
	return ~(~x | ~y);
}

/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
*/

int isZero(int x) {
	/*
	* if x = 1, (x | x) = 1
	* if x = 0, (x | x) = 0
	* 
	* So, if we invert this operation
	* x = 1, !(x | x) = 0
	* x = 0, !(x | x) = 1
	* 
	*/
	return x = !(x | x);
}

//2
/* 
* byteSwap - swaps the nth byte and the mth byte
*  Examples: byteSwap(0x 12 34 56 78 , 1, 3) = 0x 56 34 12 78
*            byteSwap(0x DE AD BE EF, 0, 2) = 0x DE EF BE AD
* 
*  You may assume that 0 <= n <= 3, 0 <= m <= 3
*  Legal ops: ! ~ & ^ | + << >>
*  Max ops: 25
*  Rating: 2
*/

int byteSwap(int x, int n, int m) {
	
	// Get the nth and mth byte
	int byteN = (x >> (n << 3)) & 0xFF;  // Hex: 0xFF 
	int byteM = (x >> (m << 3)) & 0xFF;  // Bin: 1111 1111
	// Output: byteN = 0x000000NN, byteM=0x000000MM

	/**
	 * Hex number - ByteN, ByteM
	 * x = 0x12345678
	 * byteN = 0x00000056
	 * byteM = 0x00000012
	*/

	int mask = ~((0xFF << (n << 3)) | (0xFF << (m << 3))); // Output: 0x00ff00ff
	mask = x&mask;
	// x = 0x12345678, mask = 0x00ff00ff
	// output = 0x00340078

	//Add ByteN in M position and ByteM in N position
	mask = mask | (byteN << (m << 3));
	mask = mask | (byteM << (n << 3));
	
  return mask;
}



/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
*/
int implication(int x, int y) {

	/**
	 * Using propositional logic
	 * 
	 * (p -> q) === (¬p v q)
	 * =====================
	 * (x -> y) === (!x | y)
	 * 
	 * 
	 * 
	 * Note: I also find that the "implies gate" is: (!x and y)
	 * But I don't know why ~(~(!x) | ~y) doesn't work, this was my
	 * first option to solve this problem.
	*/
	return  (!x | y);
}

//3
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
*/

int isLess(int x, int y) {
  int sign_bit_x = (x >> 31) & 1;
  int sign_bit_y = (y >> 31) & 1;

  int diff_signs = (sign_bit_x ^ sign_bit_y);  // 1 if signs are different, 0 if the same

  int x_minus_y = x + (~y + 1);  // Calculate x - y

  // if signs are different, return 1 if x is negative, else 0
  // if signs are the same, return 1 if x - y is negative, else 0
  return (diff_signs & sign_bit_x) | ((~diff_signs) & ((x_minus_y >> 31) & 1));
}


/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	// (!x) << 31 -> if !x == true -> 0x80000000, else -> 0x00000000
	// If x is nonzero, mask = 0xFFFFFFFF; otherwise, mask = 0x00000000
	int mask = ((!x) << 31) >> 31; 
   

  // Conditionally selects bits from y and z based on the 'mask' and combines them.
  return (y & ~mask) | (z & mask);
}


/*
 * sum3 - x+y+z using only a single '+'
 *   Example: sum3(3, 4, 5) = 12
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 16
 *   Rating: 3
 */
/* A helper routine to perform the addition.  Don't change this code */

static int sum(int x, int y) {
  return x + y;
}

int sum3(int x, int y, int z) {
  // word1 = XOR of the 3 input integers (x, y, z).
  int word1 = x ^ y ^ z;
  
  // take the bitwise OR of x, y, and z, then XOR it with word1.
  // take the bitwise AND of x, y, and z.
  // perform a bitwise OR between the result from step 1 and the result from step 2.
  int word2 = (((x | y | z) ^ word1) | (x & y & z));
  word2 = word2 << 1;
  // leftshift the combined result by 1 bit.
  return sum(word1, word2);
}

//4
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
*/
int absVal(int x) {
  int sign_bit = (x >> 31);
	// if x positive, the sing bit is 0 -> x >> 31 = 0
	// if x negative, the sing bit is 1 -> x >> 31 = 1
	// x >> 31 extracts the sign bit as either 0 or -1
	x = (x + sign_bit) ^ sign_bit;  // XOR
  return x ; 
}



/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
*/

int trueFiveEighths(int x) {
	int div_by8 = x >> 3; // divide x by 8
	int remainder = x & 7; // find remainderainder, 7 = 0111 shift 3 to the right but still need those bits
	int mul5 = (div_by8 << 2) + div_by8; // multiplies div_by8 by 5 (multiplies by 4 and adds)
	int remainder5 = (remainder << 2) + remainder; // multiplies remainder by 5 (multiplies by 4 and adds)
	int sign_remainder = (x >> 31) & 7; // remainderainder of the sign
	return mul5 + ((remainder5 + sign_remainder) >> 3);
}


/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
*/

int isPower2(int x) {
  /* 
   * check if x is not zero
   * convert the result back to its original form,  
   * if x is no zero, !!x will be 1, and if x is zero, !!x will be 0. 
   * 
  */
  int is_not_zero = !!x;

  // check if x is positive
  int is_positive = !((x >> 31) & 1);
  int x_minus1= (x + (~0));

  // check if x is a power of 2 by ensuring that only one bit is set
  int is_power2 = !((x & x_minus1 ) | (!x));

  // check the conditions to check if x is a power of 2
  return is_not_zero & is_positive & is_power2;
}
