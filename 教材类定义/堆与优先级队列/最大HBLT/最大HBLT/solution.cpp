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
}//˽�кϲ�������Ĭ��xΪ�󣬲�ͣ�ؽ�x����������y�ϲ���������������Ϊ�գ�������������������������������Ϊ�գ���������������sС�����������򽻻���������
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
}//����ɾ��������ɾ������ɾ�������������������ϲ�
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
}//���г�ʼ��һ�����HBLT������n��ֻ��һ��Ԫ�ص����HBLT�����䰴˳����ɶ��С�����ɾ���������������ϲ��������β��ֱ������ֻ��һ������