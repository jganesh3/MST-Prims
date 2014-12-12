/*
*  @author : Ganesh Joshi
*  File : MinPriority.cpp  
*  
*  Date : 18 May 2013 
*
*/

#include"MinPriority.h"
int INFINITY=100;


/*
 This function is used to Min heapify Q
*/
void MinPriority::MinHeapify(int i,int heapsize)
{
    int p;
    int q;
    int smallest;

    p=2*i+1;
    q=2*i+2;

if ((p<heapsize) && (Queue[p].first<=Queue[i].first))		
	{
			if(Queue[p].first==Queue[i].first)				
			{
				if(Queue[p].second->name<Queue[i].second->name)
					smallest=p;
				else
					smallest=i;
			}		
			else smallest=p;
	}
	else 
		smallest=i;
	
	int t=smallest;
    
	if ((q<heapsize) && (Queue[q].first<=Queue[smallest].first)) 
			if(Queue[q].first==Queue[smallest].first)      
			{
				if(Queue[q].second->name<Queue[smallest].second->name)
					smallest=q;
				else
					smallest=t;
			}
			else
				smallest=q;

	if (smallest!=i)							
    {
		swap(Queue[smallest],Queue[i]);        		
		MinHeapify(smallest,heapsize);
    }
}



/*
 This function is used to construct edge of the Adjacency List
*/
void MinPriority::constructEdge(string &sourceVertex, string &destVertex,int &weight)
{
	Vertex * src=getVertex(sourceVertex);
	Vertex * dst=getVertex(destVertex);
	src->adj.push_back(pair<int,Vertex *> (weight,dst));
	
	
}

/*
 This function is used to construct edge of the Adjacency List
*/

Vertex * MinPriority::getVertex(string &nameOFvertex)
{
	vtxmap::iterator vtx = vertexMap.find( nameOFvertex );
	if( vtx == vertexMap.end( ) )
    		{
       		 Vertex *newvertex = new Vertex( nameOFvertex );
        		 vertexMap.insert( vtxpair( nameOFvertex, newvertex ) );
			 return newvertex;
    		}
    return (*vtx).second;
}

/*
 This function is used to Minimum spanning tree using Prim's algorithm
*/
void MinPriority::mstPrims(Vertex* r)
{	
vtxmap::iterator itr;	

string x;
Vertex *vtx;
r->key=0;
r->parent="NIL";
int total=0;
for(itr=vertexMap.begin();itr!=vertexMap.end();itr++)
{
	Queue.push_back (pair<int,Vertex *> (itr->second->key,itr->second));
}
while(!Queue.empty())
{
	vtx=Queue[0].second;	
	cout<<Queue[0].second->name<<" "<<Queue[0].second->parent<<" "<<Queue[0].first<<endl;
	total=total+Queue[0].first;
	Queue.erase(Queue.begin());
	if(Queue.empty())
	{
		cout<<total;
		return;
	}
for(int i=0;i<vtx->adj.size();i++)
{
	for(int k=0;k<Queue.size();k++)
	{
		if((vtx->adj[i].second==Queue[k].second) && (vtx->adj[i].first < vtx->adj[i].second->key))
		{
			vtx->adj[i].second->path=vtx;
			vtx->adj[i].second->key=vtx->adj[i].first;
			vtx->adj[i].second->parent=vtx->name;
			for(int j=0;j<Queue.size();j++)
			{
				if(Queue[j].second==vtx->adj[i].second)
				{
					Queue.erase(Queue.begin()+j);
					Queue.push_back(pair<int,Vertex *> (vtx->adj[i].first,vtx->adj[i].second));	
					break;
				}	
			}
		break;
		}	
	}	
}	
	for(int j=((Queue.size()) / 2)-1;j>=0;j--) 
	MinHeapify(j,Queue.size());
	
}

}



/*
 Constructor
*/

Vertex::Vertex(string &n)
{
	name=n;
	dist=INFINITY;
	path=NULL;
    key=INFINITY;	
}

/*
 This function is used to get vertexmap
 */

vtxmap MinPriority::getVertexmap()
{
    return vertexMap;
}
