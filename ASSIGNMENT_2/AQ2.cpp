#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    
    for (char c : s) {
        freq[c - 'a']++;
        if (freq[c - 'a'] >= 2) {
            cout << "YES";
            return 0;
        }
    }
    
    cout << "NO";
    return 0;
}
