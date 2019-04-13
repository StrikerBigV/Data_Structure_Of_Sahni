template <class T>
class arrayList:public linearList<T>
{public:
    arrayList(int incapacity=10);
	arrayList(const arrayList<T>&);
	~arrayList(){delete []element;}
	//构造函数，复制构造函数，析构函数
	bool empty()const{return listSize==0;}
	int size()const{return listSize;}
	T& get(int theIndex)const;
	int indexof(const T& theElement);
	void erase(int theIndex);
	void insert(const T& theElement,int theIndex);
	// 主要方法及操作
 protected:
	void checkIndex(int theIndex)const;
	T* element;
	int arrayLength;
	int listSize;
	//异常处理函数及类的数据
};
template <class T>
arrayList<T>::arrayList(int incapacity)
{arrayLength=incapacity;
 element=new T[arrayLength];
 listSize=0;
}//构造函数
template <class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{arrayLength=theList.arrayLength;
 listSize=theList.listSize;
 element=new T[arrayLength];
 copy(theList.element,theList.element+listSize,element);
}//复制构造函数
template <class T>
void arrayList<T>::checkIndex(int theIndex)const
{
	if(theIndex<0||theIndex>=listSize)
    {ostringstream s;
     s<<"index="<<theIndex<<"size="<<listSize;
     throw illegalIndex(s.str());
	}
}//保证索引在0-listSize之间，包括对异常的处理
template <class T>
T& arrayList<T>::get(int theIndex)const
{checkIndex(theIndex);
 return arrayList(theIndex);
}//判断异常，返回索引对应的元素
template <class T>
int arrayList<T>::indexof(const T& theElement)
{for(int i=0;i<listSize;i++)
    if(element[i]==theElement)
		return i;
}// 根据元素确定索引
template <class T>
void arrayList<T>::erase(int theIndex)
{checkIndex(theIndex);
 for(int i=theIndex;i<listSize;i++)
	 element[i]=element[i+1];
 element[--listSize].~T[];
}//删除索引对应的元素
template <class T>
void arrayList<T>::insert(const T& theElement,int theIndex)
{checkIndex(theIndex);
 for(int i=listSize-1;i>theIndex;i--)
	 element[i]=element[i-1];
 element[theIndex]=theElement;
 listSize++;
}//在给定索引处插入元素