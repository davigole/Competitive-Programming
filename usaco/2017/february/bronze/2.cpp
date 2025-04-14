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

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string S;
    cin >> S;

    int out = 0;
    uset<int> explored;

    for (int i=0; i<52; i++) {
        char c = S[i];
        if (explored.count(c)) continue;
        explored.insert(c);

        int counted[26]{0};
        for (int j=(i+1); S[j]!=c; j++) {
            if (explored.count(S[j])) continue;
            counted[S[j]-'A']++;
        }

        for (int j=0; j<26; j++) {
            if (counted[j] == 1) out++;
        }
    }

    cout << out;
}