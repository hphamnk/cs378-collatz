// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <utility>  // pair

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param  r a  std::istream
 * @return a pair of the two ints, otherwise a pair of zeros
 */
std::pair<int, int> collatz_read (std::istream&);

// ------------
// collatz_find_cycle_length
// ------------

/**
 * find the cycle length of a number recursively\n
 * if n = 1: return 1\n
 * if n is even: x = n / 2\n
 * 		\t- if x < 1 million and is in cache: get cycle length from cache\n
 *		\t- else call this function and pass x in as parameter and +1 to the cycle length that it returns\n
 * if n is odd: x = n + (n >> 1) + 1\n
 * 		\t- if x < 1 million and is in cache: get cycle length from cache\n
 *		\t- else call this function and pass x in as parameter and +2 to the cycle length that it returns\n
 * @param  n number
 * @return the cycle length of n
 */

int collatz_find_cycle_length(int);

// ------------
// collatz_eval
// ------------

/**
 * if i > j: switch i and j so first input (i) is smaller than second input (j)\n
 * if i > 1: a = i /2, then find the max cycle length from a to j to reduce unnecessary calculations\n
 * for loop from a to j:\n
 * 		\t if cycle length of an element is not in cache:\n
 *			\t\t- call collatz_find_cycle_length to find its cycle length and save it into cycle_length\n
 *		\t if cycle length of an element is in cache:\n
 *			\t\t- get that cycle length and save it into cycle_length\n
 *		\t- if cycle_length > biggest_cycle_length: copy cycle_length into biggest_cycle_length\n
 * return biggest_cycle_length as answer\n
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
int collatz_eval (int, int);

// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param w a std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (std::ostream&, int, int, int);

// -------------
// collatz_solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void collatz_solve (std::istream&, std::ostream&);

#endif // Collatz_h
