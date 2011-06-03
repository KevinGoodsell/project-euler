/* Project Euler #37
 *
 * The number 3797 has an interesting property. Being prime itself, it is
 * possible to continuously remove digits from left to right, and remain prime
 * at each stage: 3797, 797, 97, and 7. Similarly we can work from right to
 * left: 3797, 379, 37, and 3.
 *
 * Find the sum of the only eleven primes that are both truncatable from left to
 * right and right to left.
 *
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
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

bool is_truncatable_prime(long val)
{
    long place = 1;
    long right = 0;

    if (!is_prime(val)) return false;

    while (true) {
        right += (val % 10) * place;
        place *= 10;
        val /= 10;
        if (val == 0) break;

        if (!is_prime(val)) return false;
        if (!is_prime(right)) return false;
    }

    return true;
}

int main()
{
    int count = 0;
    long sum = 0;

    for (long i=11; i<1000000000; i+=2) {
        if (is_truncatable_prime(i)) {
            sum += i;
            count++;
            if (count == 11) break;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
