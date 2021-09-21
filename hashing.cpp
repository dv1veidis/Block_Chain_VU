#include "My_lib.h"


string hashavimas (string input){
    string hash = "";
    int salt = 2048; // reiksme kuri leidzia net tusciam input buti hashuojamam ir padidina atsistiktinuma
    unsigned int combination =0; // unsigned int, kad int negaletu buti neigiamas
    unsigned int ascii;
    for(int i=0; i<input.size(); i++){
        ascii=input[i];
        combination += (ascii * salt) + i*salt; 
    }
    string pattern = "0a1b2c3d4e5F6f7g8h9ijklmnopqrstuvwxyz";

    for(int i=0; i<64; i++){
        hash+=pattern[(combination-i)%pattern.size()];
    }
    return hash;
}