#include "util.h"

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

bool is_prime(llong val)
{
    if (val < 2) return false;
    if (val == 2) return true;
    if (val % 2 == 0) return false;

    llong i = 3;

    while (i * i <= val) {
        if (val % i == 0) {
            return false;
        }

        i += 2;
    }

    return true;
}

