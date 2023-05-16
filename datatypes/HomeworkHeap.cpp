static void heapify(T* arr, int size, int idx){
    int largest=idx;
 
    int l=2*idx+1;
    int r=2*idx+2;
 
    if (l<size && arr[l]>arr[largest]) largest=l;
    if (r<size && arr[r]>arr[largest]) largest=r;
    if (largest!=idx) {
        T temp=arr[idx];
        arr[idx]=arr[largest];
        arr[largest]=temp;
        
        heapify(arr,size,largest);
    }
}
 
static void heapSort(T* start, T* end){
    int size=end-start;
    for(int i=size;i>=0;i--)
        Sorting<T>::heapify(start,size,i);
 
    for(int i=size-1;i>0;i--){
        T temp=*start;
        *start=*(start+i);
        *(start+i)=temp;
 
        // call max heapify on the reduced heap
        Sorting<T>::heapify(start,i,0);
    }
    Sorting<T>::printArray(start,end);
}
//////////
//////////
//////////


class Heap {
    public:
    int* arr;
    int cap;
    int size;
    Heap(){
        this->cap=100;
        this->size=0;
        this->arr=new int[cap];
    }
    ~Heap(){
        delete[] arr;
    }
    
    int parent(int idx){return (idx-1)/2;}
    int left(int idx){return 2*idx+1;}
    int right(int idx){return 2*idx+2;}
    
    void push(int data){
        if(size==cap-1)
        {
            int* NEWARR=new int[cap*2];
            for(int i=0;i<cap;i++)
                NEWARR[i]=arr[i];
            
            delete[] arr;
            arr=NEWARR;
        }
        
        arr[size]=data;
        size++;
        reheapUp(size-1);
    }

    int peek(){
        if(size==0) return 0;
        return arr[0];
    }
    
    bool pop(){
        if(size==0) return false;
        
        int temp=arr[0];
        arr[0]=arr[size-1];
        arr[size-1]=temp;
        
        size--;
        reheapDown(0);
        
        return true;
    }
    void reheapUp(int idx){
        if(idx==0) return;
    
        if(arr[parent(idx)]<arr[idx])
        {
            int temp=arr[idx];
            arr[idx]=arr[parent(idx)];
            arr[parent(idx)]=temp;
            
            reheapUp(parent(idx));
        }
        else return;
    }
    void reheapDown(int idx){
        int TheChosenOne;
    
        if(left(idx)<size)
        {
            if(right(idx)<size) 
            TheChosenOne=(arr[left(idx)]>arr[right(idx)])?left(idx):right(idx);     
            else 
            TheChosenOne=left(idx);
        }
        else return;
    
        if(arr[idx]<arr[TheChosenOne])
        {
            int temp=arr[idx];
            arr[idx]=arr[TheChosenOne];
            arr[TheChosenOne]=temp;
            
            reheapDown(TheChosenOne);
        }
        else return;
    }
};

int minWaitingTime(int n, int arrvalTime[], int completeTime[]) {
    // YOUR CODE HERE
    Heap MyHeap;
    
    
    
    return 0;
    
}

//////////
//////////
//////////

template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return !count;
}

template<class T>
T Heap<T>::peek(){
    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for(int i=0;i<count;i++)
        if(elements[i]==item) return true;
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if(isEmpty()) return false;
    
    T temp=elements[0];
    elements[0]=elements[count-1];
    elements[count-1]=temp;
    
    count--;
    reheapDown(0);
    
    return true;
}
//////////
//////////
//////////

int parent(int idx){return (idx-1)/2;}

template<class T>
void Heap<T>::push(T item){
    if(count==capacity-1)
    {
        T* NEWARR=new T[capacity*2];
        for(int i=0;i<capacity;i++)
            NEWARR[i]=elements[i];
        
        delete[] elements;
        ensureCapacity(capacity*2);
        elements=NEWARR;
    }
    
    elements[count]=item;
    count++;
    reheapUp(count-1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    capacity=minCapacity;
}

template<class T>
void Heap<T>::reheapUp(int idx){
    if(idx==0) return;

    if(elements[parent(idx)]<elements[idx])
    {
        T temp=elements[idx];
        elements[idx]=elements[parent(idx)];
        elements[parent(idx)]=temp;
        
        reheapUp(parent(idx));
    }
    else return;
}


//////////
//////////
//////////

int parent(int idx){return (idx-1)/2;}
int left(int idx){return 2*idx+1;}
int right(int idx){return 2*idx+2;}

void reheapDown(int maxHeap[], int size, int idx)
{
    if(idx<0 || idx>=size || size==0) return;
    
    int TheChosenOne;

    if(left(idx)<size)
    {
        if(right(idx)<size) 
        TheChosenOne=(maxHeap[left(idx)]>maxHeap[right(idx)])?left(idx):right(idx);     
        else 
        TheChosenOne=left(idx);
    }
    else return;

    if(maxHeap[idx]<maxHeap[TheChosenOne])
    {
        int temp=maxHeap[idx];
        maxHeap[idx]=maxHeap[TheChosenOne];
        maxHeap[TheChosenOne]=temp;
        
        reheapDown(maxHeap,size,TheChosenOne);
    }
    else return;
}

void reheapUp(int maxHeap[], int size, int idx)
{
    if(idx<0 || idx>=size || size==0) return;
    
    if(idx==0) return;

    if(maxHeap[parent(idx)]<maxHeap[idx])
    {
        int temp=maxHeap[idx];
        maxHeap[idx]=maxHeap[parent(idx)];
        maxHeap[parent(idx)]=temp;
        
        reheapUp(maxHeap,size,parent(idx));
    }
    else return;
}


//////////
//////////
//////////


template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for(int i=0;i<count;i++)
        if(elements[i]==item) return i;
    return 0;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int idx=getItem(item);
    elements[idx]=elements[count-1]; //copy last value to that place, then don't care the true last value by reduce size by 1
    reheapDown(idx);
    reheapUp(idx);
    
    count--;
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    count=0;
}





