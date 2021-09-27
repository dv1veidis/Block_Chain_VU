#include "My_lib.h"
#include "hashing.cpp"
#include "./sha256/sha256.h"
#include "pairGenerator.cpp"



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
else if (a == 5){
    int b = 0;
    double fullTimeHash = 0;
    double fullTimeSHA = 0;
    ifstream openf("./Test/konstitucija.txt");
    openf.open("./Test/konstitucija.txt");
    buffer<<openf.rdbuf();
    openf.close();
    getline(buffer, eil);
    ivestis.push_back(eil);
    while (getline(buffer, eil)){
        ivestis.push_back(eil);
    }
    while (b!= 5000){
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i=0; i<ivestis.size(); i++){
        hash.push_back(hashavimas(ivestis[i]));
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time-start_time;
    auto start_time2=std::chrono::high_resolution_clock::now();
    //cout<<"Mano hash laikas "<<(double)(time/std::chrono::microseconds(5))/1000<<" ms" <<endl;
    for (int i=0; i<ivestis.size(); i++){
        hash2.push_back(sha256(ivestis[i]));
    }
    auto second_end = std::chrono::high_resolution_clock::now();
    auto sha256_time = second_end - start_time2;
    //cout<<"SHA-256 laikas "<< (double)(sha256_time/std::chrono::microseconds(5))/1000<<" ms"<<endl;
    
    fullTimeHash +=(double)(time/std::chrono::microseconds(5))/1000;
    fullTimeSHA += (double)(sha256_time/std::chrono::microseconds(5))/1000;
    b++;
    hash.clear();
    hash2.clear();
    }
    fullTimeHash = fullTimeHash/5000;
    fullTimeSHA = fullTimeSHA/5000;
   cout<<"Average time for my hash = "<<fixed<<setprecision(3)<<fullTimeHash<<" ms"<<endl;
   cout<<"Average time for my SHA-256 = "<<fixed<<setprecision(3)<<fullTimeSHA<<" ms"<<endl;
}
else if(a==6){
    randomPairGenerator(ivestis, ivestis2, hash, hash2);
}
else if(a==7){
    ofstream fd ("./Test/poros2.txt");
    ofstream df ("./Test/poros2_hash.txt");
    vector <int> eilutes;
    string Pattern = "abcdefghijklmnopqrstuvwxyz0123456789";
    srand (time(NULL));
    int times=0;
    string random, random2;
    int randNum, randPattern, usableNum;
    string TestHash, TestHash2;
    string bitHash= "";
    string bitHash2="";
    int hexDifference=0;
    double hexPercentile=0;
    int bitDifference=0;
    double bitPercentile=0;
    int minHex=64, maxHex=0, minBit=512, maxBit=0;
    for (int i=0; i<100000; i++){
        random="";
        random2="";
        randNum = (rand()%1000+1);
        randPattern = rand()%randNum+1;
        for(int j=0; j<randNum; j++){
            if(randPattern== j+1  ){
                usableNum= rand() % Pattern.size();
                if(usableNum==Pattern.size()){
                    random+=Pattern[usableNum-1];
                }
                else if(usableNum==0){
                    random+=Pattern[usableNum+1];
                }
                else{
                    random+=Pattern[usableNum+1];
                }      
                random2+=Pattern[usableNum];
            }
            else{
                usableNum= rand() % Pattern.size();
                random+=Pattern[usableNum];
                random2+=Pattern[usableNum];
            }
            
        }
        ivestis.push_back(random);
        hash.push_back(hashavimas(random));
        ivestis2.push_back(random2);
        hash2.push_back(hashavimas(random2));
    }
    for(int i=0; i<100000; i++){
        hexDifference=0;
        bitDifference=0;
        fd<<ivestis[i]<<" "<<ivestis2[i]<<endl;
        df<<hash[i]<<" "<<hash2[i]<<endl;
        TestHash= hash[i];
        TestHash2= hash2[i];
        bitHash="";
        bitHash2="";
        for(int j=0; j<64; j++ ){
            bitHash+=bitset<8>(TestHash[j]).to_string();
            bitHash2+=bitset<8>(TestHash2[j]).to_string();
            if(TestHash[j]!=TestHash2[j]){
                hexDifference++;
            }
        }
        if(hexDifference>maxHex){
            maxHex=hexDifference;
        }
        if(hexDifference<minHex){
             minHex=hexDifference;
        }
        hexPercentile+= (double)(hexDifference*100/64);
        for(int k=0; k<512; k++){
            if(bitHash[k]!=bitHash2[k]){
                bitDifference++;
            }
        }
        if(bitDifference>maxBit){
            maxBit=bitDifference;
        }
        if(bitDifference<minBit){
             minBit=bitDifference;
        }
        bitPercentile+=(double)(bitDifference*100/512);
        if((hash[i]==hash2[i]) && (ivestis[i]!=ivestis2[i])){
            eilutes.push_back(i);
        }
    }
    fd.close();
    df.close();
    if(eilutes.size()==0){
        cout<<"Kolizija neaptikta"<<endl;
    }
    else{
        cout<<"Kolizija aptikta :";
        for(int i=0; i<eilutes.size(); i++){
            cout<<eilutes[i]<<", ";
        }
        cout<<" Eilutese"<<endl;
    }
    cout<<"                                "<<"Hex "<<"Bit"<<endl;
    cout<<"Minimalio skirtingumo reiksmes: "<<minHex<<"  "<<minBit<<endl;
    cout<<"Maksimalios skirtingumo reiksmes: "<<maxHex<<"  "<<maxBit<<endl;
    cout<<fixed<<setprecision(2)<<"Hexadecimal difference achieved: "<<hexPercentile/100000<<" %"<<endl;
    cout<<fixed<<setprecision(2)<<"Bit difference achieved: "<<bitPercentile/100000<<" %"<<endl;
}

}

void testai (vector<string> &ivestis, vector<string> &ivestis2, vector<string> &hash, vector<string> &hash2){
    cout<<"Pasirinkite testa(Iveskite testo skaiciu): \n"
    <<"1 - dvieju simboliu hash playginimas\n"
    <<"2 - tuscio failo hashavimas\n"
    <<"3 - >1000 simboliu failu hashavimas\n"
    <<"4 - >1000 simboliu failu, skirianciu tik vienu simboliu, hashavimo palyginimas\n"
    <<"5 - konstitucija.txt failo hashavimo laiko matavimas palyginant su SHA-256\n"
    <<"6 - Poru generatorius\n"
    <<"7 - Poru tesiskirianciu vienu simboliu bitu ir hexu skirtumo palyginimas"<<endl;
    cout<<"Jusu ivestis : ";
    int pasirinkimas;
    cin>>pasirinkimas;
    while(pasirinkimas>7 || pasirinkimas<1){
        cin.clear();
        cin.ignore();
        cout<<"Blogas ivestis. Prasome ivesti is naujo!"<<endl;
        cout<<"Jusu ivestis : ";
        cin>>pasirinkimas;
    }
        testInput(ivestis, ivestis2, hash, hash2, pasirinkimas);
}