#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    //vector<int> prime_factors;
    unordered_map<int, int> prime_factors;//O(1)
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            //prime_factors.push_back(i);
            prime_factors[i]++;
            n /= i;
        }
    }
    if(n > 1){
        //prime_factors.push_back(n);
        prime_factors[n]++;
    }
    for(auto factor: prime_factors){
        cout << factor.first << "^" << factor.second << " ";
    }
}