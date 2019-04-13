class linkedDigraph: public graph<bool>
{
	protected:
		int n;
		int e;
		graphChain<int> *aList;
	public:
		linkedDigraph(int numberOfVertices)
		{
			if(numberOfVertices<0)
				throw illegalParameterValue("Wrong");
			n=numberOfVertices;
			e=0;
			aList=new graphChain<int>[n+1];
		}
		~linkedDigraph(){delete []aList;}
		bool existEdge(int i,int j)
		{
			if(i<1||j<1||i>n||j>n||aList[i].indexOf(j)==-1)
				return false;
			else
				return true;
		}
		void insertEdge(edge<bool> *theEdge)
		{
			int v1=theEdge->vertex1();
			int v2=theEdge->vertex2();
			if(v1<1||v2<1||v1>n||v2>n||v1==v2)
				throw illegalParameterValue("Wrong");
			if(aList[v1].indexOf(v2)==-1)
			{
				aList[v1].insert(0,v2);
				e++;
			}

		}
		void eraseEdge(int i,int j)
		{
			if(i>0&&j>0&&i<n+1&&j<n+1)
			{
				int *v=aList[i].eraseElement(j);
				if(v!=NULL)
					e--;
			}
		}
		void checkVertex(int theVertex)const
		{
			if(theVertex<1||theVertex>n)
			{
				ostringstream s;
				s<<"Wrong";
				throw illegalParameterValue(s.str());
			}

		}
		int degree(int theVertex)
		{throw undefinedMethod("Wrong");}
		int inDrgee(int theVertex)const
		{
			checkVertex(theVertex);
			int sum=0;
			for(int j=0;j<n;j++)
				if(aList[j].indexOf(theVertex)!=-1)
					sum++;
			return sum;
		}
		int outDegree(int theVertex)
		{
			checkVertex(theVertex);
			return aList[theVertex].size();
		}
		//µü´úÆ÷ÂÔ
}