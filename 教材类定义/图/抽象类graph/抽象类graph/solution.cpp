template <class T>
class graph
{
	virtual ~graph(){};
	virtual int numberOfVerticles()const=0;
	virtual int numberOfEdges()const=0;
	virtual bool existEdge(int,int)const=0;
	virtual void insertEdge(edge<T>*)=0;
	virtual void eraseEdge(int,int)=0;
	virtual int degree(int)const=0;
	virtual int inDegree(int)const=0;
	virtual int outDegree(int)const=0;
	virtual bool didected()const=0;
	virtual bool weighted()const=0;
	virtual vertexIterator<T>* iterator(int)=0;
}