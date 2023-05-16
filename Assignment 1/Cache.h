#ifndef CACHE_H
#define CACHE_H

#include "main.h"

class Cache {
        Elem** arr;
        int* age;
        int* left;
        int* right;

        int capacity;
        int size;
	public:
    Cache(int s){
        arr=new Elem*[s];
        age=new int[s];
        left=new int[s];
        right=new int[s];

        capacity=s;

        for(int i=0;i<capacity;i++)
        {
            left[i]=-1;
            right[i]=-1;
            age[i]=0;
        }

        size=0;
    }
    ~Cache() {
        for(int i=0;i<capacity;i++) delete arr[i];

        delete arr;

        delete[] age;
        delete[] left;
        delete[] right;
    }

    Data* read(int addr);
    Elem* put(int addr, Data* cont);
    Elem* write(int addr, Data* cont);
    void print();
    void preOrder();
    void inOrder();

    void Swap(int idx1, int idx2);
    Elem* outFIFO();
    Elem* outLIFO();
};
#endif