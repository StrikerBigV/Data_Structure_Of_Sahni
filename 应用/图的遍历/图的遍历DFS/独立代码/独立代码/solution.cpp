void dfs(int v,int reach[],int label)
{
	graph<T>::reach=reach;
	graph<T>::label=label;
	rDfs(v);
}
void rDfs(int v)
{
	reach[v]=label;
	vertexIterator<T>*iv=iterator(v);
	int u;
	while((u=iv->next())!=0)
	{
		if(reach[u]==0)
			rDfs(u);
		delete iv;
	}
}