#ifndef INCLUDED_BIGINT_H
#define INCLUDED_BIGINT_H 1

#include <vector>
#include <string>

namespace bigint
{

// To avoid overflow, base^2 must be representable in digit_type.
// base must be a power of 10 for easy base-10 digit extraction.
const unsigned base = 10000;
typedef unsigned long digit_type;
typedef std::vector<digit_type> digits_type;

class BigInt
{
public:
    BigInt(long val=0);

    BigInt operator*(const BigInt &other) const;
    BigInt &operator*=(const BigInt &other);

    std::string as_string() const;

protected:
    void normalize();
    void trim();

private:
    digits_type digits;
    bool negative;
};

}

#endif
