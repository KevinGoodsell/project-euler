/* Project Euler #32
 *
 * We shall say that an n-digit number is pandigital if it makes use of all the
 * digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1
 * through 5 pandigital.
 *
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
 * multiplicand, multiplier, and product is 1 through 9 pandigital.
 *
 * Find the sum of all products whose multiplicand/multiplier/product identity
 * can be written as a 1 through 9 pandigital.
 * HINT: Some products can be obtained in more than one way so be sure to only
 * include it once in your sum.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <map>

bool has_pandigital_product(long a, long b)
{
    long product = a * b;
    std::ostringstream sout;
    sout << a << b << product;
    std::string digits = sout.str();

    if (digits.size() != 9) {
        return false;
    }

    for (char c='1'; c<='9'; c++)
    {
        if (digits.find(c) == std::string::npos) {
            return false;
        }
    }

    return true;
}

int digits(long val)
{
    // Doesn't work for negatives
    if (val < 10) return 1;
    return 1 + digits(val / 10);
}

long pow10(unsigned n)
{
    long result = 1;
    while (n > 0) {
        result *= 10;
        n--;
    }
    return result;
}

int main()
{
    typedef std::map<long, bool> pandig_type;
    pandig_type pandigital_products;

    for (long i=1; i<=9999; i++) {
        int i_dig = digits(i);
        // I think all solutions must have:
        // digits(i) + digits(j) == 5
        long j = pow10(4 - i_dig);
        for (;j<=9999; j++) {
            long product = i*j;
            int dig = i_dig + digits(j) + digits(product);
            if (dig > 9) {
                break;
            }

            if (has_pandigital_product(i, j)) {
                pandigital_products[product] = true;
            }
        }
    }

    long sum = 0;
    for (pandig_type::iterator it=pandigital_products.begin();
         it!=pandigital_products.end();
         ++it)
    {
        sum += it->first;
    }

    std::cout << sum << std::endl;

    return 0;
}
