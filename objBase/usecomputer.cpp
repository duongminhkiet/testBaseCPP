/* 
 * File:   usecomputer.cpp
 * Author: minhkiet
 *
 * Created on June 13, 2013, 8:11 PM
 */

#include <cstdlib>

#include "computer.h"
#include <string.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Computer compt;
    char* osname = new char[8];
    strcpy(osname, "Android");

    
    compt.installOs(osname);
    
    
    compt.on();
    compt.off();
    return 0;
}

