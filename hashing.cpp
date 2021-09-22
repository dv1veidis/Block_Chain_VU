#include "My_lib.h"


string hashavimas (string input){
    string hash = "";
    int salt = 512; // reiksme kuri leidzia net tusciam input buti hashuojamam ir padidina atsistiktinuma
    unsigned int combination =salt*2; // unsigned int, kad int negaletu buti neigiamas
    unsigned int ascii;
    unsigned int random=2;
    for(int i=0; i<input.size(); i++){
        ascii=input[i];
        combination = (combination << 2)-ascii-i +salt;
        random=(random<<3) - i*ascii;
        
    }
    //cout<<random<<endl; 
    //cout<<combination<<endl;
    string pattern = "0123456789abcdef"; // pattern for a hexadecimal system
    unsigned int naudojamas;
    if(random>combination){
        naudojamas = random-combination;
    }
    else{
        naudojamas = combination-random;
    }

    for(int i=0; i<64; i++){  
        naudojamas += combination *i + random/naudojamas + (naudojamas>>i);
        hash+=pattern[naudojamas%pattern.size()];
        //cout<<randInt<<endl;
    }
    return hash;
}