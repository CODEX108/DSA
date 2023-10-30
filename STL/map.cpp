#include <iostream>
#include <map>
using namespace std;

//Time complexity for O(log n) for sorted maps
int main()
{
    map <int,string> m;
    m[3] = "The Code Segment";
    m[1] = "Manjiri";
    m[2] = "Codex108";
    m.insert({5,"Mj8"});
    for(auto i:m){
        cout<<i.first<<" ";
    }cout << endl;

    cout<<"Finding 3 => "<<m.count(3);
    cout<<"before erase"<<endl;
    for(auto i:m){
        cout<<i.first<<" ";
    }cout << endl;
    cout<<"After erase"<<endl;
    m.erase(3);
    for(auto i:m){
        cout<<i.first<<" ";
    }cout << endl;

    auto it = m.begin();
    if(it!=m.end()){
        cout<<"Found "<<(*it).first<<" "<<(*it).second<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    return 0;
}