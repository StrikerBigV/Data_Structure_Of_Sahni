//本模块只寻找路径
//迷宫大小size，迷宫元素数组maze[][]在输入模块输入
struct position
{
	int row;
	int col;
}
bool findpath()
{
	path=new arrayStack<position>;
	position offset[4];
	offset[0].row=0;offset[0].col=1;
	offset[1].row=1;offset[1].col=0;
	offset[2].row=0;offset[2].col=-1;
	offset[3].row=-1;offset[3].col=0;//初始化位偏移量
	for(int i=0;i<=size+1;i++)
	{
		maze[0][i]=maze[size+1][i]=1;
		maze[i][0]=maze[i][size+1]=1;
	}//在给定迷宫外加一堵围墙
	position here;
	here.row=1;
	here.col=1;
	maze[1][1]=1;
	int option=0;
	int lastoption=3;
	while(here.row!=size||here.col!=size)//若未到终点
	{
		int r,c;
		while(option<lastoption)
		{
			r=here.row+offset[option].row;
			c=here.row+offset[option].col;
			if(maze[r][c]==0) break;
			option++;
		}//移到下一步
	if(option<lastoption)//是否可行
	{
		path->push(here);
		here.row=r;
		here.col=c;
		maze[r][c]=1;//将该位置封住，防止再来
		option=0;
	}
	else
	{
		if(path->empty())
			return false;//栈中无位置，即无路径，返回错误
		position next=path->top();//从栈中取回上一个位置
		if(next.row=here.row)
			option=2+next.col-here.col;
		else
			option=3+next.row-here.row;//重新确定偏移量
		here=next;//回到上一个位置
	}
	}
	return true;
}