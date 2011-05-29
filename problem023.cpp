/* Project Euler #23
 *
 * A perfect number is a number for which the sum of its proper divisors is
 * exactly equal to the number. For example, the sum of the proper divisors of
 * 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than
 * n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
 * number that can be written as the sum of two abundant numbers is 24. By
 * mathematical analysis, it can be shown that all integers greater than 28123
 * can be written as the sum of two abundant numbers. However, this upper limit
 * cannot be reduced any further by analysis even though it is known that the
 * greatest number that cannot be expressed as the sum of two abundant numbers
 * is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum
 * of two abundant numbers.
 */

#include <iostream>
#include <vector>
#include <map>

bool is_abundant(long val)
{
    long sum = 1;
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

    return sum > val;
}

int main()
{
    std::vector<long> abundants;

    for (long i=12; i<=28123; i++) {
        if (is_abundant(i)) {
            abundants.push_back(i);
        }
    }

    std::map<long, bool> abundant_sums;
    for (size_t i=0; i<abundants.size(); i++) {
        for (size_t j=i; j<abundants.size(); j++) {
            long sum = abundants[i] + abundants[j];
            if (sum > 28123) {
                break;
            }
            abundant_sums[sum] = true;
        }
    }

    long sum = 0;
    for (long i=1; i<=28123; i++) {
        if (abundant_sums.count(i) == 0) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
