#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    char ch;
    unordered_map<char,node*>children;
    bool terminal;
    node(char data){
       this->ch=data;
       this->terminal=false;
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
        }
        else{
            node * child=new node(currentChar);
            currentNode->children[currentChar]=child;
            currentNode=child;
        }
     }
     currentNode->makeTerminal();
    }
    bool search(string word){
       node* currentNode=root;
      for(int i=0;i<word.size();i++){
        if(currentNode->children.count(word[i])){
            currentNode=currentNode->children[word[i]];
        }
        else{
            return false;
        }
      }
      return currentNode->isTerminal();
    }
    bool IsThereAnyWordThatStartsWith(string word){
       node* currentNode=root;
       for(int i=0;i<word.size();i++){
        if(currentNode->children.count(word[i])){
            currentNode=currentNode->children[word[i]];
        }
        else{
            return false;
        }
      }
      return true;
    }
};
int main(){
trie trie1;
trie1.insert("ram");
trie1.insert("ravi");
trie1.insert("sita");
trie1.insert("laxman");
trie1.insert("balram");
cout<<"laxman present "<<trie1.search("laxman")<<endl;
cout<<"manish present "<<trie1.search("manish")<<endl;
cout<<"does any word start with sit "<<trie1.IsThereAnyWordThatStartsWith("sit")<<endl;
cout<<"does any word start with lux "<<trie1.IsThereAnyWordThatStartsWith("lux")<<endl;
return 0;
}