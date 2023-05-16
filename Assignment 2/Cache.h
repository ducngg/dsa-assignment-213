#ifndef CACHE_H
#define CACHE_H

#include "main.h"


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Main memory ////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


Elem** MAIN;        //Main memory
int MAINSIZE;       //Current size


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Search Engine //////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


//Used for BST
class Node{
    public:
    int key;
    Elem* value;
    Node* left;
    Node* right;

    Node(int key, Elem* value):key(key),value(value),left(NULL),right(NULL){}
};

class SearchEngine {
    //TODO
    public:
    Node* root;

    SearchEngine():root(NULL){}
    virtual ~SearchEngine(){}

    virtual void clear(Node* n)=0;
    virtual Node* search(int key)=0;
    virtual void insert(Node* n)=0;
    virtual Node* remove(Node* r, int key)=0;
    virtual void inOrder(Node* n)=0;
    virtual void preOrder(Node* n)=0;
    virtual void inOrder()=0;
    virtual void preOrder()=0;
};

class BST : public SearchEngine {
    //TODO
    public:

    BST(){};
    ~BST(){
        clear(root);
    }
    void clear(Node* n);
    Node* search(int key);
    void insert(Node* n);
    Node* remove(Node* r, int key);
    void inOrder(Node* n);
    void preOrder(Node* n);
    void inOrder();
    void preOrder();
};

void BST::clear(Node* n){
    if(!n) return;
    if(n->left) clear(n->left);
    if(n->right) clear(n->right);
    delete n;
}

Node* BST::search(int key){
    Node* r=root;
    while(r)
    {
        if(r->key==key) return r;
        else if(key<r->key) r=r->left;
        else r=r->right;
    }
    return NULL;
}

void BST::insert(Node* n){
    if(!root)
    {
        root=n;
        return;
    }

    Node* r=root;
    while(true)
    {
        if(n->key<=r->key)
        {
            if(r->left) r=r->left;
            else
            {
                r->left=n;
                break;
            }
        }
        else
        {
            if(r->right) r=r->right;
            else
            {
                r->right=n;
                break;
            }
        } 
    }
}

Node* BST::remove(Node* r, int key){
    if(key<r->key){
        r->left=remove(r->left,key);
        return r;
    }
    else if(key>r->key){
        r->right=remove(r->right,key);
        return r;
    }
    else{
        if((r->left==NULL)||(r->right==NULL)){
            Node* newRoot=((r->left)?r->left:r->right);           
            delete r;
            return newRoot; 
        }
        else{                
            Node* minRight=r->right;
            while(minRight->left) minRight=minRight->left;

            r->key=minRight->key;                               //Copy minRight to the node that needs to be removed
            r->value=minRight->value;

            r->right=remove(r->right,minRight->key);            //Delete minRight instead

            return r;
        }
    }
}

void BST::inOrder(Node* n){
    if(!n) return;
    if(n->left) inOrder(n->left);
    n->value->print();
    if(n->right) inOrder(n->right);
}

void BST::preOrder(Node* n){
    if(!n) return;
    n->value->print();
    if(n->left) preOrder(n->left);
    if(n->right) preOrder(n->right);
}

void BST::inOrder(){
    cout<<"Print BST in inorder:\n";
    inOrder(root);
}

void BST::preOrder(){
    cout<<"Print BST in preorder:\n";
    preOrder(root);
}


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Replacement Policies ///////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


#define MAX true
#define MIN false

class LNode{
    public:
    int count;
    Elem* value;
    LNode* next;
    LNode* prev;

    //Initialize count as 1
    LNode(int count=1, Elem* value=NULL, LNode* prev=NULL, LNode* next=NULL):count(count),value(value),next(next),prev(prev){}
};

class List{
    public:
    LNode* head;                //Least recently used
    LNode* tail;                //Most recently used

    List(){
        head=new LNode();       //Dummy nodes at head and tail
        tail=new LNode();
        head->next=tail;
        tail->prev=head;
    }
    ~List(){
        LNode* decoy=head;
        while(decoy!=NULL)
        {
            decoy=decoy->next;
            delete head;
            head=decoy;
        }
    }
    bool empty();
    void push(Elem* value, int count);          //Push back at tail
    void pop(Elem* value);                      //Delete
    LNode* nodeOf(int addr);                    //Return the node of that addr
    Elem* leastRecentFind(int count);
    Elem* mostRecentFind(int count);

    void print(){                               //For testing
        cout<<"---"<<endl;
        for(LNode* n=head;n!=tail;n=n->next)
        {
            if(n!=head && n!=tail)
            {
                cout<<n->count<<" ";
                n->value->print();
            }
        }
        cout<<"---"<<endl;
    }
};

