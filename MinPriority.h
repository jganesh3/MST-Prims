/*
*  @author : Ganesh Joshi
*  File : MinPriority.h  
*  class : Vertex 
*  Date : 18 May 2013 
*
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Vertex
{
 private:  
        string name;
		string parent;
		vector<pair<int,Vertex *> > adj;
		int dist;
		int key;

 public:
        friend class MinPriority;
        Vertex *path;
		Vertex();
		Vertex(string &);
		void reset(map<string,Vertex *>);
        ~Vertex()
         {
          for(int i=0;i<adj.size();i++)
            {
              delete adj[i].second;
            }
                                                                                            
         }
};


typedef map<string,Vertex *> vtxmap;
typedef pair<string,Vertex *>vtxpair;



class MinPriority 
{
   vtxmap vertexMap;
   vector<pair<int,Vertex *> > Queue;


public:
	void constructEdge(string &,string &,int &);
	void mstPrims(Vertex*);		
	Vertex * getVertex(string &);
	void MinHeapify(int i,int heapsize);
    vtxmap getVertexmap();
    ~MinPriority()
     {
       for(int i=0;i<Queue.size();i++)
       {
          delete Queue[i].second;
       }
                                                    
     }

};
