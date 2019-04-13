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
}//构造函数
template <class T>
matrix<T>::martix(const matrix<T>& m)
{
	theRows=m.theRows;
	theColumns=m.theColumns;
	element=new T[theRows*theColumns];
	copy(m.element,m.element+theRows*theColumns,element);
}//复制构造函数
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
}//重载操作符=
template <class T>
T& matrix<T>::operator()(int i,int j)const
{
	return element[(i-1)*theColumns+j-1];
}//重载操作符()
template <class T>
martix<T>& matrix<T>::operator+(const matrix<T>&)
{
	matrix<T> w(theRows,theColumns);
	for(int i=0;i<theRows*theColumns;i++)
		w.element[i]=element[i]+m.element[i];
	return w;
}//重载操作符+，w为结果矩阵
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
}//ct可看作某一行某一具体项，cm可看作某一列某一具体项，cw为结果矩阵的项；
//先算（i，j）第一项，再算剩余项并加起来存储到w对应项中；
//接下来从行的起点和下一列开始，算完某一行；
//接下来从下一行开始；
//算完所有行。