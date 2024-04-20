// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i = 1; i <= n; i++){
//         cin >> arr[i];
//     }
//     int q;
//     cin >> q;
//     vector<pair<int, int>> Q[n];
//     for(int i = 1; i <= q; i++){
//         int l, r;
//         cin >> l >> r;
//         Q[r].push_back({l, i});
//     }
//     map<int, int> last_id;
//     for(int  i = 1; i <= n; i++) {
//         if(last_id.find(arr[i]) == last_id.end()) {
//             upd(i, 1);
//         }else{
//             upd(last_id[arr[i]], -1);
//             upd(i, 1);
//         }
//         last_id[arr[i]] = i;
//         for(auto x: Q[i]) {
//             int l = x.first, id = x.second;
//             ans[id] = query(l, i);
//         }
//     }
//     for(int i = 1; i <= 1; i++){
//         cout << ans[i] << "\n";
//     }
// }