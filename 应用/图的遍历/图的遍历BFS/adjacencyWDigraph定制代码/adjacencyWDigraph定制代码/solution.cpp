void bfs(int v,int reach[],int label)
{
	arrayQueue<int>* q(10);
	reach[v]=label;
	q.push(v);
	while(!q.empty())
	{
		int w=q.front();
		q.pop();
		for(int u=0;u<n+1;u++)
			if(a[w][u]!=noEdge&&reach[u]==0)
			{
				q.push(u);
				reach[u]=label;
			}
	}
}