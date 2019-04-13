template <class T>
class huffmanTree
{
	public:
		huffmanTree(T weight[],int n);
		virtual ~huffmanTree();
	private:
		huffmanTreeNode<T>* root;
		void merge(huffmanTreeNode<T>& t1,huffmanTreeNode<T>& t2,huffmanTreeNode<T>* parent);
}//��huffmanTree
template <class T>
huffmanTree::hffmanTree(T weight[],int n)
{
	minHeap<HuffmanTreeNode<T>> heap; 
	huffmanTreeNode<T> &leftChild,&rightChild,*parent;
	huffmanTreeNode<T>* nodeList=new huffmanTreeNode<T>[n];
	for(int i=0;i<n;i++)
	{
		nodeList[i].element=weight[i];
		nodeList[i].parent=nodeList[i].left=nodeList[i].right=NULL;
		heap.insert(nodeList[i]);
	}
	for(int i=0;i<n;i++)
	{
		parent=new huffmanTreeNode<T>;
		firstChild=heap.removeMin();
		secondChild=heap.removeMin();
		merge(firstChild,secondChild,parent);
		heap.insert(parent);
		root=parent;
	}
	delete []nodeList;
}//����huffmanTree���Ƚ�һ����С�ѣ��ٽ�һ��Ԫ��ΪhuffmanTree�����飬����Ȩ������weight�������鸳ֵ������������������С�Ѹ�ֵ��
//��ͣ�Ĵ���С��ɾ��Ȩ����С������huffmanTree���ϲ����ٲ����β��ֱ��ֻ��һ������