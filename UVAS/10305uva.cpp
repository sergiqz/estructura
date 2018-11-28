#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> grafo;
vector<bool> visited;
vector<int> rpta;

void dfs(int u){
	visited[u]=1;
	for(int i=0;i<grafo[u].size();i++){
		if(!visited[grafo[u][i]]){
			dfs(grafo[u][i]);
		}
	}
	rpta.push_back(u);
}

int main(){
	int n,m,i,j;
	while((cin>>n>>m) and m!=0){
		grafo.assign(n,vector<int>());
		visited.assign(n,1);
		while(m--){
			cin>>i>>j;
			grafo[i-1].push_back(j-1);
		}
		for(int x=0;x<grafo.size();x++){
			if(visited[x]==1){
				dfs(x);
			}
		}
		reverse(rpta.begin(),rpta.end());
		for(int y=0; y<rpta.size();y++){
			if(y<rpta.size()-1){
				cout<<rpta[y]+1<<" ";
			}
			else{
				cout<<rpta[y]+1<<endl;
			}
		}
		rpta.clear();
	}
	return 0;
}