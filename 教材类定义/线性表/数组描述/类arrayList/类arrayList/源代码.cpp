template <class T>
class arrayList:public linearList<T>
{public:
    arrayList(int incapacity=10);
	arrayList(const arrayList<T>&);
	~arrayList(){delete []element;}
	//���캯�������ƹ��캯������������
	bool empty()const{return listSize==0;}
	int size()const{return listSize;}
	T& get(int theIndex)const;
	int indexof(const T& theElement);
	void erase(int theIndex);
	void insert(const T& theElement,int theIndex);
	// ��Ҫ����������
 protected:
	void checkIndex(int theIndex)const;
	T* element;
	int arrayLength;
	int listSize;
	//�쳣���������������
};
template <class T>
arrayList<T>::arrayList(int incapacity)
{arrayLength=incapacity;
 element=new T[arrayLength];
 listSize=0;
}//���캯��
template <class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{arrayLength=theList.arrayLength;
 listSize=theList.listSize;
 element=new T[arrayLength];
 copy(theList.element,theList.element+listSize,element);
}//���ƹ��캯��
template <class T>
void arrayList<T>::checkIndex(int theIndex)const
{
	if(theIndex<0||theIndex>=listSize)
    {ostringstream s;
     s<<"index="<<theIndex<<"size="<<listSize;
     throw illegalIndex(s.str());
	}
}//��֤������0-listSize֮�䣬�������쳣�Ĵ���
template <class T>
T& arrayList<T>::get(int theIndex)const
{checkIndex(theIndex);
 return arrayList(theIndex);
}//�ж��쳣������������Ӧ��Ԫ��
template <class T>
int arrayList<T>::indexof(const T& theElement)
{for(int i=0;i<listSize;i++)
    if(element[i]==theElement)
		return i;
}// ����Ԫ��ȷ������
template <class T>
void arrayList<T>::erase(int theIndex)
{checkIndex(theIndex);
 for(int i=theIndex;i<listSize;i++)
	 element[i]=element[i+1];
 element[--listSize].~T[];
}//ɾ��������Ӧ��Ԫ��
template <class T>
void arrayList<T>::insert(const T& theElement,int theIndex)
{checkIndex(theIndex);
 for(int i=listSize-1;i>theIndex;i--)
	 element[i]=element[i-1];
 element[theIndex]=theElement;
 listSize++;
}//�ڸ�������������Ԫ��