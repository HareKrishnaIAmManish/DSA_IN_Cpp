#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    char ch;
    unordered_map<char,node*>children;
    bool terminal;
    int countWordsendingHere;
    int countWordsStartingFromHere;
    node(char data){
       this->ch=data;
       this->terminal=false;
       this->countWordsendingHere=0;
       this->countWordsStartingFromHere=0;
    }
    void makeTerminal(){
        this->terminal=true;
    }
    bool isTerminal(){
        return this->terminal==true;
    }
};
class trie{
    public:
    node* root;
    trie(){
        root=new node('\0');
    }
    void insert(string word){
        node *currentNode=root;
     for(int i=0;i<word.size();i++){
        char currentChar=word[i];
        if(currentNode->children.count(currentChar)){
           currentNode=currentNode->children[currentChar];
           currentNode->countWordsStartingFromHere++;
        }
        else{
            node * child=new node(currentChar);
            currentNode->children[currentChar]=child;
            currentNode=child;
            currentNode->countWordsStartingFromHere++;
        }
     }
     currentNode->makeTerminal();
     currentNode->countWordsendingHere++;
    }
    // bool search(string word){
    //    node* currentNode=root;
    //   for(int i=0;i<word.size();i++){
    //     if(currentNode->children.count(word[i])){
    //         currentNode=currentNode->children[word[i]];
    //     }
    //     else{
    //         return false;
    //     }
    //   }
    //   return currentNode->isTerminal();
    // }
    // bool IsThereAnyWordThatStartsWith(string word){
    //    node* currentNode=root;
    //    for(int i=0;i<word.size();i++){
    //     if(currentNode->children.count(word[i])){
    //         currentNode=currentNode->children[word[i]];
    //     }
    //     else{
    //         return false;
    //     }
    //   }
    //   return true;
    // }
    int countWordsEqualTo(string word){
      node* currentNode=root;
      for(int i=0;i<word.size();i++){
        char ch=word[i];
        if(currentNode->children.count(ch)){
          currentNode=currentNode->children[ch];
        }
        else{
            return 0;
        }
      }
     return currentNode->countWordsendingHere;
    }
    int countWordsStartingWith(string prefix){
        node* currentNode=root;
        for(int i=0;i<prefix.size();i++){
           if(currentNode->children.count(prefix[i])){
            currentNode=currentNode->children[prefix[i]];  
           }
           else{
            return 0;
           }
        } 
        return currentNode->countWordsStartingFromHere;
    }
    void erase(string word){
        node* currentNode=root;
        for(int i=0;i<word.size();i++){  
            currentNode=currentNode->children[word[i]];
            currentNode->countWordsStartingFromHere--;
        }
          currentNode->countWordsendingHere--;
        } 
};
int main(){
trie trie1;
trie1.insert("ram");
trie1.insert("ravi");
trie1.insert("sita");
trie1.insert("laxman");
trie1.insert("balram");
trie1.insert("ram");
trie1.insert("ra");
trie1.insert("ravi");
// cout<<"laxman present "<<trie1.search("laxman")<<endl;
// cout<<"manish present "<<trie1.search("manish")<<endl;
// cout<<"does any word start with sit "<<trie1.IsThereAnyWordThatStartsWith("sit")<<endl;
// cout<<"does any word start with lux "<<trie1.IsThereAnyWordThatStartsWith("lux")<<endl;
cout<<trie1.countWordsEqualTo("ram")<<endl;
cout<<trie1.countWordsStartingWith("ra")<<endl;
trie1.erase("ra");
cout<<trie1.countWordsEqualTo("ram")<<endl;
cout<<trie1.countWordsStartingWith("ra")<<endl;
return 0;
}