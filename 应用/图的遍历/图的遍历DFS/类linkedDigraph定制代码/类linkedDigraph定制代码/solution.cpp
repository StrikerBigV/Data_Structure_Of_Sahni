void rDfs(int v)
{
	reach[v]=label;
	for(chainNode<int>*u=aList[v].firstNode;u!=NULL;u=u->next)
		if(reach[u->element]==0)
		{
			rDfs(u->element);
			reach[u->element]=label;
		}
}