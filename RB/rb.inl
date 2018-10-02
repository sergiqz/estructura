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

