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
		vector<string> condition ;
		vector<vector<double>> probability;

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
		for(auto x : model.arr){
			cout<<x->columnName<<" :";
			for(auto xx: x->values)cout<<xx<<", ";
			cout<<endl;
			cout<<"\ntype: ";
			for(auto xxx: x->type)cout<<xxx<<", ";
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
		cout<<"Check relation: ";
		int n=model.arr.size();
		for(int i=0;i<n;i++){
			
			Node* x=model.arr[i];
			cout<<"Parent   "<<x->columnName<<"  Child:        ";
			for(auto xx: x->parent){
				cout<<xx->columnName<<", ";
			}
			cout<<endl;
		}
	}

	bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[]) {
      vis[node] = 1;
      dfsVis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkCycle(it, adj, vis, dfsVis)) return true;
        } else if (dfsVis[it]) {
          return true;
        }
      }
      dfsVis[node] = 0;
      return false;
    }


	bool isCyclic(int N, vector < int > adj[]) {
      int vis[N], dfsVis[N];
     
      for(int i = 0; i < N; i++){
        vis[i] = 0;
        dfsVis[i] = 0;
      }

      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          // cout << i << endl; 
          if (checkCycle(i, adj, vis, dfsVis)) {
             // cout << i << endl;
            return true;
          }
        }
      }
      return false;
    }

	void addEdge(vector < int > adj[], int u, int v) {
		adj[u].push_back(v);
	}

	string isDAG(){
		map<string,int> mp;
		int i=0;
		int V=data.size();
		vector < int > adj[V];
		for(auto x: data){mp[x.first]=i;i++;}
		for(auto x: relations){
			if(mp.find(x.first)!=mp.end() and mp.find(x.second)!=mp.end())
				addEdge(adj, mp[x.first], mp[x.second]);
			else
				return x.first+" "+x.second+" " "The entered Relations can't form a garph.";
		}
		if (isCyclic(V, adj))
			return "Cycle Detected";
		else
			return "No Cycle Detected";

		return "Some Error";

	}

	void build_condition(Node* root,vector<vector<string>> &arr,int sz,string ans){
		if(sz==arr.size()){
			root->condition.push_back(ans);
			return;
		}
		int n=arr[sz].size();
		for(int i=0;i<n;i++){
			string out=ans+arr[sz][i]+"@";
			build_condition(root,arr,sz+1,out);
		}
	}

	void create_condition(){
		int n=model.arr.size();
		for(int i=0;i<n;i++){
			Node *root=model.arr[i];
			int parent_size=root->parent.size();
			vector<vector<string>> arr(parent_size);
			int ii=0;
			for(auto x : root->parent){
				vector<string> v;
				string ss="";
				for(auto y : x->type){
					string invector=ss+y;
					v.push_back(invector);
				}
				arr[ii]=v;
				ii++;
			}
			build_condition(root,arr,0,"@");
		}
	}

	void check_condition(){
		int n=model.arr.size();
		for(int i=0;i<n;i++){
			Node *root=model.arr[i];
			cout<<"Node :"<<root->columnName<<"\n";
			for(auto x: root->condition)cout<<x<<",";
			cout<<"\n";
		}
	}

	vector<string> convert_to_vector(string str){
		vector<string> order;
		int n = str.size();
		string val="";
		
		for(int i=0; i<n; i++) {
			if(str[i] == '@') continue;
			val = "";
			while(str[i] != '@'){
				val += str[i++];
			}
			order.push_back(val);
		}
		return order;

	}

	void create_Probability(){
		int n=model.arr.size();
		bool tip=false;

		// first loop (all nodes);

		for(int ii=0;ii<n;ii++){
			tip=false;
			Node *root=model.arr[ii];
			if(root->columnName=="Disease") tip=true;
			int nn=root->type.size();
			int mm=root->condition.size();
			int val_n=root->values.size();
			int parent_n=root->parent.size();
			vector<vector<double>> arr(nn, vector<double>( mm,0));


			// second loop (column)

			for(int j=0; j<mm; j++){
				vector<string> v=convert_to_vector(root->condition[j]);
				//if(tip){for(auto x: v)cout<<x<<" ";cout<<endl;} //getting all the values in V

				// third loop (row)
				set<string>::iterator it =root->type.begin();
				for(int i=0;i<nn;i++){
					// create the iterator of set
					int cnt=0;
					for(int k=0;k<val_n;k++){
						bool ut=false;
						// if(tip)cout<<root->values[k]<<" "<<*it<<" \n";
						if(root->values[k]==*it and v.size()==parent_n){
							ut=true;
							for(int l=0;l<parent_n;l++){
								if(root->parent[l]->values[k]!=v[l]){
									ut=false;
									break;
								}

							}
						}
						if(ut==true)cnt++;
					}
					// if(tip)cout<<"count: "<<cnt<<"\n";
					double out=(double(cnt))/val_n;
					arr[i][j]=max(1e-100,out);

					it++;
				}
			}
			root->probability=arr;

		}
	}


	void check_probability(){
		int n=model.arr.size();
		for(int i=0;i<n;i++){
			Node *root=model.arr[i];
			cout<<"Node : "<<root->columnName<<endl;
			for(auto x: root->probability){
				for(auto y : x){
					cout<<y<<" ";
				}
				cout<<endl;
			}
		}
	}

	vector<string> predict_probability_off_all(map<string,string> &mp,Node *root_node){
		vector<string> ans;
		int type_n=root_node->type.size();
		int n=model.arr.size();
		vector<double> arr(type_n,1);
		set<string>::iterator it =root_node->type.begin();
		double mx=1e-100;
		for(int xx=0;xx<type_n;xx++){
			mp[root_node->columnName]=*it;
			for(int ii=0;ii<n;ii++){
				Node *root=model.arr[ii];
				string out="@";
				int parent_n=root->parent.size();
				int condition_n=root->condition.size();
				for(int i=0;i<parent_n;i++){
					out+=mp[root->parent[i]->columnName];
					out+="@";
				}
				int index_j=-1,index_i=-1;
				for(int i=0;i<condition_n;i++){
					if(root->condition[i]==out)index_j=i;
				}
				int cnt=0;
				for(auto x: root->type){
					if(x==mp[root->columnName]){index_i=cnt;break;}
					else cnt++;
				}
				if(index_j==-1 or index_i==-1)arr[xx]*=1;
				else{
					arr[xx]*=root->probability[index_i][index_j];
				}
			}
			// cout<<arr[xx]<<"\n";
			if(arr[xx]>mx){
				ans.clear();
				mx=arr[xx];
			}
			if(arr[xx]==mx)ans.push_back(*it);
			it++;
		}
		
		return ans;
	}


	void predict(){

		cout<<"\n*********************************************\n";
		int count=1;
		vector<string> arr;
		for(auto x: data){
			cout<<count<<" :"<<x.first<<"\n";
			arr.push_back(x.first);
			count++;
		}
		int input1;
		cout<<"\nEnter the number what you wnated to predict: ";
		cin>>input1;
		if(input1<0 || input1>=count){cout<<"Enter the Correct Number";return;}
		map<string,string> mp;

		int n=model.arr.size();

		cout<<"\n Enter the data of the Nodes: \n";
		int input2;
		Node* input3;
		for(int ii=0;ii<n;ii++){
			Node *root= model.arr[ii];
			if(root->columnName==arr[input1-1]){input3=root;continue;}//some changes here
			cout<<"Node: "<<root->columnName<<"\n";
			
			int cnt=1;
			for(auto x: root->type){
				cout<<cnt<<" :"<<x<<"\n";
				cnt++;
			}
			cout<<"Select the value: ";
			cin>>input2;
			if(input2<=0 || input2>=cnt){ii--;continue;}
			set<string>::iterator it =root->type.begin();
			for(int i=1;i<input2;i++)it++;
			mp[root->columnName]=*it;
		}

		cout<<"/nThe output is : \n";
		for(auto x: mp){
			cout<<x.first<<" "<<x.second<<"\n";
		}

		vector<string> ans=predict_probability_off_all(mp,input3);

		cout<<"The predicted values of "<<input3->columnName<<" is/are: ";
		for(auto x: ans)cout<< x<< " ";

	}


	string check_accuracy(unordered_map<string,vector<string>> arr,int n_arr,string to_check){
		int count=0;
		map<string,string> mp;
		// creating the map;
		for(auto x: arr){
			if(x.first!=to_check)
				mp[x.first]="";
		}
		Node* input3=NULL;
		//assining value to map
		int m=model.arr.size();
		for(int i=0;i<m;i++){
			Node *root= model.arr[i];
			if(root->columnName==to_check){input3=root;break;}
		}
		if(input3==NULL) return "The paramenter inputed to find dont match the Model feilds";
		for(int i=0;i<n_arr;i++){
			for(auto x: arr){
				if(x.first!=to_check)
					mp[x.first]=x.second[i];
			}
			vector<string> ans=predict_probability_off_all(mp,input3);

			int ans_n=ans.size();
			cout<<arr[to_check][i]<<": ";
			for(int j=0;j<ans_n;j++){
				cout<<ans[j]<<" ";
			}
			cout<<endl;
			for(int j=0;j<ans_n;j++){
				if(ans[j]==arr[to_check][i]){
					count++;
					break;
				}
			}
		}

		double out= (double)count/n_arr;
		out*=100;
		string out_ans=to_string(out);
		return out_ans;  

	} 

};


#endif