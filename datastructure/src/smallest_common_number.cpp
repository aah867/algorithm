#include <iostream>
#include <vector>

using namespace std;

/**
 * Smallest Common Number:
 * Given three integer arrays sorted in ascending order, return the smallest number that is common in all three arrays.
 * Return -1 if there is no common number.
*/

int find_least_common_number(const std::vector<int>& arr1, const std::vector<int>& arr2, const std::vector<int> arr3)
{
    int i=0, j=0, k=0;

    while (i < arr1.size() && j < arr2.size() && k < arr3.size())
    {
        if ((arr1[i] == arr2[j]) && (arr2[j] == arr3[k]))
        {
            return arr1[i];
        }

        if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k])
        {
            i++;
        }
        else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k])
        {
            j++;
        }
        else if (arr3[k] <= arr1[i] && arr3[k] <= arr2[j])
        {
            k++;
        }
    }

    return -1;
}


int main()
{
    vector<int> v1 = {6, 7, 10, 25, 30, 63, 64};
    vector<int> v2 = {1, 4, 5, 6, 7, 8, 50};
    vector<int> v3 = {1, 6, 10, 14};
    int result = find_least_common_number(v1, v2, v3);
    cout << "Least Common Number: " << result;
}
