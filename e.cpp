#include <bits/stdc++.h>

using namespace std;

unsigned long long calcula(unsigned long long med,unsigned long long n){
	unsigned long long ant = med - 1;
	unsigned long long cont = ant * n - ( ( ant / 2 ) * (ant / 2 + 1 ) );

	if( !(ant&1) )
		cont += ant/2;

	return cont;
}

unsigned long long busbin(unsigned long long ini,unsigned long long fin,unsigned long long valor,unsigned long long n){
	unsigned long long med;

	while(ini<fin){
		med = (ini + fin ) / 2;
		unsigned long long cont = calcula(med , n);
		unsigned long long cont2 = calcula(med - 1 , n);

		if(cont<valor) ini = med + 1;
		else if(cont>=valor && cont2>=valor) fin = med - 1;
		else return med;
	}

	return ini;
}

int main(){
	unsigned long long n;
	unsigned long long b;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while(cin >> n >> b, !cin.fail()){
		unsigned long long pos = busbin( 1 , 2 * n , b, n) - 1;
		unsigned long long movx = (pos - 1) / 2;
		unsigned long long movy = (pos - 1) - movx;
		unsigned long long x, y;
		x = ((movx & 1ULL) == 0ULL) ? 1 + movx / 2 : n - movx / 2;
		y = ((movy & 1ULL) == 0ULL) ? movy / 2 : n - movy / 2;
		switch(pos % 4) {
			case 0:
				x -= b - calcula(pos, n);
				break;
			case 1:
				y += b - calcula(pos, n);
				break;
			case 2:
				x += b - calcula(pos, n);
				break;
			case 3:
				y -= b - calcula(pos, n);
				break;
		}
		cout << x << ' ' << y << '\n';
	}
	cout.flush();
	return 0;
}
