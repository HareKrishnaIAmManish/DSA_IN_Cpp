/*
suppose i have an array now i want to find frequency of
an element in a particular range
leetcode 2080
https://leetcode.com/problems/range-frequency-queries/
*/
class RangeFreqQuery {
    public:
        vector<unordered_map<int,int>>st;
        int n;
        unordered_map<int,int>addMaps(unordered_map<int,int>&mp1,unordered_map<int,int>&mp2){
             unordered_map<int, int> merged = mp2;
            for (auto it : mp1) {
                merged[it.first] += it.second;
            }
            return merged;
        }
        void buildTree(vector<int>&arr,int i,int lo,int hi){
          if(lo==hi){
            int key=arr[lo],freq=1;
            st[i].insert({key,freq});
            return;
          }
          int mid=lo + (hi-lo)/2;
          buildTree(arr,2*i+1,lo,mid);
          buildTree(arr,2*i+2,mid+1,hi);
          st[i]=addMaps(st[2*i+1],st[2*i+2]);
        }
        RangeFreqQuery(vector<int>& arr) {
            n=arr.size();
            st.resize(4*n);
            buildTree(arr,0,0,n-1);
        }
        int getFreq(int i,int lo,int hi,int &l,int &r,int &value){
              if(l>hi or r<lo) return 0;
              if(lo>=l and hi<=r){
                return st[i][value];
              }
              int mid=lo+(hi-lo)/2;
              int leftAns=getFreq(2*i+1,lo,mid,l,r,value);
              int rightAns=getFreq(2*i+2,mid+1,hi,l,r,value);
              return leftAns+rightAns;
        }
        int query(int left, int right, int value) {
            return getFreq(0,0,n-1,left,right,value);
        }
    };
    
    /**
     * Your RangeFreqQuery object will be instantiated and called as such:
     * RangeFreqQuery* obj = new RangeFreqQuery(arr);
     * int param_1 = obj->query(left,right,value);
     */