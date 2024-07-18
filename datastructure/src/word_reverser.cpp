#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * @brief “Reverse the order of words in a given string.”
 *
 */
void reverser(std::string& str)
{
    string word;
    stringstream ss(str);
    std::string result;
    while (ss >> word)
    {
        result.insert(0, word);
        result.insert(result.begin(), ' ');
    }
    // char *p = strtok(str, " ");
    str = result;
}


int main()
{
    std::cout << "--------------------------" << std::endl;
    string s = "I love to read articles on Favtutor.";
    reverser(s);
    std::cout << s;
}
