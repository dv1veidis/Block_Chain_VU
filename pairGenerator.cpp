#include "My_lib.h"

void randomPairGenerator (vector<string> &ivestis, vector<string> &ivestis2, vector<string> &hash, vector<string> &hash2){
    cout<<"Ar norite generuoti naujas poras?(t/T - taip, n/N - ne)"<<endl;
    string pasirinkimas;
    cin>>pasirinkimas;
    while (pasirinkimas!="t" && pasirinkimas!="T" && pasirinkimas!="n" && pasirinkimas!="N"){
        cout<<"Bloga ivestis. Prasome ivesti is naujo!"<<endl;
        cin>>pasirinkimas;
    }
    if(pasirinkimas=="t" || pasirinkimas=="T"){
        ofstream fd ("./Test/poros.txt");
    ofstream df ("./Test/poros_hash.txt");
    vector <int> eilutes;
    string Pattern = "abcdefghijklmnopqrstuvwxyz0123456789";
    srand (time(NULL));
    int times=0;
    string random;
    string random2;
    for (int i=0; i<25000; i++){
        random="";
        random2="";
        for(int j=0; j<10; j++){
            random+=Pattern[rand() % Pattern.size()];
            random2+=Pattern[rand() % Pattern.size()];
        }
        ivestis.push_back(random);
        hash.push_back(hashavimas(random));
        ivestis2.push_back(random2);
        hash2.push_back(hashavimas(random2));
    }
    for (int i=0; i<25000; i++){
        random="";
        random2="";
        for(int j=0; j<100; j++){
            random+=Pattern[rand() % Pattern.size()];
            random2+=Pattern[rand() % Pattern.size()];
        }
        ivestis.push_back(random);
        hash.push_back(hashavimas(random));
        ivestis2.push_back(random2);
        hash2.push_back(hashavimas(random2));
    }
    for (int i=0; i<25000; i++){
        random="";
        random2="";
        for(int j=0; j<500; j++){
            random+=Pattern[rand() % Pattern.size()];
            random2+=Pattern[rand() % Pattern.size()];
        }
        ivestis.push_back(random);
        hash.push_back(hashavimas(random));
        ivestis2.push_back(random2);
        hash2.push_back(hashavimas(random2));
    }
    for (int i=0; i<25000; i++){
        random="";
        random2="";
        for(int j=0; j<1000; j++){
            random+=Pattern[rand() % Pattern.size()];
            random2+=Pattern[rand() % Pattern.size()];
        }
        ivestis.push_back(random);
        hash.push_back(hashavimas(random));
        ivestis2.push_back(random2);
        hash2.push_back(hashavimas(random2));
    }
    for(int i=0; i<100000; i++){
        fd<<ivestis[i]<<" "<<ivestis2[i]<<endl;
        df<<hash[i]<<" "<<hash2[i]<<endl;
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

    }
    else{
        string vieta = "./Test/poros";
        ofstream df ("./Test/poros_hash.txt");
        ifstream openf (vieta+"poros.txt");
        vector <int> eilutes;
        stringstream buffer;
        string pair1, pair2;
        string eil;    
        openf.open(vieta+".txt");
        if(!openf){
            cout<<"Nera poros.txt failo Test aplanke, programa bus nutraukiama"<<endl;
        }
        else{
            buffer<<openf.rdbuf();
            getline(buffer, eil);
            buffer>>pair1>>pair2;
            ivestis.push_back(pair1);
            ivestis2.push_back(pair2);
            hash.push_back(hashavimas(pair1));
            hash2.push_back(hashavimas(pair2));
            while(getline(buffer, eil)){
                buffer>>pair1>>pair2;
                ivestis.push_back(pair1);
                ivestis2.push_back(pair2);
                hash.push_back(hashavimas(pair1));
                hash2.push_back(hashavimas(pair2));
            }
            for(int i=0; i<100000; i++){
                df<<hash[i]<<" "<<hash2[i]<<endl;
                if((hash[i]==hash2[i]) && (ivestis[i]!=ivestis2[i])){
                eilutes.push_back(i);
                }
            }       
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

        }
    }
    
}