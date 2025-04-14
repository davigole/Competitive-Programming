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

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<vi> spotty(M);
    vector<uset<char>> plain(M);


    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char c; cin >> c;
            spotty[j].pb(c);
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char c; cin >> c;
            plain[j].insert(c);
        }
    }

    int out = 0;
    for (int i=0; i<M; i++) {
        bool isAnswer = true;

        for (char c : spotty[i]) {
            if (plain[i].count(c)) {
                isAnswer = false;
                break;
            }
        }

        if (isAnswer) out++;
    }

    cout << out;
}