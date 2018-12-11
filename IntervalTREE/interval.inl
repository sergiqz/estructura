node::node(const int & l, const int & h){
	low=l;
	high=h;
	p_child[0] = NULL;
	p_child[1] = NULL;
	BalanceFactor = 0;
	max=h;
}

intervalTree::intervalTree(){
	root=NULL;
}

bool intervalTree::insert(node **n,const int & l,const int & h)
{
	if((*n)==NULL){
		(*n)=new node(l,h);
		return true;
	}
	
	if((*n)->low==l){
		return false;
	}

	if((*n)->max < h){
		(*n)->max = h;
	}

	if(insert(&((*n)->p_child[l>(*n)->low]),l,h)){
		return checkNbalalnce(n);
	}

	return true;
}

void intervalTree::insert(const int & l, const int & h){
	insert(&this->root,l,h);
}

bool intervalTree::find(const int & l, const int & h){
	node **n;
	if(find(n,l))
	{
		return true;
	}
	return false;
}

bool intervalTree::find(node **& n, const int & l){
    n= &root;
    while((*n)){
        if(l==((*n)->low)){
            return true;
        }
        n = &(*n)->p_child[l>(*n)->low];
    }
    return false;
}

bool intervalTree::checkNbalalnce(node **n)
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

bool intervalTree::turnSide(node **n, bool side)
{
	node *mid = (*n)->p_child[side];
	(*n)->p_child[side] = mid->p_child[!side];
	mid->p_child[!mid] = (*n);
	(*n) = mid;
}

int intervalTree::getSize(){
	node *p_root = this->root;
	getSize(p_root);
}

int intervalTree::getSize(node *n)
{
	if(n==NULL){
		return 0;
	}
	if(n->p_child[0]==n->p_child[1]){
		return 1;
	}
	return max(getSize(n->p_child[0]),getSize(n->p_child[1]))+1;
}

bool intervalTree::dooverlap(node *i1, const int & l, const int & h){
	if(i1->low <= h and l <= i1->high){
		return true;
	}
	return false;
}

node * intervalTree::overlapSearch(node ** n, const int & l, const int & h){
	if((*n)==NULL){
		return NULL;
	}
	if(dooverlap((*n),l,h)){
		return (*n);
	}
	if((*n)->p_child[0] != NULL and (*n)->p_child[0]->max >= l){
		return overlapSearch(&(*n)->p_child[0],l,h);
	}	
	return overlapSearch(&(*n)->p_child[1],l,h);
}

void intervalTree::overlapSearch(const int & l, const int & h){
	node * N;
	N = overlapSearch(&this->root,l,h);
	if(N == NULL){
		cout<<"Sin intervalo de superposicion"<<endl;
	}
	else{
		cout<<N->low<<" "<<N->high<<endl;
	}
}

void intervalTree::print(){
	ofstream os("intervalGRAF.dot");
	os<<"digraph {"<<endl;
	os<<"p"<<root<<" "<<"[label=\""<<"["<<root->low<<" "<<","<<" "<<root->high<<"]"<<"\\l"<<root->max<<"\"]"<<endl;
	os<<"p"<<root<<endl;
	print(root,os);
	os<<"}"<<endl;
	os.close();
	system("dot.lnk -Tpng  < intervalGRAF.dot > intervalGRAF.png");
}

void intervalTree::print(node *n, ofstream & os){
	if(n!=NULL){
		if(n->p_child[0]!=NULL){
			os<<"p"<<n->p_child[0]<<" "<<"[label=\""<<"["<<n->p_child[0]->low<<" "<<","<<" "<<n->p_child[0]->high<<"]"<<"\\l"<<n->p_child[0]->max<<"\"]"<<endl;
			os<<"p"<<n<<"->"<<"p"<<n->p_child[0]<<endl;
			print(n->p_child[0],os);
		}
		if(n->p_child[1]!=NULL){
			os<<"p"<<n->p_child[1]<<" "<<"[label=\""<<"["<<n->p_child[1]->low<<" "<<","<<" "<<n->p_child[1]->high<<"]"<<"\\l"<<n->p_child[1]->max<<"\"]"<<endl;
			os<<"p"<<n<<"->"<<"p"<<n->p_child[1]<<endl;
			print(n->p_child[1],os);
		}
	}
}