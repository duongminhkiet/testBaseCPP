/*
    @Kietdk
    complie: g++ -o useMyset usemyset.cpp myset.cpp
 */

#include "myset.h"
//#include <iostream>
#include <string.h>

int main()
{
    Myset s1;
    Myset s2 = "example";
    Myset s3(s2);
    
    
    std::cout<<"s2 = "<<s2<<"\n";
    std::cout<<"s3 = "<<s3<<"\n\n";
    
    char **charset = new char*[4];
    charset[0] = new char[6];
    strcpy(charset[0], "cbkas");
    charset[1] = new char[4];
    strcpy(charset[1], "123");
    charset[2] = new char[7];
    strcpy(charset[2], "rotolo");
    charset[3] = new char[5];
    strcpy(charset[3], "zeta");
    Myset s4(charset,4);//// s4 has 4 elements: "cbkas", "123", "rotolo", "zeta"
    std::cout<<"element of s4: ";s4.show_elements();

    for(int i=0; i < 4; i++)
      delete []charset[i];
    delete [] charset;

    s1.size(); // output: 0
    s4.size(); // output: 4
    
    std::cout<<"s4 = "<<s4<<"\n"; 
    std::cout<<"s3 = "<<s3<<"\n"; 
    
    s1 = s3;
    Myset s5a = s4 + s3; // s5a will have "cbkas", "123", "rotolo", "zeta", "example"
    std::cout<<"s4+s3 = "<<s5a<<"\n"; 
    std::cout<<"s4 = "<<s4<<"\n"; 
    std::cout<<"s3 = "<<s3<<"\n"; 
    Myset s5b = s4 / s3; // s5b is difference of s4 with s3
    std::cout<<"diff s4/s3 = "<<s5b<<"\n"; 
    Myset s5c = unionset(s4, s3); // s5c is union of s4 and s3
    std::cout<<"union(s4,s3) = "<<s5c<<"\n"; 
    Myset s5d = inter(s4, s3); // s5d is intersect of s4 and s3
    std::cout<<"inter(s4,s3) = "<<s5d<<"\n"; 

    Myset s6 = s2 + "abc99";
    std::cout<<"s6 = "<<s6<<"\n";
    s6.append("minute"); // s6 will have "example", "abc99", "minute"
    std::cout<<"s6 = "<<s6<<"\n";
    std::cout << s6[2];
}
