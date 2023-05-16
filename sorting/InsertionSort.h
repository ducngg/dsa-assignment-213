int IScomparecount=0, ISswapcount=0, SScomparecount=0, SSswapcount=0;

void InsertionSort(int* ARRAY, int size){
    int temp;
    for(int i=1;i<size;i++)
    {
        for(int j=i;j>0;j--)
        {
            IScomparecount++;
            if(ARRAY[j]<ARRAY[j-1])
            {
                ISswapcount++;

                temp=ARRAY[j];
                ARRAY[j]=ARRAY[j-1];
                ARRAY[j-1]=temp;
            }
            else break;
        }
    }
}

void ShellSort(int* ARRAY, int size){
    int temp;
    int k=1;
    while(k*3+1<=size) k=3*k+1;
    
    while(k>=1)
    {
        //Total "k" segments, loop for each segment "i".
        for(int i=0;i<k;i++)
            //Loop for all elements in segment i: j=i+k, j=i+2k... (don't care first element j=i)
            for(int j=i+k;j<size;j+=k)
                //Backward compare process for each element in one segment.
                for(int s=j;s>=k;s-=k)
                {
                    SScomparecount++;

                    if(ARRAY[s]<ARRAY[s-k])
                    {
                        SSswapcount++;

                        temp=ARRAY[s];
                        ARRAY[s]=ARRAY[s-k];
                        ARRAY[s-k]=temp;
                    }
                    else break;
                }
        //Just for viewing after each "k";
        //std::cout<<"{"<<k<<"}";Print(ARRAY,size);

        k=(k-1)/3;
    }
}