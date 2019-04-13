void bfs(int v,int reach[],int label)
{
	arrayQueue<int>* q(10);
	reach[v]=label;
	q.push(v);
	while(!q.empty())
	{
		int w=q.front();
		q.pop();
		for(chainNode<int>*u=aList[w].firstNode;u!=NULL;u=u->next)
			if(reach[u->element]==0)
			{
				q.push(u->element);
				reach[u->element]=label;
			}
	}
}