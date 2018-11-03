#include <cstring>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

template <class T, int N=64>
class binomial_heap;

template <class T>
class binomial_tree
{
private:
	T dato;
	vector<binomial_tree<T>*> p_childs;
public:
	binomial_tree(const T & d):dato(d){}
	~binomial_tree(){}
	void print(ostream & os){
		os<<"p"<<this<<" [label=\""<<dato<<"\"]"<<endl;
		for(binomial_tree<T>*p:p_childs){
			p->print(os);
			os<<"p"<<this<<" -> p"<<p<<endl;
		}
	}
	friend class binomial_heap<T>;
};

template <class T, int N>
class binomial_heap
{
private:
	binomial_tree<T> * head[N];
	binomial_tree<T> * max;
public:
	binomial_heap(){
		memset(head,0,sizeof(head));
		max=NULL;
	}
	~binomial_heap(){}
	void insert(const T & d){
		insert(new binomial_tree<T>(d));
	}
	void insert(binomial_tree<T> * b){
		int i = b->p_childs.size();
		if(!max){
			max=b;
		}
		if(!head[i]){
			head[i]=b;
			if(head[i]->dato>max->dato){  
				max=head[i];
			}
			return;
		}
		insert(merge(head[i],b));
		head[i]=NULL;
	}
	binomial_tree<T> * merge(binomial_tree<T> * a, binomial_tree<T> * b){
		if(a->dato > b->dato){           
			a->p_childs.push_back(b);
			return a;
		}
		b->p_childs.push_back(a);
		return b;
	}	
	T get_max(){
		return max->dato;
	}
	void print(){
		ofstream os("binh.dot");
		os<<"digraph bh{ "<<endl;
		for(int i=0; i<N; i++){
			if(head[i]) head[i]->print(os);
		}
		os<<"}"<<endl;
		os.close();
	}
	T extractMax(){
		head[max->p_childs.size()]=NULL;
		for(int m=0;m<max->p_childs.size();m++){
			if(!head[m]){
				head[m]=max->p_childs[m];
				max->p_childs.pop_back();
			}
			else{
				int degree=m;
				while(head[degree]){
					degree++;
				}
				for(int o=degree;o>m;o--){
					head[o]=head[o-1];
					head[o-1]=NULL;
				}
				head[m]=max->p_childs[m];
				max->p_childs.pop_back();
				for(int o=m+1;o<degree+1;o++){
					head[o]=merge(head[o],head[o-1]);
					head[m]=NULL;
				}
			}
		}
		T exMayor = max->dato;
		max=NULL;
		for(int m=0;m<N-1;m++){
			if(head[m]){
				if(!max){
					max=head[m];
				}
				if(head[m]->dato>max->dato){
					max=head[m];
				}
			}
		}
		return exMayor;
	}
};

int main(){
	binomial_heap<int> bh;
	return 0;
}
