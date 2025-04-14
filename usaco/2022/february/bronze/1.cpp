#include <bits/stdc++.h>
using namespace std;
 
#define	   ll	   long long
#define	   mp	   make_pair
#define	   pb	   push_back
#define	   vi	   vector<int>
#define	   uset	 unordered_set
#define	   pii	  pair<int, int>

int solve() {
    int N;
    cin >> N;

    vi a(N);

    int minTry = -1;
    int maxTry = 0;

    for (int& i : a) {
        cin >> i;
        minTry = (minTry == -1) ? i : max(minTry, i);
        maxTry += i;
    }

    for (int valTry=minTry; valTry<=maxTry; valTry++) {
        bool isAnswer = true;
        int oper = 0;

        for (int i=0; i<N; i++) {
            int sum = a[i];

            while (sum < valTry && i < N) {
                i++;
                oper++;
                sum += a[i];
            }

            if (sum != valTry) {
                isAnswer = false;
                break;
            }
        }

        if (isAnswer) return oper;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i=0; i<T; i++) cout << solve() << '\n';
}