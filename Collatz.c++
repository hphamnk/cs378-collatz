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

    int x;

    if (n == 1)
        return 1;
    if ( (n % 2) == 0)
    {
        x = n/2;
        return collatz_find_cycle_length(x) +1 ;
    }
    else
    {
        x = (3 * n +1) / 2;
        return collatz_find_cycle_length(x) + 2;
    }



}
// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
    int temp;

    // swap i and j if i>j
    if (i > j)
    {
        temp = i;
        i = j;
        j = temp;
    }
    assert(i <= j);




    return collatz_find_cycle_length(j);
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
