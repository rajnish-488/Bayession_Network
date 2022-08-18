#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

struct node {
	string nodeName;
	vector<string> parents;
	vector<int> parentsIndices;	
	vector<double> probs;
	vector< vector<char> > truthTable;
};
//tkn should be read for relation and data to be passed using for loop
for(int i=0; i<n; i++)
{
    if(tkn != NULL){
	    topNode = new node; //first "word" on line has to be name of a node
	    topNode->nodeName = tkn;
    }
    else 
	    continue;
}

//now inserting the probability in the node after establishin all relation and calculating its dependency
// The atof() function in C++ interprets the contents of a string as a floating point number and return its value as a double.
while(tkn != NULL){	
	if( !atof(tkn) && strcmp(tkn,"NONE") != 0) //any non-number is name of parent
	{
		topNode->parents.push_back(tkn);
		addParentNode(topNode, tkn);
	}
	else if(atof(tkn)) //any number is a probability
	{
		topNode->probs.push_back(atof(tkn));	
		numProbsInBN++;
	}
	tkn = strtok(NULL,delim);
}