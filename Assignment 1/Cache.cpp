#include "main.h"

Data* Cache::read(int addr) {

    int idx=0;

    while(idx!=-1)
    {
        if(addr==arr[idx]->addr)
            return arr[idx]->data;
        else if(addr<arr[idx]->addr)
            idx=left[idx];
        else 
            idx=right[idx];
    }
    
    return NULL;
}
//
Elem* Cache::put(int addr, Data* data) {

    for(int i=0;i<size;i++) age[i]++;

    Elem* OUTPUT=NULL;

    if(size==capacity-1)
    {
        if(addr%2==0) OUTPUT=outFIFO();
        else OUTPUT=outLIFO();
    }

    arr[size]=new Elem(addr,data,false);

    int idx=0;

    if(capacity!=0)
    while(true)
    {
        if(addr<=arr[idx]->addr)
        {
            if(left[idx]==-1)
            {
                left[idx]=size;
                break;
            }
            else
            {
                idx=left[idx];
            }
        }
        else   
        {
            if(right[idx]==-1)
            {
                right[idx]=size;
                break;
            }
            else
            {
                idx=right[idx];
            }
        }
    }

    if(size!=capacity-1) size++;

    return OUTPUT;
}
Elem* Cache::write(int addr, Data* cont) {
    int idx=0;
    while(idx!=-1)
    {
        if(addr==arr[idx]->addr)
        {
            arr[idx]->data=cont;
            return NULL;
        }
        else if(addr<arr[idx]->addr)
            idx=left[idx];
        else 
            idx=right[idx];
    }

    return put(addr,cont);
}
void Cache::print() {
	for (int i = 0; i < capacity; i++)
        arr[i]->print();
}
void Cache::preOrder() {
	for (int i = 0; i < capacity; i++)
        arr[i]->print();
}
void Cache::inOrder() {
    for (int i = 0; i < capacity; i++)
        arr[i]->print();
}



void Cache::Swap(int idx1, int idx2) {
    Elem* t=arr[idx1];      
    arr[idx1]=arr[idx2];    
    arr[idx2]=t;            

    int A=age[idx1];
    age[idx1]=age[idx2];
    age[idx2]=A;

    int L=left[idx1];
    left[idx1]=left[idx2];
    left[idx2]=L;

    int R=right[idx1];
    right[idx1]=right[idx2];
    right[idx2]=R;
}
Elem* Cache::outFIFO(){
    Elem* OUTPUT=new Elem(arr[0]->addr,arr[0]->data,arr[0]->sync);

    Elem** DECOYarr=new Elem*;

    size=0;
    for(int i=0;i<capacity;i++)
    {
        left[i]=-1;
        right[i]=-1;
        age[i]=-1;
    }

    for(int i=0;i<capacity;i++) DECOYarr[i]=new Elem(arr[i]->addr,arr[i]->data,arr[i]->sync);

    for(int i=0;i<capacity;i++) delete arr[i];
    for(int i=1;i<capacity;i++) put(DECOYarr[i]->addr, DECOYarr[i]->data);

    for(int i=0;i<capacity;i++) delete DECOYarr[i];
    delete DECOYarr;

    return OUTPUT;
}
Elem* Cache::outLIFO(){
    int youngest=age[0];
    for(int i=0;i<capacity;i++)
    {
        if(age[i]<=youngest) youngest=i;
    }

    Elem* OUTPUT=new Elem(arr[youngest]->addr,arr[youngest]->data,arr[youngest]->sync);

    for(int i=0;i<capacity;i++)
    {
        if(left[i]==youngest) left[i]=-1;
        if(right[i]==youngest) right[i]=-1;
    }

    age[youngest]=0;
    
    return OUTPUT;
}