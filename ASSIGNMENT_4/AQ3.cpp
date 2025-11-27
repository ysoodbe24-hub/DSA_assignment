#include <bits/stdc++.h>
using namespace std;

bool canBeSorted(queue<int> q){
    stack<int> st;
    int n=q.size(), need=1;
    while(!q.empty()){
        if(q.front()==need){ q.pop(); need++; }
        else if(!st.empty() && st.top()==need){ st.pop(); need++; }
        else{ st.push(q.front()); q.pop(); }
    }
    while(!st.empty() && st.top()==need){ st.pop(); need++; }
    return need==n+1;
}

int main(){
    queue<int> q;
    for(int x: {5,1,2,3,4}) q.push(x);
    cout<<(canBeSorted(q)?"Yes":"No")<<'\n';
    return 0;
}
