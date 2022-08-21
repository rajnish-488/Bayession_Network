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
    allNode model;

	Bayesian_Network(unordered_map<string,vector<string>> inputdata,vector<pair<string,string>> inputrelation){
		data=inputdata;
		relations=inputrealtion;
        model->arr={};
	}

	//check the null values is there oe not;// special


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


	// check the relation { Rajnish }



	//filling the conidtion table based on the parent node;

	vector<pair<string,vector<string>>> solve(vector<Node*> parent,int i,vector<string> &v,int n,Node* A){
		if(i==n){
			for(int i=0;i<n;i++){

			}
		}
	}

	void set_condition(){
		int n=model->arr.size();
		for(int i=0;i<n;i++){
			vector<Node*> parent=model->arr[i]->parent;
			int n=parent.size();
			for(int i=0;i<n;i++){
				vector<string> x;
				model->arr[i].condition.push_back({parent[i]->columnName,x});
			}
			vector<string> v;
			solve(parent,0,v,n);

		}
	}


	// based on condition we havew to create the probabolity;

	//got to all nodes and find the probability and multuiply it;

}


#endif