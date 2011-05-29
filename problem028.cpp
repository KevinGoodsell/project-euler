/* Project Euler #28
 *
 * Starting with the number 1 and moving to the right in a clockwise direction a
 * 5 by 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of the numbers on the diagonals is 101.
 *
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
 * formed in the same way?
 */

#include <iostream>

int main()
{
    const int width = 1001;
    const int mid = width / 2;
    const int loops = width / 2 + 1;

    long spiral[width][width];

    long counter = 1;
    spiral[mid][mid] = counter++;
    for (int loop=1; loop<loops; loop++) {
        int lower = mid - loop;
        int upper = mid + loop;

        // Down
        for (int y=lower+1; y<=upper; y++) {
            spiral[upper][y] = counter++;
        }

        // Left
        for (int x=upper-1; x>=lower; x--) {
            spiral[x][upper] = counter++;
        }

        // Up
        for (int y=upper-1; y>=lower; y--) {
            spiral[lower][y] = counter++;
        }

        // Right
        for (int x=lower+1; x<=upper; x++) {
            spiral[x][lower] = counter++;
        }
    }

    long sum = 0;
    for (int i=0; i<width; i++) {
        sum += spiral[i][i];
        sum += spiral[i][width-i-1];
    }
    sum--; // We added the center twice.

    std::cout << sum << std::endl;

    return 0;
}
