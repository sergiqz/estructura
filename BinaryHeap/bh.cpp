// Example program
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class T, size_t cap = 1000>
class BH
{
    private:
        T * elems;
        size_t size;
        ofstream os;
        
    public:
        BH(): elems(new T[cap]), size(0), os("grap.dot") {};
        ~BH()
        {
            delete [] elems;
        }

        int parent(int i){
            return (i-1)/2;
        }

        int left(int i){
            return i*2+1;
        }

        int right(int i){
            return i*2+2;
        }
        
        void push(T x)
        {
            if(size==cap){
                return;
            }
            size++;
            int i=size-1;
            elems[i]=x;
            while(i!=0 and elems[parent(i)]>elems[i]){
                swap(elems[i],elems[parent(i)]);
                i=parent(i);
            }
        }
        
        // delete min 
        void pop()
        {
            if(size == 0){
                return;
            }
            elems[0]=elems[size-1];
            delete elems[size-1];
            down(0);
        }
        
        // min 
        T top()
        {
            return elems[0];
        }

        void printGEGE(){
            os<<"graph {"<<endl;
            os<<elems[0]<<endl;
            printDeMachos();
            os<<"}"<<endl;
        }

        void printDeMachos(){
            int c=0;
            while(c<size){
                int l=left(c);
                int r=right(c);
                if(l<size){
                    os<<elems[c]<<"--"<<elems[l]<<endl;
                }
                if(r<size){
                    os<<elems[c]<<"--"<<elems[r]<<endl;
                }
                c++;
            }
        }
    
    private:
        void up(int i)
        {
            if(i>=0 and parent(i)>=0 and elems[parent(i)]>elems[i]){
                int tmp = elems[i];
                elems[i]=elems[parent(i)];
                elems[parent(i)]=tmp;
                up(parent(i));
            }
        }
        
        void down(int i)
        {
            int _left=left(i);
            int _right=right(i);
            if(_left>=0 and _right>=0 and elems[_left] > elems[_right]){
                _left=_right;
            }
            if(_left>0 and elems[i]>elems[_left]){
                int tmp=elems[i];
                elems[i]=elems[_left];
                elems[_left]=tmp;
                down(_left);
            }
        }
};

void heapify(int arr[],int n,int i){ 
    int nodo=i; 
    int left=2*i+1;
    int right=2*i+2; 
    if (left<n and arr[left]>arr[nodo]){
        nodo=left; 
    }
    if (right<n and arr[right]>arr[nodo]){ 
        nodo=right; 
    }
    if (nodo!=i){ 
        swap(arr[i], arr[nodo]); 
        heapify(arr,n,nodo); 
    } 
} 

void heapSort(int arr[],int n){
    for (int i=n/2-1;i>=0;i--){
        heapify(arr,n,i); 
    }
    for (int i=n-1;i>=0;i--){  
        swap(arr[0],arr[i]); 
        heapify(arr,i,0); 
    } 
} 

void print(int arr[], int n) 
{ 
    for (int i=0; i<n;i++){
        cout<<arr[i]<<" "; 
    }
} 

int main()
{
    BH<int> h;
    int arr[]={45,12,3,98,72,88};
    int tam = 6;
    heapSort(arr,tam); 
    print(arr,tam);
    /*
    for(int i = 20; i > 0; i--){
        h.push(i);

    }
    //for(int i = 0; i < 69; i++){
    //    h.print(i);
    //}
    
    //cout << h.top() << endl;
    h.printGEGE();
    */
    return 0;
}