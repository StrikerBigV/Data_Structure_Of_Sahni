int *equivClass,//等价类数组
	n;//元素个数
void initialize(int numberOfElements)
{
	n=numberOfElements;
	equivClass=new int[n+1];
	for(int e=0;e<n;e++)
		equivClass[e]=e;
}//等价类数组初始化
void unite(int classA,int classB)
{
	for(int k=1;k<=n;k++)
		if(equivClass[k]==classB)
			equivClass[k]=classA;
}//合并两个等价类
int find(int theElement)
{
	return equivClass[theElement];
}//查找某个元素的等价类