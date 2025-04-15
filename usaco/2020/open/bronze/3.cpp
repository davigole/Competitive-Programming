#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>

int N, T;
bool sickAtEnd[102];
vector<pair<int, pii>> reg;

bool test(int p0, int K) {
    vi currShake(N+1);
    vector<bool> currSick(N+1);
    
    currSick[p0] = true;

    for (auto r : reg) {
        int a = r.second.first;
        int b = r.second.second;

        if (currSick[a]) currShake[a]++;
        if (currSick[b]) currShake[b]++;

        if (currSick[a] && currShake[a] <= K) {
            currSick[b] = true;
        } else if (currSick[b] && currShake[b] <= K) {
            currSick[a] = true;
        }
    }

    for (int i=1; i<=N; i++) {
        if (currSick[i] != sickAtEnd[i]) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    cin >> N >> T;
    reg.resize(T);

    for (int i=1; i<=N; i++) {
        char c;
        cin >> c;
        sickAtEnd[i] = (c=='1');
    }
    for (auto& r : reg) {
        cin >> r.first >> r.second.first >> r.second.second;
    }
    sort(reg.begin(), reg.end());

    // here -1 represents infinity
    int x = 0; // number of possible p0's
    int y = -1; // min K
    int z = 0; // max K

    for (int p0=1; p0<=N; p0++) {
        bool canBe = false;

        for (int K=0; K<=(int)reg.size(); K++) {
            if (!test(p0, K)) continue;

            canBe = true;

            y = (y == -1) ? K : min(y, K);

            if (z != -1) {
                if (K == (int)reg.size()) z = -1;
                else z = max(z, K);
            }
        }

        if (canBe) x++;
    }

    cout << x << ' ' << y << ' ';
    
    if (z == -1) cout << "Infinity";
    else cout << z;
}