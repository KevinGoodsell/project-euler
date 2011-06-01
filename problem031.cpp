/* Project Euler #31
 *
 * In England the currency is made up of pound, £, and pence, p, and there are
 * eight coins in general circulation:
 *
 *     1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 *
 * It is possible to make £2 in the following way:
 *
 *     1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 *
 * How many different ways can £2 be made using any number of coins?
 */

#include <iostream>
#include <vector>

long count_ways(long target, const std::vector<long> &values)
{
    if (target == 0) {
        return 1;
    }

    if (values.empty()) {
        return 0;
    }

    long largest = values.back();
    std::vector<long> smaller(values.begin(), values.end()-1);
    long sum = 0;
    for (long i=0; i*largest<=target; i++) {
        long new_target = target - i * largest;
        sum += count_ways(new_target, smaller);
    }

    return sum;
}

int main()
{
    const long vals[8] = {1, 2, 5, 10, 20, 50, 100, 200};
    const std::vector<long> values(vals, vals+8);

    std::cout << count_ways(200, values) << std::endl;

    return 0;
}
