#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>


int out = 0;
vi currQueens;

bool reserved[64]; // (y, x)

bool isAttacked(int pos) {
    for (int queen : currQueens) {
        if ((queen % 8) == (pos % 8)) return true; // vertical line
        else if (queen/8 == pos/8) return true; // horizontal line
        else if (abs(queen/8 - pos/8) == abs((queen % 8) - (pos % 8))) return true; // diagonal line
    }

    return false;
}

void explore(int k, int last=-1) {
    if (k == 8) {
        out++;
        return;
    }

    for (int i=(last+1); i<64; i++) {
        if (reserved[i]) continue;
        if (!isAttacked(i)) {
            currQueens.pb(i);

            explore(k+1, i);
            currQueens.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int y=0; y<8; y++) {
        for (int x=0; x<8; x++) {
            char c;
            cin >> c;
            reserved[8*y + x] = (c == '*');
        }
    }

    explore(0);
    cout << out;
}