#include "monitor.h"
#include "computer.h"
#include "cpu.h"
#include <iostream>
using namespace std;

void Computer::installOs(const char* nameOS){
    Os os;
    os.setStr(nameOS);
    Power power;
    Cpu cpu;
    cpu.setOs(os);
    cpu.setPower(power);
    this->cpu = cpu;
   
    
}
void Computer::on(){
    this->cpu.on();
    this->monitor.setBrightness(10);
}
void Computer::off(){
    this->cpu.off();
    offMonitor();
}
void Computer::offMonitor(){
    this->monitor.setBrightness(0);
}
void Computer::setCpu(Cpu cpu){
    this->cpu=cpu;
}
void Computer::setMonitor(Monitor monitor){
    this->monitor=monitor;
}
Cpu Computer::getCpu(){
    return this->cpu;
}
Monitor Computer::getMonitor(){
    return this->monitor;
}
