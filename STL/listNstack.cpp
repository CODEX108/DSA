#include <iostream>
#include <list>
#include <stack>
using namespace std;
// Time complexity O(n)
int main()
{
    list<int> l;
    cout << "Max size: " << l.max_size() << endl;
    l.push_back(1);
    l.push_front(4);
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Size " << l.size() << endl;
    cout << "Erease the first element ";
    l.erase(l.begin());
    cout << "Size " << l.size() << endl;

    //Stacks
    stack<string> s;
    s.push("Hello");
    s.push("World");
    cout << "Size " << s.size() << endl;
    cout << "Top " << s.top() << endl;
    s.pop();
    cout << "Size " << s.size() << endl;
    cout << "Top " << s.top() << endl;
    cout<< "Empty "<<s.empty()<<endl;
    return 0;
}