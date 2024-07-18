#include <iostream>
#include <set>

/**
 * @brief Find the total number of palindromic substrings within a given string.
 * This problem is a variation on the "Longest Subsequence" question type.
 */

using namespace std;

int palindromic_substr(std::string str, std::set<string> &result)
{
    const int n = str.size();
    bool table[n][n];
    for(int gap=0; gap < n; gap++)
    {
        for(int i=0, j=gap; j < n; i++, j++)
        {
            if (gap==0)
                table[i][j] = true;
            else if (gap == 1)
                table[i][j] = (str[i] == str[j]);
            else
            {
                table[i][j] = (str[i] == str[j] && table[i+1][j-1]);
            }
            if(table[i][j])
            {
                result.insert(str.substr(i, j-i+1));
            }
        }
    }
    return result.size();
}

int main() {
    string str = "Galababalaxy";
    set<string> result;
    // Call the function to find palindromic substrings
    palindromic_substr(str, result);
    cout << "Number of distinct palindromic substrings are: " << result.size() << endl;
    // Print the distinct palindromic substrings
    for (const string &s : result)
        cout << s << endl;
    return 0;
}
