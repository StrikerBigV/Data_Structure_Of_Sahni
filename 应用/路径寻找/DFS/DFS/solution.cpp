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
	reach[s]=1;
	vertexIteator<T>* is=iteator(s);
	int u;
	while((u=is->next())!=0)
	{
		if(reach[u]==0)
		{
			path[++length]=u;
			if(u==destination||rFindPath(u))
				return true;
			length--;
		}
	}
	delete is;
	return false;
}