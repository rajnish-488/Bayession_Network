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

    Node(string s){
        this.columnName=s;
    }
};

void populateTruthTableNodes(node* oneNode, int rows, int cols);
struct allNode
{
	vector<Node *> arr;
};

class Bayesian_Network{

	public:
	// data input: 				unordered_map<string,vector<string>>
	// input relation data : 	vector<pair<string,string>>


	unordered_map<string,vector<string>> data;
	vector<pair<string,string>> relations; //parent, child
    allNode model;

	Bayesian_Network(unordered_map<string,vector<string>> inputdata,vector<pair<string,string>> inputrelation){
		data=inputdata;
		relations=inputrealtion;
        model->arr={};
	}

	//check the null values is there oe not; // special

	// create the seperate node and strore all of the in allNode (harshit)
	// put the name, values, type

    void Add_data(){
        for(auto x : data){
            Node *p= new Node(x.first);
            p->values=x.second;
            unordered_set<string> s;
            int n=x.second.size();
            for(int i=0;i<n;i++){
                s.insert(x.second[i]);
            }
            p->type=s;
            model->arr.push_back(p);
        }
    }

	//based on given relation find the relation and put in each nodes parent and children (Akash FuckBoy)
    void add_relation(){
        string ancestor, child;

        for(int j=0; j<relations.size(); j++){
            ancestor=relations[j].first, child=relations[j].second;

            for(int i=0; i<model->arr.size(); i++){
                
                if( model->arr[i]->columnName == (child)) {
                    model->arr[i]->parent.push_back(ancestor);
                }

                if( model->arr[i]->columnName == (ancestor) ) {
                    model->arr[i]->next.push_back(child);
                }
            }
        }
    }

	// check the relation { Harshit }



	//filling the conidtion table based on the parent node;


	// based on condition we havew to create the probabolity;

	//got to all nodes and find the probability and multuiply it;
//     void populateTruthTableNodes(node* oneNode, int rows, int cols)
//     {
// 	    vector<char> tempVec;
// 	    for(int i = 0; i < cols; i++)
// 		    tempVec.push_back('T');
// 	    for(int i = 0; i < rows; i++)
// 		    oneNode->truthTable.push_back(tempVec);
		
// 	    int exp= 1;
//     	    for( int i = 0;  i < cols; i++)
//     	    {
//         	    for(int j= 0;  j< rows; j++)
//         	    {
// 	   		        int val = 1- j/exp % 2;
// 	   		        if(val)
// 				        oneNode->truthTable[j][cols-1-i] = 'T';
// 			        else
// 				        oneNode->truthTable[j][cols-1-i] = 'F'; 	 	 
// 		        }
//         	exp *= 2;
// 	}	
// }

    /*vector<pair<string, vector<string>>> solve(vector<Node*> parent, ){ 
        string ancestor="";
        for(int i=0; i<parent.size(); i++){
            ancestor += parent[i]->parent;

        }
    }*/

//recursively build the data members in the vector
    vector<vector<int>> build(vector<vector<int>> & arr, int type){
        vector<vector<int>> ar;
        if(arr.size()==0){
            for(int i=0; i<type; i++){
                vector<int> a = {i};
                ar.push_back(a);
            }
        }
        else{
            for(int j=0; j<type; j++){
                for(int i=0; i<arr.size(); i++){
                    vector<int> temp = arr[i];
                    temp.push_back(j);
                    ar[i].push_back(temp);
                }
            }
        }

        return ar;
    }

    vector<pair<string, vector<string>>> solve(vector<Node*> parent, int i, vector<string> &v, int n, Node* A){
		vector<vector<int>> table;
        
        for(int i=0; i<parent.size(); i++){
            int val = parent->type.size();
            v.push_back(parent->columnName);
            build(table, val);
        }
        // if(i==n){
		// 	for(int i=0;i<n;i++){
                
		// 	}
		// }
	}
}


#endif