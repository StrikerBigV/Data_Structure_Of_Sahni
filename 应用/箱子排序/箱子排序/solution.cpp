//利用类Chain的成员函数进行箱子排序
#include <iostream>
#include <string>
using namespace std;
struct studentRecord
{
	int score;
	string* name;
	int operator !=(const studentRecord& x)const
	{
		return score!=x.score;
	}
}//结构体定义
ostream& operator<<(ostream& out,const studentRecord& x)
{
	out<<x.score<<' '<<*x.name<<endl;
	return out;
}//重载<<
void binSort(chain<studentRecord>& theChain,int range)
{
	chain<studentRecord> *bin;
	bin=new chain<studentRecord>[range+1];
	int numberofElements=theChain.size();
	for(int i=1;i<=numberofElements;i++)
	{
		studentRecord x=theChain.get(0);
		theChain.erase(0);
		bin[x.score].insert(0,x);
	}//取出theChain中的元素并放在箱子里，注意删除被取走后的线性表中节点
	for(int j=range;j>=0;j--)
		while(!bin[j].empty())
		{
			studentRecord x=bin.get(0);
			bin.erase(0);
			theChain.insert(0,x);
		}//取出箱子中的元素并放在theChain里，注意删除被取走后的线性表中节点
		delete [] bin;//删除箱子
}