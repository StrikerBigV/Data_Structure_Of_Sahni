struct equivNode
{
	int equivClass,
		size,
		next;
};//结构体equivNode，包含等价类的元素特征，等价类内元素多少，next指针
equivNode *node;//等价类数组
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
}//等价类数组初始化
void unite(int classA,int classB)
{
	if(node[classA].equivClass>node[classB].equivClass)
	{
		int temp;
		temp=classA;
		classA=classB;
		classB=temp;
	};//取较小者为classA
	int k;
	for(k=classA;node[k].next!=0;k=node[k].next)
		node[k].equivClass=classB;//将classA后链表除最后一位外所有元素的等价类改为classB
	node[k].equivClass=classB;//将classA链表最后一位元素的等价类改为classB
	node[classB].size+=node[classA].size;//将classB后链表的大小改为原classA与classB后链表大小和
	node[k].next=node[classB].next;
	node[classB].next=classA;
}
int find(int theElement)
{
	return node[theElement].equivClass;
}//查找元素对应的等价类