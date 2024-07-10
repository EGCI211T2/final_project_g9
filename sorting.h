void display(int a[],int N){
        int i;
       for(i=0;i<N;i++)
           cout<<a[i]<<" ";
       cout<<endl;
    
}

void swap(int & x,int &y)
{
        int temp=y;
        y=x;
        x=temp;
    
}
void bubbleSort(double a[],int N)
{
    int temp, i, j;
    for(i = 0; i < N-1; i++)  
    {
        for(j = 0; j < N-i-1; j++) 
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}