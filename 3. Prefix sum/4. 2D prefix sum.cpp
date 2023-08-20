#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int arr[N][N];
long long pref[N][N];//already initialised by 0
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            pref[i][j] = arr[i][j] + pref[i-1][j] + pref[i][j-1] -pref[i-1][j-1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << pref[c][d] - pref[a-1][d] - pref[c][b-1] + pref[a-1][b-1] << "\n";
    }
}
// /*
// 1. first row er prefix sum ber kora
// 2. first column er prefix sum ber kora
// 3. prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] + arr[i][j] - prefix[i-1][j-1];
// */
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int m; 
//     cin >> m;
//     int arr[n][m];
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cin >> arr[i][j];
//         }
//     }
//     int pre[n][m];
//     pre[0][0] = arr[0][0];
//     for(int i=1; i<m; i++) pre[0][i] = pre[0][i-1] + arr[0][i];
//     for(int j=1; j<n; j++) pre[j][0] = pre[j-1][0] + arr[j][0];
//     for(int i=1; i<n; i++){
//         for(int j=1; j<m; j++){
//             pre[i][j] = pre[i][j-1] + pre[i-1][j] + arr[i][j] - pre[i-1][j-1];
//         }
//     }
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cout << pre[i][j] << " ";
//         }
//         cout << "\n";
//     }
//     cout << "\n";
// }