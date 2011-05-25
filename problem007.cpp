/* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the 10001st prime number?
 */

#include <iostream>

// long long is not strict C++, unfortunately.

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
    int count = 1;
    long long test;

    for (test=3; ; test+=2) {
        if (is_prime(test)) {
            if (++count == 10001) {
                break;
            }
        }
    }

    std::cout << test << std::endl;

    return 0;
}
