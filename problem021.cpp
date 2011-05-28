/* Project Euler #21
 *
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 * which divide evenly into n).
 * If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and
 * each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <iostream>

long sum_divisors(long val)
{
    long sum = 1; // 1 divides everything
    long i;

    for (i=2; i*i<val; i++) {
        if (val % i == 0) {
            sum += i;
            sum += val / i;
        }
    }

    if (i*i == val) {
        sum += i;
    }

    return sum;
}

int main()
{
    long sum = 0;

    for (long i=2; i<10000; i++) {
        long val = sum_divisors(i);
        if (i != val && i == sum_divisors(val)) {
            sum += val;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
