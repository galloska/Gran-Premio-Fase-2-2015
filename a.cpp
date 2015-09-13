#include <bits/stdc++.h>
using namespace std;

#define cost first
#define node second
#define prime(i) (n + i)

typedef pair< int, int > pii;

list< pii > al[20002];
int mc[20002];

int main() {
	int n, m, a, b, c;
	priority_queue< pii, vector< pii >, greater< pii > > pq;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= 2 * n; i++) {
			al[i].clear();
		}
		fill_n(mc + 1, n * 2, 1 << 30);
		while (m--) {
			scanf("%d%d%d", &a, &b, &c);
			al[a].push_back(pii(c, prime(b)));
			al[b].push_back(pii(c, prime(a)));
			al[prime(a)].push_back(pii(c, b));
			al[prime(b)].push_back(pii(c, a));
		}
		pq.push(pii(0, 1));
		mc[1] = 0;
		while (!pq.empty()) {
			pii u = pq.top();
			pq.pop();
			if (u.cost != mc[u.node]) {
				continue;
			}
			//printf("%d %d\n", u.node, u.cost);
			for (pii v : al[u.node]) {
				//printf("try %d %d\n", v.node, mc[v.node]);
				if (u.cost + v.cost < mc[v.node]) {
					mc[v.node] = mc[u.node] + v.cost;
					pq.push(pii(mc[v.node], v.node));
					//printf("enter %d %d\n", v.node, mc[v.node]);
				}
			}
		}
		printf("%d\n", mc[n] == 1 << 30 ? -1 : mc[n]);
	}
	return 0;
}
