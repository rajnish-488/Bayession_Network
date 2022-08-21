#include <bits/stdc++.h>
#include "./data/createData.h"
#include "./input/dataInput.h"
#include "./input/relationInput.h"

using namespace std;


int main(){

    //creattion of the data set

    createData create;
    create.dataset(6,5,10);

    // taking the input data and storing it in the structure;

    dataInput datatake;
    unordered_map<string,vector<string>> data = datatake.get_data("./data/test.csv");
    datatake.print();

    // taking the realtion as input;
    relationInput relationtake;
    vector<pair<string,string>> relation= relationtake.reation_Input("./data/relation.csv");
    // int n=relation.size();
    // cout<<"\n";
    // for(int i=0;i<n;i++){
    //     cout<<relation[i].first<<" "<<relation[i].second<<"\n";
    // }
    

    return 0;
}