# Headers

#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <utility>		// std::pair
#include<array> // for array, at()
#include<tuple> // for get()


bool myfunction (int i,int j) { return (i<j); }




# Sort
# ------

bool myfunction (int i,int j) { return (i<j); }

int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

std::array<int,6> ar = {1, 2, 3, 4, 5, 6};
std::cout << ar.size();



// using default
sort(a, a + asize);

// using default comparison (operator <):
std::sort (myvector.begin(), myvector.end(), myfunc);

// using lambda function:
std::sort(arr.begin(), arr.end(), [](int i, int j) { return i > j; });

// binary search (needs to be sorted before)
if (std::binary_search(arr.begin(), arr.end(), 8))
{
    std::cout << "Item found!" << std::endl;
}
else
{
    std::cout << "\n Item not found" << std::endl;
}

// 2D-Algorithm
std::vector<std::vector<int>> arr = {   {1, 2},
                                        {2,2,3},
                                        {8,4} };
std::sort(arr.begin(), arr.end(), 
        [](const std::vector<int>& i, const std::vector<int>& j)
        { return i.size() < j.size(); });

// Reverse order traversing, reverse sorting
std::sort(arr[2].rbegin(), arr[2].rend(), [](int i, int j) { return i < j;});

// ------------------- MAP ----------------

#include <map>
using namespace std;

int main()
{
    map<string, string> m = {
        {"k1", "v1"},
        {"k2", "v2"},
        {"k3", "v3"}
    };
    
    for (const auto& i: m)
        std::cout << i.first << " = " << i.second << "\n" << std::endl;
    for (auto& [k, v]: m)
        std::cout << k << "=" << v << "\n" << std::endl;
}


// ------------------- UNORDERED MAP ----------------
    unordered_map<string, double> um;
    um["a"] = 1.0;
    um["b"] = 2.0;
    string key="a";
    if (um.find(key) != um.end())
        std::cout << "Key found!" << std::endl;
    
#include <bits/stdc++.h>
#include <sstream>

unordered_map<string, int> word_count;
stringstream ss(str);
string word;
while (ss >> word)
    word_count[word]++;
for (const auto& i: word_count)
    std::cout << i.first << ":: " << i.second << std::endl;

//---------------------------------------------------------------------

#include <sstream>
#include <map>
#include <iostream>

using namespace std;

int totalWords(string str){
   stringstream s(str);
   string word;
   int count = 0;
   while (s >> word)
      count++;
   return count;
}

void countFrequency(string st){
   map<string, int> FW;
   stringstream ss(st);
   string Word;
   while (ss >> Word)
      FW[Word]++;
   map<string, int>::iterator m;
   for (m = FW.begin(); m != FW.end(); m++)
      cout << m->first << " = " << m->second << "\n";
}

int main(){
   string s = "Ajay Tutorial Plus, Ajay author";
   cout << "Total Number of Words=" << totalWords(s)<<endl;
   countFrequency(s);
   return 0;
}

// ----- Priority queue ----------
https://en.cppreference.com/w/cpp/container/priority_queue
http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/

std::greater<int>
std::less<int>

void SamplePriorityQueueWithLamda()
{
    // using lambda to compare elements.
    auto compare = [](int lhs, int rhs)
                {
                    return lhs < rhs;
                };

    std::priority_queue<int, std::vector<int>, decltype(compare)> q(compare);

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);


    printQueue(q);
}

//-------------------- Operator overloading --------------------
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) {real = r;   imag = i;}
     
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    void print() { cout << real << " + i" << imag << '\n'; }
};
 
int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print();
}

class Count {
   private:
    int value;

   public:
    Count() : value(5) {}
    void operator ++ () {
        ++value;
    }
};


// Smart pointers
// --------------------------------------------------------------------
https://www.internalpointers.com/post/beginner-s-look-smart-pointers-modern-c

std::unique_ptr<int[]>  p2 = std::make_unique<int[]>(50);
std::shared_ptr<Object> p2 = std::make_shared<Object>("Lamp");
std::shared_ptr<int[]> p2(new int[16], [] (int* i) { 
  delete[] i; // Custom delete
});


// ----------------------------------------
Foo array[10];
Foo *foo = std::find(std::begin(array), std::end(array), someObject);
if (foo != std::end(array)) {
    cerr << "Found at position " << std::distance(array, foo) << endl;
}

// std::find function call
int item = 30;
it = std::find (vec.begin(), vec.end(), item);
if (it != vec.end())
{
    std::cout << "Element " << item <<" found at position : " ;
    std::cout << it - vec.begin() << " (counting from zero) \n" ;
}

it = std::find_if(vec.begin(), vec.end(), IsOdd);
bool IsOdd(int i) { return i % 2; }


const bool is_in = container.contains(element);
Pre C++20 the typical way was:

const bool is_in = container.find(element) != container.end();


//---------------------------------------------------------------------
void generatePrimeFactors(int N)
{
    while (N%2 == 0)
    {
        std::cout << 2 << " ";
        N = (int) N/2;
    }
    for(int i=3; i <= sqrt(N); i += 2)
    {
        while (N%i == 0)
        {
            std::cout << i << " ";
            N = N/i;
        }
    }
    
    if (N > 2)
        std::cout << N << std::endl;
}