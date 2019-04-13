template <class E>
struct binaryTreeNode
{
	E element;
	binaryTreeNode<E>* leftChild;
	binaryTreeNode<E>* rightChild;

	binaryTreeNode(){leftChild=rightChild=NULL;}
	binaryTreeNode(const E& theElement)
	{
		element(theElement);
		leftChild=rightChild=NULL;
	}
	binaryTreeNode(const E& theElement,theLeftChild,theRightChild)
	{
		element(theElement);
		leftChild=theLeftChild;
		rightChild=theRightChild;
	}//结构体binaryTreeNode定义，包含元素和两个指针（左子树，右子树）
};
template <class E>
class binaryTree
{
	public:
	virtual ~binaryTree(){};
	virtual bool empty()const=0;
	virtual int Size()const=0;
	virtual void preOrder(void (*)(T*));
	virtual void inOrder(void (*)(T*));
	virtual void postOrder(void(*)(T));
	virtual void levelOrder(void(*)(T*));
};// 抽象类binaryTree
template <class E>
class linkedBinaryTree:public binaryTree<binayTree<E>>
{
	public:
		linkedBinaryTree(){root=NULL;treeSize=0;}
		~linkedBinaryTree(){erase();}
		bool empty(){return treeSize==0;}
		int Size(){return treeSize;}
		void preOrder(void (*theVisit)(binaryTree<E>*))
		{
			visit=theVisit;
			preOrder(root);
		}
		void inOrder(void (*theVisit)(binaryTree<E>*))
		{
			visit=theVisit;
			inOrder(root);
		}
		void postOrder(void (*theVisit)(binaryTree<E>*))
		{
			visit=theVisit;
			postOrder(root);
		}
		void levelOrder(void (*theVisit)(binaryTree<E>*));
		void erase()
		{
			postOrder(dispose);
			root=NULL;
			treeSize=0;
		}
	private:
		binaryTreeNode<E>* root;
		int treeSize;
		static void(*visit)(binaryTreeNode<E>*);
		static void preOrder(binaryTreeNode<E>* t);
		static void inOrder(binaryTreeNode<E>* t);
		static void postOrder(binaryTreeNode<E>* t);
		static void dispose(binaryTreeNode<E>* t){delete t;}
};//链表二叉树类定义
template <class E>
void linkedBinaryTree::(*visit)(binaryTreeNode<E>* t)
{
	cout<<t->element<<'	';
}
template <class E>
void linkedBinaryTree::preOrder(binaryTreeNode<E>* t)
{
	if(t!=NULL)
	{
		linkedBinaryTree::visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}//前序遍历
}
template <class E>
void linkedBinaryTree::inOrder(binaryTreeNode<E>* t)
{
	if(t!=NULL)
	{
		inOrder(t->leftChild);
		linkedBinaryTree::visit(t);
		inOrder(t->rightChild);
	}//中序遍历
}
void linkedBinaryTree::postOrder(binaryTreeNode<E>* t)
{
	if(t!=NULL)
	{
		postOrder(t->leftChild);
		postOrder(t->rightChild);
		linkedBinaryTree::visit(t);
	}//后序遍历
}
template <class E>
void linkedBinaryTree::levelOrder(binaryTreeNode<E>* t)
{
	arrayQueue<binaryTreeNode<E>*> q;
	while(t!=NULL)
	{
		linkedBinaryTree::visit(t);
		if(t->leftChild!=NULL)
			q,push(t->leftChild);
		if(t->rightChild!=NULL)
			q,push(t->rightChild);
		try
		{
			t=q.front();
		}
		catch(empty)
		{
			retutn;
		}
		q.pop();
	}
}//层次遍历