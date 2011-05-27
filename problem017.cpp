/* Project Euler #17
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
 * letters. The use of "and" when writing out numbers is in compliance with
 * British usage.
 */

#include <iostream>

int ones_counts[] = {
    4, // zero
    3, // one
    3, // two
    5, // three
    4, // four
    4, // five
    3, // six
    5, // seven
    5, // eight
    4, // nine
    3, // ten
    6, // eleven
    6, // twelve
    8, // thirteen
    8, // fourteen
    7, // fifteen
    7, // sixteen
    9, // seventeen
    8, // eighteen
    8  // nineteen
};

int tens_counts[] = {
    0, // zero, unused
    0, // ten, unused
    6, // twenty
    6, // thirty
    5, // forty
    5, // fifty
    5, // sixty
    7, // seventy
    6, // eighty
    6  // ninety
};

int count_letters(int val)
{
    if (val < 20) {
        return ones_counts[val];
    }

    if (val < 100) {
        int result = tens_counts[val / 10];
        val %= 10;
        // Don't say things like "seventy zero"
        if (val > 0) {
            result += ones_counts[val];
        }

        return result;
    }

    // "hundred" -> 7
    int result = ones_counts[val / 100] + 7;
    val %= 100;
    if (val > 0) {
        // "... and" -> 3
        result += 3 + count_letters(val);
    }

    return result;
}

int main()
{
    long sum = 0;
    for (int i=1; i<1000; i++) {
        sum += count_letters(i);
    }
    // "one thousand" -> 11
    sum += 11;

    std::cout << sum << std::endl;

    return 0;
}
