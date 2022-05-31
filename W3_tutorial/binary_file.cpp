// 5.	Write a C++ program that stores the following data into a binary file. 
// The data from each array will be stored into three binary files using different methods: 
// a) insertion operator b) put method c) write method.
// Character array: 0x5A, 0x3F, 0x33, 0x3D, 0x40, 0x6B, 0x4C, 0x58, 0x72, 0x4E, 0x2F
// Using a hex editor, analyse the data in each file and relate them to the above array data.





#include <iostream>
#include <fstream>
#include <cstring>
#define MAXSIZE 100

 
int main () {
    std::fstream myfile;
    myfile.open("binary.dat", std::ios::out | std::ios::binary); 

    if (!myfile) { 
        std::cerr << "Fail to create/open file \n";
        return -1;
    }

    //Define array of char values
    char data[11] = {0x5A, 0x3F, 0x33, 0x3D, 0x40, 0x6B, 0x4C, 0x58, 0x72, 0x4E, 0x2F};

    //Qa Write to file using insertion operator
    for (int i = 0; i < 11; i++) {
        myfile << data[i];
    }

    //Qb Write to file using put method
    for (int i = 0; i < 11; i++) {
        myfile.put( data[i] );
    }

    //Qb Write to file using write method
    myfile.write(data, 11);

   return 0;
}