//全局变量
arraystack<int>* track;//缓冲数组栈轨道
int numberofcars;
int numberoftracks;
int smallestcar;//所有缓冲轨道里最小的车厢
int itstrack;//最小车厢所在的轨道

bool railroad(int inputorder[],int theNumberofcars,int theNumberoftracks)
{
	numberofcars=theNumberofcars;
	numberoftracks=theNumberoftracks;
	track=new arraystack<int>[numberoftracks+1];
	int nextcartooutput=1;//下一个出轨道的，初始化为1
	smallestcar=numberofcars+1;//开始缓冲轨道里无车厢

	for(int i=1;i<numberofcars;i++)
		if(inputorder[i]==nextcartooutput)//直接出轨道
		{
			cout<<"move car"<<inputorder[i]<<"from input track to output track"<<endl;
			nextcartooutput++;
			while(smallestcar==nextcartooutput)//缓冲轨道里的最小车厢移出轨道
			{
				outputfromholdingtrack();
				nextcartooutput++;
			}
		}
		else 
			if(!putinholdingtrack(inputorder[i]))//不能出轨道的入轨车厢按一定规则压入缓冲轨道里
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
}//缓冲轨道里的最小车厢移出轨道
bool putinholdingtrack(int c)
{
	int besttrack=0;
	int besttop=numberofcars+1;

	for(int i=0;i<numberoftracks;i++)//扫描选择合适的缓冲轨道
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
			if(besttrack==0) besttrack=i;//有空缓冲轨道，就近选择
	if(besttrack==0) return false;//循环结束，无合适轨道
	track[besttrack].push(c);//将车厢压入合适的缓冲轨道
	cout<<"move car"<<c<<" from input track to holding track"<<besttrack<<endl;
	if(c<smallestcar)
	{
		smallestcar=c;
		itstrack=besttrack;
	}//若有需要，更新最小车厢及其轨道
	return true;
}//入轨道的车厢进入最合适的缓冲轨道