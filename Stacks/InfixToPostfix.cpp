#include<bits/stdc++.h>
using namespace std;

int precedence(char x){
   if(x == '+' || x == '-')
      return 1;
   if(x == '*' || x == '/')
      return 2;
   if(x == '^')
      return 3;
   return 0;
}
string toPostfix(string infix){
   stack<char> st;
   infix = '(' + infix + ')';
   string postfix = "";

   for(int i = 0; i < infix.length(); i++){
      if(infix[i] == '(')
         st.push(infix[i]);
      if((infix[i] >= 'a' && infix[i] <= 'z') ||(infix[i] >= 'A' && infix[i] <= 'Z'))
         postfix += infix[i];

      if(infix[i] == '+' || infix[i] == '-' ||infix[i] =='^' ||infix[i] =='*' || infix[i] == '/'){
         while(precedence(st.top()) >= precedence(infix[i])){
            postfix += st.top();
            st.pop();
         }
         st.push(infix[i]);
      }

      if(infix[i] == ')'){
         while(st.top() != '('){
            postfix += st.top();
            st.pop();
         }
         st.pop();
      }
   }

   return postfix;
}
int main(){
   string infix;
   cin >> infix;
   cout<<toPostfix(infix);
}
