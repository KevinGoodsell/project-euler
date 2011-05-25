/* The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */

#include <iostream>

long square_of_sum(long max)
{
    long sum = (max + 1) * max / 2;
    return sum * sum;
}

long sum_of_squares(long max)
{
    long sum = 0;

    for (long i=1; i<=max; i++) {
        sum += i * i;
    }

    return sum;
}


int main()
{
    std::cout << square_of_sum(100) - sum_of_squares(100) << std::endl;

    return 0;
}
