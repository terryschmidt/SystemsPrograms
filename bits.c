/* 
 * CS:APP Data Lab 
 * 
 * <Terry Schmidt. userid sch, DePaul ID number 1433009>
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

  INTEGER CODING RULES
 
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
     For example, you cannot use the word "unsigned".
  7. Use any data type other than int.  
     For example, you cannot use arrays, structs, or unions.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

  EXAMPLES OF ACCEPTABLE CODING STYLE

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

  // You may wish to print intermediate results while debugging your
  // code.  For example:
  int pow2plus4(int x) {
    int result = (1 << x);
    printf ("pow2plus4: x=%08x, result=%08x\n", x, result);

    // You can also spread prints over multitple source lines:
    printf ("after addition x=%08x", x);
    result += 4;
    printf ("result=%08x\n", result);
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

  NOTES

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
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
       /* NOT OR effectively becomes AND */
       return ~(~x | ~y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* applying DeMorgans Law to: (~x & y) | (x & ~y) */
  return ~(~(x & ~y) & ~(y & ~x));
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  /* using NOT XOR is effectively == */
  return !(x ^ y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* n << 3 adjusts n so it is represented in bit form */
  /* 0xff is applied to get only the least significant byte */
  return (0xFF & (x >> (n << 3)));
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
    /* shift 31 bits to the left to remove all but the LSB.
       then arithmetically shifted right 31 bits to copy LSB */
    return ((x << 31) >> 31);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  int aShift = x >> n;
  int removeLeft = ~0 << (32 + ~n) << 1; /*shift 1's left by 32-n*/
  removeLeft = ~removeLeft; /*this flips all the bits, putting wanted 1's on right*/
  return removeLeft & aShift; /*return the right end of aShift*/
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  int allBits;
  int allOdd = (0xAA << 8) | 0xAA;
  allOdd = allOdd | (allOdd << 16); /* integers that have odd bits get set to 1*/
  allBits = allOdd | x;
  allBits = ~allBits; /* if it is even, it becomes 0*/
  return !allBits;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  x = x & (~x+1); /*gives mask of LSB*/
  x = ~x + 1; /*sign bit is only zero if x was zero*/
  return (~(x >> 31)) & 1; /*return opposite of the sign bit*/
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  int negative_x = ~x + 1; /* this gives the logical negative of x*/
  return(x & negative_x); /* x and the logical negative of x combining via the & operator produce what we want*/
  
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31; /* this will shift the '1' bit to make 0x80000000*/
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
  x = x >> 31;
  x = x + 1;
  return !x; /* 0 becomes 1, 1 becomes 0 */
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /* boolean value of sign x is 1 = negative, 0 = non-neg */
  int sign_x = x >> 31;
  /* boolean value of sign y is 1 = negative, 0 = non-neg */
  int sign_y = y >> 31;
  /* if x is larger, sign bits of (~y + x) is 0
     if y is larger, sign bit of (~y + x) is 1 */
  int equal = !(sign_x ^ sign_y) & ((~y + x) >> 31);
  /* if signs are opposite, then reverse */
  int notEqual = sign_x & !sign_y;
  /* this returns 0 when x is >, so we take the negation */
  return !( equal | notEqual);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  x = !!x; /* this will put x in 0 or 1 form*/
  x = ~x+1; /* x now becomes either all 1s or all 0s*/
  return (x & y) | (~x & z);
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
  /* we need to account for x >> n if positive, and x >> n + 1 if negative*/
  /* subtract 1 from 2^n
     /* this accounts for the need to +1*/
  int mask = (1 << n) + ~0;
  /* Use & operator on mask and sign bit of x*/
     int equalizer = (x >> 31) & mask;
     /* add 0 if x started out positive
	add 1 if x started out negative*/
     return (x + equalizer) >> n;
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  /* case 1 - x positive, y positive, overflow doesn't happen
     case 2 - x negative, y negative, overflow doesn't happen
     case 3 - x positive, y negative, overflow can happen if sign of diff is negative
     case 4 - x negative, y positive, overflow can happen if sign of diff is positive*/
  int diff = x + (~y+1);
  int sx = (x>>31) & 1;
  int sy = (y>>31) & 1;
  int sd = (diff>>31) & 1;
  return !((!sx&sy&sd) | (sx & !sy &!sd));
}
