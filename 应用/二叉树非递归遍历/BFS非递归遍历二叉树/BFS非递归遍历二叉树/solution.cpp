template<class T>  
void binaryTree<T>::PreOrderWithoutRecusion (binaryTreeNode<T>* root) 
{
	using std::queue;
	queue <binaryTreeNode<T>*> aQueue;
	binaryTreeNode<T>* pointer=root;
	if(pointer)
		aQueue.push(pointer);
	while(!aQueue.empty())
		{
			pointer=aQueue.front();
			aQueue.pop();
			visit(pointer->element);
			if(pointer->leftChild!=NULL)
				aQueue.push(pointer->leftChild);
			if(pointer->rightChild!=NULL)
				aQueue.push(pointer->rightChild);
	}
}