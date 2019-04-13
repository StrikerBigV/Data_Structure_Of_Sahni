int* findpath(int theSource,int theDestination)
{
	int n=numberOfVertices();
	path=new int[n+1];
	path[1]=theSource;
	length=1;
	destination=theDestination;
	reach=new int[n+1];
	for(int i=0;i<=n;i++)
		reach[i]=0;
	if(theSource==theDestination||rFindPath(theSource))
		path[0]=length-1;
	else
	{
		delete []path;
		path=NULL;
	}
	delete[]reach;
	return path;
}
bool rFindPath(int s)
{
	arrayQueue<int>* q(10);
	reach[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int w=q.front();
		q.pop();
		vertexIterator<T>* iw=iterator(w);
		int u;
		while((u=iw->next())!=0)
			if(reach[u]==0)
			{
				path[++length]=u;
				q.push(u);
				reach[u]=1;
			}
	}
}