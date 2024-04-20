#include <bits/stdc++.h>
using namespace std;

map<long long, int> factors;

long long gcd(long long a, long long b) {
    return (b == 0) ? a : gcd(b, a % b);
}

long long pollards_rho(long long n) {
    if (n == 1) return 1;

    if (n % 2 == 0) return 2;

    long long x = rand() % (n - 2) + 2;
    long long y = x;
    long long c = rand() % (n - 1) + 1;
    long long d = 1;

    while (d == 1) {
        x = (x * x + c) % n;
        y = (y * y + c) % n;
        y = (y * y + c) % n;
        d = gcd(abs(x - y), n);
    }

    return d;
}

void efficientPrimeFactorization(long long n) {
    if (n <= 1) return;

    while (n > 1) {
        long long factor = pollards_rho(n);

        // Handle the prime factor
        while (n % factor == 0) {
            factors[factor]++;
            n /= factor;
        }
    }
}

int main() {
    long long num;
    cout << "Enter a number: ";
    cin >> num;

    // Clear the global factors map before each use
    //factors.clear();

    // Perform efficient prime factorization
    efficientPrimeFactorization(num);

    // Display the prime factors and their multiplicities
    cout << "Prime Factorization of " << num << ":\n";
    for (const auto& factor : factors) {
        cout << factor.first << "^" << factor.second << " ";
    }

    return 0;
}
