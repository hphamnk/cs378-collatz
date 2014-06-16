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
        // x = (3 * n +1) / 2;
        x = n + (n >> 1) + 1;
        return collatz_find_cycle_length(x) + 2;
    }



}
// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
    int temp_swap;
    int highest_cycle_length = 0;
    

    // switch i and j if i>j
    if (i > j)
    {
        temp_swap = i;
        i = j;
        j = temp_swap;
    }
    assert(i <= j);

    int a = i;

    if (j > 1)
    { 
        int a = j/2;
        // cout << "j/2: " << a << endl;
    }

    for (int x = a; x <= j; x++)
    {
        int cycle_length = collatz_find_cycle_length(x);

        if (cycle_length > highest_cycle_length)
        {
            highest_cycle_length = cycle_length;
        }
    }

    // return collatz_find_cycle_length(j);
    return highest_cycle_length;
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