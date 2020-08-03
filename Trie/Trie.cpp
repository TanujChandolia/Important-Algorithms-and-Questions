#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
   TrieNode* child[26];
   bool isEnd;
   TrieNode(){
      isEnd = false;
      for(int i = 0; i < 26; i++)
         child[i] = NULL;
   }
};

void insertTrie(string x,TrieNode* root){
   TrieNode* temp = root;
   for(int i = 0; i < x.length(); i++){
      int key = x[i]-'a';
      if(!temp -> child[key]){
         temp -> child[key] = new TrieNode();
      }
      temp = temp -> child[key];
   }
   temp -> isEnd = true;
   cout<<"Inserted "<<x<<"\n";
}

bool searchTrie(string x, TrieNode* root){
   TrieNode* curr = root;
   for(int i = 0; i < x.length(); i++){
      int key = x[i]-'a';
      if(!curr -> child[key])
         return false;
      curr = curr -> child[key];
   }
   return curr -> isEnd;
}
bool isEmpty(TrieNode* root){
   for(int i = 0; i < 26; i++){
      if(root -> child[i])
         return false;
   }
   return true;
}
TrieNode* deleteTrie(TrieNode* root, string x, int i){
   if(!root) return nullptr;

   if(i == x.length()){
      root ->isEnd = false;
      if(isEmpty(root)){
         delete(root);
         root = nullptr;
      }
      return root;
   }

   int key = x[i] - 'a';
   root ->child[key] = deleteTrie(root -> child[key],x,i+1);

   if(isEmpty(root) && root -> isEnd == false){
      delete(root);
      root = nullptr;
   }
   return root;
}
void printTrie(TrieNode* root){
   queue<TrieNode*> q;
   q.push(root);

   while(!q.empty()){
      root = q.front();
      q.pop();
      for(int i = 0; i < 26; i++){
         cout<<root -> child[i]<<" ";
         if(root -> child[i])
            q.push(root -> child[i]);
      }
      cout<<"\n";
   }
}
int main(){
   TrieNode* root = new TrieNode();

   vector<string> dict = {"hello","help","hell","geeks","geek","cat","cut"};
   for(int i = 0; i < dict.size(); i++){
      insertTrie(dict[i], root);
   }

   //printTrie(root);

   for(int i = 0; i < 3; i++){
      string s;
      cin >> s;
      if(searchTrie(s,root))
         cout<<"Found\n";
      else
         cout<<"Not Found\n";
   }

   deleteTrie(root, "geek", 0);
   if(searchTrie("geek",root))
      cout<<"Found";
   else
      cout<<"Not found";
   return 0;
}
