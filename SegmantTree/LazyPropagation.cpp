#include<bits/stdc++.h>
using namespace std;
vector<int>st;
vector<int>lazy;
int getSum(int i,int lo,int hi,int l,int r){
    //check for pending lazy updates
    if(lazy[i]!=0){
     int rangeSize=hi-lo+1;
     st[i]+=rangeSize*lazy[i];
     if(lo!=hi){
        //make sure its not the leaf
        //send lazy to left and right child
        lazy[2*i+1]+=lazy[i];
        lazy[2*i+2]+=lazy[i];
     }  
     lazy[i]=0; 
    }
    //range exactly same 
    if(lo>=l and hi<=r){
    return st[i];
  }
  //outside case
  if(l>hi or r<lo){
    return 0;
  }
  //overlapping or completeley inside case
  int mid=lo+((hi-lo)/2);
  int left=getSum(2*i+1,lo,mid,l,r);
  int right=getSum(2*i+2,mid+1,hi,l,r);
  return left+right;
}
void buildTree(int arr[],int i,int lo,int hi){
    if(lo==hi){
        st[i]=arr[lo];
        return;
    }
    int mid =lo +((hi-lo)/2);
    buildTree(arr,2*i+1,lo,mid);
    buildTree(arr,2*i+2,mid+1,hi); 
    st[i]=st[2*i+1]+st[2*i+2];
}
void updateRange(int i,int lo,int hi,int l,int r,int val){
//check for pending lazy updates
if(lazy[i]!=0){
    int rangeSize=hi-lo+1;
    st[i]+=rangeSize*lazy[i];
    if(lo!=hi){
       //make sure its not the leaf
       //send lazy to left and right child
       lazy[2*i+1]+=lazy[i];
       lazy[2*i+2]+=lazy[i];
    }  
    lazy[i]=0; 
   }
   if(lo>=l and hi<=r){//update entire low to high [lo,hi]
    int rangeSize=hi-lo+1;
    st[i]+=rangeSize*val;
    if(lo!=hi){
        //make sure its not the leaf
        //send lazy to left and right child
        lazy[2*i+1]+=val;
        lazy[2*i+2]+=val;
     } 
     return;
  }
  //outside case
  if(l>hi or r<lo){
    return;
  }
  int mid=lo+((hi-lo)/2);
  updateRange(2*i+1,lo,mid,l,r,val);
  updateRange(2*i+2,mid+1,hi,l,r,val);
  st[i]=st[2*i+1]+st[2*i+2];
}
int main(){
    int arr[]={1,4,2,8,6,4,9,3};
    int n=sizeof(arr)/4;
    st.resize(4*n);
    lazy.resize(4*n,0);
    buildTree(arr,0,0,n-1);
    for(auto it:st){
        cout<<it<<" ";
    }
    cout<<endl;
  int l,r;
  cout<<"tell l and r"<<endl;
  cin>>l>>r;
  cout<<getSum(0,0,n-1,l,r)<<endl;
  updateRange(0,0,n-1,2,5,10); 
  cout<<getSum(0,0,n-1,l,r)<<endl;
  return 0;
}
