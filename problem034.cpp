/* Project Euler #34
 *
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 * Find the sum of all numbers which are equal to the sum of the factorial of
 * their digits.
 *
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */

#include <iostream>
#include <vector>

long fact(long val)
{
    long result = 1;

    while (val > 0) {
        result *= val;
        val--;
    }

    return result;
}

long digit_fact_sum(long val)
{
    std::vector<long> digit_fact;

    while (val > 0) {
        digit_fact.push_back(fact(val % 10));
        val /= 10;
    }

    long sum = 0;
    for (unsigned i=0; i<digit_fact.size(); i++) {
        sum += digit_fact[i];
    }

    return sum;
}

int main()
{
    long sum = 0;

    // 9! * 7 = 2540160, so nothing above 9999999 can possibly meet the
    // requirements.
    for (long i=3; i<9999999; i++) {
        if (i == digit_fact_sum(i)) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
