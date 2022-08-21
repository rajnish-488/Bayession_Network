#ifndef network_H
#define network_H

#include <bits/stdc++.h>

using namespace std;

struct Node {
	string columnName;
	vector<Node*> parent;
	vector<Node*> next;
	vector<string> values;
	unordered_set<string> type;
	vector<pair<string,vector<string>>> condition ;
	vector<pair<string,vector<double>>> probability;
};

struct allNode
{
	vector<Node *> arr;
};

class Bayesian_Network{

	public:
	// data input: 				unordered_map<string,vector<string>>
	// input relation data : 	vector<pair<string,string>>


	unordered_map<string,vector<string>> data;
	vector<pair<string,string>> relations;

	Bayesian_Network(unordered_map<string,vector<string>> inputdata,vector<pair<string,string>> inputrelation){
		data=inputdata;
		relations=inputrealtion;
	}

	//check the null values is there oe not;// special


	// create the seperate node and strore all of the in allNode (harshit)
	// put the name, values, type

	


	//based on given relation find the relation and put in each nodes parent and children (Akash FuckBoy)


	// check the relation { Rajnish }



	//filling the conidtion table based on the parent node;


	// based on condition we havew to create the probabolity;

	//got to all nodes and find the probability and multuiply it;

}


#endif