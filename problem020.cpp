/* Project Euler #20
 *
 * n! means n * (n − 1) * ... * 3 * 2 * 1
 *
 * For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 =
 * 27.
 *
 * Find the sum of the digits in the number 100!
 */

#include <iostream>
#include <string>

#include "bigint.h"

using bigint::BigInt;

int main()
{
    BigInt foo = 1;

    for (int i=1; i<=100; i++) {
        foo *= BigInt(i);
    }

    std::string digits = foo.as_string();
    long sum = 0;
    for (std::string::iterator it=digits.begin(); it!=digits.end(); ++it) {
        sum += *it - '0';
    }

    std::cout << sum << std::endl;

    return 0;
}
