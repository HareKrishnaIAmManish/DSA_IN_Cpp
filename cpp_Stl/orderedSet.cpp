#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int>ost;
    ost.insert(55);
    ost.insert(45);
    ost.insert(5);
    ost.insert(8);
    ost.insert(4);
    ost.insert(1);
    ost.insert(7);
    ost.insert(44);
    int n=ost.size();
    cout<<"size is"<<n<<endl;
    auto lb=ost.lower_bound(7);
    auto ub=ost.upper_bound(7);
    cout<<"lower bound is"<<*lb<<" "<<"upper bound is"<<*ub<<endl;
    ost.erase(7);
     lb=ost.lower_bound(7);
     ub=ost.upper_bound(7);
    cout<<"lower bound is"<<*lb<<" "<<"upper bound is"<<*ub;
    return 0;
}