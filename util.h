#ifndef INCLUDED_UTIL_H
#define INCLUDED_UTIL_H 1

#include <string>
#include <vector>

#ifdef USE_LONG_LONG
typedef long long llong;
typedef unsigned long long ullong;
#else
typedef long llong;
typedef unsigned long ullong;
#endif

void permute(std::vector<std::string> &out, std::string &s, unsigned index);
bool is_prime(llong val);

#endif
