#ifndef network_H
#define network_H

#include <bits/stdc++.h>

using namespace std;

class Node {

	public:
		string columnName;
		vector<Node*> parent;
		vector<Node*> next;
		vector<string> values;
		set<string> type;
		vector<pair<string,vector<string>>> condition ;
		vector<pair<string,vector<double>>> probability;

		Node(string val){
			columnName=val;
		}
};

class allNode
{
	public:
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
			relations=inputrelation;
			model.arr={};
		}

	//check the null values is there oe not;// special


	// create the seperate node and strore all of the in allNode (harshit)
	// put the name, values, type
	void Add_data(){
        for(auto x : data){
            Node *p= new Node(x.first);
            p->values=x.second;
            set<string> s;
            int n=x.second.size();
            for(int i=0;i<n;i++){
                s.insert(x.second[i]);
            }
            p->type=s;
            model.arr.push_back(p);

        }
    }
	
	void check1(){
		cout<<"print: ";
		for(auto x : model.arr){
			cout<<x->columnName<<" :";
			for(auto xx: x->values)cout<<xx<<" ";
			cout<<endl;
			cout<<"type: ";
			for(auto xxx: x->type)cout<<xxx<<" ";
			cout<<endl;
		}
	}

	//based on given relation find the relation and put in each nodes parent and children (Akash FuckBoy)
	void add_relation(){
        string ancestor, child;

        for(int j=0; j<relations.size(); j++){
            ancestor=relations[j].first, child=relations[j].second;
			Node *x,*y;
            for(int i=0; i<model.arr.size(); i++){
                
                if( model.arr[i]->columnName == child) {
					x=model.arr[i];
                }

                if( model.arr[i]->columnName == (ancestor) ) {
					y=model.arr[i];
                }
            }
			x->parent.push_back(y);
			y->next.push_back(x);
        }
    }

	void check_relation(){
		int n=model.arr.size();
		for(int i=0;i<n;i++){
			
			Node* x=model.arr[i];
			cout<<"Parent "<<x->columnName<<" :";
			for(auto xx: x->parent){
				cout<<xx->columnName<<" ";
			}
			cout<<endl;
		}
	}

	// // check the relation { Rajnish }
	// bool checkCycle(int node, unordered_map<string, list<string> > &adj, unordered_map<string , bool >& visited , unordered_map<string , bool > & dfsvisited) {
	// 	visited[node] = true;
	// 	dfsvisited[node] = true;

	// 	for(auto neighbour: adj[node]){
	// 		if(visited[neighbour]==false){
	// 			bool cycleDetected = checkCycle(neighnour,adj,visited,dfsvisited);
	// 			if(cycleDetected)
	// 				return true;
	// 		}
	// 		else if(dfsvisited[neighbour]){
	// 			return true
	// 		}
	// 	}
	// 	dfsvisited[node] = false;
	// 	return false;
	// }


	// // taking no of nodes or vertices 
	// bool isDAG()
	// {
	// 	// No. of nodes or vertices
	// 	int vertices=data.size();

	// 	// create a adjacency list for all nodes
	// 	unordered_map<string, list<string> > adj;


	// 	for(int i=0;i<relations.size();i++){
	// 		int u = relations[i].first;
	// 		int v = relations[i].second;

	// 		adj[u].push_back(v);
	// 	}

	// 	// make a visited and dfsvisited map 
	// 	unordered_map<string , bool > visited;
	// 	unordered_map<string , bool > dfsvisited;
		
	// 	for(int i = 1; i <=vertices; i++)
	// 	{
	// 		if(visited[i]==false){
	// 			// call checkcycle function for detect DAG in a given relation 
	// 			if(checkCycle(i, adj, visited, dfsvisited)) {
	// 				return true;
	// 			}
	// 		}
	// 	}
	// 	return false;
	// }


	// //filling the conidtion table based on the parent node;
	// vector<vector<int>> build(vector<vector<int>> & arr, int type){
    //     vector<vector<int>> ar;
    //     if(arr.size()==0){
    //         for(int i=0; i<type; i++){
    //             vector<int> a = {i};
    //             ar.push_back(a);
    //         }
    //     }
    //     else{
    //         for(int j=0; j<type; j++){
    //             for(int i=0; i<arr.size(); i++){
    //                 vector<int> temp = arr[i];
    //                 temp.push_back(j);
    //                 ar[i].push_back(temp);
    //             }
    //         }
    //     }

    //     return ar;
    // }

    // vector<pair<string, vector<string>>> create_condition_table(vector<Node*> parent, int i, vector<string> &v, int n, Node* A){
	// 	vector<vector<int>> table;
        
    //     for(int i=0; i<parent.size(); i++){
    //         int val = parent->type.size();
    //         v.push_back(parent->columnName);
    //         build(table, val);
    //     }
        
	// }

	// // based on condition we havew to create the probabolity;
	// void setProbability(Node * root){
	// 	//initiate the probability datatype;
	// 	for(string x: root->type){
	// 		vector<double> vv;
	// 		root->probability.push_back({x,vv});
	// 	}
		
	// 	int m=root->condition.size();

	// 	if(m!=0){
	// 		int n=root->condition[0].second.size();
	// 		vector<pair<string,string>> pp; // to store all the values of the in each row
	// 		for(int i=0;i<m;i++){// to store the column name in pair;
	// 			pp.push_back({root->condition[i].first,""});
	// 		}
	// 		for(int i=0;i<n;i++){// travesed to get the values of each row;
	// 			for(int j=0;j<m;j++){
	// 				// setting all the values of each pair in the condition row;
	// 				pp[j].second=root->condition[j].second[i];
	// 			}
	// 			vector<int> arr;//vector<to store all the values;
	// 			int nn=data[root->columnName].size();
	// 			bool check;
	// 			for(int j=0;j<nn;j++){
	// 				// travese therought all the values of data;
	// 				check=true;
	// 				for(int k=0;k<m;k++){
	// 					//traverse frrom all the values in column of pp vector<pair>
	// 					if(data[pp[k].first][j]!=pp[k].second){
	// 						check=false;// checking if the pp data is same for that row in data
	// 						break
	// 					}
	// 				}

	// 				if(check){// it the condition that the column is the one which is the  solution
	// 					arr.push_back(data[root->columnName][j]);
	// 				}
	// 				int ppp=root->probability.size();
	// 				int arr_n=arr.size()

	// 				for(int k=0;k<ppp;k++){//pass through all the values of the probability
	// 					int data=count(arr,arr + arr_n,root->probability[k].first);
	// 					double xx=data/arr_n;
	// 					if(xx==0) x=1e-6;
	// 					root->probability[k].second.push_back(xx);
	// 				}


	// 			}

	// 		}


	// 	}
	// }

	// void findProbanbility(){
	// 	int n=mode->arr.size();
	// 	for(int i=0;i<n;i++){
	// 		setProbability(model->arr[i]);
	// 	}

	// }



	//got to all nodes and find the probability and multuiply it;

};


#endif