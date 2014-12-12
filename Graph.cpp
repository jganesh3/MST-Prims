/**
 * @file Graph.cpp
 * 
 * @brief This class will be used to create the graph
 *    
 * @author Ganesh Joshi 
 * @date 05/14/2013
 */

#include"Graph.h"
#include"MinPriority.h"
#include<fstream>
#include<sstream>
#include<iostream>


/**
*      Function readfile() is used to read the input file and
*      populate the vertex of the graph 
* 
*/ 

void Graph::readFile()
{

    Vertex *v;
    MinPriority g;
    vtxmap::iterator itr;
    string str2,str1,str4;		
    int wt;
    string source, dest,str3;
    getline(cin,str1);
    stringstream read1(str1);

while(read1>>str3)
{	
	v=g.getVertex(str3);
}	

 while(getline(cin, str2 ) )    
    {
		if(str2=="\n")
		break;
	
	else if(!cin.eof())     
	{
        stringstream read2(str2); 
		read2>>source;  
		read2>>dest;  
		read2>>wt;  
       	g.constructEdge(source,dest,wt);
		if(source!=dest)
		g.constructEdge(dest,source,wt);

	}
 }

    vtxmap x;
    x=g.getVertexmap();
	itr=x.begin();	
	g.mstPrims(itr->second);	
	
	
}

