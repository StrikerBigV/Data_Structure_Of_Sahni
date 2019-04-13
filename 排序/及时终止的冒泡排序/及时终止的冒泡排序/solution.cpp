template <class T>
bool bubble(T a[],int n)
{
	bool swapped=false;
	for(int i=0;i<n;i++)
		if(a[i]>a[i+1])
		{
			T& temp;
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
			swapped=true;
		}
    return swapped;
}
template <class T>
void bubblesort(T a[],int n)
{
	for(int i=n;i>1&&bubble(a[],i);i--);
}