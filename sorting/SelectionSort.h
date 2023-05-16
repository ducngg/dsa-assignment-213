int SeScomparecount=0, SeSswapcount=0;

void SelectionSort(int* ARRAY, int size){
    int MIN, minidx, temp;
    for(int i=0;i<size-1;i++)
    {
        MIN=ARRAY[i];
        minidx=i;
        
        //Loop from i+1 to the end to find the smallest
        for(int j=i+1;j<size;j++)
        {
            SeScomparecount++;

            if(MIN>ARRAY[j])
            {
                MIN=ARRAY[j];
                minidx=j;
            }
        }
        SeSswapcount++;

        temp=ARRAY[i];
        ARRAY[i]=ARRAY[minidx];
        ARRAY[minidx]=temp;
    }
}