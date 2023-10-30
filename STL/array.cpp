#include <iostream>
#include<array>

using namespace std;
 int main()
{
    //Time compleity O(1)
array<int,4> a = {1,2,3,4};
cout<<a[0]<<endl;
cout<<"Element at 2nd index"<<a.at(2)<<endl;
cout<<"Is Empty"<<a.empty()<<endl;
cout<<"Front "<<a.front()<<endl;
cout<<"back "<<a.back()<<endl;

int size = a.size();
cout<<"Array size: "<<size<<endl;

for(int i=0;i<size;i++){
    cout<<a[i]<<endl;
}
return 0;
}