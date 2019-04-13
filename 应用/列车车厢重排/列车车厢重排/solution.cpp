//ȫ�ֱ���
arraystack<int>* track;//��������ջ���
int numberofcars;
int numberoftracks;
int smallestcar;//���л���������С�ĳ���
int itstrack;//��С�������ڵĹ��

bool railroad(int inputorder[],int theNumberofcars,int theNumberoftracks)
{
	numberofcars=theNumberofcars;
	numberoftracks=theNumberoftracks;
	track=new arraystack<int>[numberoftracks+1];
	int nextcartooutput=1;//��һ��������ģ���ʼ��Ϊ1
	smallestcar=numberofcars+1;//��ʼ���������޳���

	for(int i=1;i<numberofcars;i++)
		if(inputorder[i]==nextcartooutput)//ֱ�ӳ����
		{
			cout<<"move car"<<inputorder[i]<<"from input track to output track"<<endl;
			nextcartooutput++;
			while(smallestcar==nextcartooutput)//�����������С�����Ƴ����
			{
				outputfromholdingtrack();
				nextcartooutput++;
			}
		}
		else 
			if(!putinholdingtrack(inputorder[i]))//���ܳ��������쳵�ᰴһ������ѹ�뻺������
				return false;
	return true;
}
void outputfromholdingtrack()
{
	smallestcar=numberofcars+2;
	itstrack=0;
	for(int i=0;i<numberoftracks;i++)
		if(!track[i].empty()&&track[i].top()<smallestcar)
		{
			smallestcar=track[i].top();
			itstrack=i;
		}
	track[itstrack].pop();
	cout<<"move car"<<smallestcar<<" from holding track"<<itstrack<<" to output track"<<endl;
}//�����������С�����Ƴ����
bool putinholdingtrack(int c)
{
	int besttrack=0;
	int besttop=numberofcars+1;

	for(int i=0;i<numberoftracks;i++)//ɨ��ѡ����ʵĻ�����
	  if(!track[i].empty())
		{
			int topcar=track[i].top();
			if(c<topcar&&topcar<besttop)
			{
				besttrack=i;
				besttop=topcar;
			}
		}
		else 
			if(besttrack==0) besttrack=i;//�пջ��������ͽ�ѡ��
	if(besttrack==0) return false;//ѭ���������޺��ʹ��
	track[besttrack].push(c);//������ѹ����ʵĻ�����
	cout<<"move car"<<c<<" from input track to holding track"<<besttrack<<endl;
	if(c<smallestcar)
	{
		smallestcar=c;
		itstrack=besttrack;
	}//������Ҫ��������С���ἰ����
	return true;
}//�����ĳ����������ʵĻ�����