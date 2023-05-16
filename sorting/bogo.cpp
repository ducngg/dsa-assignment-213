#include"/Users/duc/Downloads/WorkSpace/CodeCpp/DSA_213/cpplibduc.h"
#include"InsertionSort.h"
#include"SelectionSort.h"
#include"BubbleSort.h"
#include"QuickSort.h"
#include"MergeSort.h"
#include"Misc.h"

int main(){
    int n;
    cout<<"Array size: ";
    nAgain:
    cin>>n;
    if(n<2) {cout<<"\n! Invalid size !"; goto nAgain;}
    int ARRAY[n];

    RefreshRandomizer();

    string INPUT;
    CHOOSERANDOMIZERAGAIN:
    cout<<"\n->'unique' or 'normal' randomizing? "; cin>>INPUT;
    if(INPUT=="unique") UniqueRandomizer(ARRAY,n);
    else if(INPUT=="normal") Randomizer(ARRAY,n);
    else goto CHOOSERANDOMIZERAGAIN;
    Print(ARRAY,n);

    int estimated=factorial(n);
    int printstep=estimated/1000;
    if(printstep<1000) printstep=1;
    int count=0;

    while(!sorted(ARRAY,n))
    {
        UniqueRandomizer(ARRAY,n);
        count++;
        if(count%printstep==0) cout<<"Count: "<<count<<"     Estimated: "<<estimated<<endl;
    }
    cout<<"!! DONE Bogo Sort !! "<<count<<"\n";
    Print(ARRAY,n);

}