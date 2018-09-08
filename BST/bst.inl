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
	os<<"graph {"<<endl;
	os<<p_root->key<<endl;
	print(p_root);
	os<<"}"<<endl;
}

template <class K, class D>
void bst<K,D>::print(node<K,D> *n){
	if(n!=NULL)
    {
        
        if(n->p_child[0]!=NULL){
            os<<n->key;
            os<<"--";
            os<<n->p_child[0]->key<<endl;
            print(n->p_child[0]);
        }
        if(n->p_child[1]!=NULL){
            os<<n->key;
            os<<"--";
            os<<n->p_child[1]->key<<endl;
            print(n->p_child[1]);
        }
    }
}

template <class K, class D>
void bst<K,D>::remove(const K & key){
	remove(&p_root,key);
}

template <class K, class D>
void bst<K,D>::remove(node<K,D>** n,const K & key){
	if(*n == NULL) return ;//No es encontrar el valor X de los nodos 
    if(key <(*n)->key) 
    { 
         remove(&(*n)->p_child[0], key);//Si X es inferior al valor del nodo, sigue en el árbol de la izquierda elimina el nodo X 
    }
 
    else if(key > (*n)->key)
    { 
         remove(&(*n)->p_child[1], key);//Si X es mayor que el valor del nodo, sigue en el nodo eliminar X subárbol 
    } 
 
    else//Si son iguales, el nodo es eliminar nodo 
    { 
        if((*n)->p_child[0] and (*n)->p_child[1])//El nodo tiene dos hijos 
        { 
            node<K,D>* temp = (*n)->p_child[1];//Nodos hijo temp hacia la derecha 
            while(temp->p_child[0]!=NULL) temp=temp->p_child[0];//Encontrar un mínimo de nodos
            //A la derecha en el valor mínimo de nodos subárbol de asignar a este nodo 
            (*n)->key = temp->key;
            (*n)->data = temp->data;
            remove(&(*n)->p_child[1],temp->key);//Eliminar nodos en el valor mínimo de la derecha subárbol 
        } 
        else//El nodo tiene un hijo o 1 0 
        { 
            node<K,D>* temp = *n; 
            if((*n)->p_child[0] == NULL)//Hijo o no, el hijo de la derecha 
            	(*n) = (*n)->p_child[1]; 
            else if((*n)->p_child[1] == NULL)//A la izquierda, hijo 
            	(*n) = (*n)->p_child[0];
            temp = NULL; 
            delete(temp); 
        } 
	}
}

template <class K, class D>
bool bst<K,D>::remove_v2(K key){
	node<K,D> **n;
	n=&p_root;
	node<K,D> *tmp;
	node<K,D> *tmp2;

	if(find(key,n)){
		tmp=*n;
		if(tmp->p_child[0]==NULL and tmp->p_child[1]==NULL){
			*n=NULL;
			delete tmp;
		}
		else if(tmp->p_child[0]!=NULL and tmp->p_child[1]==NULL){
				*n=(*n)->p_child[0];
				tmp->p_child[0]=NULL;
				delete tmp;
		}
		else if(tmp->p_child[0]==NULL and tmp->p_child[1]!=NULL){
				*n=(*n)->p_child[1];
				tmp->p_child[1]=NULL;
				delete tmp;
		}
		
		/*
		bool c=tmp->p_child[0]==NULL;
		*n=(*n)->p_child[c];
		tmp->p_child[c]=NULL;
		delete tmp;
		*/

		else{
			node<K,D> *pd; //padre
			node<K,D> *aux;
			tmp=*n;
			aux=tmp->p_child[0];
			pd=p_root;
			if(aux->p_child[1]==NULL){
                tmp->key=aux->key;
                tmp->p_child[0]=aux->p_child[0];
                delete aux;
            }
            else{
                while((aux->p_child[1]!=NULL)){
                    pd=aux;
                    aux=aux->p_child[1];
                }

                tmp->key=aux->key;
                pd->p_child[1]=NULL;
            	delete aux;
        	}
        }	
	}
}