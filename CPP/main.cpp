#include <bits/stdc++.h>
#include "./data/createData.h"
#include "./input/dataInput.h"
#include "./input/relationInput.h"
#include "./Baysseion_Network/network.h"

using namespace std;

int main(){

    //creattion of the data set

    createData create;
    create.dataset(6,5,10);

    // taking the input data and storing it in the structure;

    dataInput datatake;
    unordered_map<string,vector<string>> data = datatake.get_data("./data/test.csv");// getting the correct values;
    datatake.print();

    // taking the realtion as input;
    relationInput relationtake;
    vector<pair<string,string>> relation= relationtake.reation_Input("./data/relation.csv");//getting the correct values

    int n=relation.size();
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<relation[i].first<<" "<<relation[i].second<<"\n";
    }

    cout<<"*********************************************\n";

    Bayesian_Network *model=new Bayesian_Network(data,relation);
    model->Add_data();
    // model->check1();
    model->add_relation();
    cout<<"The Cycle is: "<<model->isDAG()<<"\n\n";
    // model->check_relation();
    model->create_condition();
    model->check_condition();
    model->create_Probability();
    model->check_probability();
    return 0;
}