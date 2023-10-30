#include <iostream>
#include <set>
using namespace std;

int main()
{
    cout << "SETS" << endl;
    set <int> s;
    s.insert(2);
    s.insert(2);
    s.insert(2);

    for(int i=0;i<=5;i++){
        s.insert(i);
    }

    for(int i:s){
        cout<<i<<" ";
    }cout<<endl;


    set <int> :: iterator  it = s.begin();
    it++;
    s.erase(it);
    for(int i:s){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"is -5 present? -> "<<s.count(-5)<<endl;
    s.insert(10);
    s.insert(40);

//the find(),insert ,begin,count function has a time complexity of O(log n) rest have O(n)
//if the elem exists return its iterator
    set <int> :: iterator itr = s.find(5);
    //5 ke baad ke saare elments mil jayenge
   for(auto i = itr; i != s.end();i++){
    //we get the refernce of 5...
         cout<<*i<<" ";
   }cout<<endl;
    return 0;
}