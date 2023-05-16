using namespace std;
void Print(int* ARRAY, int size){
    std::cout<<"\nArray: [";
    for(int i=0;i<size;i++)
    {
        std::cout<<*(ARRAY+i);
        std::cout<<((i<size-1)?", ":"");
    }
    std::cout<<"]\n";
}

void Print(int* ARRAY, int left, int right){
    std::cout<<"\nArray: [";
    for(int i=left;i<=right;i++)
    {
        std::cout<<*(ARRAY+i);
        std::cout<<((i!=right)?", ":"");
    }
    std::cout<<"]\n";
}

void RefreshRandomizer(){
    int N; cout<<"\nType number to randomize: "; cin>>N;
    for(int i=0;i<N%100;i++) rand();
    N=rand()%N;
    for(int i=0;i<rand()%N;i++) rand();
}

void UniqueRandomizer(int* ARRAY, int size){
    vector<int> RandArray;
    for(int i=1;i<=size;i++) RandArray.push_back(i);
    int itemleft=size, randomnumber;
    while(itemleft>0)
    {
        randomnumber=rand()%itemleft;
        ARRAY[itemleft-1]=RandArray[randomnumber];
        RandArray.erase(RandArray.begin()+randomnumber);
        itemleft--;
    }
}

void Randomizer(int* ARRAY, int size){
    vector<int> RandArray;
    for(int i=0;i<size;i++) ARRAY[i]=rand()%size;
}

bool sorted(int* ARRAY, int size){
    for(int i=1;i<size;i++)
        if(ARRAY[i]<ARRAY[i-1]) return false;

    return true;
}

int factorial(int n){
    if(n==1) return n;
    return n*factorial(n-1);
}