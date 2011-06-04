/* Project Euler #43
 *
 * The number, 1406357289, is a 0 to 9 pandigital number because it is made up
 * of each of the digits 0 to 9 in some order, but it also has a rather
 * interesting sub-string divisibility property.
 *
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note
 * the following:
 *
 *     * d2d3d4=406 is divisible by 2
 *     * d3d4d5=063 is divisible by 3
 *     * d4d5d6=635 is divisible by 5
 *     * d5d6d7=357 is divisible by 7
 *     * d6d7d8=572 is divisible by 11
 *     * d7d8d9=728 is divisible by 13
 *     * d8d9d10=289 is divisible by 17
 *
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "util.h"

using std::string;
using std::vector;

vector<string> get_pandigitals()
{
    string digits("0123456789");
    vector<string> permutations;
    vector<string> result;

    permute(permutations, digits, 0);

    vector<string>::iterator it;
    for (it=permutations.begin(); it!=permutations.end(); ++it) {
        string &value = *it;
        if (value[0] == '0') {
            continue;
        }

        result.push_back(value);
    }

    return result;
}

bool has_property(const string &value)
{
    string split(value.substr(1, 3) + ' ' +
                 value.substr(2, 3) + ' ' +
                 value.substr(3, 3) + ' ' +
                 value.substr(4, 3) + ' ' +
                 value.substr(5, 3) + ' ' +
                 value.substr(6, 3) + ' ' +
                 value.substr(7, 3));

    std::istringstream sin(split);
    vector<int> parts(7);
    for (int i=0; i<7; i++) {
        sin >> parts[i];
    }

    if (parts[0] % 2 == 0 &&
        parts[1] % 3 == 0 &&
        parts[2] % 5 == 0 &&
        parts[3] % 7 == 0 &&
        parts[4] % 11 == 0 &&
        parts[5] % 13 == 0 &&
        parts[6] % 17 == 0) {
        return true;
    }

    return false;
}

int main()
{
    vector<string> pandigitals(get_pandigitals());
    std::istringstream sin;

    long long sum = 0;
    vector<string>::iterator it;
    for (it=pandigitals.begin(); it!=pandigitals.end(); ++it) {
        if (has_property(*it)) {
            long long value;
            sin.clear();
            sin.str(*it);
            sin >> value;
            sum += value;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
