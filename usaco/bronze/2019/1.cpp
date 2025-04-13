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

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int N;
    cin >> N;

    vector<pair<pii, int>> swaps(N);
    for (auto& s : swaps) cin >> s.first.first >> s.first.second >> s.second;

    int best = 0;

    for (int pos=1; pos<=3; pos++) {
        int curr = pos;
        int score = 0;

        for (auto& s : swaps) {
            if (curr == s.first.first) curr = s.first.second;
            else if (curr == s.first.second) curr = s.first.first;

            if (s.second == curr) score++;
        }

        best = max(score, best);
    }
    
    cout << best;
}