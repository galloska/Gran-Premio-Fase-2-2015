#include <bits/stdc++.h>
using namespace std;

typedef pair< int, int > pii;

string s;
int sp[2002];
pii dp[2002][2002];
bool v[2002][2002];


pii f(int i, int j) {
	if (i > j) {
		return pii(0, 0);
	}
	if (i == j) {
		return pii(sp[i], 1);
	}
	if (v[i][j])
		return dp[i][j];
	v[i][j] = true;
	dp[i][j] = max(f(i, j - 1), f(i + 1, j));
	if (s[i] == s[j]) {
		pii t = f(i + 1, j - 1);
		dp[i][j] = max(dp[i][j], pii(t.first + sp[i] + sp[j], t.second + 2));
	}
	return dp[i][j];
}

int main() {
	int i, j, n;
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while (cin >> s, !cin.fail()) {
		for (i = 0; i < s.size(); i++) {
			sp[i] = 0;
			for (j = 0; j < s.size(); j++) {
				v[j][i] = false;
			}
		}
		cin >> n;
		while (n--) {
			cin >> i;
			sp[i - 1] = 1;
		}
		cout << (f(0, s.size() - 1)).second << '\n';
	}
	cout.flush();
	return 0;
}
