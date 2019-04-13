template <class T>
void insertsort(T a[],int n)
{
	for(int i=0;i<n;i++)
	{
		T t=a[i];
		for(int j=i-1;j>0&&t<a[j];j--)
			a[j+1]=a[j];
		a[j+1]=t;
	}
}