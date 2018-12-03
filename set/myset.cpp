#include <cstring>
#include <string.h>

#include "myset.h"

using std::cout;
using std::cin;

Myset::Myset(const char *s)
{
    strs = new char*[1];
    int len = std::strlen(s);
    strs[0] = new char[len+1];
    std::strcpy(strs[0],s);
    number = 1;
}

Myset::Myset(char **s, int n)
{
    number = n;
    strs = new char*[number];
    for(int i=0;i<number;i++)
    {
        strs[i] = new char[std::strlen(s[i])+1];
        std::strcpy(strs[i],s[i]);
    }
}

void Myset::show_elements()
{
    std::cout<<"{";
    for(int i=0;i<number-1;i++)
    {
       std::cout<<strs[i]<<", ";
    }
    std::cout<<strs[number-1]<<"}\n";
}

Myset::Myset(const Myset & myset)
{
    number = myset.number;
    strs = new char*[number];
    
    for(int i=0;i<number;i++)
    {
       strs[i] = new char [strlen(myset.strs[i])+1];
       strcpy(strs[i],myset.strs[i]);
    }
}

Myset::Myset(int n)
{
    number = n;
}

Myset::~Myset()
{
    if(number>0)
    {  
      for(int i =0;i<number;i++)
          delete [] this->strs[i];
      delete [] this->strs;
    }
    
    number = 0;
}

Myset & Myset::operator=(const Myset & myset)
{
    if(this == & myset)
        return *this;

    if(number>0){
      for(int i=0;i<number;i++)
        delete [] strs[i];
      delete [] strs;
    }

    number = myset.number;
    strs = new char*[number];
    for(int i=0;i<number;i++)
    {
       strs[i] = new char [strlen(myset.strs[i])+1];
       strcpy(strs[i],myset.strs[i]);
    }

    return *this;
}

char* & Myset::operator[](int i)
{
    return strs[i];
}

/*
const char & Myset::operator[](int i) const
{
    return strs[i];
}
*/

//diff
Myset operator/(Myset & ms1, Myset & ms2)
{
    int i=0;
    Myset tmp;
    while(i<ms1.number)
    {
        int j=0;
        bool isdiff = true;
        while(j<ms2.number)
        {
            if(strcmp(ms1.strs[i],ms2.strs[j]) == 0)
              isdiff = false;
            j++;
        };
        if(isdiff){
            tmp.append(ms1.strs[i]);
        }
        i++;
    };
    return tmp;
}

Myset & Myset::operator+(const Myset & myset)
{
  char **tmp = new char*[number+myset.number];
  for(int i=0;i<number;i++)
  {
    tmp[i] = new char[strlen(strs[i])+1];
    strcpy(tmp[i],strs[i]);
  }
  for(int i=0;i<myset.number;i++)
  {
    tmp[i+number] = new char[strlen(myset.strs[i])+1];
    strcpy(tmp[i+number],myset.strs[i]);
  }
  
  Myset ms(tmp,number+myset.number);
  *this = ms;
  return *this;
}

Myset & Myset::append(char *s)
{
  Myset tmp(s);
  *this = *this + tmp;
  return *this;
}

Myset unionset(Myset & ms1, Myset & ms2)
{
  return (ms1/ms2 + ms2);
}

Myset inter(Myset & ms1, Myset & ms2)
{
  Myset tmp1 = unionset(ms1,ms2);
  Myset tmp2 = tmp1/ms1;
  
  return ms2/tmp2;
}


bool operator==(Myset & ms1, Myset & ms2)
{
    if(ms1.number != ms2.number)
      return false;
    
    Myset tmp = ms1/ms2;
    if(tmp.number == 0)
      return true;
    else
      return false;
}

ostream & operator<<(ostream &os, const Myset & ms)
{
    int n = ms.number;
    os << "{";
    for(int i=0;i<n;i++){
        os << ms.strs[i]<<",";
    }
    os << "}";
    return os;
}

/*
istream & operator<<(istream &is, const Myset & ms)
{
    char tmp[80];
    is.get(tmp,80);
    if(is)
        ms.str = tmp;
    while(is && is.get() != '\n')
        continue;
    return is;
}
*/
