#include "power.h"
#include <iostream>
#include<iostream>
using namespace std;
Power::Power(){
    //nothing
}


Power::~Power(){
}

void Power::on(){
    cout << "power on" << endl;
}
void Power::off(){
    cout << "power off" << endl;
}
