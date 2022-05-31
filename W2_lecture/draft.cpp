#include <iostream>
#include <iomanip>
#include <fstream>


//write ro file --> cout and read to file --> cin

int main () {

    char str[100] = {};
    //Create and open a file (use write mode only to create file).
    std::fstream myfile;
    myfile.open("myFile.txt", std::ios::out); //out = output = write to that file

    //if myfile == 0
    if (!myfile) {
        std::cerr << "Fail to create/open file \n";
        return -1;
    }

    //Write to file
    int num = 10;
    myfile << num << " Hello World !"; //similar with cout
    myfile.close(); // close the file.
    std::cout << "Wrote to the file ! \n" << std::endl;

    //Open for reading and read
    myfile.open("myFile.txt", std::ios::in);
    myfile >> num >> str;

    std::cout << "Read from file: " << std::endl;
    std::cout << num << " " << str << "\n"; 

    myfile.close(); // close the file.
    return 0;
}