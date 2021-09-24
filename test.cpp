#include "My_lib.h"
#include "hashing.cpp"

void testInput(vector<string> &ivestis, vector<string> &ivestis2, vector<string> &hash, vector<string> &hash2, int a){
string eil;
stringstream buffer;
stringstream buffer2;
if(a == 1){
    ifstream openf("./Test/a.txt");
    openf.open("./Test/a.txt");
    buffer<<openf.rdbuf();
    openf.close();
    getline(buffer, eil);
    ivestis.push_back(eil);
    hash.push_back(hashavimas(eil));
    while (getline(buffer, eil)){
        ivestis.push_back(eil);
        hash.push_back(hashavimas(eil));
    }
    ifstream openf2("./Test/b.txt");
    openf2.open("./Test/b.txt");
    buffer2<<openf2.rdbuf();
    openf2.close();
    getline(buffer2, eil);
    ivestis2.push_back(eil);
    hash2.push_back(hashavimas(eil));
    while (getline(buffer2, eil)){
        ivestis2.push_back(eil);
        hash2.push_back(hashavimas(eil));
    }
    if(hash[0] == hash2[0]){
        cout<<"Ivyko kolizija"<<endl;
        cout<<ivestis[0]<<" "<<hash[0]<<endl;
        cout<<ivestis2[0]<<" "<<hash2[0]<<endl;
    }
    else{
        cout<<"Hash skirtingas"<<endl;
        cout<<ivestis[0]<<" "<<hash[0]<<endl;
        cout<<ivestis2[0]<<" "<<hash2[0]<<endl;
    }

}
else if (a==2){
    ifstream openf("./Test/empty.txt");
    openf.open("./Test/empty.txt");
    buffer<<openf.rdbuf();
    openf.close();
    getline(buffer, eil);
    ivestis.push_back(eil);
    hash.push_back(hashavimas(eil));
    cout<<"Tuscias failas empty.txt : "<<hash[0];
}
else if (a==3){
    ifstream openf("./Test/TestA.txt");
    openf.open("./Test/TestA.txt");
    buffer<<openf.rdbuf();
    openf.close();
    getline(buffer, eil);
    ivestis.push_back(eil);
    hash.push_back(hashavimas(eil));
    while (getline(buffer, eil)){
        ivestis.push_back(eil);
        hash.push_back(hashavimas(eil));
    }
    ifstream openf2("./Test/TestB.txt");
    openf2.open("./Test/TestB.txt");
    buffer2<<openf2.rdbuf();
    openf2.close();
    getline(buffer2, eil);
    ivestis2.push_back(eil);
    hash2.push_back(hashavimas(eil));
    while (getline(buffer2, eil)){
        ivestis2.push_back(eil);
        hash2.push_back(hashavimas(eil));
    }
    if(hash[0] == hash2[0]){
        cout<<"Ivyko kolizija"<<endl;
        cout<<"TestA - "<<hash[0]<<endl;
        cout<<"TestB - "<<hash2[0]<<endl;
    }
    else{
        cout<<"Hash skirtingas"<<endl;
        cout<<"TestA - "<<hash[0]<<endl;
        cout<<"TestB - "<<hash2[0]<<endl;
    }
}
else if (a==4){
    ifstream openf("./Test/TestA_A.txt");
    openf.open("./Test/TestA_A.txt");
    buffer<<openf.rdbuf();
    openf.close();
    getline(buffer, eil);
    ivestis.push_back(eil);
    hash.push_back(hashavimas(eil));
    while (getline(buffer, eil)){
        ivestis.push_back(eil);
        hash.push_back(hashavimas(eil));
    }
    ifstream openf2("./Test/TestA_B.txt");
    openf2.open("./Test/TestA_B.txt");
    buffer2<<openf2.rdbuf();
    openf2.close();
    getline(buffer2, eil);
    ivestis2.push_back(eil);
    hash2.push_back(hashavimas(eil));
    while (getline(buffer2, eil)){
        ivestis2.push_back(eil);
        hash2.push_back(hashavimas(eil));
    }
    if(hash[0] == hash2[0]){
        cout<<"Ivyko kolizija"<<endl;
        cout<<"TestA_A - "<<hash[0]<<endl;
        cout<<"TestA_B - "<<hash2[0]<<endl;
    }
    else{
        cout<<"Hash skirtingas"<<endl;
        cout<<"TestA_A - "<<hash[0]<<endl;
        cout<<"TestA_B - "<<hash2[0]<<endl;
    }
}

}

void testai (vector<string> &ivestis, vector<string> &ivestis2, vector<string> &hash, vector<string> &hash2){
    cout<<"Pasirinkite testa(Iveskite testo skaiciu): \n"
    <<"1 - dvieju simboliu hash playginimas\n"
    <<"2 - tuscio failo hashavimas\n"
    <<"3 - >1000 simboliu failu hashavimas\n"
    <<"4 - >1000 simboliu failu, skirianciu tik vienu simboliu, hashavimo palyginimas"<<endl;
    cout<<"Jusu ivestis : ";
    int pasirinkimas;
    cin>>pasirinkimas;
    while(pasirinkimas>4 || pasirinkimas<1){
        cin.clear();
        cin.ignore();
        cout<<"Blogas ivestis. Prasome ivesti is naujo!"<<endl;
        cout<<"Jusu ivestis : ";
        cin>>pasirinkimas;
    }
        testInput(ivestis, ivestis2, hash, hash2, pasirinkimas);
}