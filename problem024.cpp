/* Project Euler #24
 *
 * A permutation is an ordered arrangement of objects. For example, 3124 is one
 * possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
 * are listed numerically or alphabetically, we call it lexicographic order. The
 * lexicographic permutations of 0, 1 and 2 are:
 *
 * 012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
 * 5, 6, 7, 8 and 9?
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

void get_permutations(vector<string>& permutations, string& s, size_t start)
{
    if (start == s.size() - 1) {
        permutations.push_back(s);
        return;
    }

    char temp = s[start];
    for (size_t i=start; i<s.size(); i++) {
        s[start] = s[i];
        s[i] = temp;
        get_permutations(permutations, s, start+1);
        s[i] = s[start];
    }
    s[start] = temp;
}

int main()
{
    vector<string> p;
    string s = "0123456789";

    get_permutations(p, s, 0);

    std::sort(p.begin(), p.end());

    std::cout << p[999999] << std::endl;

    return 0;
}
