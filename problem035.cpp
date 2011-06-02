/* Project Euler #35
 *
 * The number, 197, is called a circular prime because all rotations of the
 * digits: 197, 971, and 719, are themselves prime.
 *
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71,
 * 73, 79, and 97.
 *
 * How many circular primes are there below one million?
 */

#include <iostream>

bool is_prime(long val)
{
    if (val < 2) return false;
    if (val == 2) return true;
    if (val % 2 == 0) return false;

    long i = 3;

    while (i * i <= val) {
        if (val % i == 0) {
            return false;
        }

        i += 2;
    }

    return true;
}

bool is_circular_prime(long val)
{
    long pow10 = 1;
    while (pow10 * 10 < val) {
        pow10 *= 10;
    }

    long rot = val;
    do {
        if (!is_prime(rot)) {
            return false;
        }
        rot = (rot % 10) * pow10 + (rot / 10);
    } while (rot != val);

    return true;
}

int main()
{
    long count = 1; // Count 2 ahead of time, skip evens.

    for (long i=3; i<1000000; i+=2) {
        if (is_circular_prime(i)) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
