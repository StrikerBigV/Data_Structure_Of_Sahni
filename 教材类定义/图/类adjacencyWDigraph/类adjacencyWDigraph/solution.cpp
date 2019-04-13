template <class T>
class adjacencyWDigraph:public graph<T>
{
	protected:
		int n;//������
		int e;//����
		T** a;//�ڽӾ����Ӧ������
		T noEdge;//T���ͱ�������Ϊ�ñ߲�����
	public:
		adjacencyWDigraph(int numberOfVerticles=0,T theNoEdge=0)
		{
			if(numberOfverticles<0)
				throw illegalParameterValue("Wrong");
			n=numOfVerticles;
			e=0;
			noEdge=theNoEdge;
			maked2dArray(a,n+1,n+1);
			for(int i=0;i<n+1;i++)
				fill(a[i],a[i]+n+1,noEdge);
		}//���캯������ʼ��n,e,a,noEdge
		~adjacencyWDigraph(){delete2dArray(a,n+1);}
		int numberOfVerticles()const{return n;}
		int numberOfEdges()const{return e;}
		bool directed(){return true;}
		bool weighted(){return true;}
		bool existEdge(int i,int j)const
		{
			if(i<0||j<0||i>n||j>n||a[i][j]==noEdge)
				return false;
			else
				return true;
		}//�жϸñ��Ƿ����
		void insertEdge(edge<T>* theEdge)//edge��һ��ģ���࣬����Ԫ�ص�һ����vertex1���ڶ�����vertex2��Ȩ��weight
		{
			int v1=theEdge->vertex1();
			int v2=theEdge->vertex2();
			if(v1<0||v2<0||v1>n||v2>n||v1==v2)
			{
				ostringstream s;
				s<<"Wrong";
				throw illegalParameterValue(s.str());
			}//�ñ߲�Ӧ���ڣ��׳�����
			if(a[v1][v2]==noEdge)//�ñ�ԭ�������ڣ�����Ȩ�ڽӾ���Ķ�ӦֵΪnoEdge
				e++;//����һ
			a[v1][v2]=theEdge->weight();//�ø����ߵ�Ȩ�ظ���ԭ�ߵ�Ȩ�أ������Ǹ�ԭ�����ڵı߸�Ȩ�أ�
		}//�����
		void eraseEdge(int i,int j)
		{
			if(i>1&&j>1&&i<n+1&&j<n+1&&a[i][j]!=noEdge)//�ߴ���
			{
				a[i][j]=noEdge;//��Ȩ
				e--;//�߼�һ
			}
		}//ɾ����
		void checkvertex(int theVertex)const
		{
			if(theVertex<0||theVertex>n)
			{
				ostringstream s;
				s<<"Wrong";
				throw illegalParameterValue(s.str());
			}
		}//��鶥���Ƿ���Ч
		void degree(int theVertex)const
		{throw undefinedMethod("degree()undefined");}//��Ȩͼû�жȵ�˵��
		void indrgee(int theVertex)const
		{
			checkVertex(theVertex);
			int sum=0;
			for(int j=0;j<n+1;j++)
				if(a[j][theVertex]!=noEdge)
					sum++;
			return sum;
		}//�������
		void outdrgee(int theVertex)const
		{
			checkVertex(theVertex);
			int sum=0;
			for(int j=0;j<n+1;j++)
				if(a[theVertex][j]!=noEdge)
					sum++;
			return sum;
		}//�������
		//��������
}