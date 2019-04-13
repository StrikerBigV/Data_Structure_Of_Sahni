template <class T>
class arraystack: public stack
{
   public:
	   arraystack(int incapacity=10);
	   ~arraystack(){delete [] stack;}
	   bool empty()const{return stackTop==-1;}
	   int size()const{return stackTop+1;}
	   T& top(){return stack[stackTop];}
	   void pop(){stack[stackTop--].~T();}
	   void push(const T& theElement){stack[++stackTop]=theElement;};
   private:
	   int stackTop;
	   int arrayLength;
	   T* stack;
}
template <class T>
arraystack<T>::arraystack(int incapacity)
{
	incapacity=arrayLength;
	stack=new T[arrayLength];
	stack=-1;
}