bool List::empty(){return head->next==tail;}
void List::push(Elem* value, int count=1){
    LNode* n=new LNode(count,value,tail->prev,tail);

    tail->prev->next=n;
    tail->prev=n;
}
void List::pop(Elem* value){
    for(LNode* n=head;n!=tail;n=n->next)
    {
        if(n->value && n->value==value)
        {
            n->prev->next=n->next;
            n->next->prev=n->prev;
            break;
        }
    }
}
LNode* List::nodeOf(int addr){
    for(LNode* n=head;n!=tail;n=n->next)
    {
        if(n->value && n->value->addr==addr) return n;
    }
    return NULL;
}
Elem* List::leastRecentFind(int count){
    for(LNode* n=head;n!=tail;n=n->next)
    {
        if(n->value && n->count==count) return n->value;
    }
    return NULL;
}
Elem* List::mostRecentFind(int count){
    for(LNode* n=tail;n!=head;n=n->prev)
    {
        if(n->value && n->count==count) return n->value;
    }
    return NULL;
}

void Swap(LNode* x, LNode* y){LNode temp=*x;*x=*y;*y=temp;}

class ReplacementPolicy {
    public:
    //TODO

    bool Max;                   //Max heap or Min heap
    LNode** HeapArray;          //Array represents heap

    void ReheapUp(int idx);
    void ReheapDown(int idx);

    ReplacementPolicy(bool Max);
    virtual ~ReplacementPolicy();
  
    int Parent(int idx){return (idx-1)/2;}
    int Left(int idx){return (2*idx+1);}
    int Right(int idx){return (2*idx+2);}
    virtual void insert(Elem* value);
    virtual void remove(Elem* value);
    virtual void trigger(int addr);             //Update the relative element in array 

    virtual Elem* choose(int count)=0;
    virtual void print()=0;
};

ReplacementPolicy::ReplacementPolicy(bool Max){
    MAIN=new Elem*[MAXSIZE];
    MAINSIZE=0;

    this->Max=Max;
    HeapArray=new LNode*[MAXSIZE];
}
ReplacementPolicy::~ReplacementPolicy(){
    for(int i=0;i<MAINSIZE;i++) delete HeapArray[i];
    delete[] HeapArray;

    for(int i=0;i<MAINSIZE;i++) delete MAIN[i];
    delete[] MAIN;

    MAINSIZE=0;
}
void ReplacementPolicy::insert(Elem* value){
    HeapArray[MAINSIZE-1]=new LNode(1,value);       //Initialize count as 1
    ReheapUp(MAINSIZE-1);
}
void ReplacementPolicy::remove(Elem* value){
    for(int i=0;i<MAINSIZE;i++)                                         
    {
        if(HeapArray[i]->value==value)
        {
            Swap(HeapArray[i],HeapArray[MAINSIZE-1]);
            MAINSIZE--;
            ReheapDown(i);

            break;
        }
    }
}
void ReplacementPolicy::ReheapUp(int idx){
    //Check if it's root
    if(idx==0) return;

    //Check if need to be ReheapUp
    if( (Max && (HeapArray[Parent(idx)]->count<HeapArray[idx]->count))
        ||
        (!Max && (HeapArray[Parent(idx)]->count>HeapArray[idx]->count)) )
    {
        Swap(HeapArray[idx], HeapArray[Parent(idx)]);
        ReheapUp(Parent(idx));
    }
    else return;
}
void ReplacementPolicy::ReheapDown(int idx){
    if(idx>=MAINSIZE) return;

    int TheChosenOne;

    //Check if it's leaf, if not leaf then choose TheChosenOne
    if(Left(idx)<MAINSIZE)
    {
        if(Right(idx)<MAINSIZE) 
        {
            if(Max) TheChosenOne=(HeapArray[Right(idx)]->count>=HeapArray[Left(idx)]->count) ? Right(idx) : Left(idx);  
                        
            else    TheChosenOne=(HeapArray[Left(idx)]->count<=HeapArray[Right(idx)]->count) ? Left(idx) : Right(idx);  
        }   
        else 
        TheChosenOne=Left(idx);
    }
    else return;

    //Check if need to be ReheapDown
    if((Max && HeapArray[idx]->count<=HeapArray[TheChosenOne]->count)
        ||
      (!Max && HeapArray[idx]->count>=HeapArray[TheChosenOne]->count))
    {
        Swap(HeapArray[idx],HeapArray[TheChosenOne]);
        ReheapDown(TheChosenOne);
    }
    else return;
}
void ReplacementPolicy::trigger(int addr){
    for(int i=0;i<MAINSIZE;i++)
    {
        if(HeapArray[i]->value->addr==addr)
        {
            HeapArray[i]->count++;
            Swap(HeapArray[i],HeapArray[MAINSIZE-1]);

            MAINSIZE--;
            ReheapDown(i);

            MAINSIZE++;
            ReheapUp(MAINSIZE-1);

            return;
        }
    }
}



