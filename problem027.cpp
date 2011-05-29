/* Project Euler #27
 *
 * Euler published the remarkable quadratic formula:
 *
 * n^2 + n + 41
 *
 * It turns out that the formula will produce 40 primes for the consecutive
 * values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is
 * divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly
 * divisible by 41.
 *
 * Using computers, the incredible formula  n^2 - 79n + 1601 was discovered,
 * which produces 80 primes for the consecutive values n = 0 to 79. The product
 * of the coefficients, -79 and 1601, is -126479.
 *
 * Considering quadratics of the form:
 *
 *     n^2 + an + b, where |a| < 1000 and |b| < 1000
 *
 *         where |n| is the modulus/absolute value of n
 *             e.g. |11| = 11 and |-4| = 4
 *
 * Find the product of the coefficients, a and b, for the quadratic
 * expression that produces the maximum number of primes for
 * consecutive values of n, starting with n = 0.
 */

#include <iostream>

bool is_prime(long val)
{
    if (val < 2) return false;
    if (val == 2) return true;
    if (val % 2 == 0) return false;

    for (long i=3; i*i<=val; i+=2) {
        if (val % i == 0) return false;
    }

    return true;
}

long count_primes(int a, int b)
{
    long i;
    for (i=0; ; i++) {
        long val = i*i + i*a + b;
        if (not is_prime(val)) {
            break;
        }
    }

    return i;
}

int main()
{
    long max_a, max_b, max_primes=0;

    for (long a=-999; a<1000; a++) {
        for (long b=-999; b<1000; b++) {
            long primes = count_primes(a, b);
            if (primes > max_primes) {
                max_primes = primes;
                max_a = a;
                max_b = b;
            }
        }
    }

    std::cout << (max_a * max_b) << std::endl;

    return 0;
}
