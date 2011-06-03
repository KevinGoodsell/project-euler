/* Project Euler #40
 *
 * An irrational decimal fraction is created by concatenating the positive
 * integers:
 *
 * 0.123456789101112131415161718192021...
 *
 * It can be seen that the 12th digit of the fractional part is 1.
 *
 * If dn represents the nth digit of the fractional part, find the value of the
 * following expression.
 *
 * d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
 */

#include <iostream>
#include <sstream>
#include <string>

int get_digit(long pos)
{
    int group = 1;
    long group_start = 1; // group ^ 10

    while (true) {
        long group_size = 9 * group * group_start;
        if (pos <= group_size) break;
        pos -= group_size;
        group++;
        group_start *= 10;
    }

    // val is the number before appending into the irrational
    long val = group_start + (pos-1) / group;
    int digit_pos = group - 1 - (pos-1) % group;
    while (digit_pos > 0) {
        val /= 10;
        digit_pos--;
    }
    return val % 10;
}

int main()
{
    long result = get_digit(1)
                * get_digit(10)
                * get_digit(100)
                * get_digit(1000)
                * get_digit(10000)
                * get_digit(100000)
                * get_digit(1000000);

    std::cout << result << std::endl;

    /*
    // Ugly brute-force approach
    std::ostringstream sout;
    std::string val;

    for (long i=0; i<10000000; i++) {
        sout << i;
        val = sout.str();
        if (val.size() > 1000000) {
            break;
        }
    }

    long result = long(val[1] - '0') * (val[10] - '0') * (val[100] - '0') *
        (val[1000] - '0') * (val[10000] - '0') * (val[100000] - '0') *
        (val[1000000] - '0');

    std::cout << result << std::endl;
    */

    return 0;
}