class MFU : public ReplacementPolicy {
    //TODO
    public:
    MFU() : ReplacementPolicy(MAX){}
    ~MFU(){}

    void print(){
        for(int i=MAINSIZE-1;i>=0;i--) HeapArray[i]->value->print();
    }
    Elem* choose(int count){
        return HeapArray[0]->value;
    }
};

class LFU : public ReplacementPolicy {
    //TODO
    public:
    LFU() : ReplacementPolicy(MIN){}
    ~LFU(){}

    void print(){
        for(int i=0;i<MAINSIZE;i++) HeapArray[i]->value->print();
    }
    Elem* choose(int count){
        return HeapArray[0]->value;
    }
};

class MFRU: public ReplacementPolicy {
    //TODO
    public:
    List MyList;

    MFRU() : ReplacementPolicy(MAX){}
    ~MFRU(){}

    void print(){
        LNode** decoyArray=new LNode*[MAINSIZE];
        List decoyList;
        LNode* n=MyList.head->next;
        for(int i=0;i<MAINSIZE;i++)
        {
            decoyList.push(n->value,n->count);   //copy MyList to decoyList
            decoyArray[i]=HeapArray[i];          //copy HeapArray to decoyArray

            n=n->next;
        }

        int counter=HeapArray[0]->count;                //Check the count from high to low
        while(!decoyList.empty())
        {
            Elem* e=decoyList.mostRecentFind(counter);
            while(!e)                                   //If no element has that count, count--
            {
                counter--;
                e=decoyList.mostRecentFind(counter);
            }
            while(e)                                    //Print from most recently used of that count
            {
                for(int i=0;i<MAINSIZE;i++)
                {
                    if(decoyArray[i]->value==e)
                    {
                        e->print();

                        decoyList.pop(e);
                        decoyArray[i]->value=NULL;

                        break;
                    }
                }
                e=decoyList.mostRecentFind(counter);
            }
        }

        delete[] decoyArray;
    }
    void insert(Elem* value){
        ReplacementPolicy::insert(value);
        MyList.push(value);
    }
    void remove(Elem* value){
        ReplacementPolicy::remove(value);
        MyList.pop(value);
    }
    Elem* choose(int count){
        return MyList.mostRecentFind(count);
    }
    void trigger(int addr){
        ReplacementPolicy::trigger(addr);
        LNode* n=MyList.nodeOf(addr);       //Find that node in list, then put it to the top
        MyList.pop(n->value);
        MyList.push(n->value,n->count+1);
        
        delete n;
    }
};

class LFRU: public ReplacementPolicy {
    //TODO
    public:
    List MyList;

    LFRU() : ReplacementPolicy(MIN){}
    ~LFRU(){}

    void print(){
        LNode** decoyArray=new LNode*[MAINSIZE];
        List decoyList;
        LNode* n=MyList.head->next;
        for(int i=0;i<MAINSIZE;i++)
        {
            decoyList.push(n->value,n->count);   //copy MyList to decoyList
            decoyArray[i]=HeapArray[i];          //copy HeapArray to decoyArray

            n=n->next;
        }

        int counter=HeapArray[0]->count;                //Check the count from low ot high
        while(!decoyList.empty())
        {
            Elem* e=decoyList.leastRecentFind(counter);
            while(!e)                                   //If no element has that count, count++
            {
                counter++;
                e=decoyList.leastRecentFind(counter);
            }
            while(e)                                    //Print from least recently used of that count
            {
                for(int i=0;i<MAINSIZE;i++)
                {
                    if(decoyArray[i]->value==e)
                    {
                        e->print();

                        decoyList.pop(e);
                        decoyArray[i]->value=NULL;

                        break;
                    }
                }
                e=decoyList.leastRecentFind(counter);
            }
        }

        delete[] decoyArray;
    }
    void insert(Elem* value){
        ReplacementPolicy::insert(value);
        MyList.push(value);
    }
    void remove(Elem* value){
        ReplacementPolicy::remove(value);
        MyList.pop(value);
    }
    Elem* choose(int count){
        return MyList.leastRecentFind(count);
    }
    void trigger(int addr){
        ReplacementPolicy::trigger(addr);
        LNode* n=MyList.nodeOf(addr);       //Find that node in list, then put it to the top
        MyList.pop(n->value);
        MyList.push(n->value,n->count+1);
        
        delete n;
    }
};

#endif