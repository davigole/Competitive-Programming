#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>

int output = 0;

bool col[8];
bool diagTopRight[15];
bool diagBottomLeft[15];
bool reserved[8][8]; // [x][y]

void explore(int y) {
    if (y == 8) {
        output++;
        return;
    }

    for (int x=0; x<8; x++) {
        if (reserved[x][y] || col[x] || diagTopRight[x+y] || diagBottomLeft[y-x+7]) continue;

        col[x] = diagTopRight[x+y] = diagBottomLeft[y-x+7] = 1;
        explore(y+1);
        col[x] = diagTopRight[x+y] = diagBottomLeft[y-x+7] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int y=0; y<8; y++) {
        for (int x=0; x<8; x++) {
            char c;
            cin >> c;
            reserved[x][y] = (c == '*');
        }
    }

    explore(0);
    cout << output;
}