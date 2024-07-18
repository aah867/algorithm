#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/**
 * @brief “Implement the function myQueue reverseK(myQueue queue, int k)
 * which takes a queue and a number k as input and reverses the first k elements of the queue.”
 */

void reverseK(queue<int> &q, int k)
{
    if(q.empty() || k <= 1)
        return;

    int i = 0;
    std::stack<int> s;
    while (i < k)
    {
        s.push(q.front());
        q.pop();
        i++;
    }

    int size = q.size();
    for (int i=0; i<size; i++)
    {
        int item = q.front();
        q.pop();
        q.push(item);
    }
    while(!s.empty())
    {
        int item = s.top();
        s.pop();
        q.push(item);
    }
}


int main()
{
    queue<int> mQ;
    mQ.push(1);
    mQ.push(2);
    mQ.push(3);
    mQ.push(4);
    mQ.push(5);
    reverseK(mQ,3);

    while (!mQ.empty())
    {
        std::cout << mQ.front() << std::endl;
        mQ.pop();
    }
}
