#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MAXN = 3005;

vector<int> x,y;
map<int,int> uno;
map<int,int> dos;
vector<pii> ar;
bool mat[MAXN][MAXN];
int suma[MAXN][MAXN];

int Get(pii a,pii b){
	if( a.second>b.second ){
		pii a1 = a;
		a = pii(b.first , a1.second);
		b = pii(a1.first , b.second );
		swap(a,b);
	}
	return suma[ b.first ][b.second] - suma[ a.first - 1 ][b.second] - suma[ b.first ][ a.second - 1 ] + suma[ a.first - 1 ][ a.second - 1 ];
}

int main(){
	int n,a,b;
	while(scanf("%d",&n)!=EOF){
		x.clear();
		y.clear();
		uno.clear();
		dos.clear();
		ar.clear();
		int u = 1, z = 1;

		for(int i=0;i<n;i++){
			scanf("%d %d",&a,&b);
			x.push_back(a);
			y.push_back(b);
			ar.push_back( pii(a,b) );
		}

		sort( x.begin() , x.end() );
		sort( y.begin() , y.end() );

		for(int i=0;i<x.size();i++){
			if(uno.find(x[i])==uno.end())
				uno[ x[i] ] = u++;
		}

		for(int i=0;i<y.size();i++){
			if(dos.find(y[i])==dos.end())
				dos[ y[i] ] = z++;
		}

		for(int i=0;i<MAXN;i++)
			for(int j=0;j<MAXN;j++){
				suma[i][j] = 0;
				mat[i][j] = false;
			}

		for(int i=0;i<n;i++)
			mat[ uno[ ar[i].first ] ][ dos[ ar[i].second ] ] = true;

		/*for(int i=1;i<10;i++){
			for(int j=1;j<10;j++){
				printf("%d ",mat[i][j]);
			}
			printf("\n");
		}*/

		for(int i=1;i<MAXN;i++)
			for(int j=1;j<MAXN;j++)
				suma[i][j] = suma[i][j-1] + mat[i][j];

		for(int j=1;j<MAXN;j++)
			for(int i=1;i<MAXN;i++)
				suma[i][j] = suma[i][j] + suma[i-1][j];

		/*printf("\n");
		for(int i=1;i<10;i++){
			for(int j=1;j<10;j++){
				printf("%d ",suma[i][j]);
			}
			printf("\n");
		}*/

		for(int i=0;i<n;i++)
			ar[i] = pii( uno[ar[i].first] , dos[ ar[i].second ] );

		sort( ar.begin() , ar.end() );

		int cont = 0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if( Get( ar[i] , ar[j] ) == 2 )
					cont++;
			}
		}

		printf("%d\n",cont);
		
	}
	return 0;
}
