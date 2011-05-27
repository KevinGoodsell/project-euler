/* Project Euler #19
 * You are given the following information, but you may prefer to do some
 * research for yourself.
 *
 *  * 1 Jan 1900 was a Monday.
 *  * Thirty days has September,
 *    April, June and November.
 *    All the rest have thirty-one,
 *    Saving February alone,
 *    Which has twenty-eight, rain or shine.
 *    And on leap years, twenty-nine.
 *  * A leap year occurs on any year evenly divisible by 4, but not on a century
 *    unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth century
 * (1 Jan 1901 to 31 Dec 2000)?
 */

#include <iostream>

const int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// for start_day, 0 = sunday, 1 = monday, etc.
int count_first_sundays(int start_day, bool leap)
{
    int sum = 0;
    int month_start = start_day;

    for (int month=0; month<12; month++) {
        if (month_start == 0) {
            sum++;
        }

        month_start += month_days[month];
        if (month == 1 && leap) {
            month_start++;
        }
        month_start %= 7;
    }

    return sum;
}

bool is_leap(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

int main()
{
    int start_day = 1; // Jan 1 1900: Monday
    start_day = (start_day + 365) % 7; // 1900 - non-leap

    int sum = 0;
    for (int year=1901; year<=2000; year++) {
        sum += count_first_sundays(start_day, is_leap(year));

        start_day += 365;
        if (is_leap(year)) {
            start_day++;
        }
        start_day %= 7;
    }

    std::cout << sum << std::endl;

    return 0;
}
