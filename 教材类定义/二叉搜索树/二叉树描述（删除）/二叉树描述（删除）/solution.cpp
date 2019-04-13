template <class T>
class binarySearchTree: public binaryTree<T>
{
	//......
	void removeHelp(binaryTreeNode<T>* root,const T& theKey);
}
template <class T>
void binarySearchTree<T>::removeHelp(binaryTreeNode<T>* root,const T& theKey)
{
	if(root=NULL)
		cout<<"WRONG"<<endl;
	else if(theKey<root.element)
		removeHelp(root->leftChild,theKey);
	else if(theKey>root.element)
		removeHelp(root->rightChild,theKey);//寻找要删除的结点
	else
	{
		binaryTreeNode<T>* temp;
		if(root->leftChild=NULL)
			root=root->rightChild;//左子树为空
		else if(root->rightChild=NULL)
			root=root->leftChild;//右子树为空
		else
		{
			temp=deleteMin(root->rightChild);//寻找右子树的最小元素
			root->element=temp->element;
		}
		delete temp;//左右子树均不空
	}
}
template <class T>
binaryTreeNode* BST::deleteMin(binaryTreeNode <T> *& root)
{
	if(root->leftChild!=NULL)
		return deleteMin(root->leftChild);
	else
	{
		binaryTreeNode<T>* temp=root;
		root=root->rightChild;
		return temp;
	}
}