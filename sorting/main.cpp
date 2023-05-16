#include"/Users/duc/Downloads/WorkSpace/CodeCpp/DSA_213/cpplibduc.h"
#include"InsertionSort.h"
#include"SelectionSort.h"
#include"BubbleSort.h"
#include"QuickSort.h"
#include"MergeSort.h"
#include"Misc.h"

using namespace std;

int main(){
    int n;
    cout<<"Array size: ";
    nAgain:
    cin>>n;
    if(n<2) {cout<<"\n! Invalid size !"; goto nAgain;}
    int ARRAY[n], ARRAYCOPY[n], ARRAYCOPY2[n], ARRAYCOPY3[n], ARRAYCOPY4[n];

    RefreshRandomizer();

    string INPUT;
    CHOOSERANDOMIZERAGAIN:
    cout<<"\n->'unique' or 'normal' randomizing? "; cin>>INPUT;
    if(INPUT=="unique") UniqueRandomizer(ARRAY,n);
    else if(INPUT=="normal") Randomizer(ARRAY,n);
    else goto CHOOSERANDOMIZERAGAIN;
    
    for(int i=0;i<n;i++) 
    {
        ARRAYCOPY[i]=ARRAY[i];
        ARRAYCOPY2[i]=ARRAY[i];
        ARRAYCOPY3[i]=ARRAY[i];
        ARRAYCOPY4[i]=ARRAY[i];
    }

    Print(ARRAY,n);

    InsertionSort(ARRAY,n);
    ShellSort(ARRAYCOPY,n);
    SelectionSort(ARRAYCOPY2,n);
    BubbleSort(ARRAYCOPY3,n);
    QuickSort(ARRAYCOPY4,0,n-1);

    //Print(ARRAYCOPY2,n);
    cout<<"\nFINAL:";
    Print(ARRAYCOPY4,n);
    
    cout<<setw(25)<<left<<"\nInsertion sort: "<<setw(11)<<right<<IScomparecount<<" comparisons, "<<setw(11)<<right<<ISswapcount<<" swaps."
        <<setw(25)<<left<<"\nShell sort: "<<setw(11)<<right<<SScomparecount<<" comparisons, "<<setw(11)<<right<<SSswapcount<<" swaps."
        <<setw(25)<<left<<"\nSelection sort: "<<setw(11)<<right<<SeScomparecount<<" comparisons, "<<setw(11)<<right<<SeSswapcount<<" swaps."
        <<setw(25)<<left<<"\nBubble sort: "<<setw(11)<<right<<BScomparecount<<" comparisons, "<<setw(11)<<right<<BSswapcount<<" swaps."
        <<setw(25)<<left<<"\nQuick sort: "<<setw(11)<<right<<QScomparecount<<" comparisons, "<<setw(11)<<right<<QSswapcount<<" swaps."

        <<"\n\n";
}