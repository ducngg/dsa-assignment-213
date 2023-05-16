int binarySearch(int arr[], int left, int right, int x){
    int mid;
    if(right>=left)
    {
        mid=left+(right-left)/2;
        
        cout << "We traverse on index: " << mid << endl;
        if(x==arr[mid])
        {
            return mid;
        }
        else if(x<arr[mid])
        {
            return binarySearch(arr,left,mid-1,x);
        }
        else
        {
            return binarySearch(arr,mid+1,right,x);
        }
    }
    else return -1;
}

//////////////
//////////////
//////////////

bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
    // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
    map< int,pair<int,int> > Hash;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            pair<int,int> p(arr[i],arr[j]);
            
            if(Hash.find(arr[i]+arr[j])==Hash.end()) //that sum value is not recorded
            {
                Hash[arr[i]+arr[j]]=p;
            }
            else    //the sum has existed -> the pair makes that sum is in the hashtable
            {
                pair1=Hash[arr[i]+arr[j]];
                pair2=p;

                return true;
            }
        }
    }
    return false;
}

//////////////
//////////////
//////////////

#include <sstream>
#include <string>
#include <math.h>
int foldShift(long long key, int addressSize)
{
    if(key<0) key=-key;
    if(key<10) return key;
    
    stringstream ss;
    long long int sum=0;
    long long int value;
    string s=to_string(key);
    for(unsigned int i=0;i<s.length();i+=addressSize)
    {
        ss<<s.substr(i,addressSize);
        ss>>value;
        sum+=value;
        ss.clear();
    }
    
    return sum%(long long int)(pow(10,addressSize));
}


int rotation(long long value, int addressSize)
{
    if(value<0) value=-value;
    if(value<10) return foldShift(value,addressSize);
    
    int last=value%10;
    value=value/10;
    long long int weight=1;
    while(weight<value) weight*=10;
    value+=last*weight;
    
    return foldShift(value,addressSize);
}

//////////////
//////////////
//////////////

int interpolationSearch(int arr[], int left, int right, int x)
{
    int pos;
    if(right>=left && x>=arr[left] && x<=arr[right])
    {
        pos=left+(x-arr[left])*(right-left)/(arr[right]-arr[left]);
        
        cout << "We traverse on index: " << pos << endl;
        if(x==arr[pos])
        {
            return pos;
        }
        else if(x<arr[pos])
        {
            return interpolationSearch(arr,left,pos-1,x);
        }
        else
        {
            return interpolationSearch(arr,pos+1,right,x);
        }
    }
    else return -1;
}


//////////////
//////////////
//////////////

int jumpSearch(int arr[], int key, int size) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int jump=floor(sqrt(size));
    for(int i=0;i<size;i+=jump)
    {
        cout<<i<<" ";
        if(arr[i]==key) return i;
        if(arr[i]>key)
        {
            for(int j=(i-jump)+1;j<i;j++)
            {
                cout<<j<<" ";
                if(arr[j]==key)
                {
                    return j;
                }

                if(arr[j]>key) break;
            }
            return -1;
        }
        if(i+jump>=size)
        {
            for(int j=i+1;j<=size;j++)
            {
                cout<<j<<" ";
                if(arr[j]==key)
                {
                    return j;
                }

                if(arr[j]>key) break;
            }
            return -1;
        }
    }
    return -1;
}

//////////////
//////////////
//////////////

#include <math.h>
long int midSquare(long int seed)
{
    seed=seed*seed;
    seed=seed/100;
    return seed%10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed%mod;
}

int sizeOf(long int n){ 
    int size=0;
    long int n2=n;
    while(n2!=0)
    {
        n2/=10;
        size++;
    }
    return size;
}

int take(long int n, int idx){
    int size=0;
    long int n2=n;
    while(n2!=0)
    {
        n2/=10;
        size++;
    }

    for(int i=1;i<idx;i++)
    {
        n/=10;
    }
    
    return n%10;
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{
    long int OUTPUT=0;
    for(int i=size-1;i>=0;i--)
    {
        OUTPUT+=pow(10,size-i-1)*take(seed,sizeOf(seed)-extractDigits[i]);
    }
    return OUTPUT;
}

//////////////
//////////////
//////////////

