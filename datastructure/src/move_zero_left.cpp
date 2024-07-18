#include <iostream>
#include <vector>

using namespace std;

/**
 * Given an integer array, move all elements that are 0 to the left while
 * maintaining the order of other elements in the array. The array must
 * be modified in-place.”
 */

void move_zero_left(vector<int>& arr)
{
    int j=0;
    for(int i=0; i<arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            int k = i;
            while(k >= j)
            {
                arr[k] = arr[k-1];
                k--;
            }
            arr[j] = 0;
            j++;
        }
    }
}


int main()
{
    vector<int> arr = {1, 10, 20, 0, 59, 63, 0, 88, 0};
    move_zero_left(arr);

    for(auto i: arr)
    {
        std::cout << i << " ";
    }
}
