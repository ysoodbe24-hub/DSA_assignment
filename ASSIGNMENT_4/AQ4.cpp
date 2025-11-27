#include <bits/stdc++.h>
using namespace std;

int countUnable(vector<int> students, vector<int> sandwiches){
    queue<int> q;
    for(int x: students) q.push(x);
    int i=0, rotations=0, n=students.size();
    while(!q.empty() && i<sandwiches.size()){
        if(q.front()==sandwiches[i]){
            q.pop(); i++; rotations=0;
        }else{
            q.push(q.front()); q.pop();
            rotations++;
            if(rotations==q.size()) break;
        }
    }
    return q.size();
}

int main(){
    vector<int> students={1,1,0,0};
    vector<int> sandwiches={0,1,0,1};
    cout<<countUnable(students,sandwiches)<<'\n';
    return 0;
}
