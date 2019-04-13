template <class T>
class linkedqQueue: public Queue
{
	public:
		linkedQueue(int incapacity){queueFront=NULL;queueBack=NULL;queueSize=0;}
		~linkedQueue();
		bool empty(){return queueSize==0;}
		int size(){return queueSize;}
		void pop();
		void push(const T& theElement);
}
template <class T>
linkedQueue<T>::~linkedQueue()
{
	while(!queueFront==queueBack)
		{
			chainNode<T>* nextNode=queueFront->next;
			delete queueFront;
			queueFront=nextNode;
	}
}
template <class T>
void linkedQueue<T>::pop()
{
	if(empty())
		return 1;
	chainNode<T>* nextNode=queue->next;
	delete queueFront;
	queueFront=nextNode;
	queueSize--;
}
template <class T>
void linkedQueue<T>::push()
{
	chainNode<T>* newNode=new chainNode(theElement,NULL);
	if(queueSize==0)
		queueFront=queueBack=newNode;
	else
	{
		queueBack->next=newNode;
		queueBack=newNode;
	}
	queueSize++;
}