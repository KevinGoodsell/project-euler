/* Project Euler #15
 *
 * Starting in the top left corner of a 2x2 grid, there are 6 routes (without
 * backtracking) to the bottom right corner.
 *
 * How many routes are there through a 20x20 grid?
 */

#include <iostream>
#include <stdexcept>

const int grid_size = 20;
long long routes[grid_size][grid_size];

long long count_routes(int n, int m)
{
    if (n == 0 || m == 0) {
        return 1;
    }

    long long result = routes[n][m];
    if (result != 0) {
        return result;
    }

    result = count_routes(n-1, m) + count_routes(n, m-1);
    if (result > 0x3FFFFFFFFFFFFFFFLL) {
        throw std::runtime_error("Big numbers!");
    }
    routes[n][m] = routes[m][n] = result;
    return result;
}

int main()
{
    std::cout << count_routes(20, 20) << std::endl;

    return 0;
}
