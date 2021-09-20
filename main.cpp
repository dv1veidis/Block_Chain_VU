#include "My_lib.h"

void input (vector<string> &ivestis){
cout<<"Ar norite duomenis ivesti is failo ar ranka?(f-failo/r-rankos)"<<endl;
string input;
cin>>input;
while(input!="f" && input!="F" && input!="r" && input!="R"){
input.erase();
cout<<"Neteisinga Ivestis! Prasome ivesti f arba r"<<endl;
cin>>input;
}

if(input =="f" || input=="F"){
    string eil;
    string failas;
    cout<<"Iveskite tik failo pavadinima"<<endl;
    cin>>failas;
    ifstream openf(failas);
    stringstream buffer;
    openf.open(failas+".txt");
    while(!openf){
        cout<<"Nerastas "<<failas<<" failas!"<<endl;
    cin>>failas;
    openf.open(failas);
    }
    buffer<<openf.rdbuf();
    openf.close();
    getline(buffer, eil);
    ivestis.push_back(eil);
    while (getline(buffer, eil)){
        ivestis.push_back(eil);
    }

}
else {
    string pasirinkimas="t";
    while (pasirinkimas == "T" || pasirinkimas == "t"){
    cout<<"Iveskite ka norite hashuoti"<<endl;
    string naudIvestis="";
    cin.ignore();
    getline(cin, naudIvestis);
    ivestis.push_back(naudIvestis);
    cout<<"Ar dar norite ivesti kazka naujo?(Iveskite T/t jei taip, ir N/n jei ne)"<<endl;
    cin>>pasirinkimas;
    }
}
}

void output(vector<string> ivestis){
for(int i=0; i<ivestis.size(); i++){
    cout<<ivestis[i]<<endl;
}
}


int main(){
    vector<string> ivestis;
    input(ivestis);
    output(ivestis);

    return 0;
}