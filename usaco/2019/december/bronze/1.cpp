#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>

const int MAXN = 21;
bool consistent[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int K, N;
    cin >> K >> N;

    set<pii> consistent, inconsistent;

    for (int i=0; i<K; i++) {
        vi ranking(N);
        for (int& cow : ranking) cin >> cow;

        for (int j=0; j<N; j++) {
            for (int k=(j+1); k<N; k++) {
                pii correct = mp(ranking[j], ranking[k]);
                pii incorrect = mp(ranking[k], ranking[j]);

                if (consistent.count(incorrect)) { // pair is not consistent
                    consistent.erase(incorrect);
                    inconsistent.insert(correct);
                    inconsistent.insert(incorrect);
                } else if (inconsistent.count(correct) == 0) {
                    consistent.insert(correct);
                }
            }
        }
    }

    cout << consistent.size();
}