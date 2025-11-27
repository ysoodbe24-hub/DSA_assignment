#include <iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> NextGreaterElement(vector<int> &arr){
    stack<int> st;
    vector<int> result;

    for(int i = arr.size() - 1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }

        if(st.empty()){
            result.push_back(-1);
        }
        else{
            result.push_back(st.top());
        }

        st.push(arr[i]);
    }

    return result;
}

int main(){

    vector<int> arr = {8, 10, 2, 5, 4};
    
    vector<int> ans = NextGreaterElement(arr);

    for(int i = ans.size() - 1; i >=0; i--){
        cout << ans[i] << " ";
    }
    
    return 0;
}