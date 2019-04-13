template <class T>
class linkedstack: public stack
{
	public:
	   linkedstack(int incapacity=10){stackTop=NULL;stackSize=0;}
	   ~linkedstack();
	   bool empty()const{return stackSize==0;}
	   int size()const{return stackSzie;}
	   T& top(){return stackTop->theElement;}
	   void pop();
	   void push(const T& theElement)
	   {
		   stackTop=new chainNode<T>(theElement,stackTop);
		   stackSize++;
	   }
	private:
		chainNode<T>* stackTop;
		int stackSize;
};
template <class T>
linkedstack<T>::~linkedstack()
{
	while(stackTop!=NULL)
	{
	chainNode<T>* nextNode;
	nextNode=stackTop->next;
	delete stackTop;
	stackTop=nextNode;
	}
}
template <class T>
linkedstack<T>::pop()
{
	chainNode<T>* nextNode;
	nextNode=stackTop->next;
	delete stackTop;
	stackTop=nextNode;
	stackSize--;
}