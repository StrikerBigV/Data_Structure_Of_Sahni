template <class T>
class matrix
{
	friend ostream& operator<<(ostream&,const matrix<T>&);
	public:
		matrix(int theRows=0,int theColumns=0);
		martix(const matrix<T>&);
		~matrix(){delete []element;}
		T& operator()(int i,int j)const;
		martix<T>& operator=(const matrix<T>&);
		martix<T> operator+()const;
		martix<T> operator+(const matrix<T>&)const;
		martix<T> operator-()const;
		martix<T> operator-(const matrix<T>&)const;
		martix<T> operator*(const matrix<T>&)const;
	private:
		int theRows;
		int theColumns;
		T* element;
};
template <class T>
matrix<T>::matrix(int theRows,int theColumns)
{
	this->theRows=theRows;
	this->theColumns=theColumns;
	element=new T[theRows*theColumns];
}//���캯��
template <class T>
matrix<T>::martix(const matrix<T>& m)
{
	theRows=m.theRows;
	theColumns=m.theColumns;
	element=new T[theRows*theColumns];
	copy(m.element,m.element+theRows*theColumns,element);
}//���ƹ��캯��
template <class T>
martix<T>& matrix<T>::operator=(const matrix<T>&)
{
	if(this!=&m)
	{
		delete[]element;
		theRows=m.theRows;
		theColumns=m.theColumns;
		element=new T[theRows*theColumns];
		copy(m.element,m.element+theRows*theColumns,element);
	}
	return *this;
}//���ز�����=
template <class T>
T& matrix<T>::operator()(int i,int j)const
{
	return element[(i-1)*theColumns+j-1];
}//���ز�����()
template <class T>
martix<T>& matrix<T>::operator+(const matrix<T>&)
{
	matrix<T> w(theRows,theColumns);
	for(int i=0;i<theRows*theColumns;i++)
		w.element[i]=element[i]+m.element[i];
	return w;
}//���ز�����+��wΪ�������
template <class T>
martix<T>& matrix<T>::operator*(const matrix<T>& m)const
{
	matrix<T> w(m.theRows,m.theColumns);
	int ct=0,cm=0,cw=0;
	for(int i=0;i<theRows;i++)
	{
		for(in j=0;j<theColumns;j++)
		{
			T sum=element[ct]*m.element[cm];
			for(int k=2;k<theColumns;k++)
			{
				ct++;
				cm+=m.theColumns;
				sum+=element[ct]*m.element[cm];
			}
			w.element[cw++]=sum;
			ct-=theColumns-1;
			cm=j;
		}
		ct+=theColumns;
		cm=0;
	}
	retun w;
}//ct�ɿ���ĳһ��ĳһ�����cm�ɿ���ĳһ��ĳһ�����cwΪ���������
//���㣨i��j����һ�����ʣ����������洢��w��Ӧ���У�
//���������е�������һ�п�ʼ������ĳһ�У�
//����������һ�п�ʼ��
//���������С