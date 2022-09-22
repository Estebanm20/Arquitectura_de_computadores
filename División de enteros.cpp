#include<iostream>
#include<bitset>
using namespace std;

int main()
{
    const int n = 10;
    int z = 0;
    int x = 3;
    int c = 100,Count = n;
    bitset<n> num_c(c),num_z(z);

    for(int Count = 0;Count>0;Count = Count++){
        num_c[0] = num_z[n-1];
        z = num_c.to_ullong();
        num_c <<= 1;
        num_z <<= 1;

        z -=x;

        bitset<n> a (z);
        num_c = a;
        Count--;

    }
    cout<<"Cociente"<<endl<<num_c<<c<<endl;
    cout<<"Residuo"<<endl<<num_z<<z<<endl;

    return 0;
}