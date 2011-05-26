/* Project Euler #14
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n -> n/2 (n is even)
 * n -> 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following
 * sequence:
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it
 * is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <iostream>
#include <stdexcept>

const long stored_lengths = 10000;
int lengths[stored_lengths];

int chain_length(long long val)
{
    if (val > 0xFFFFFFFFFFFFFFFLL) {
        std::cerr << val << std::endl;
        throw std::runtime_error("Whoa, that's a big number!");
    }

    if (val == 1) {
        return 0;
    }

    int length;

    if (val < stored_lengths) {
        length = lengths[val];
        if (length > 0) {
            return length;
        }
    }

    if (val % 2 == 0) {
        length = 1 + chain_length(val/2);
    } else {
        length = 1 + chain_length(3*val + 1);
    }

    if (val < stored_lengths) {
        lengths[val] = length;
    }

    return length;
}

int main()
{
    int max = 0;
    int max_starting = 1;

    for (long i=1; i<1000000; i++) {
        int length = chain_length(i);
        if (length > max) {
            max = length;
            max_starting = i;
        }
    }

    std::cout << max_starting << std::endl;

    return 0;
}
