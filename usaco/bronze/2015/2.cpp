#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>

int speedLimit[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    int segStart = 1;
    for (int i=0; i<N; i++) {
        int length, limit;
        cin >> length >> limit;

        for (int j=segStart; j<(segStart+length); j++) speedLimit[j] = limit;
        segStart += length;
    }

    int best = 0;

    int currPos = 1;
    for (int i=0; i<M; i++) {
        int length, speed;
        cin >> length >> speed;

        for (int j=currPos; j<(currPos+length); j++) best = max(best, speed-speedLimit[j]);
        currPos += length;
    }

    cout << best;
}