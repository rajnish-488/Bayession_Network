#ifndef dataInput_H
#define dataInput_H

#include<bits/stdc++.h>

using namespace std;

class dataInput{
    public:

    unordered_map<string,vector<string>> ans;//globel function will retuen the data stored in the path;
    vector<string> index;

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

    void take_header(string s){
        int n=s.size();
        string p="";
        for(int i=0;i<n;i++){
            if(s[i]==','){
                trim(p);
                vector<string> empty_vector;
                ans[p]=empty_vector;
                index.push_back(p);
                p="";
            }
            else{
                p+=s[i];
            }

        }
        trim(p);
        vector<string> empty_vector;
        ans[p]=empty_vector;
        index.push_back(p);
        // return ans;
    }

    void take_values(string s){
        int n=s.size();
        string p="";
        int ii=0;
        for(int i=0;i<n;i++){
            if(s[i]==','){
                trim(p);
                ans[index[ii]].push_back(p);
                ii++;
                p="";
            }
            else{
                p+=s[i];
            }

        }
        trim(p);
        ans[index[ii]].push_back(p);
        // return ans;
    }

    unordered_map<string,vector<string>> get_data(string path){
        ans.clear();
        // cout<<"11\n";
        fstream newfile;
        try{
            newfile.open( path,ios::in); //open a file to perform read operation using file object
        }catch(string err){
            cout<<err<<"\n";
        }
        // cout<<"12\n";
        if (newfile.is_open()){   //checking whether the file is open
            string tp;
            bool first_line=true;
            while(getline(newfile, tp)){ //read data from file object and put it into string.
                if(first_line==true){
                    // cout<<"true";
                    take_header(tp);
                    first_line=false;
                }else{
                    // cout<<"false";
                    take_values(tp);
                }
                // cout<<"count\n";
            }
            newfile.close(); //close the file object.
        }else{
            cout<<"wrong path";
        }
        // cout<<"13\n";
        return ans;   
    }

    void print(){
        for(auto x: ans){
            cout<<x.first<<" -> ";
            int n=x.second.size();
            for(int i=0;i<n;i++){
                cout<<x.second[i]<<" ";
            }
            cout<<"\n";
        }
    }
};

#endif