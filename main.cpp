#include "My_lib.h"
#include "test.cpp"
#include "input.cpp"
#include "./sha256/sha256.h"
#include "./sha256/sha256.cpp"


int main(){
    vector<string> ivestis;
    vector<string> hash;
    vector<string> ivestis2;
    vector<string> hash2;
    string pasirinkimas;
    cout<<"Norite pasinaudoti hash algoritmu(Iveskite a/A) ar norite atlikti testus(Iveskite t/T)"<<endl;
    cin>>pasirinkimas;
    while(pasirinkimas.size()>1 ||(pasirinkimas != "a" && pasirinkimas != "A" && pasirinkimas != "t" && pasirinkimas != "T") ){
        cout<<"Bloga ivestis. Prasome ivesti is naujo!"<<endl;
        cin>>pasirinkimas;
    } 
    if(pasirinkimas == "a" || pasirinkimas == "A"){
        input(ivestis, hash);
        output(ivestis, hash);
    }
    else{
        testai(ivestis,ivestis2, hash, hash2);
    }
    

    return 0;
}