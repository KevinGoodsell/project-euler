/* Project Euler #4
 *
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>
#include <sstream>

bool is_palindrome(long val)
{
    std::ostringstream sout;
    sout << val;

    std::string text(sout.str());
    std::string reversed(text.rbegin(), text.rend());

    return text == reversed;
}

int main()
{
    long max = 0;

    for (int i=99; i<1000; i++) {
        for (int j=i; j<1000; j++) {
            int val = i*j;
            if (is_palindrome(val) && val > max) {
                max = val;
            }
        }
    }

    std::cout << max << std::endl;

    return 0;
}
