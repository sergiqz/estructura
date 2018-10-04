template<class K, class D>
node<K,D>::node(const K & k, const D & d){
	key=k;
	data=d;
	p_child[0]=NULL;
	p_child[1]=NULL;
	color=RED;
}

template<class K, class D>
rb<K,D>::rb(){
	p_root=NULL;
}

template<class K,class D>
bool rb<K,D>::insert(const K & key,const D & data){
	insert(key,data,&p_root,NULL);
	return true;
}

template<class K, class D>
node<K,D> * rb<K,D>::insert(const K & key,const D & data, node<K,D> ** n, node<K,D> ** p){
	if(!(*n)){
		(*n) = new node<K,D>(key,data);
		(*n)->color = RED;
		return (*n);
	}
	if((*n)->key==key){
		return NULL;
	}
	bool idx_child = ((*n)->key < key);
	node<K,D> *child = insert(key,data,&(*n)->p_child[idx_child],n);
	if(!child){
		return (*n);
	}
	if(!p){
		return NULL;
	}
	if((getColor(child)==RED) and (getColor(*n)==RED)){
		bool idx_parent = ((*p)->p_child[1] == (*n));
		node<K,D> *uncle = (*p)->p_child[!idx_parent];
		if(getColor(uncle)==RED){
			(*n)->color = BLACK;
			uncle->color = BLACK;
			(*p)->color = RED;
			p_root->color = BLACK;
			return (*n);
		}
		if(getColor(uncle)==BLACK){
			if(idx_child!=idx_parent){
				turnSide(n,idx_child);
				turnSide(p,idx_parent);
				(*p)->color = BLACK;
				(*p)->p_child[0]->color = RED;
				(*p)->p_child[1]->color = RED;
				p_root->color = BLACK;
			}
			else{
				turnSide(p,idx_parent);
				(*p)->color = BLACK;
				(*p)->p_child[!idx_parent]->color = RED;
				p_root->color = BLACK;
			}
		}	
	}
	return (*n); 
}

template<class K,class D>
bool rb<K,D>::turnSide(node<K,D> **n, bool side)
{
	node<K,D> *mid = (*n)->p_child[side];
	(*n)->p_child[side] = mid->p_child[!side];
	mid->p_child[!mid] = (*n);
	(*n) = mid;
}

template<class K,class D>
color_t rb<K,D>::getColor(node<K,D> *&n) {
    if (n == NULL){
        return BLACK;
    }
    return n->color;
}

template<class K,class D>
void rb<K,D>::setColor(node<K,D> *&n, color_t color) {
    if (n == NULL){
        return;
    }
    n->color = color;
}

template<class K, class D>
void rb<K,D>::printCOLOR(ofstream & es,node<K,D> *ptr){
  if (ptr == NULL)
    return;
  if(ptr->color == 0){
    es<< ptr->key << "[style=filled, fillcolor=black, fontcolor=white]"<< endl;
  }
  else es<< ptr->key << "[style=filled, fillcolor=red]"<< endl;
  printCOLOR(es,ptr->p_child[0]);
  printCOLOR(es,ptr->p_child[1]);
}

template<class K, class D>
void rb<K,D>::printARBOL(int num){
	string num_arch = to_string(num);
	string ext1 = ".dot";
	string num_xt1=""+ num_arch +""+ ext1 +"";
	ofstream es(num_xt1);
	////////
	string s = to_string(num);
	string pt1="dot.lnk -Tpng  < ";
	string pt2=" > ";
	string pt3=".png";
	string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
	const char *buffer = rt.c_str();
	////////
    es<<"digraph mentions {"<<endl;
    printARBOL(es,p_root);
    printCOLOR(es,p_root);
    es<<"}"<<endl;
    es.close();
    system(buffer);
}

template<class K, class D>
void rb<K,D>::printARBOL(ofstream & es,node<K,D> *n){
    if(n!=NULL){
        if(n->p_child[0]!=NULL){
            es<<n->key;
            es<<" -> ";
            es<<n->p_child[0]->key<<endl;
            printARBOL(es,n->p_child[0]);
        }
        if(n->p_child[1]!=NULL){
            es<<n->key;
            es<<" -> ";
            es<<n->p_child[1]->key<<endl;
            printARBOL(es,n->p_child[1]);
        }
    }
}
