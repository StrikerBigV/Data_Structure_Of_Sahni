int *equivClass,//�ȼ�������
	n;//Ԫ�ظ���
void initialize(int numberOfElements)
{
	n=numberOfElements;
	equivClass=new int[n+1];
	for(int e=0;e<n;e++)
		equivClass[e]=e;
}//�ȼ��������ʼ��
void unite(int classA,int classB)
{
	for(int k=1;k<=n;k++)
		if(equivClass[k]==classB)
			equivClass[k]=classA;
}//�ϲ������ȼ���
int find(int theElement)
{
	return equivClass[theElement];
}//����ĳ��Ԫ�صĵȼ���