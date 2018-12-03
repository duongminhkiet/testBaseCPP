/* 
 * File:   os.h
 * Author: minhkiet
 *
 * Created on June 13, 2013, 8:08 PM
 */

#ifndef OS_H
#define	OS_H
class Os{
private :
    char *str;
public:
     Os();
     virtual ~Os();
     virtual void boot();
     virtual void shutdown();
     virtual void setStr(const char *str);
     virtual char * getStr();
     virtual  Os & operator=(const Os &os);
};


#endif	/* OS_H */

