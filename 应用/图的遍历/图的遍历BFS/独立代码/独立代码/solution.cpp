virtual void bfs(int v,int reach[],int label)
{
	arrayQueue<int> q(10);
	reach[v]=leabel;
	q.push(v);
	while(!q.empty())
	{
		int w=q.front();
		q.pop();
		vertexIterator<T>*iw=iterator(w);
		int u;
		while((u=iw->next())!=0)
			if(reach[u]==0)
			{
				q.push(u);
				reach[u]=label;
			}
			delete iw;
	}
}