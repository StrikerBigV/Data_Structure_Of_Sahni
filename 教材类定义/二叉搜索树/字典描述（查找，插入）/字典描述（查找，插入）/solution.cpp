template <class K,class E>
class binarySearchTree: public dictionary<K,E>
{
	//......
	pair<const K,E>* find(const K& theKey) const;
	void insert(const pair<const K,E>& thePair);
}
template <class K,E>
pair<const K,E>* binarySearchTree<K,E>::find(const K& theKey)
{
	binaryTreeNode<pair<const K,E>>* p=root;
	while(p!=NULL)
		if(theKey<p->element.first)
			p=p->leftChild;
		else 
			if(theKey>p->element.first)
			p=p->rightChild;
			else
				return &p->element;
	return NULL;
}//查找
template<class K,E>
void binarySearchTree<K,E>::insert(const pair<const K,E>& thePair)
{
	binaryTreeNode<pair<const K,E>>* p=root;
								   * pp=NULL;
	while(p!=NULL)
	{
		pp=p;
		if(p->element.first>thePair.first)
			p=p->leftChild;
		else
			if(p->element.first<thePair.first)
				p=p->rightChild;
			else
			{
				p->element.second=thePair.second;
				return;
			}
	}
	binaryTreeNode<pair<const<K,E>>* newNode=new binaryTreeNode<const<K,E>>(thePair);
	if(root!=NULL)
		if(pp->element.first<thePair.first>
			pp->rightChild=newNode;
		else
			pp->leftChild=newNode;
	else
		root=newNode;
	treeSize++;
}//  插入，若找到含要查找关键词的元素，则不做改变；否则，将其插入遍历中断点即最后一个子根的左子树或右子树。