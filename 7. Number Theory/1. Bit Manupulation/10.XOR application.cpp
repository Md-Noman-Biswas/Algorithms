/*
given array a of n integers. All integers are present in even count except one.
Find that one integer which has odd count in 0(n) TC and 0(1) space
n < 10^5
a[i] < 10^5
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> arr;
        ans ^= arr;
    }
    cout << ans << "\n";
}