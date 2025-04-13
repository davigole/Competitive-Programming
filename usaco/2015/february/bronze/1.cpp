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

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string S, T;
    cin >> S >> T;

    for (int i=0; i<=(int)(S.size()-T.size()); i++) {
        if (S.substr(i, T.size()) == T) {
            S.erase(S.begin() + i, S.begin() + i + T.size());
            i = max(i-(int)T.size(), 0);
        }
    }

    cout << S;
}