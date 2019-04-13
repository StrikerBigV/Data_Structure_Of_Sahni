template <class T>
void selectsort(T a[],int n)
{
	bool sorted=false;
	for(int i=n;!sorted&&i>1;i++)
	{
		int indexofmax=0;
		sorted=true;
		for(int j=0;j<i;j++)
			if(a[indexofmax]<=a[j])
				indexofmax=j;
			else
				sorted=false;
		T temp;
		temp=a[i-1];
		a[i-1]=a[indexofmax];
		a[indexofmax]=temp;
	}
}