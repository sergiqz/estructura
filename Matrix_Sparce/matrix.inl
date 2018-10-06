template <class T>
m_p<T>::~m_p()
{
}

template <class T>
T & m_p<T>::operator()(const int & i, const int & j)	
{
	node<T> ** nr;
	if(!find(nr, i, j, 0))	
	{
		node<T> ** nc;
		find(nc, j, i, 1);	

		*nr = *nc = new node<T>(i, j, *nr, *nc);
	
	}

	return (*nr)->dato;
}


template <class T>
bool m_p<T>::find(node<T> **& n, const int & i, const int & p, const bool & b)
{

	n = &index[b][i];	
	while(*n)
	{
		if((*n)->pos[!b] == i){
			return true;
		}
		if((*n)->pos[!b] > i){ 
			return false;
		}
		n = &(*n)->p_next[b];
	}

	return false;
}