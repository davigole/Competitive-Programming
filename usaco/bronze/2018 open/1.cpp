#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>

char board[9];
int lines[8][3] {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    for (int i=0; i<9; i++) cin >> board[i];

    uset<int> indWins;
    set<pii> groupWins;
    for (int i=0; i<8; i++) {
        char first = board[lines[i][0]];
        char second = board[lines[i][1]];
        char third = board[lines[i][2]];

        if (third != first && third != second && second != first) continue; // every character is different
        
        if (first == second && second == third) indWins.insert(first); // individual wins
        else {
            char winner1 = first;
            char winner2 = (first == second) ? third : second;
            if (winner1 > winner2) swap(winner1, winner2);
            groupWins.insert(mp(winner1, winner2));
        }
    }

    cout << indWins.size() << '\n' << groupWins.size();
}