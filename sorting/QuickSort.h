//https://dangky.tinhnguyenhetphcm.vn/result/12/MHX202214043252O507QPDQ

int QScomparecount=0, QSswapcount=0;

int MedianOf(int* ARRAY, int a, int b, int c){
    QScomparecount+=8;
    return ((ARRAY[a]>=ARRAY[b] && ARRAY[b]>=ARRAY[c])||(ARRAY[c]>=ARRAY[b] && ARRAY[b]>=ARRAY[a]))?b
          :((ARRAY[c]>=ARRAY[b] && ARRAY[b]>=ARRAY[a])||(ARRAY[b]>=ARRAY[a] && ARRAY[a]>=ARRAY[c]))?c
          :a;
}

int DivideReturnPivotPos(int* ARRAY, int left, int right){
    int pivot_pos=MedianOf(ARRAY,left,(left+right)/2,right);
    int Lidx=left-1, Ridx=right+1, temp;

    while(Lidx<Ridx)
    {
        Lidx++;

        QScomparecount++;

        if(ARRAY[Lidx]>=ARRAY[pivot_pos])
        {
            while(Lidx<Ridx)
            {
                Ridx--;

                QScomparecount++;

                if(ARRAY[Ridx]<=ARRAY[pivot_pos]) 
                {
                    QSswapcount++;

                    temp=ARRAY[Lidx];
                    ARRAY[Lidx]=ARRAY[Ridx];
                    ARRAY[Ridx]=temp;

                    QScomparecount+=2;

                    if(Lidx==pivot_pos) 
                    {
                        pivot_pos=Ridx;
                        Ridx++;
                    }
                    if(Ridx==pivot_pos) 
                    {
                        pivot_pos=Lidx;
                        Lidx--;
                    }

                    break;
                }
            }
        }
    }

    return pivot_pos;
}

void QuickSort(int* ARRAY, int left, int right){
    // std::cout<<"\n\nBEFORE: ARRAY: "; for(int i=left;i<=right;i++) std::cout<<" "<<ARRAY[i]; std::cout<<std::endl<<"from "<<left<<" to "<<right<<": ";
    if(left<right)
    {
        int pivot=DivideReturnPivotPos(ARRAY,left,right);
        // std::cout<<" PIVOT {idx: "<<pivot<<" value: "<<ARRAY[pivot]<<"}"<<"\nAFTER: ARRAY: "; for(int i=left;i<=right;i++) std::cout<<" "<<ARRAY[i];
        QuickSort(ARRAY,left,pivot-1);
        QuickSort(ARRAY,pivot+1,right);
    }
}