template<class T>  
void binaryTree<T>::PreOrderWithoutRecusion (binaryTreeNode<T>* root) 
{
	using std::stack;
	stack <binaryTreeNode<T>*> aStack;
	binaryTreeNode<T>* pointer=root;
	while(!aStack.empty()||pointer)
	{
		if(pointer)
			{
				aStack.push(pointer);
				if(pointer->leftChild!=NULL)
				pointer=pointer->leftChild;
		else 
			{
				pointer=aStack.top();
				aStack.pop();
				visit(pointer->element);
				pointer=pointer->rightChild;
				}
		}
	}
}