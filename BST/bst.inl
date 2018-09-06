template <class K, class D>
node<K,D>::node(const K & k, const D & d){
	key=k;
	data=d;
	p_child[0]=NULL;
	p_child[1]=NULL;
}

template <class K, class D>
bool bst<K,D>::find(const K & key, D & data){
	node<K,D> **n;
	if(find(key,n))
	{
		data=(*n)->data;
		return true;
	}
	return false;
}

template <class K, class D>
bool bst<K,D>::find(const K & key, node<K,D> **& n){
	n=&p_root;
	while(*n)
	{
		if((*n)->key==key){
			return true;
		}
		n=&(*n)->p_child[(*n)->key<key]; 
	}
	return false;
}

template <class K, class D>
bool bst<K,D>::insert(const K & key, const D & data){
	node<K,D> **n;
	if(!find(key,n))
	{
		*n=new node<K,D>(key,data);
		return true;
	}
	return false;
}

template <class K, class D>
void bst<K,D>::print(){
	cout<<"graph {"<<endl;
	cout<<p_root->key<<endl;
	print(p_root);
	cout<<"}"<<endl;
}

template <class K, class D>
void bst<K,D>::print(node<K,D> *n){
	if(n!=NULL)
    {
        
        if(n->p_child[0]!=NULL){
            cout<<n->key;
            cout<<"--";
            cout<<n->p_child[0]->key<<endl;
            print(n->p_child[0]);
        }
        if(n->p_child[1]!=NULL){
            cout<<n->key;
            cout<<"--";
            cout<<n->p_child[1]->key<<endl;
            print(n->p_child[1]);
        }
    }
}