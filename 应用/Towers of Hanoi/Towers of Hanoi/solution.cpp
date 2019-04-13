arraystack<int> tower[4];
void moveandshow(int,int,int,int);
void hanoi(int n)
{
	for(int i=0;i<n;i++)
		tower[1].push(i);
	moveandshow(n,1,2,3);
}
void moveandshow(int n,int x,int y,int z)
{
	if(n>0)
	{
		moveandshow(n-1,x,z,y);
		int d=tower[x].top();
		tower[x].pop();
		tower[y].push(d);
		moveandshow(n-1,z,y,x);
	}
}