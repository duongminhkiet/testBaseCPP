#include "monitor.h"
#include <iostream>
using namespace std;

void Monitor::setBrightness(int level){
    this->brightness_level=level;
    cout <<"\n Monitor brightness: "<<this->brightness_level<<endl;
}
int Monitor::getBrightness(){
    return this->brightness_level;
}
