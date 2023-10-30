#include <iostream>
#include <queue>
#include <deque>
using namespace std;

void dequeFunc()
{
    deque<int> d;
    cout << "Max size: " << d.max_size() << endl;

    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    d.pop_back();
    d.pop_front();
    for (int i : d)
    {
        cout << i << " ";
    }

    d.push_back(12);
    d.push_front(43);
    // print first index element
    cout << endl
         << d.at(0) << endl;
    // print last index element
    cout << d.at(d.size() - 1) << endl;
    // print first index element
    cout << d.front() << endl;
    // print last index element
    cout << d.back() << endl;
    // print size of deque
    cout << d.size() << endl;
    // print if deque is empty or not
    cout << d.empty() << endl;

    cout << "Size " << d.size() << endl;
    cout << "Erease the first element ";
    d.erase(d.begin(), d.begin() + 1);
    cout << "Size " << d.size() << endl;

    // although the size decreases but the max size remains same as it was in the starting

    cout << "Max size: " << d.max_size();
}

void queueFunc()
{
    // Queue Time complexity O(1);
    cout << "Queue" << endl;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Size " << q.size() << endl;
    cout << "Front " << q.front() << endl;
    cout << "Back " << q.back() << endl;
    q.pop();
    cout << "Size " << q.size() << endl;
    cout << "Front element ->  " << q.front() << endl;
    cout << "Back element ->" << q.back() << endl;
    cout << "Empty " << q.empty() << endl;
}

void priQueFunc()
{
    // Priority Queue -Max heap implementation
    cout << "Priority Queue" << endl;
    priority_queue<int> maxi;
    maxi.push(12);
    maxi.push(10);
    maxi.push(50);
    maxi.push(3);
    maxi.push(1);
    int n = maxi.size();
    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }

    //Min heap
    cout << endl
         << "Min heap" << endl;
    priority_queue<int, vector<int>, greater<int>> mini;
    mini.push(12);
    mini.push(10);
    mini.push(50);
    mini.push(3);
    mini.push(1);
    n = mini.size();
    for (int i = 0; i < n; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }cout<<endl;
    cout<<"Is empty -> "<<mini.empty();
}

int main()
{
    priQueFunc();
    return 0;
}
