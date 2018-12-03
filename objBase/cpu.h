/* 
 * File:   cpu.h
 * Author: minhkiet
 *
 * Created on June 13, 2013, 8:10 PM
 */

#ifndef CPU_H
#define	CPU_H

#include "power.h"
#include "os.h"

class Cpu{
private:
    Power power;
    Os os;
public:
    virtual  void on();
    virtual  void off();
    virtual  void setPower(Power power);
    virtual  void setOs(Os os);
    virtual  Power getPower();
    virtual  Os getOs();
};


#endif	/* CPU_H */

