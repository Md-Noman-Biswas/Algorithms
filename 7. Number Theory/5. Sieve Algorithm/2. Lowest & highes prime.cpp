#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define ll long long

vector<bool> isPrime(N, 1);
vector<int> lp(N,0), hp(N,0);
vector<int> spf(N, 0);

void SPS(){
    for(int i = 2; i < N; i++){
        spf[i] = i;
    }

    for(int i = 2; i < N; i++){
        for(int j = i; j < N; j += i){
            spf[j] = min(spf[j], i);
        }
    }
}

/*
    how to use:(in main)
    while(num > 1){
        int prime_factor = spf[num];
        while(num % prime_factor == 0){
            allPrime_factors.push_back(prime_factor);
            num /= prime_factor;
        }
    }
*/

void prime_factors(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < N; i++){
        if(isPrime[i] == true){
            lp[i] = hp[i] = i;
            for(int j=2*i; j<N; j+=i){
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j] == 0){
                    lp[j] = i;
                }
            }
        }
    }
}

int main(){
    prime_factors();
    SPS();
    vector<int> allPrime_factors;
    int num;
    cin >> num;
    while(num > 1){
        int prime_factor = spf[num];
        while(num % prime_factor == 0){
            allPrime_factors.push_back(prime_factor);
            num /= prime_factor;
        }
    }
    for(auto it: allPrime_factors){
        cout << it << " ";
    }
    //cout << allPrime_factors[num-1] << "\n";

}


