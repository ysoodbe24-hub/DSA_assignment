#include <bits/stdc++.h>
using namespace std;

int minIndex(queue<int>& q, int sorted){
    int n=q.size();
    int minVal=INT_MAX, idx=-1;
    for(int i=0;i<n;i++){
        int x=q.front(); q.pop();
        if(i<=n-sorted-1 && x<minVal){minVal=x; idx=i;}
        q.push(x);
    }
    return idx;
}

void insertMinToRear(queue<int>& q, int minIdx){
    int n=q.size();
    int minVal=0;
    for(int i=0;i<n;i++){
        int x=q.front(); q.pop();
        if(i==minIdx) minVal=x;
        else q.push(x);
    }
    q.push(minVal);
}

void sortQueue(queue<int>& q){
    for(int i=0;i<q.size();i++){
        int idx=minIndex(q,i);
        insertMinToRear(q,idx);
    }
}

int main(){
    queue<int> q;
    for(int x: {11,5,4,21}) q.push(x);
    sortQueue(q);
    while(!q.empty()){ cout<<q.front()<<(q.size()>1?' ':'\n'); q.pop(); }
    return 0;
}
