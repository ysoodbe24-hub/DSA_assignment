#include<iostream>
#include<string>
using namespace std;
 class Mystack{
    int top;
    char arr[100];
    public:
Mystack(){
top=-1;
}

void push(char val){
 if(top>=99){
    cout<<"stack is full"<<endl;
    return;
 }
 top++;
 arr[top]=val;
}
char pop(){
if(empty()){
    cout<<"stack empty"<<endl;
}
return arr[top--];

}

  

bool empty(){
    return top<0;
}


 };
int main(){
    Mystack s;
    string str="DataStructure";

    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }

while(!s.empty()){
    cout<<s.pop();
}
cout<<endl;
    return 0;
}