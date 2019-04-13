//������Chain�ĳ�Ա����������������
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
}//�ṹ�嶨��
ostream& operator<<(ostream& out,const studentRecord& x)
{
	out<<x.score<<' '<<*x.name<<endl;
	return out;
}//����<<
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
	}//ȡ��theChain�е�Ԫ�ز����������ע��ɾ����ȡ�ߺ�����Ա��нڵ�
	for(int j=range;j>=0;j--)
		while(!bin[j].empty())
		{
			studentRecord x=bin.get(0);
			bin.erase(0);
			theChain.insert(0,x);
		}//ȡ�������е�Ԫ�ز�����theChain�ע��ɾ����ȡ�ߺ�����Ա��нڵ�
		delete [] bin;//ɾ������
}