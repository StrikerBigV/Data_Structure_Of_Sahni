struct equivNode
{
	int equivClass,
		size,
		next;
};//�ṹ��equivNode�������ȼ����Ԫ���������ȼ�����Ԫ�ض��٣�nextָ��
equivNode *node;//�ȼ�������
int n;
void initialize(int numberOfElements)
{
	n=numberOfElements;
	node=new equivNode[n+1];
	for(int e=1;e<=n;e++)
	{
		node[e].equivClass=e;
		node[e].next=0;
		node[e].size=1;
	}
}//�ȼ��������ʼ��
void unite(int classA,int classB)
{
	if(node[classA].equivClass>node[classB].equivClass)
	{
		int temp;
		temp=classA;
		classA=classB;
		classB=temp;
	};//ȡ��С��ΪclassA
	int k;
	for(k=classA;node[k].next!=0;k=node[k].next)
		node[k].equivClass=classB;//��classA����������һλ������Ԫ�صĵȼ����ΪclassB
	node[k].equivClass=classB;//��classA�������һλԪ�صĵȼ����ΪclassB
	node[classB].size+=node[classA].size;//��classB������Ĵ�С��ΪԭclassA��classB�������С��
	node[k].next=node[classB].next;
	node[classB].next=classA;
}
int find(int theElement)
{
	return node[theElement].equivClass;
}//����Ԫ�ض�Ӧ�ĵȼ���