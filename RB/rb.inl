template<class K, class D>
node<K,D>::node(const K & k, const D & d){
	key=k;
	data=d;
	p_child[0]=NULL;
	p_child[1]=NULL;
	color=RED;
	parent=NULL;
}

template<class K, class D>
rb<K,D>::rb(){
	p_root=NULL;
}

template<class K,class D>
void rb<K,D>::insert(const K & key,const D & data){
	node<K,D>*p,*q;
	node<K,D>*t=new node<K,D>(key,data);
	t->key=key;
	p=p_root;
	q=NULL;
	if(p_root==NULL)
	{
	    p_root=t;
	    t->parent=NULL;
	}
	else
	{
	    while(p!=NULL)
	    {
	        q=p;
	        if(p->key<t->key){
	            p=p->p_child[1];
	        }
	        else{
	            p=p->p_child[0];
	        }
	    }
	    t->parent=q;
	    if(q->key<t->key){
	        q->p_child[1]=t;
	    }
	    else{
	        q->p_child[0]=t;
	    }
	}
    fixInsertRBTree(t);
}

template<class K,class D>
void rb<K,D>::fixInsertRBTree(node<K,D> *&ptr){
	node<K,D> *parent = NULL;
    node<K,D> *grandparent = NULL;
    while(ptr != p_root and getColor(ptr) == RED and getColor(ptr->parent) == RED) {
        parent = ptr->parent;
        grandparent = parent->parent;
        if(parent == grandparent->p_child[0]){
            node<K,D> *tio = grandparent->p_child[1];
            if(getColor(tio) == RED){
                setColor(tio, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } 
            else{
                if(ptr == parent->p_child[1]){
                    rotacionizq(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotacionder(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
        else{
            node<K,D> *tio = grandparent->p_child[0];
            if(getColor(tio) == RED){
                setColor(tio, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else{
                if(ptr == parent->p_child[0]){
                    rotacionder(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotacionizq(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    setColor(p_root, BLACK);   
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

template<class K,class D>
void rb<K,D>::rotacionizq(node<K,D>*& ptr){
    node<K,D> *right_child = ptr->p_child[1];
    ptr->p_child[1] = right_child->p_child[0];
    if (ptr->p_child[1] != NULL){
        ptr->p_child[1]->parent = ptr;
    }

    right_child->parent = ptr->parent;

    if (ptr->parent == NULL){
        p_root = right_child;
    }
    else{
    	if (ptr == ptr->parent->p_child[0]){
        	ptr->parent->p_child[0] = right_child;
    	}
   
	    else{
	        ptr->parent->p_child[1] = right_child;
	    }
	}
    right_child->p_child[0] = ptr;
    ptr->parent = right_child; 
}

template<class K,class D>
void rb<K,D>::rotacionder(node<K,D>*& ptr){
    node<K,D> *left_child = ptr->p_child[0];
    ptr->p_child[0] = left_child->p_child[1];

    if (ptr->p_child[0] != NULL){
        ptr->p_child[0]->parent = ptr;
    }

    left_child->parent = ptr->parent;

    if (ptr->parent == NULL){
        p_root = left_child;
    }
    else{ 
    	if (ptr == ptr->parent->p_child[0]){
        	ptr->parent->p_child[0] = left_child;
    	}
	    else{
	        ptr->parent->p_child[1] = left_child;
	    }
	}
    left_child->p_child[1] = ptr;
    ptr->parent = left_child;
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
