/* 
 * File:   computer.h
 * Author: minhkiet
 *
 * Created on June 13, 2013, 8:11 PM
 */

#ifndef COMPUTER_H
#define	COMPUTER_H

#include "monitor.h"
#include "cpu.h"
#include "monitor.h"

class Computer{
private:
    Cpu cpu;
    Monitor monitor;
public:
    virtual  void installOs(const char *nameOS);
    virtual  void on();
    virtual  void off();
    virtual  void offMonitor();
    // for after call constructor
    virtual  void setCpu(Cpu cpu);
    virtual  void setMonitor(Monitor monitor);
    virtual  Cpu getCpu();
    virtual  Monitor getMonitor();
};

#endif	/* COMPUTER_H */

