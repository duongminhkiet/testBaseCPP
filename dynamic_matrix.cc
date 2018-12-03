/*
    @kietdk
    complie g++ -o dynamic_matrix dynamic_matrix.cc
    run ./dynamic_matrix
*/

#include <stdio.h>
#include <iostream>

void input_matrix(int **&p, int &m, int &n)
{
    std::cout<<"Input number rows of matrix: ";
    std::cin>>m;
    std::cout<<"Input number collum of matrix: ";
    std::cin>>n;
    int tmp;
    
    p=new int *[m];
    for(int i=0;i<m;i++)
        *(p+i)=new int[n];
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            std::cout<<"p["<<i<<"]["<<j<<"]= ";
            std::cin>>tmp;
            *(*(p+i)+j) = tmp;
        }
}

void output_matrix(int **p, int n, int m)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
            std::cout<<*(*(p+i)+j)<<"\t";
        std::cout<<"\n";
    }
}

int main()
{
    int m,n;
    int **p;
    input_matrix(p,m,n);
    output_matrix(p,m,n);
    
    
    for(int i=0;i<m;i++)
        delete []*(p+i);
    delete []p;
    
    return 0;
}