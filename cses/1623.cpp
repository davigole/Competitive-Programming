#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<ll>
#define	   uset	 unordered_set
#define	   pii	  pair<ll, ll>

vi P;
ll N;
ll best = -1;
ll total = 0;
ll currSum = 0;

void explore(ll i) {    
    if (i == N) {
        ll currDiff = abs(currSum - (total - currSum));
        best = (best == -1) ? currDiff : min(best, currDiff);
        return;
    }

    currSum += P[i];
    explore(i+1);
    currSum -= P[i];
    explore(i+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    P.resize(N);
    for (ll& i : P) {
        cin >> i;
        total += i;
    }

    explore(0);
    cout << best;
}