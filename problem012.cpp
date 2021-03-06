/* Project Euler #12
 * The sequence of triangle numbers is generated by adding the natural numbers.
 * So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first
 * ten terms would be:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * Let us list the factors of the first seven triangle numbers:
 *
 *     1: 1
 *     3: 1,3
 *     6: 1,2,3,6
 *    10: 1,2,5,10
 *    15: 1,3,5,15
 *    21: 1,3,7,21
 *    28: 1,2,4,7,14,28
 *
 * We can see that 28 is the first triangle number to have over five divisors.
 *
 * What is the value of the first triangle number to have over five hundred
 * divisors?
 */

#include <iostream>
#include <limits>

int count_divisors(long val)
{
    int count = 0;
    long i;

    for (i=1; i*i<val; i++) {
        if (val % i == 0) {
            count += 2;
        }
    }

    if (i*i == val) count++;

    return count;
}

int main()
{
    const long max = std::numeric_limits<long>::max();
    long triangle = 0;
    for (long i=1; triangle<=max-i; i++) {
        triangle += i;
        if (count_divisors(triangle) > 500) {
            std::cout << triangle << std::endl;
            break;
        }
    }

    return 0;
}
