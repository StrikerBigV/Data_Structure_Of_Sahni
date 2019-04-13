int main()
{
	int n,r;
	cout<<"enter number of elements"<<endl;
	cin>>n;
	if(n<2)
	{
		cout<<"too few elements"<<endl;
		return 1;
	}//对n的输入判定
	cout<<"enter number of relations"<<endl;
	cin>>r;
	if(r<1)
	{
		cout<<"too few relations"<<endl;
		return 1;
	}//对r的输入判定
	arrayStack<int>* list=new arrayStack[n+1];//建立n个栈
	int a,b;
	for(int i=0;i<r;i++)
	{
		cout<<"enter next relation"<<endl;
		cin>>a>>b;
		list[a]->push(b);
		list[b]->push(a);
	}//输入r个关系对，并将每一个元素的关系元素们压入该元素对应的栈中
	arrayStack<int> unprocessedlist;//建立存放未输入过本栈的栈
	bool* out=new bool[n+1];
	for(int i=0;i<n;i++)
		out[i]=false;//建立bool数组，并将每个元素初始化为false
	for(int i=0;i<n;i++)
		if(!out[i])//若未输出过
		{
			unprocessedlist->push(i);//将元素依次压入unprocessedlist栈中
			while(!unprocessedlist->empty())//只要栈不空
			{
				cout<<"new class is :"<<i<<endl;
				out[i]=true;//已输出过
				int j=unprocessedlist->top();
				unprocessedlist->pop();//元素出栈
			    while(!list[j]->empty())
				{
					int q=list[j]->top();
					list[j]->pop();//list中元素出栈
					if(!out[q])//若未输出过
					{
						cout<<q<<" ";
						out[q]=true;//已输出过
						unprocessedlist->push(q);
					}//将元素压入unprocessedlist栈中
				}
			}
			cout<<endl;
		}
		cout<<"end"<<endl;
}