/*
suppose i have an array 
array is ->      {1,4,2,8,6,4,9,3}
its indices are->{0,1,2,3,4,5,6,7}
i want max element in a particular range this would have worst case complexity of O(n)
and suppose i have multiple queries then it would be O(nq)
what segment tree does is makes it into O(qlogn)
14:25
Implementation->57:35
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>st;
int getMax(int i,int lo,int hi,int l,int r){
    //range exactly same 
    if(lo>=l and hi<=r){
    return st[i];
  }
  //outside case
  if(l>hi or r<lo){
    return INT_MIN;
  }
  //overlapping or completeley inside case
  int mid=lo+((hi-lo)/2);
  int left=getMax(2*i+1,lo,mid,l,r);
  int right=getMax(2*i+2,mid+1,hi,l,r);
  return max(left,right);
}
void buildTree(int arr[],int i,int lo,int hi){
    if(lo==hi){
        st[i]=arr[lo];
        return;
    }
    int mid =lo +((hi-lo)/2);
    buildTree(arr,2*i+1,lo,mid);
    buildTree(arr,2*i+2,mid+1,hi); 
    st[i]=max(st[2*i+1],st[2*i+2]);
}
int main(){
    int arr[]={1,4,2,8,6,4,9,3};
    int n=sizeof(arr)/4;
    st.resize(4*n);
    buildTree(arr,0,0,n-1);
    for(auto it:st){
        cout<<it<<" ";
    }
    cout<<endl;
    int l,r;
    cout<<"tell l and r"<<endl;
    cin>>l>>r;
    //1:1:53
    cout<<getMax(0,0,n-1,l,r)<<endl;
    return 0;
}
//done 
//Note that this is unmutable
//1:17:10
