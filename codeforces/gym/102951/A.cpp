#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>
 
const int MAXN = 5010;
int x[MAXN], y[MAXN];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    cin >> N;
 
    for (int i=0; i<N; i++) cin >> x[i];
    for (int i=0; i<N; i++) cin >> y[i];
 
    int best = 0;
 
    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {
            int deltaX = (x[i] - x[j]);
            int deltaY = (y[i] - y[j]);
 
            best = max(best, deltaX*deltaX + deltaY*deltaY);
        }
    }
 
    cout << best;
}