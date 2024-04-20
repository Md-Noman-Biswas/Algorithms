#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"

bool isValid(string s) {
    stack<char> st;
    map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' ||  s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else if(st.empty() || mp[s[i]] != st.top()){
            return false;
        }else{
            st.pop();
        }
    }
    return st.empty();
}


void solve(){
    string s;
    cin >> s;
    if(isValid(s)){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}