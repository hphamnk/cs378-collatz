// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

// ------------
// Global
// ------------
#define CACHE_SIZE 1000000
int lazy_cache[CACHE_SIZE] = {0};


// ------------
// collatz_read
// ------------

std::pair<int, int> collatz_read (std::istream& r) {
	int i;
	r >> i;
	if (!r)
		return std::make_pair(0, 0);
	int j;
	r >> j;
	return std::make_pair(i, j);}


// ------------
// collatz_cycle_length
// ------------

int collatz_find_cycle_length(int n) {
	int cycle_length_from_cache;
	int x;
	

	if (n == 1)
		return 1;

	if ( (n % 2) == 0 && n > 0)
	{
		x = n/2;

		if (x < CACHE_SIZE && x > 0)
		{
			
			cycle_length_from_cache = lazy_cache[x];

			if (cycle_length_from_cache == 0)
			{
				return collatz_find_cycle_length(x) + 1;
			}
			else
			{
				return cycle_length_from_cache + 1;
			}
		}
		else
		{
			assert(x > CACHE_SIZE || x <= 0);
			return collatz_find_cycle_length(x) +1 ;
		}
	}
	else
	{
		// x = (3 * n +1) / 2;
		x = n + (n >> 1) + 1;

		if (x < CACHE_SIZE && x > 0)
		{
			cycle_length_from_cache = lazy_cache[x];
			
			if (cycle_length_from_cache == 0)
			{
				return collatz_find_cycle_length(x) + 2;
			}
			else
			{
				return cycle_length_from_cache + 2;
			}
		}
		else
		{
			assert(x > CACHE_SIZE || x <= 0);
			return collatz_find_cycle_length(x) + 2;
		}
	}
}
// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
	// <your code>
	int temp_swap;
	int biggest_cycle_length = 0;
	int cycle_length = 0;

	// switch i and j if i>j
	if (i > j)
	{
		temp_swap = i;
		i = j;
		j = temp_swap;
	}
	assert(i <= j);

	int a = i;

	if (i > 1)
	{ 
		int a = i/2;
	}

	for (int x = a; x <= j; x++)
	{
		cycle_length = lazy_cache[x];

		if (cycle_length == 0)
		{
			cycle_length = collatz_find_cycle_length(x);
			lazy_cache[x] = cycle_length;
		}

		if (cycle_length > biggest_cycle_length)
		{
			biggest_cycle_length = cycle_length;
		}

	}
	assert (biggest_cycle_length > 0);
	return biggest_cycle_length;
}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
	w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
	while (true) {
		const std::pair<int, int> p = collatz_read(r);
		if (p == std::make_pair(0, 0))
			return;
		const int v = collatz_eval(p.first, p.second);
		collatz_print(w, p.first, p.second, v);}}
