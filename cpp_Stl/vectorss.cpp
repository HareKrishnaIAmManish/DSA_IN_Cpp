#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int>vec;
vec.push_back(6);
vec.push_back(2);
vec.push_back(3);
vec.push_back(1);
vec.push_back(4);
vec.push_back(7);
vec.push_back(5);
int n=vec.size();
sort(vec.begin(),vec.end());
for(int i=0;i<n;i++){
  cout<<vec[i]<<" ";
}
cout<<endl;
reverse(vec.begin(),vec.end());
for(int i=0;i<n;i++){
    cout<<vec[i]<<" ";
  }
cout<<endl;
reverse(vec.begin(),vec.end());
for(int i=0;i<n;i++){
    cout<<vec[i]<<" ";
  }
cout<<endl;
int lb=*lower_bound(vec.begin(),vec.end(),5);
int ub=*upper_bound(vec.begin(),vec.end(),5);
cout<<"lower and upper bounds of 5 are "<<lb<<" "<<ub<<" "<<endl;
return 0;
}