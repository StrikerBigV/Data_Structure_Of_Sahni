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
}//����
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
}//  ���룬���ҵ���Ҫ���ҹؼ��ʵ�Ԫ�أ������ı䣻���򣬽����������жϵ㼴���һ���Ӹ�������������������