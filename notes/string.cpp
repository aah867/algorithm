#include<iostream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

void reverseString(std::string str)
{
    stringstream in(str);
    string i;
    stack<string> out;
    while(in >> i) {
        out.push(i);
    }
    while(!out.empty()) {
        std::cout << out.top() << " ";
        out.pop();
    }
}

int longestUniqueSubsttr(string s)
{
    // Creating a map to store the last positions of occurrence
    map<char, int> seen ;
    int maximum_length = 0;
    // Starting the initial point of window to index 0
    int start = 0;
    for(int end = 0; end < s.length(); end++)
    {
        // Checking if we have already seen the element or not
        if (seen.find(s[end]) != seen.end())
        {
            // If we have seen the number, move the start
            // pointer to position after the last occurrence
            start = max(start, seen[s[end]] + 1);
        }
        // Updating the last seen value of the character
        seen[s[end]] = end;
        maximum_length = max(maximum_length,
                             end - start + 1);
    }
    return maximum_length;
}
 