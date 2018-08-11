#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long LL;

const LL maxn = 1000 + 10;
LL n , m , h , a[maxn] , sum = 0 , sum1;
ld ans = 1;

int main(){
  cin >> n >> m >> h;
  h--;
  for(LL i = 0 ; i < m ; i++){
    cin >> a[i];
    sum += a[i];
  }
  a[h]--;
  sum--;
  n--;
  sum -= a[h];
  sum1 = sum + a[h];
  for(LL i = 0 ; i < n ; i++){
    if(sum1 - i == 0){
      cout << -1 << endl;
      return 0;
    }
    ans *= ld(sum - i) / ld(sum1 - i);
  }
  ans = 1.0 - ans;
  cout.precision(6);
  cout << fixed;
  cout << ans << endl;
  return 0;
}