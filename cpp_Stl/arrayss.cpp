#include<bits/stdc++.h>
using namespace std;
int main(){
int arr[8]={1,5,4,6,69,7,5,7};
int n=8;
// cout<<arr<<endl;
// cout<<arr+n<<endl;
// cout<<*arr<<endl;
sort(arr,arr+n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
reverse(arr,arr+n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
reverse(arr,arr+n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
int lb_index=lower_bound(arr,arr+n,6)-arr;
int ub_index=upper_bound(arr,arr+n,6)-arr;
cout<<"the indices of the lower and upperbounds are "<<lb_index<<" and "<<ub_index;
cout<<"the elements of the lower and upperbounds are "<<arr[lb_index]<<" and "<<arr[ub_index];
return 0;
}