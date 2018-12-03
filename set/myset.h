#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include <ostream>
#include <istream>

using std::ostream;
using std::istream;

class Myset {
private:
    char *str;
    char **strs;
    int number;
    Myset *ms_;
public:
    Myset(const char *s);
    Myset(char **s, int n);
    Myset(){number = 0;}
    Myset(const Myset &); //copy constructor
    Myset(int n); //array Myset n elements
    ~Myset();
    int size(){return number;}

    void show_elements();
    Myset & append(char *s);
    friend Myset unionset(Myset &, Myset &);
    friend Myset inter(Myset &, Myset &);
    //overload operator methods
    Myset & operator=(const Myset &);
    Myset & operator=(const char *);
    char* & operator[](int i);
    //const char &operator[](int i) const;
    Myset & operator+(const Myset &);
    
    friend Myset operator/(Myset & ms1, Myset & ms2);
    
    friend ostream & operator<<(ostream & os, const Myset & myset);
    friend istream & operator>>(istream & is, Myset & ms);
    friend bool operator==(Myset & ms1, Myset & ms2);
};

#endif
