//��ģ��ֻѰ��·��
//�Թ���Сsize���Թ�Ԫ������maze[][]������ģ������
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
	offset[3].row=-1;offset[3].col=0;//��ʼ��λƫ����
	for(int i=0;i<=size+1;i++)
	{
		maze[0][i]=maze[size+1][i]=1;
		maze[i][0]=maze[i][size+1]=1;
	}//�ڸ����Թ����һ��Χǽ
	position here;
	here.row=1;
	here.col=1;
	maze[1][1]=1;
	int option=0;
	int lastoption=3;
	while(here.row!=size||here.col!=size)//��δ���յ�
	{
		int r,c;
		while(option<lastoption)
		{
			r=here.row+offset[option].row;
			c=here.row+offset[option].col;
			if(maze[r][c]==0) break;
			option++;
		}//�Ƶ���һ��
	if(option<lastoption)//�Ƿ����
	{
		path->push(here);
		here.row=r;
		here.col=c;
		maze[r][c]=1;//����λ�÷�ס����ֹ����
		option=0;
	}
	else
	{
		if(path->empty())
			return false;//ջ����λ�ã�����·�������ش���
		position next=path->top();//��ջ��ȡ����һ��λ��
		if(next.row=here.row)
			option=2+next.col-here.col;
		else
			option=3+next.row-here.row;//����ȷ��ƫ����
		here=next;//�ص���һ��λ��
	}
	}
	return true;
}