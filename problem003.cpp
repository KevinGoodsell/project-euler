/* Project Euler #3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
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

int main() {
    long long val = 600851475143LL;
    long long i = 2;
    long long largest = 0;

    while (i * i <= val) {
        if (is_prime(i) && val % i == 0) {
            largest = i;
        }

        i++;
    }

    std::cout << largest << std::endl;

    return 0;
}
