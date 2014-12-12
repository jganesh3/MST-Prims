/*
* @author : Ganesh Joshi
*  File : MSTapp.cpp  
*  Functions:GenerateGraph()
*  Date :18 May 2013 
*
*/
#include<iostream>
#include"Graph.h"
#include"MSTapp.h"
#include<sstream>
#include<fstream>
using namespace std;

void MSTapp::GenerateGraph()
{
	Graph reader;
	reader.readFile();
			
}

int main(int argc, char* argv[])
{
	
	MSTapp x;
	x.GenerateGraph();

}                     
