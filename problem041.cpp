/* Project Euler #41
 *
 * We shall say that an n-digit number is pandigital if it makes use of all the
 * digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is
 * also prime.
 *
 * What is the largest n-digit pandigital prime that exists?
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

bool is_prime(long val)
{
    if (val < 2) return false;
    if (val == 2) return true;
    if (val % 2 == 0) return false;

    long i = 3;

    while (i * i <= val) {
        if (val % i == 0) {
            return false;
        }

        i += 2;
    }

    return true;
}

void permute(std::vector<std::string> &out, std::string &s, unsigned index)
{
    if (index == s.size()) {
        out.push_back(s);
        return;
    }

    char temp = s[index];
    for (unsigned i=index; i<s.size(); i++) {
        s[index] = s[i];
        s[i] = temp;
        permute(out, s, index+1);
        s[i] = s[index];
    }
    s[index] = temp;
}

std::vector<long> get_pandigitals()
{
    std::vector<std::string> strings;
    for (int n=1; n<=9; n++) {
        std::string digits;
        for (int i=0; i<n; i++) {
            digits.push_back('1' + i);
        }
        permute(strings, digits, 0);
    }

    std::vector<long> result;
    std::istringstream sin;
    for (unsigned i=0; i<strings.size(); i++) {
        long val;
        sin.clear();
        sin.str(strings[i]);
        sin >> val;
        result.push_back(val);
    }

    return result;
}

int main()
{
    std::vector<long> pandigitals = get_pandigitals();

    long max = 0;
    for (size_t i=0; i<pandigitals.size(); i++) {
        long val = pandigitals[i];
        if (is_prime(val) and val > max) {
            max = val;
        }
    }

    std::cout << max << std::endl;

    return 0;
}
