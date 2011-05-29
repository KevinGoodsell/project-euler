/* Project Euler #30
 *
 * Surprisingly there are only three numbers that can be written as the sum of
 * fourth powers of their digits:
 *
 *     1634 = 1^4 + 6^4 + 3^4 + 4^4
 *     8208 = 8^4 + 2^4 + 0^4 + 8^4
 *     9474 = 9^4 + 4^4 + 7^4 + 4^4
 *
 * As 1 = 1^4 is not a sum it is not included.
 *
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *
 * Find the sum of all the numbers that can be written as the sum of fifth
 * powers of their digits.
 */

#include <iostream>

long sum_of_fifths(long val)
{
    long sum = 0;
    while (val > 0) {
        long digit = val % 10;
        val /= 10;
        sum += digit*digit*digit*digit*digit;
    }
    return sum;
}

int main()
{
    long sum = 0;
    // 9**5 * 7 == 413343, so no 7-digit or higher number can have a
    // sum-of-fifth-power-of-digits that is as large as it.
    for (long i=2; i<=9999999; i++) {
        if (i == sum_of_fifths(i)) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
