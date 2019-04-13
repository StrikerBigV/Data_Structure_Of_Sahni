template <class T>
class huffmanTree
{
	public:
		huffmanTree(T weight[],int n);
		virtual ~huffmanTree();
	private:
		huffmanTreeNode<T>* root;
		void merge(huffmanTreeNode<T>& t1,huffmanTreeNode<T>& t2,huffmanTreeNode<T>* parent);
}//类huffmanTree
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
}//构造huffmanTree。先建一个最小堆，再建一个元素为huffmanTree的数组，利用权重数组weight给该数组赋值，再利用这个数组给最小堆赋值。
//不停的从最小堆删除权重最小的两个huffmanTree，合并，再插入堆尾，直至只有一棵树。