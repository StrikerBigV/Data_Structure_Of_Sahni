void rDfs(int v)
{
	reach[v]=label;
	for(int u=1;u<n;u++)
		if(a[v][u]!=noEdge&&reach[u]==0)
		{
			rDfs(u);
			reach[u]=label;
		}
}