bool checkBox(int net[],int n)
{
	arrayStack<int>* s=new arrayStack<int>(n);
	for(int i=0;i<n;i++)
		if(!s->empty())
		{
			if(net[s->top()]=net[i])
				s->pop();
			else s->push(i);
		}
		else s->push(i);
	if(s->empty())
	{
		cout<<"switch box is not routable"<<endl;
		return true;
	}
	cout<<"switch box is routable"<<endl;
	return false;
}