int main()
{
	int n,r;
	cout<<"enter number of elements"<<endl;
	cin>>n;
	if(n<2)
	{
		cout<<"too few elements"<<endl;
		return 1;
	}//��n�������ж�
	cout<<"enter number of relations"<<endl;
	cin>>r;
	if(r<1)
	{
		cout<<"too few relations"<<endl;
		return 1;
	}//��r�������ж�
	arrayStack<int>* list=new arrayStack[n+1];//����n��ջ
	int a,b;
	for(int i=0;i<r;i++)
	{
		cout<<"enter next relation"<<endl;
		cin>>a>>b;
		list[a]->push(b);
		list[b]->push(a);
	}//����r����ϵ�ԣ�����ÿһ��Ԫ�صĹ�ϵԪ����ѹ���Ԫ�ض�Ӧ��ջ��
	arrayStack<int> unprocessedlist;//�������δ�������ջ��ջ
	bool* out=new bool[n+1];
	for(int i=0;i<n;i++)
		out[i]=false;//����bool���飬����ÿ��Ԫ�س�ʼ��Ϊfalse
	for(int i=0;i<n;i++)
		if(!out[i])//��δ�����
		{
			unprocessedlist->push(i);//��Ԫ������ѹ��unprocessedlistջ��
			while(!unprocessedlist->empty())//ֻҪջ����
			{
				cout<<"new class is :"<<i<<endl;
				out[i]=true;//�������
				int j=unprocessedlist->top();
				unprocessedlist->pop();//Ԫ�س�ջ
			    while(!list[j]->empty())
				{
					int q=list[j]->top();
					list[j]->pop();//list��Ԫ�س�ջ
					if(!out[q])//��δ�����
					{
						cout<<q<<" ";
						out[q]=true;//�������
						unprocessedlist->push(q);
					}//��Ԫ��ѹ��unprocessedlistջ��
				}
			}
			cout<<endl;
		}
		cout<<"end"<<endl;
}