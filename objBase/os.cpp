#include "os.h"
#include <string.h>
#include<iostream>
using namespace std;
Os::Os(){
    this->str = new char[1];
    strcpy(this->str, "\0");
}


Os::~Os(){
    if(this->str){ 
        delete []this->str;
    }
}

void Os::boot(){
    cout << "\n boot " << str << endl; 
}
void Os::shutdown(){
    cout << "\n shutdown " << str << endl;
}
// all below methods use when initialize object
void Os::setStr(const char * str){
    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);
}
char * Os::getStr(){
    return this->str;
}
Os& Os::operator=(const Os &os) {
    if(this != &os) {
        if(this->str) delete []this->str;
        this->str = new char[strlen(os.str) + 1];
        strcpy(this->str, os.str);
    }

    return *this;
}

