#include <bits/stdc++.h>
using namespace std;

// Macros for convenience
#define LL long long
#define ULL unsigned long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// Constants
const LL MOD = 1e9 + 7;
const LL INF = 1e18;
const LD EPS = 1e-9;

// Utility Functions
LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

LL modAdd(LL a, LL b, LL m = MOD) {
    return ((a % m + b % m) % m + m) % m;
}

LL modSub(LL a, LL b, LL m = MOD) {
    return ((a % m - b % m) % m + m) % m;
}

LL modMul(LL a, LL b, LL m = MOD) {
    return ((a % m) * (b % m)) % m;
}

LL modPow(LL a, LL b, LL m = MOD) {
    LL res = 1;
    while (b > 0) {
        if (b & 1) res = modMul(res, a, m);
        a = modMul(a, a, m);
        b >>= 1;
    }
    return res;
}

LL modInv(LL a, LL m = MOD) {
    return modPow(a, m - 2, m); // m must be prime
}


bool canMakeThreeDistinctSums(vector<int>& a, vector<int>& b) {
    int n = a.size();
    
    set<int> sums;
    for (int i = 0; i < n; i++) {
        sums.insert(a[i] + b[i]);
    }

    if (sums.size() >= 3) return true;

   
    sort(a.begin(), a.end()); 

           set<int> new_sums;
            for (int j = 0; j < n; j++) {
                new_sums.insert(a[j] + b[j]);
            }

            if (new_sums.size() >= 3) return true;

    
    int i=0, j=n-1; 
    while (i < j) {
        swap(a[i], a[j]);
          set<int> new_sums;
            for (int j = 0; j < n; j++) {
                new_sums.insert(a[j] + b[j]);
            }

            if (new_sums.size() >= 3) return true;
        i++;
        j--;
    }

    return false;
}

// Main Function Template
int main() {
    FAST_IO;

    int t;
    cin >> t; // Input number of test cases
    while (t--) {
       int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    if (canMakeThreeDistinctSums(a, b))
        cout << "YES\n";
    else
        cout << "NO\n";
    }

    return 0;
}