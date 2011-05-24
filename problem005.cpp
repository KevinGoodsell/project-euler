/* Project Euler #5
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1
 * to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 */

#include <iostream>

bool is_divisible(long val)
{
    for (int i=2; i<=20; i++) {
        if (val % i != 0) return false;
    }

    return true;
}

int main()
{
    for (long i=20; ; i+=20) {
        if (is_divisible(i)) {
            std::cout << i << std::endl;
            break;
        }
    }

    return 0;
}
