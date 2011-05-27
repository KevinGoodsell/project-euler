/* Project Euler #16
 *
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */

#include <iostream>

// In binary, 2^1000 is 1001 digits, therefore in octal it is ceil(1001/3) = 334
// digits. This is large enough for any base greater than 8, also.
const int num_digits = 334;
const int base = 1000;

void double_val(int val[])
{
    for (int i=0; i<num_digits; i++) {
        val[i] *= 2;
    }

    for (int i=0; i<num_digits-1; i++) {
        if (val[i] >= base) {
            val[i+1] += val[i] / base;
            val[i] %= base;
        }
    }

    // An overflow check could be done here: if val[num_digits-1] > base, then
    // trouble.
}

long sum_digits(int val[])
{
    long sum = 0;

    for (int i=0; i<num_digits; i++) {
        int digit = val[i];
        while (digit > 0) {
            sum += digit % 10;
            digit /= 10;
        }
    }

    return sum;
}

int main()
{
    int value[num_digits] = {1};

    for (int i=1; i<=1000; i++) {
        double_val(value);
    }

    std::cout << sum_digits(value) << std::endl;

    return 0;
}
