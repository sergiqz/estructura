template <class K,class D>
node<K,D>::node(const K & k, const D & d){
	key=k;
	data=d;
	BalanceFactor=0;
	p_child[0]=NULL;
	p_child[1]=NULL;
}

template<class K,class D>
void avl<K,D>::insert(const K & key,const D & data)
{ 
	node<K,D>**searcher = &this->p_root;
    insert(searcher,key,data); 
} 

template<class K,class D>
bool avl<K,D>::insert(node<K,D> **n,const K & key,const D & data)
{
	if((*n)==NULL){
		(*n)=new node<K,D>(key,data);
		return true;
	}

	if((*n)->key==key){
		return false;
	}

	if(insert(&((*n)->p_child[key>(*n)->key]),key,data)){
		return checkNbalalnce(n);
	}
	return true;
}

template<class K,class D>
bool avl<K,D>::checkNbalalnce(node<K,D> **n)
{
	(*n)->BalanceFactor=getSize((*n)->p_child[0])-getSize((*n)->p_child[1]);
	if((*n)->BalanceFactor==2){
		if((*n)->p_child[0]->BalanceFactor==1){
			turnSide(n,0);
		}
		if((*n)->p_child[0]->BalanceFactor==-1){
			turnSide(&((*n)->p_child[1]),0);
			turnSide(n,0);
		}
	}

	if((*n)->BalanceFactor==-2){
		if((*n)->p_child[1]->BalanceFactor==-1){
			turnSide(n,1);
		}
		if((*n)->p_child[1]->BalanceFactor==1){
			turnSide(&((*n)->p_child[0]),0);
			turnSide(n,1);
		}
	}
	return true;
}

template<class K,class D>
bool avl<K,D>::turnSide(node<K,D> **n, bool side)
{
	node<K,D> *mid = (*n)->p_child[side];
	(*n)->p_child[side] = mid->p_child[!side];
	mid->p_child[!mid] = (*n);
	(*n) = mid;
}

template<class K,class D>
int avl<K,D>::getSize(){
	node<K,D> *root = this->p_root;
	getSize(root);
}

template<class K,class D>
int avl<K,D>::getSize(node<K,D> *n)
{
	if(n==NULL){
		return 0;
	}
	if(n->p_child[0]==n->p_child[1]){
		return 1;
	}
	return max(getSize(n->p_child[0]),getSize(n->p_child[1]))+1;
}

template <class K, class D>
void avl<K,D>::print(){
	os<<"graph {"<<endl;
	os<<p_root->key<<endl;
	print(p_root);
	os<<"}"<<endl;
	system("dot.lnk -Tpng  < grap.dot > out2.png");
}

template <class K, class D>
void avl<K,D>::print(node<K,D> *n){
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
bool avl<K,D>::find(const K & key, D & data){
	node<K,D> **n;
	if(find(n,key))
	{
		data=(*n)->data;
		return true;
	}
	return false;
}


template <class K, class D>
bool avl<K,D>::find(node<K,D> **& n, const K & key){

    n= &p_root;

        while((*n)){
            if(key==((*n)->key)){
                return true;
            }
            n = &(*n)->p_child[key>(*n)->key];
        }
        return false;

}

template <class K, class D>
bool avl<K,D>::remove(node<K,D> **n){
	return remove(n,(*n)->key);
}


template <class K, class D>
bool avl<K,D>::remove(const K & key){
	node<K,D> **n;
	if(find(n,key)){
		return remove(n);
	}
}


template <class K, class D>
bool avl<K,D>::remove(node<K,D> **n, const K & key){
	if((*n)==NULL){
		return false;
	}

	if((*n)->key==key){
		if((*n)->p_child[0]==(*n)->p_child[1]){
			node<K,D>* parent = getParent(key);
			parent->p_child[key>parent->key]=NULL;
			delete n;
			return true;
		}
	

		if((*n)->p_child[1]==NULL){
			K aux = (*n)->p_child[0]->key;
			remove(&((*n)->p_child[0]));
			(*n)->key=aux;
			return true;
		}

		if((*n)->p_child[1]!=NULL){
            if((*n)->p_child[0]==NULL){
                return false;
            }

            if((*n)->p_child[0]!=NULL){
                node<K,D> *temp = (*n)->p_child[1];

                while (temp->p_child[0]!=NULL) {
                    temp=temp->p_child[0];
                }

                K aux_2= temp->key;
                remove(&temp);
                (*n)->key=aux_2;
                return true;
            }
        }
	}
	if(remove(&(*n)->p_child[key>(*n)->key],key)){
        return checkNbalalnce(n);
    }
}

template <class K, class D>
node<K,D>* avl<K,D>::getParent(const K & key){
	node<K,D>* parent=p_root;

    while(parent->p_child[0]!=NULL or parent->p_child[1]!=NULL){

        if(parent->p_child[0]->key!=key and parent->p_child[1]->key!=key){
            parent=parent->p_child[key>parent->key];
        }

        if(parent->p_child[0]==NULL){
            if(parent->p_child[1]->key==key){
                return parent;
            }
        }
        if(parent->p_child[1]==NULL){
            if(parent->p_child[0]->key==key){
                return parent;
            }
        }

        if(parent->p_child[0]->key==key or parent->p_child[1]->key==key){
            return parent;
        }

    }
}