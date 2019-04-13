template <class T>
class maxHblt:public maxPriorityQueue<T>,
	          public linkedBinaryTree<pair<int,T>>
{
	public:
	    bool empty() const {return treeSize == 0;}
        int size() const {return treeSize;}
        const T& top()
		{
		  return root->element.second;
		}
        void pop();
	    void push(cons T& theElement);
	    void meld(maxHblt<T>& theHblt)
		{
			meld(root,theHblt.root);
			treeSize+=theHblt.treeSize;
			theHblt.root=NULL;
			theHblt.treeSize=0;
		}
	    void initialize(T* theElements,int theSize);
	private:
		void meld(binaryTreeNode<pair<int,T>>*,binaryTreeNode<pair<int,T>*);
}
template <class T>
void maxHblt::meld(binaryTreeNode<pair<int,T>>* x,binaryTreeNode<pair<int,T>>* y)
{
	if(y==NULL)
		return;
	if(x==NULL)
	{
		x=y;
		return;
	}
	if(x->element.second<y->element.second)
		swap(x,y);
	meld(x->rightChild,y);
	if(x->lefChild==NULL)
	{
		x->leftChild=x->rightChild;
		x->rightChild=NULL;
		x->element.first=1;
	}
	else
	{
		if(x->leftChild->element.second<x->rihtChild->element.second)
			swap(x->leftChild,x->rightChild);
		x->element.first=x->rightChild>element.first+1;
	}
}//私有合并函数，默认x为大，不停地将x的右子树与y合并，若出现左子树为空，则将右子树赋给左子树，并令右子树为空；若出现左子树的s小于右子树，则交换两子树。
template <class T>
void maxHblt::push(const T& theElement)
{
	binaryTreeNode<pair<int,T>>* q=new binaryTreeNode<pair<int,T>>(pair<int,T>(1,theElement));
	meld(root,q);
	treeSize++;
}
template<class T>
void maxHblt::pop()
{
	if(root==NULL)
		return false;
	binaryTreeNode<pair<int,T>>* left=root->leftChild,
							   * right=root->rightChild;
	delete root;
	root=left;
	meld(root,right);
	treeSize--;
}//公有删除函数，删除根，删除后左子树与右子树合并
template <class T>
void maxHblt::initialize(T* theElements,int theSize)
{
	arrayQueue<binaryTreeNode<pair<int,T>>*> q(theSize);
	erase();
	for(int i=1;i<theSize;i++)
		q.push(new binaryTreeNode<pair<int,T>>(pair<int,T>(1,theElements[i])));
	for(int i=1;i,treeSize-1;i++)
	{
		binaryTreeNode<pair<int,T>>* b=q.front();
		q.pop();
		binaryTreeNode<pair<int,T>>* c=q.front();
		q.pop();
		meld(b,c);
		q.push(b);
	}
	if(theSize>0)
		root=q.front();
	treeSize=theSize;
}//公有初始化一棵最大HBLT，创立n个只含一个元素的最大HBLT，将其按顺序组成队列。依次删除队首两棵树，合并，插入队尾。直至队列只有一棵树。