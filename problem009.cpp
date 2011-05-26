/* Project Euler #9
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for
 * which,
 * a^2 + b^2 = c^2
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <iostream>

int main()
{
    int a, b, c;

    for (a = 1; a < 998; a++) {
        for (b = a+1; ; b++) {
            c = 1000 - a - b;
            if (c < b || c < a) break;

            if (a*a + b*b == c*c) {
                std::cout << a << ' ' << b << ' ' << c << std::endl;
                std::cout << (a*b*c) << std::endl;
                return 0;
            }
        }
    }


    return 0;
}
