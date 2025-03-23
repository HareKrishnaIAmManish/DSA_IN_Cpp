//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
class node{
    public:
   node* left;
   node* right;
   node(){
    this->left=this->right=nullptr;
   }
};
class Solution {
public:
    //compares incoming value with existing inserted data in trie
    int maxXorPair(node* head,int value){
       int curr_xor=0;
       node* curr=head;
       for(int i=31;i>=0;i--){
        //   int bit=(value>>i)&i;
        int bit=(value>>i)&1;
          if(bit==0){
            if(curr->right!=nullptr){
               curr=curr->right;  
               curr_xor +=(1<<i);
            }
          else{
                    curr=curr->left;
          }
       }
       else{
        if(curr->left!=nullptr){
            curr=curr->left;
            curr_xor+=(1<<i);
        }else{
            curr=curr->right;
        }
       }
    }
    return curr_xor;
}
void insert(node * head,int value){
    node * curr=head;
    for(int i=31;i>=0;i--){
        //int bit=(value>>i)&i;
        int bit=(value>>i)&1;
        if(bit==0){
            if(curr->left==nullptr){
                curr->left=new node();
            }
            curr=curr->left;
        } else{
            if(curr->right==nullptr){
                curr->right=new node();
            }
            curr=curr->right;
        }
    }
}
    int findMaximumXOR(vector<int>& nums) {
        node * head=new node();
        insert(head,nums[0]);
        int ans=INT_MIN;
      for(int i=0;i<nums.size();i++){
         ans=max(ans,maxXorPair(head,nums[i]));
         insert(head,nums[i]);
      }
      return ans;
    }
};