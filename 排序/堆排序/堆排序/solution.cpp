void shiftDown(int heapArray[],int i,int heapSize)
{
	int j=2*i+1;
	int temp=heapArray[i];
	while(j<heapSize)
	{
		if(heapArray[j]<heapArray[j+1])
			j++;
		if(heapArray[i]<heapArray[j])
			{
				heapArray[i]=heapArray[j];
				i=j;
				j=2*j+1;
		}
		heapArray[i]=temp;
	}
}
void heapSort(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		shiftDown(a,i,n);
	for(int i=n-1;i>=0;i--)
		{
			swap(a[0],a[i]);
			shiftDown(a,0,i);
	}
}