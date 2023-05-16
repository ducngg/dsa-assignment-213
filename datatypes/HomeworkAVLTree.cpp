void rprintInorder(Node* n){
    if(!n) return;
    
    if(n->pLeft) rprintInorder(n->pLeft);
    cout<<n->data<<" ";
    if(n->pRight) rprintInorder(n->pRight);
}
void printInorder(){
    rprintInorder(root);
}
bool search(int x){
    if(!root) return false;
    
    Node* r=root;
    while(true)
    {
        if(x==r->data) return true;
        else if(x<r->data)
        {
            if(!r->pLeft) return false;
            r=r->pLeft;
        }
        else 
        {
            if(!r->pRight) return false;
            r=r->pRight;
        }
    }
}
void rclear(Node* n){
    if(!n) return;
    
    if(n->pLeft) rclear(n->pLeft);
    if(n->pRight) rclear(n->pRight);
    delete n;
}
void clear(){
    rclear(root);
}

////////////
////////////
////////////


//Helping functions

Node* rotateLeft(Node* root){
    Node* newRoot=root->pRight;
    root->pRight=newRoot->pLeft;
    newRoot->pLeft=root;
    
    return newRoot;
}

Node* rotateRight(Node* root){
    Node* newRoot=root->pLeft;
    root->pLeft=newRoot->pRight;
    newRoot->pRight=root;
    
    return newRoot;
}

Node* insert(Node* n, T value){
    if(!n) return new Node(value);
 
    if(value<n->data) n->pLeft=insert(n->pLeft,value);
    else n->pRight=insert(n->pRight,value);

    int balance=getHeightRec(n->pLeft)-getHeightRec(n->pRight);
    
    //Left Left
    if(balance>1 && value<n->pLeft->data)
        return rotateRight(n);
        
    //Right Right
    if(balance<-1 && value>=n->pRight->data)
        return rotateLeft(n);
        
    //Left Right
    if(balance>1 && value>=n->pLeft->data)
    {
        n->pLeft=rotateLeft(n->pLeft);
        return rotateRight(n);
    }
    
    //Right Left
    if(balance<-1 && value<n->pRight->data)
    {
        n->pRight = rotateRight(n->pRight);
        return rotateLeft(n);
    }
    
    return n;
}

void insert(const T &value){
    //TODO
    root=insert(root,value);
}


////////////
////////////
////////////

//Helping functions
Node* maxOf(Node* n)
{
    Node* decoy=n;
    while(!decoy->pRight) decoy=decoy->pRight;
    return decoy;
}
Node* minOf(Node* n)
{
    Node* decoy=n;
    while(!decoy->pLeft) decoy=decoy->pLeft;
    return decoy;
}
int getBalance(Node* n){
    if(!n) return 0;
    return getHeightRec(n->pLeft)-getHeightRec(n->pRight);
}
Node* remove(Node* n, T value){
    if(value<n->data) n->pLeft=remove(n->pLeft,value);
    else if(value>n->data) n->pRight=remove(n->pRight,value);
    else //value==n->data
    {
        if(!n->pLeft && n->pRight)
        {
            *n=*n->pRight; 
            delete n->pRight;
            n->pRight=NULL;
        }
        else if(n->pLeft && !n->pRight)
        {
            *n=*n->pLeft; 
            delete n->pLeft;
            n->pLeft=NULL;
        }
        else if(!n->pLeft && !n->pRight)
        {
            delete n;
            n=NULL;
        }
        else
        {
            Node* minR=minOf(n->pRight);
 
            n->data=minR->data;
 
            n->pRight=remove(n->pRight,minR->data);
        }
    }

    if(!n) return n;

    //Left Left
    if(getBalance(n)>1 && getBalance(n->pLeft)>=0)
        return rotateRight(n);
        
    //Right Right
    if(getBalance(n)<-1 && getBalance(n->pRight)<=0)
        return rotateLeft(n);
        
    //Left Right
    if(getBalance(n)>1 && getBalance(n->pLeft)>0)
    {
        n->pLeft=rotateLeft(n->pLeft);
        return rotateRight(n);
    }
    
    //Right Left
    if(getBalance(n)<-1 && getBalance(n->pRight)>0)
    {
        n->pRight = rotateRight(n->pRight);
        return rotateLeft(n);
    }
    
    //Not imbalanced
    return n;
}

void remove(const T &value){
    //TODO
    root=remove(root,value);
}