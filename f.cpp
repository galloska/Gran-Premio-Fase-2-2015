#include <bits/stdc++.h>

int f[100];

int main() {
	int n;
	int k;
	int m;
	f[0] = 1;
	for (int i = 1; i < 100; i++) {
		f[i] = i * f[i - 1];
		if(f[i]>100000)	break;
	}
	while (scanf("%d", &n) != EOF) {
		int pos = 8,cont = 0;
		while(n>0){

			while(n>=f[pos]){
				n-=f[pos],cont++;
			}

			pos--;
		}
		printf("%d\n",cont);
	}
	return 0;
}
