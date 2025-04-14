#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>

int N, B;
vi x;
vi y;
vector<pii> cows;

int calc(int a, int b) {
    int r1 = 0;
    int r2 = 0;
    int r3 = 0;
    int r4 = 0;

    for (pii pos : cows) {
        if (pos.first > a && pos.second > b) r1++;
        else if (pos.first < a && pos.second > b) r2++;
        else if (pos.first < a && pos.second < b) r3++;
        else if (pos.first > a && pos.second < b) r4++;
    }

    return max(r1, max(r2, max(r3, r4)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    cin >> N >> B;
    x.resize(N);
    y.resize(N);
    cows.resize(N);
    
    for (int i=0; i<N; i++) {
        cin >> cows[i].first >> cows[i].second;
        x[i] = cows[i].first - 1;
        y[i] = cows[i].second - 1;
    }

    int best = N;

    for (int a : x) {
        for (int b : y) {
            best = min(best, calc(a, b));
        }
    }

    cout << best;
}