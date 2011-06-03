/* Project Euler #39
 *
 * If p is the perimeter of a right angle triangle with integral length sides,
 * {a,b,c}, there are exactly three solutions for p = 120.
 *
 * {20,48,52}, {24,45,51}, {30,40,50}
 *
 * For which value of p ≤ 1000, is the number of solutions maximised?
 */

#include <iostream>

int count_solutions(int p)
{
    int sum = 0;
    for (int a=1; 2*a<p; a++) {
        // a + b > c
        // a + b > p - a - b
        // b + b > p - a - a
        // 2b > p - 2a
        // b > (p - 2a)/2
        int b=(p - 2*a)/2+1;
        if (b < a) break;

        for (; b<=p-2; b++) {
            int c = p - a - b;

            if (b > a + c) break;

            if (a*a + b*b == c*c) {
                sum++;
            }
        }
    }

    return sum;
}

int main()
{
    int max_solutions = 0;
    int max_p;

    for (int p=3; p<=1000; p++) {
        int solutions = count_solutions(p);
        if (solutions > max_solutions) {
            max_solutions = solutions;
            max_p = p;
        }
    }

    std::cout << max_p << std::endl;

    return 0;
}
