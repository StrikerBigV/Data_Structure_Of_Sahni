template <class T>
class adjacencyWDigraph:public graph<T>
{
	protected:
		int n;//顶点数
		int e;//边数
		T** a;//邻接矩阵对应的数组
		T noEdge;//T类型变量，意为该边不存在
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
		}//构造函数，初始化n,e,a,noEdge
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
		}//判断该边是否存在
		void insertEdge(edge<T>* theEdge)//edge是一个模板类，包含元素第一顶点vertex1，第二顶点vertex2，权重weight
		{
			int v1=theEdge->vertex1();
			int v2=theEdge->vertex2();
			if(v1<0||v2<0||v1>n||v2>n||v1==v2)
			{
				ostringstream s;
				s<<"Wrong";
				throw illegalParameterValue(s.str());
			}//该边不应存在，抛出错误
			if(a[v1][v2]==noEdge)//该边原来不存在，即有权邻接矩阵的对应值为noEdge
				e++;//边增一
			a[v1][v2]=theEdge->weight();//用给定边的权重覆盖原边的权重（或者是给原不存在的边赋权重）
		}//插入边
		void eraseEdge(int i,int j)
		{
			if(i>1&&j>1&&i<n+1&&j<n+1&&a[i][j]!=noEdge)//边存在
			{
				a[i][j]=noEdge;//改权
				e--;//边减一
			}
		}//删除边
		void checkvertex(int theVertex)const
		{
			if(theVertex<0||theVertex>n)
			{
				ostringstream s;
				s<<"Wrong";
				throw illegalParameterValue(s.str());
			}
		}//检查顶点是否有效
		void degree(int theVertex)const
		{throw undefinedMethod("degree()undefined");}//有权图没有度的说法
		void indrgee(int theVertex)const
		{
			checkVertex(theVertex);
			int sum=0;
			for(int j=0;j<n+1;j++)
				if(a[j][theVertex]!=noEdge)
					sum++;
			return sum;
		}//计算入度
		void outdrgee(int theVertex)const
		{
			checkVertex(theVertex);
			int sum=0;
			for(int j=0;j<n+1;j++)
				if(a[theVertex][j]!=noEdge)
					sum++;
			return sum;
		}//计算出度
		//迭代器略
}