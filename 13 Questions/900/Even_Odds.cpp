#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
  FAST_IO;
  LL n,k;
  cin>>n>>k;

  LL evenCount=n / 2;
  LL oddCount=(n + 1) / 2;

   if (k <= oddCount) {
        // k-th odd number
        cout << 2 * k - 1 << endl;
    } else {
        // k-th even number
        k -= oddCount;
        cout << 2 * k << endl;
    }
  return 0;
}