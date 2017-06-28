#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 1087;
pii a[N];
int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].F >> a[i].S;
    if (a[i].F != a[i].S) {
      cout << "rated" << endl;
      return 0;
    }
  }
  bool ok = true;
  for (int i = 1; i < n && ok; ++i)
    ok = a[i-1].F >= a[i].F;
  cout << (ok ? "maybe" : "unrated") << endl;
}
