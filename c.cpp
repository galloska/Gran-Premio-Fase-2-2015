#include <bits/stdc++.h>
using namespace std;

int f[100];

int main() {
	int n, m, o;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == m) {
				printf("%d\n", n);
		} else {
			printf("%d\n", max(n, m));
		}
	}
	return 0;
}
