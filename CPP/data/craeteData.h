#ifndef createData_H
#define createData_H

#include<bits/stdc++.h>
using namespace std;
class create_Data{
    public:
    char convert(int x){
        if(x==0){
            return '0';
        }
        else if(x==1){
            return '1';
        }
        else if(x==2){
            return '2';
        }
        else if(x==3){
            return '3';
        }
        else if(x==4){
            return '4';
        }
        else{
            return '5';
        }
    }


    // generate number 1 to 5 for No of Dieases 
    int number(){
        
        int arr[] = { 1,2,3 ,4, 5 }; 
        int random = rand()%5; 
        return arr[random];
    }


    void dataset(int symptons,int dieases,int row){
        ofstream myfile("test.csv");
        
        string heading = "X1,X2,X3,X4,X5,Dieases";
        // heading of csv file
        myfile<<heading<<endl;
        string str ="";

    
        vector<vector<string>> test;
        for(int i=0;i<row;i++){
            str = "";
            for(int j=0;j<symptons-1;j++){
                // generate random number 0 or 1
                int zero = rand() & 1;
                
                // convert integer to character
                str += convert(zero);
                
                // append into string
                str += ',';
            }
            
            int zero = number();
            // append Dieases 
            str += convert(zero);
            
            // write into file
            myfile<<str<<endl;
        }
        
        // close file 
        myfile.close();
    }

};


#endif
