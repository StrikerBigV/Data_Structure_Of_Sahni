template <class T>
class maxHeap
{
	public:
		maxHeap(const int n);
		virtual ~maxHeap(){delete []heapArray;}
		bool isLeaf(int position)const{return 2*position>=heapSize;}
		int leftChild(int position)const{return 2*position+1;}
		int rightChild(int position)const{return 2*position+2;}
		int parent(int position)const{return position/2;}
		void shiftUp(int position);
		void shiftDown(int position);
		bool insert(const T& newNode);
		bool remove(int position,T& node);
	private:
		T* heapArray;
		int heapSize;
		int maxSize;
		void buildHeap();
}
template <class T>
void maxHeap::shiftUp(int position)
{
	int temppos=position;
	T temp=heapArray[temppos];
	while(( temppos>0)&&(heapArray[temppos]>heapArray[parent(temppos)])
	{
		heapArray[temppos]=heapArray[parent(temppos)];
		temppos=parent(temppos);
	}
	heapArray[temppos]=temp;
}
template <class T>
void maxHeap::shiftDown(int position)
{
	int i=position;
	int j=2*i+1;
	T temp=heapArray[i];
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
		else break;
	}
	heapArray[i]=temp;
}
void maxHeap::buildHeap()
{
	for(int i=heapSize/2-1;i>=0;i--)
		shiftDown(i);
}
bool insert(const T& newNode)
{
	if(heapSize==maxSize)
		return false;
	headArray[heapSize]=newNode;
	shiftUp(heapSize);
	heapSize++;
}
bool remove(int position,T& node)
{
	if((position<0)||(position>=heapSize))
		return false;
	T temp=heapArray[position];
	heapArray[position]=heapArray[--heapSize];
	if(heapArray[position]<heapArray[parent(position)])
		shiftDown(position);
	else shiftUp(position);
	node=temp;
	return true;
}