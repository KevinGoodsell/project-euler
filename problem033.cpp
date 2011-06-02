/* Project Euler #33
 *
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician
 * in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which
 * is correct, is obtained by cancelling the 9s.
 *
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 * There are exactly four non-trivial examples of this type of fraction, less
 * than one in value, and containing two digits in the numerator and
 * denominator.
 *
 * If the product of these four fractions is given in its lowest common terms,
 * find the value of the denominator.
 */

#include <iostream>

int gcd(int a, int b)
{
    // Euclidean algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

class Rational {
public:
    Rational(int num, int den) : numerator(num), denominator(den) {}

    void simplify()
    {
        int d = gcd(numerator, denominator);
        numerator /= d;
        denominator /= d;
    }

    bool operator==(const Rational &other) const
    {
        return numerator == other.numerator && denominator == other.denominator;
    }

    int numerator;
    int denominator;
};

bool is_deceptive(int num, int den)
{
    Rational r(num, den);
    r.simplify();

    if (num % 10 == den % 10) {
        Rational test(num / 10, den / 10);
        test.simplify();
        if (r == test) return true;
    }

    if (num % 10 == den / 10) {
        Rational test(num / 10, den % 10);
        test.simplify();
        if (r == test) return true;
    }

    if (num / 10 == den % 10) {
        Rational test(num % 10, den / 10);
        test.simplify();
        if (r == test) return true;
    }

    if (num / 10 == den / 10) {
        Rational test(num % 10, den % 10);
        test.simplify();
        if (r == test) return true;
    }

    return false;
}

int main()
{
    Rational product(1, 1);

    for (int num=10; num<=99; num++) {
        for (int den=num+1; den<=99; den++) {
            if (num % 10 == 0 && den % 10 == 0) {
                continue;
            }

            if (is_deceptive(num, den)) {
                product.numerator *= num;
                product.denominator *= den;
            }
        }
    }

    product.simplify();
    std::cout << product.denominator << std::endl;
}
