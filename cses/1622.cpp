#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>
 
int finalSize;
int currCount[26];
int finalCount[26];
 
string currString = "";
vector<string> output;
 
void explore(int k) {
    if (k == finalSize) {
        output.pb(currString);
        return;
    }
 
    for (int i=0; i<26; i++) {
        if (currCount[i] == finalCount[i]) continue;
 
        currCount[i]++;
        currString.pb('a'+i);
        explore(k+1);
 
        currCount[i]--;
        currString.pop_back();
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string S;
    cin >> S;
 
    finalSize = S.size();
    for (char c : S) finalCount[c-'a']++;
 
    explore(0);
 
    cout << output.size() << '\n';
    for (string i : output) cout << i << '\n';
}