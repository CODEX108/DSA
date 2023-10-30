#include <iostream>
#include <vector>
using namespace std;

/*
This program demonstrates the use of vectors in C++.
Vectors are dynamic arrays that can resize themselves as elements are added or removed.
The capacity of a vector is the amount of memory allocated to it, which can be increased using the reserve() function.
*/
 int main()
{
    //Time compleity O(1)
vector<int> v;
//OR

vector <int> a(5,1); //size 5 initialise each block with 1
//copying the vector a into another vector
vector<int> last(a);
cout<<"print last"<<endl;
for(int i:last){
    cout<<i;
}cout<<endl;


cout<<"Capacity-> "<<v.capacity()<<endl;
v.push_back(1);
cout<<"Capacity-> "<<v.capacity()<<endl;
v.push_back(2);
cout<<"Capacity-> "<<v.capacity()<<endl;
v.push_back(3);
cout<<"Capacity-> "<<v.capacity()<<endl;
cout<<"size-> "<<v.size()<<endl;
cout<<"Element at 2nd index "<<v.at(2)<<endl;
cout<<"First Element "<<v.front()<<endl;
cout<<"Second element "<<v.back()<<endl;

cout<<"Before pop back"<<endl;
for(int i:v){
    cout<<i;
}cout<<endl;

v.pop_back();
cout<<"After pop back"<<endl;
for(int i:v){
    cout<<i;
}cout<<endl;

//when we perform clear operation the size fo the vector becomes 0 and not its capacity
cout<<"Clear operation: ";
v.clear();
cout<<"size-> "<<v.size()<<endl;
cout<<"Capacity-> "<<v.capacity()<<endl;
return 0;
}