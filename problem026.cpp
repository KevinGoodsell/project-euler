/* Project Euler #26
 *
 * A unit fraction contains 1 in the numerator. The decimal representation of
 * the unit fractions with denominators 2 to 10 are given:
 *
 *     1/2  =  0.5
 *     1/3  =  0.(3)
 *     1/4  =  0.25
 *     1/5  =  0.2
 *     1/6  =  0.1(6)
 *     1/7  =  0.(142857)
 *     1/8  =  0.125
 *     1/9  =  0.(1)
 *     1/10 =  0.1
 *
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
 * seen that 1/7 has a 6-digit recurring cycle.
 *
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle
 * in its decimal fraction part.
 */

#include <iostream>
#include <vector>
#include <map>

int count_repeats(int denom)
{
    int numerator = 1;
    std::map<int, int> numerator_index;
    std::vector<int> quotient;

    while (numerator_index.count(numerator) == 0) {
        int qdigit = numerator / denom;
        numerator_index[numerator] = quotient.size();
        quotient.push_back(qdigit);
        numerator %= denom;
        numerator *= 10;

        if (numerator == 0) return 0;
    }

    int start_index = numerator_index[numerator];
    return quotient.size() - start_index;
}

int main()
{
    int max_cycle = 0;
    int d = 0;
    for (int i=1; i<1000; i++) {
        int count = count_repeats(i);
        if (count > max_cycle) {
            d = i;
            max_cycle = count;
        }
    }

    std::cout << d << std::endl;

    return 0;
}
