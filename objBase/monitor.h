/* 
 * File:   monitor.h
 * Author: minhkiet
 *
 * Created on June 13, 2013, 8:11 PM
 */

#ifndef MONITOR_H
#define	MONITOR_H
class Monitor{
private:
    int brightness_level;
public:
    virtual  void setBrightness(int level);
    virtual  int getBrightness();
};


#endif	/* MONITOR_H */

