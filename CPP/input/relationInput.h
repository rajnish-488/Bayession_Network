#ifndef relationInput_H
#define relationInput_H

#include<bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;


// this will give the take the input of the relation of the node;
class relationInput{

    public:
    
 
    const std::string WHITESPACE = " \n\r\t\f\v";
    
    std::string ltrim(const std::string &s)
    {
        size_t start = s.find_first_not_of(WHITESPACE);
        return (start == std::string::npos) ? "" : s.substr(start);
    }
    
    std::string rtrim(const std::string &s)
    {
        size_t end = s.find_last_not_of(WHITESPACE);
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }
    
    std::string trim(const std::string &s) {
        return rtrim(ltrim(s));
    }


    pair<string,string> string_to_node(string s){
        int n=s.size();
        pair<string ,string> ans;
        string p="";
        for(int i=0;i<n;i++){
            if(s[i]==','){
                trim(p);
                ans.first=p;
                p="";
            }
            else{
                p+=s[i];
            }

        }
        trim(p);
        ans.second=p;
        return ans;
    }

    vector<pair<string,string>> Reation_Input(string path){
        vector<pair<string,string>> ans;
        fstream newfile;
        try{
            newfile.open(path,ios::in); //open a file to perform read operation using file object
        }catch(string err){
            cout<<err<<"\n";
        }
        
        if (newfile.is_open()){   //checking whether the file is open
            string tp;
            while(getline(newfile, tp)){ //read data from file object and put it into string.
                ans.push_back(string_to_node(tp));
            }
            newfile.close(); //close the file object.
        }else{
            cout<<"wrong path";
        }
        return ans;
    }
};

#endif