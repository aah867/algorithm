#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Given an integer array of coins[ ] of size N representing different types of denominations and an integer sum,
 * the task is to count all combinations of coins to make a given value sum.
 * Note: Assume that you have an infinite supply of each type of coin.
 */
int count_combination(int coins[], int n, int sum)
{
    if (sum == 0)
        return 1;

    if (sum < 0)
        return 0;

    if (n <= 0)
        return 0;

    return count_combination(coins, n, sum-coins[n-1]) + count_combination(coins, n-1, sum);
}


int main()
{
    int arr[] = {1, 10, 20, 0, 59, 63, 0, 88, 0, 2};
    std::cout << "result = " << count_combination(arr, 10, 20) << std::endl;
}
