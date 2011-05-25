/* Project Euler #10
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <iostream>

bool is_prime(long long val)
{
    if (val < 2) return false;
    if (val == 2) return true;
    if (val % 2 == 0) return false;

    long long i = 3;

    while (i * i <= val) {
        if (val % i == 0) {
            return false;
        }

        i += 2;
    }

    return true;
}

int main()
{
    long long sum = 2;
    long tally = 1;

    for (long i=3; i < 2000000; i+=2) {
        if (is_prime(i)) {
            sum += i;
            tally++;
        }
    }

    std::cout << sum << std::endl;
    std::cout << tally << " primes found" << std::endl;

    return 0;
}
