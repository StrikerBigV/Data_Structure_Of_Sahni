template<class T>  
void binaryTree<T>::PreOrderWithoutRecusion (binaryTreeNode<T>* root) 
{
	using std::stack;
	stack <binaryTreeNode<T>*> aStack;
	binaryTreeNode<T>* pointer=root;
	while(pointer)
		{
			visit(pointer->element);
			if(pointer->rightChild!=NULL)
				aStack.push(pointer->rightChild);
			if(pointer->leftChild!=NULL)
				pointer=pointer->leftChild;
			else
			{
				pointer=aStack.top();
				aStack.pop();
			}
	}
}