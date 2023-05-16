#include "main.h"

Cache::Cache(SearchEngine* s,ReplacementPolicy* r):rp(r),s_engine(s) {}
Cache::~Cache(){
	delete s_engine;
    delete rp;
}

// Memories used, all of them share the same Elem*.
//
// [memory]                 [used for]                  [counter]                       [store data as]
// Elem** MAIN              main memory                 int MAINSIZE                    Elem*
// Tree MyTree              se buffer                                                   Node*
// LNode** HeapArray        rp buffer                   int MAINSIZE                    LNode*
// List MyList              recently used                                               LNode*

bool s=true;        //sync related

Data* Cache::read(int addr) {
    Node* n=s_engine->search(addr);
    if(n)           //If cache contains addr, trigger addr here
    {
        rp->trigger(addr);
        return n->value->data;
    }
    else            //If cache doesn't contains addr
    {
        return NULL;
    }
}
Elem* Cache::put(int addr, Data* cont) {
    Elem* value=new Elem(addr,cont,s);
    Node* n=new Node(addr,value);

    s=true;

    if(MAINSIZE<MAXSIZE)
    {
        //Nothing going to be replaced, just add in the memories
        MAINSIZE++;

        s_engine->insert(n);            //Add in se buffer
        rp->insert(value);              //Add in rp buffer
        MAIN[MAINSIZE-1]=value;         //Add in main

        return NULL;
    }
    else
    {
        //Choose the element to be replaced base on the 'count' of heap's top
        Elem* replace=rp->choose(rp->HeapArray[0]->count);     
        rp->remove(replace);                                                //Remove in rp buffer       //MAINSIZE-- here
        s_engine->root=s_engine->remove(s_engine->root,replace->addr);      //Remove in se buffer
        for(int i=0;i<MAXSIZE;i++)                                          //Remove in main
        {
            if(MAIN[i]==replace)
            {
                delete MAIN[i];
                MAIN[i]=NULL;
                break;
            }
        }
        
        MAINSIZE++;                                                                                     //MAINSIZE++ here
        s_engine->insert(n);            //Add in se buffer
        rp->insert(value);              //Add in rp buffer
        for(int i=0;i<MAXSIZE;i++)      //Add in main
        {
            if(MAIN[i]==NULL)
            {
                MAIN[i]=value;
                break;
            }
        }           

        return replace;
    }
}
Elem* Cache::write(int addr, Data* cont) {
    if(read(addr))  //If cache contains addr, triggered addr in read(addr) function.
    {
        Node* n=s_engine->search(addr);  
        n->value->data=cont;
        n->value->sync=false;
        return NULL;
    }
    else            //If cache doesn't contain addr.
    {
        s=false;
        return put(addr,cont);
    }
}
void Cache::printRP() {
    rp->print();
}
void Cache::printSE() {
    s_engine->inOrder();
    s_engine->preOrder();
}
void Cache::printLP() {
    cout<<"Prime memory\n";                             //Print prime memory
    for(int i=0;i<MAINSIZE;i++) MAIN[i]->print();

    Elem** HashTable=new Elem*[MAXSIZE];                //Initialize HashTable
    for(int i=0;i<MAXSIZE;i++) HashTable[i]=NULL;

    for(int i=0;i<MAINSIZE;i++)                         //Put elements to HashTable
    {
        int idx=MAIN[i]->addr%MAXSIZE;
        while(HashTable[idx])
        {
            idx++;
            if(idx==MAXSIZE) idx=0;
        }
        HashTable[idx]=MAIN[i];
    }

    cout<<"Hash table memory\n";                        //Print HashTable
    for(int i=0;i<MAXSIZE;i++) if(HashTable[i]) HashTable[i]->print();
    
    delete[] HashTable;
}
