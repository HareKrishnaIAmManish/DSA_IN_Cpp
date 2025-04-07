//The mutable case
class NumArray {
    public:
        vector<int>st;
        int n;
        void buildTree(int i,int l,int r,vector<int>&st,vector<int>& nums){
            if(l==r){
                st[i]=nums[l];
                return;
            }
            int mid= l+ (r-l)/2;
            buildTree(2*i+1,l,mid,st,nums);
            buildTree(2*i+2,mid+1,r,st,nums);
            st[i]=st[2*i+1]+st[2*i+2];
        }
        NumArray(vector<int>& nums) {
            n=nums.size();
            st.resize(4*n);
             buildTree(0,0,n-1,st,nums);
        }
        void updateVal(int i,int lo,int hi,int &index,int &val){
            if(lo==hi){
                st[i]=val;
                return;
            }
            int mid=lo+(hi-lo)/2;
            if(index<=mid){updateVal(2*i+1,lo,mid,index,val);}
            else{updateVal(2*i+2,mid+1,hi,index,val);}
            st[i]=st[2*i+1]+st[2*i+2];
        }
        void update(int index, int val) {
            updateVal(0,0,n-1,index,val);
        }
        int getSum(int i,int lo,int hi,int &l,int &r){
          if(l>hi or r<lo){return 0;}
          if(lo>=l && hi<=r) return st[i];
          int mid=lo+(hi-lo)/2;
          int leftSum=getSum(2*i+1,lo,mid,l,r);
          int rightSum=getSum(2*i+2,mid+1,hi,l,r);
          return leftSum+rightSum;
        }
        int sumRange(int left, int right) {
            return getSum(0,0,n-1,left,right);
        }
    };
    
    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray* obj = new NumArray(nums);
     * obj->update(index,val);
     * int param_2 = obj->sumRange(left,right);
     */ 