template <class T>
class linearList
{
   public:
	   virtual bool empty()const=0;
	   virtual int size()const=0;
	   virtual T& get(int theIndex)const=0;
	   virtual int indexof(const T& theElement)const=0;
	   void erase(int theIndex)=0;
	   void insert(int theIndex,const T& theElement)=0;
};