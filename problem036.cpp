/* Project Euler #36
 *
 * The decimal number, 585 = 1001001001_2 (binary), is palindromic in both
 * bases.
 *
 * Find the sum of all numbers, less than one million, which are palindromic in
 * base 10 and base 2.
 *
 * (Please note that the palindromic number, in either base, may not include
 * leading zeros.)
 */

#include <iostream>
#include <sstream>
#include <string>

bool is_palindrome(const std::string &s)
{
    size_t len = s.size();

    for (size_t i=0; i<len/2; i++) {
        if (s[i] != s[len-i-1]) {
            return false;
        }
    }

    return true;
}

long make_palindrome(long val, long reverse)
{
    while (reverse > 0) {
        val <<= 1;
        if (reverse & 1) {
            val |= 1;
        }

        reverse >>= 1;
    }

    return val;
}

long make_even_palindrome(long val)
{
    return make_palindrome(val, val);
}

long make_odd_palindrome(long val, int middle)
{
    long front = val;
    front <<= 1;
    if (middle) {
        front |= 1;
    }
    return make_palindrome(front, val);
}

int main()
{
    std::ostringstream sout;
    long pals[3];

    long sum = 1; // We start testing at 0b11.
    for (long i=1;; i++) {
        pals[0] = make_even_palindrome(i);
        if (pals[0] >= 1000000) {
            break;
        }
        pals[1] = make_odd_palindrome(i, 0);
        pals[2] = make_odd_palindrome(i, 1);

        for (int j=0; j<3; j++) {
            long val = pals[j];
            if (val >= 1000000) {
                continue;
            }

            sout << val;
            std::string s(sout.str());
            sout.str("");

            if (is_palindrome(s)) {
                sum += val;
            }
        }

    }

    std::cout << sum << std::endl;

    return 0;
}
