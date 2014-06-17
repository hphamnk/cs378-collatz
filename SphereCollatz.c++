// -------
// defines
// -------

#ifdef ONLINE_JUDGE
	#define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> // cin, cout
#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair

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
		// cout << n << " seg fault here even" << endl;
		x = n/2;
		if (x < CACHE_SIZE && x > 0)
		{
			// cout << x << " seg fault reach here?" << endl;
			cycle_length_from_cache = lazy_cache[x];
			// cout << x << " seg fault WWWWWWWWWWWTFFFFFFFFF " << endl;
			if (cycle_length_from_cache == 0)
			{
				// cout << x << " even seg fault: cycle_length not in cache" << endl;
				return collatz_find_cycle_length(x) + 1;
			}
			else
			{
				// cout << x << " even seg fault: cycle_length -- in -- cache " << endl;
				return cycle_length_from_cache + 1;
			}
		}
		else
		{
			// cout << x << " even seg fault: x bigger than cache size" << endl;
			return collatz_find_cycle_length(x) +1 ;
		}
	}
	else
	{
		// cout << "seg fault here odd" << endl;
		// x = (3 * n +1) / 2;
		x = n + (n >> 1) + 1;
		// cout << "seg fault here" << endl;
		if (x < CACHE_SIZE && x > 0)
		{
			
			cycle_length_from_cache = lazy_cache[x];
			
			if (cycle_length_from_cache == 0)
			{
				// cout << x << " odd seg fault: cycle_length not in cache" << endl;
				return collatz_find_cycle_length(x) + 2;
			}
			else
			{
				// cout << x << " odd seg fault: cycle_length -- in -- cache " << endl;
				return cycle_length_from_cache + 2;
			}
		}
		else
		{
			// cout << x << " odd seg fault: x bigger than cache size" << endl;
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

	// cout << j << endl;

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
		// cout << "i/2: " << a << endl;
	}

	// cout << "a: "  << a << ", i: " << i << ", j: " << j << endl;

	for (int x = a; x <= j; x++)
	{
		// cout << "begin for loop " << i << "-" << j << " x: " << x << endl;
		cycle_length = lazy_cache[x];

		if (cycle_length == 0)
		{
			// cout << x << " not in cache" << endl;
			cycle_length = collatz_find_cycle_length(x);
			lazy_cache[x] = cycle_length;
			// cout << x << " cycle length is: " << cycle_length << endl;
		}


		if (cycle_length > biggest_cycle_length)
		{
			biggest_cycle_length = cycle_length;
		}

		// cout << "end for loop " << i << "-" << j << " x: " << x << endl;
	}

	// cout << "biggest cycle length for " << i << "-" << j << " is "  << biggest_cycle_length << endl;
	// return collatz_find_cycle_length(j);
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

// ----
// main
// ----

int main () {
	using namespace std;
	collatz_solve(cin, cout);
	return 0;}