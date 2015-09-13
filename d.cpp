#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

string mat[MAXN][MAXN];
int col[MAXN];
int fila[MAXN];
set<string> calculado;
int n,m;
vector<string> res;
map<string,int> check2;
map<string,int> check;

int buscaFila(){
	for(int i=0;i<n;i++){
		int cont = 0;
		set<string> v;
		for(int j=0;j<m;j++)
			if(!calculado.count(mat[i][j]) && !v.count(mat[i][j]) ){
				cont++;
				v.insert( mat[i][j] );
			}
		if(cont==1) return i;
	}

	return -1;
}

int buscaColumna(){
	for(int j=0;j<m;j++){
		int cont = 0;
		set<string> v;
		for(int i=0;i<n;i++)
			if(!calculado.count(mat[i][j]) && !v.count(mat[i][j]) ){
				cont++;
				v.insert( mat[i][j] );
			}
		if(cont==1) return j;
	}

	return -1;
}

int main(){

	while(cin>>n>>m){
		res.clear();
		check.clear();
		calculado.clear();
		check2.clear();

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cin>>mat[i][j];
			cin>>fila[i];
		}

		for(int i=0;i<m;i++)
			cin>>col[i];

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				if(check2.find(mat[i][j])==check2.end()){
					check2[mat[i][j]] = 1;
					res.push_back(mat[i][j]);
				}
		}

		while(1){
			int a = buscaFila();
			int b = buscaColumna();

			if(a==-1 && b==-1) break;

			//printf("%d %d\n",a,b);
			//getchar();

			if(a!=-1){
				string busco;
				int cont = 0;
				set<string> v;
				for(int j=0;j<m;j++){
					if(!calculado.count(mat[a][j]) && !v.count(mat[a][j]) ){
						cont++;
						busco = mat[a][j];
						v.insert( mat[a][j] );
					}
				}

				int res = fila[a] , cont2 = 0;

				for(int j=0;j<m;j++){
					if(calculado.count( mat[a][j] )){
						cont2++;
						res -= check[mat[a][j]];
					}
				}
				check[busco] = res / (m - cont2);
				//cout<<busco<< " "<<check[busco]<<endl;
				calculado.insert( busco );
			}
			else{
				string busco;
				int cont = 0;
				set<string> v;
				for(int i=0;i<n;i++)
					if(!calculado.count(mat[i][b]) && !v.count(mat[i][b]) ){
						cont++;
						busco = mat[i][b];
						v.insert( mat[i][b] );
					}

				int res = col[b] , cont2 = 0;

				for(int i=0;i<n;i++){
					if(calculado.count( mat[i][b] )){
						cont2++;
						res -= check[mat[i][b]];
					}
				}
				check[busco] = res / (n - cont2);
				//cout<<busco<< " "<<check[busco]<<endl;
				calculado.insert( busco );
			}
		}

		sort( res.begin() , res.end() );
		for(int i=0;i<res.size();i++)
			cout<<res[i]<<" "<<check[ res[i] ]<<'\n';

	}
	return 0;
}
