#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    vi cap(3);
    vi milk(3);

    for (int i=0; i<3; i++) cin >> cap[i] >> milk[i];

    for (int i=0; i<100; i++) {
        int from = (i%3);
        int to = ((from+1)%3);

        int poured = min(milk[from], cap[to]-milk[to]);
        milk[from] -= poured;
        milk[to] += poured;
    }

    for (int i=0; i<3; i++) cout << milk[i] << '\n';
}