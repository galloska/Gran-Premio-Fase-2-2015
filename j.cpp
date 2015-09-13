#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int puntos[100005];

int main(){
	int n,m,a;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<n;i++) puntos[i] = 0;

		for(int i=0;i<m;i++){
			for(int i=0;i<n;i++){
				scanf("%d",&a);
				puntos[i] += a;
			}
		}

		vector<pii> res;

		for(int i=0;i<n;i++)
			res.push_back( pii( -puntos[i] , -i ) );

		sort( res.begin() , res.end() );

		printf("%d\n",-(res[0].second) + 1 );
	}
	return 0;
}
