template <class T>
class arrayQueue: public Queue()
{
	public:
		arrayQueue(int incapacity=10);
		~arrayQueue();
		bool empty(){return ((theFront+1)%arrayLength)==theBack;}
		int size(){return ((arrayLength+theFront-theBack+1)%arrayLength);}
		T& front(){return queue[theFront];}
		T& back(){return queue[theBack];}
		void pop(T& it);
		void push(const T& theElement);
	private:
		int theFront;
		int theBack;
		int arrayLength;
		T* queue;
}
template <class T>
arrayQueue<T>::arrayQueue(int incapacity)
{
	arrayLength=incapacity;
	theFront=0;
	theBack=1;
	queue=new T[arrayLength];
}
void arrayQueue<T>::pop(T& it)
{
	if(empty())
		return 1;
	it=queue[theFront];
	theFront=(theFront+1)%arrayLength;
}
void arrayQueue<T>::push(const T& theElement)
{
	if(((theFront+2)%arrayLength)=theBack)
		return 1;
	theBack=(theBack+1)%arrayLength;
	queue[theBack]=theElement;
}
//综合了萨尼和张铭的定义方法