int BScomparecount=0, BSswapcount=0;

void BubbleSort(int* ARRAY, int size){
    int temp;
    bool SORTED;
    for(int i=0;i<size-1;i++)
    {
        if(SORTED) break;
        SORTED=true; //If in this very loop, nothing has to be swapped, the array has been sorted

        //Loop from the end to "i"
        for(int j=size-1;j>i;j--)
        {
            BScomparecount++;

            if(ARRAY[j]<ARRAY[j-1])
            {
                BSswapcount++;

                temp=ARRAY[j];
                ARRAY[j]=ARRAY[j-1];
                ARRAY[j-1]=temp;

                SORTED=false;
            }
        }
    }
}