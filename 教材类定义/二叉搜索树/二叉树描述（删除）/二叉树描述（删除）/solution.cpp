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
		removeHelp(root->rightChild,theKey);//Ѱ��Ҫɾ���Ľ��
	else
	{
		binaryTreeNode<T>* temp;
		if(root->leftChild=NULL)
			root=root->rightChild;//������Ϊ��
		else if(root->rightChild=NULL)
			root=root->leftChild;//������Ϊ��
		else
		{
			temp=deleteMin(root->rightChild);//Ѱ������������СԪ��
			root->element=temp->element;
		}
		delete temp;//��������������
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