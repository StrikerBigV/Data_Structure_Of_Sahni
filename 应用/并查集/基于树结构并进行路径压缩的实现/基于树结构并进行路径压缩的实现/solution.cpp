void initialize(int numberOfElements)
{
	parent=new int[numberOfElements];
	for(int e=1;e<numberOfElements;e++)
		parent[e]=0;
}//��ʼ��numberOfElements����
int find(int theElement)
{
	int theRoot=theElement;
	while(!node[theRoot].root)
		theRoot=node[theRoot].parent;
	int currentNode=theElement;
	while(currentNode!=theRoot)
	{
		int parentNode=node[currentNode].parent;
		node[currentNode].parent=theRoot;
		currentNode=parentNode;
	}
	return theRoot;
}//ѹ��·���·������ĸ�
void unite(int rootA,int rootB)
{
	parent[rootB]=rootA;
}//�ϲ�������