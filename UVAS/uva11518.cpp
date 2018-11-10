#include <iostream>
#include <vector>
using namespace std;

vector<int> grafo[10005];
bool visited[10005];
int total;

void dfs(int u){
	if(visited[u]) return;
	total++;
	visited[u]=1;
	for(auto v:grafo[u]){
		dfs(v);
	}
}

int main()
{
	int CP,n,m,l,x,y,z;
	cin>>CP;
	while(CP--){
		cin>>n>>m>>l;
		while(m--){
			cin>>x>>y;
			grafo[x].push_back(y);
		}
		while(l--){
			cin>>z;
			//if(!visited[z]){
				dfs(z);
			//}
		}
		cout<<total<<endl;
		total=0;
		memset(visited,0,sizeof(visited));
		for (int i=0;i<n;i++){
			grafo[i].clear();
		}
	}
	return 0;
}