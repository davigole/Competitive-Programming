#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>

int output[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        string left, right;
        cin >> left >> right;
        
        int leftCount[26]{0};
        int rightCount[26]{0};
        
        for (const char c : left) leftCount[c-'a']++;
        for (const char c : right) rightCount[c-'a']++;

        for (int j=0; j<26; j++) output[j] += max(leftCount[j], rightCount[j]);
    }

    for (int i=0; i<26; i++) cout << output[i] << '\n';
}