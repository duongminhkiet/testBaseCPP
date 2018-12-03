#include "cpu.h"
#include <iostream>
using namespace std;

void Cpu::on(){
    this->power.on();
    this->os.boot();
}
void Cpu::off(){
    this->os.shutdown();
    this->power.off();
}
// all below methods use when initialize object
void Cpu::setOs(Os os){
    this->os=os;
}
void Cpu::setPower(Power power){
    this->power=power;
}
Os Cpu::getOs(){
    return this->os;
}
Power Cpu::getPower(){
    return this->power;
}
