#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

map<string,vector<string>> grafo[15];
vector<string> cache[15];
map<string,bool> visited;
map<string,int> distancia;
 
int bfs(string a, string b){
	if(a==b) return 0;
	string tmp;
	int tam, tam2;
	queue<string> q;
	q.push(a);
	visited[a]=1;
	while(1){
	  	a=q.front();
		tam=a.size();
		tam2=grafo[tam][a].size();
		for(int i=0;i<tam2;i++){

		  	tmp=grafo[tam][a][i];
		  	if(tmp==b){
		    	return distancia[a]+1;
		  	}
		  	if(!visited[tmp]){
		    	distancia[tmp]=distancia[a]+1;
		    	q.push(tmp);
		    	visited[tmp]=1;
		  	}
		}
		q.pop();
	}
}

void separador(string au, string &a, string &b){
	int tam=au.size();
	for (int i=0;i<tam;i++)
	{
	    if(au[i]==' '){
	      	a=au.substr(0,i);
	      	b=au.substr(i+1);
	      	return;
	    }
	}
}

bool cambioCaracter(string a, string b){
    int tam = a.size();
    int count = 0;
    for(int i=0;i<tam;i++){
        if(a[i]!=b[i]) count++;
    }
    return count==1;
}

int main(){
	bool blank = 0;
	string a,b;
	int cases;
	cin>>cases;
	string s;
	int tam;
	string tempSTR;
	bool point;
	while(cases--){
		for (int i=0;i<15;i++)
		{
			grafo[i].clear();
			cache[i].clear();
		}
		if(blank){
			cout<<endl;
		}
		blank=1;
		while(1){
			point=0;
			cin>>s;
			if(s=="*") break;
			tam=s.size();
			for (int i=0;i<cache[tam].size();i++){
				tempSTR=cache[tam][i];
				if(cambioCaracter(tempSTR,s)){
					grafo[tam][tempSTR].push_back(s);
					grafo[tam][s].push_back(tempSTR);
				}
				else{
					if(tempSTR==s){
						point=1;
					}
				}
			}
			if(!point){
				cache[tam].push_back(s);
			}
		}
		cin.ignore();
		while(1){
			getline(cin,s);
			if(s==""){
				break;
			}
			separador(s,a,b);
			distancia.clear();
			visited.clear();
			cout<<s<<" "<<bfs(a,b)<<endl;
		}
	}
  	return 0;
}