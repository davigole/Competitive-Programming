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

    vector<string> spottyGenome(N), plainGenome(N);

    for (string& s : spottyGenome) cin >> s;
    for (string& p : plainGenome) cin >> p;

    int out = 0;
    for (int i=0; i<M; i++) {
        for (int j=(i+1); j<M; j++) {
            for (int k=(j+1); k<M; k++) {
                bool isAnswer = true;

                for (int spottyCow=0; spottyCow<N; spottyCow++) {
                    for (int plainCow=0; plainCow<N; plainCow++) {
                        if (spottyGenome[spottyCow][i] == plainGenome[plainCow][i] && spottyGenome[spottyCow][j] == plainGenome[plainCow][j] && spottyGenome[spottyCow][k] == plainGenome[plainCow][k]) {
                            isAnswer = false;
                            break;
                        }
                    }

                    if (!isAnswer) break;
                }

                if (isAnswer) out++;
            }
        }
    }

    cout << out;
}