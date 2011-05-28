#include "bigint.h"

namespace bigint
{

BigInt::BigInt(long val) : negative(false)
{
    if (val < 0) {
        negative = true;
        val = -val;
    }

    while (val > 0) {
        digits.push_back(val % base);
        val /= base;
    }
}

BigInt BigInt::operator*(const BigInt &other) const
{
    BigInt result;
    typedef digits_type::size_type size;

    result.digits.resize(digits.size() + other.digits.size(), 0);

    for (size i=0; i<digits.size(); i++) {
        for (size j=0; j<other.digits.size(); j++) {
            result.digits[i+j] += digits[i] * other.digits[j];
        }
        result.normalize();
    }

    if (this->negative != other.negative) {
        result.negative = true;
    }

    result.trim();

    return result;
}

BigInt &BigInt::operator*=(const BigInt &other)
{
    *this = *this * other;
    return *this;
}

std::string BigInt::as_string() const
{
    std::string result;
    digits_type::size_type i;
    digit_type digit;

    if (digits.size() == 0) {
        return "0";
    }

    for (i=0; i+1<digits.size(); i++) {
        digit = digits[i];
        for (unsigned i=1; i<base; i*=10) {
            result.push_back((digit % 10) + '0');
            digit /= 10;
        }
    }

    // The decimal representation of the last digit can't be zero-padded.
    digit = digits[i];
    while (digit != 0) {
        result.push_back((digit % 10) + '0');
        digit /= 10;
    }

    if (negative) {
        result.push_back('-');
    }
    return std::string(result.rbegin(), result.rend());
}

void BigInt::normalize()
{
    typedef digits_type::size_type size;

    for (size i=0; i<digits.size(); i++) {
        if (digits[i] >= base) {
            digit_type carry = digits[i] / base;
            digits[i] %= base;

            if (i+1 >= digits.size()) {
                digits.push_back(carry);
            } else {
                digits[i+1] += carry;
            }
        }
    }

}

void BigInt::trim()
{
    typedef digits_type::size_type size;

    size i;
    for (i=digits.size(); i>0; i--) {
        if (digits[i-1] != 0) break;
    }
    digits.resize(i);
}

}
