void initialize(int numberOfElements)
{
	parent=new int[numberOfElements];
	for(int e=1;e<numberOfElements;e++)
		parent[e]=0;
}//初始化numberOfElements棵树
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
}//压缩路径下返回树的根
void unite(int rootA,int rootB)
{
	parent[rootB]=rootA;
}//合并两棵树