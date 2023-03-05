#include <iostream>
#include "sha256.h"
 
using std::string;
using std::cout;
using std::endl;
 
int main(int arg, char *argA[])
{
    string in = "grape";
    string out = sha256(in);
 
    cout << "sha256('"<< in << "'):" << out << endl;
    return 0;
}
