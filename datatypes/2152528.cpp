#include<iostream>
#include<cstdlib>
#include<math.h>
#include<iomanip>

#define SIZE 53

using namespace std;

void printArr(int* arr, int size){

    cout<<"Idx   Value\n";
    for(int i=0;i<size;i++)
    {
        cout<<setw(6)<<left<<i<<arr[i]<<endl;
    }
}
void jumpSearch(int* arr, int size, int key){
    int jump=floor(sqrt(size));
    if(size<4) jump=1;

    cout<<"Key: "<<key<<" Jump: "<<jump<<endl;
    cout<<"Idx   Value\n";
    for(int i=0;i<size;i+=jump)
    {
        cout<<setw(6)<<left<<i<<arr[i]<<endl;
        if(arr[i]==key)
        {
            cout<<"! FOUNDED !\n";
            return;
        }

        if(arr[i]>key)
        {
            cout<<"BACKWARD SEARCHING\n";
            for(int j=i-1;j>i-jump;j--)
            {
                cout<<setw(6)<<left<<j<<arr[j]<<endl;
                if(arr[j]==key)
                {
                    cout<<"! FOUNDED !";
                    return;
                }

                if(arr[j]<key) break;
            }
            cout<<"! CAN'T FOUND !\n";
            return;
        }
    }
    cout<<"! CAN'T FOUND !\n";
}

int main(){
    int arr[SIZE];
    int key;

    for(int i=0;i<SIZE;i++)
    {
        arr[i]=rand()%10+i*10;
    }
    printArr(arr,SIZE);

    for(int i=0;i<10;i++)
    {
        cout<<"\n\nKEY: ";cin>>key;
        cout<<"Jump search function: \n";
        jumpSearch(arr,SIZE,key);
    }
}
