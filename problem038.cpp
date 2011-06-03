/* Project Euler #38
 *
 * Take the number 192 and multiply it by each of 1, 2, and 3:
 *
 *    192 × 1 = 192
 *    192 × 2 = 384
 *    192 × 3 = 576
 *
 * By concatenating each product we get the 1 to 9 pandigital, 192384576. We
 * will call 192384576 the concatenated product of 192 and (1,2,3)
 *
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4,
 * and 5, giving the pandigital, 918273645, which is the concatenated product of
 * 9 and (1,2,3,4,5).
 *
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as
 * the concatenated product of an integer with (1,2, ... , n) where n > 1?
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

long pandigital(long base)
{
    std::ostringstream sout;

    for (int top=2;; top++) {
        for (int i=1; i<=top; i++) {
            sout << base * i;
        }
        std::string concat(sout.str());
        sout.str("");

        if (concat.size() > 9) return -1;
        if (concat.size() < 9) continue;

        std::string sorted(concat);
        std::sort(sorted.begin(), sorted.end());
        for (int i=0; i<9; i++) {
            if (sorted[i] != '1' + i) return -1;
        }

        std::istringstream sin(concat);
        long result;
        sin >> result;
        return result;
    }
}

int main()
{
    long largest = -1;
    // with n == 2, 10000 produces 10 digits, so this is an upper limit.
    for (long i=1; i<=10000; i++) {
        long val = pandigital(i);
        if (val > largest) {
            largest = val;
        }
    }

    std::cout << largest << std::endl;

    return 0;
}
