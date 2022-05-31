// WORKING WITH FILES
#if 1

#include <fstream>
#include <iostream>

 
int main () {
    char str[100];

    //Create and open a file (use write mode only to create file).
    std::fstream myfile;
    myfile.open("myFile.dat", std::ios::out);

    if (!myfile) {
        std::cerr << "Fail to create/open file \n";
        return -1;
    }

    //Write to file
    int num = 10;
    myfile << num << " Hello World !";
    myfile.close(); // close the file.
    std::cout << "Wrote to the file ! \n" << std::endl;
    

    //Open for reading and read
    myfile.open("myFile.dat", std::ios::in);
    myfile >> num >> str;

    std::cout << "Read from file: " << std::endl;
    std::cout << num << " " << str << "\n"; 

    myfile.close(); // close the file.

   return 0;
}


#endif














#if 1

#include <iostream>
#include <fstream>             
 
int main () {
    int your_age;
    char your_name[100];

    std::ofstream myfile;  // declare an ofstream object
    myfile.open("MyFile.txt", std::ios::out); //create and open file

    if (!myfile) {
        std::cerr << "Fail to open file \n";
        return -1;
    }

    /* Write to file */
    myfile << "Saving to file ..." << std::endl; //flush to write immediately

    /* Read from console and write to file */
    std::cout << "Enter your age: "; 
    std::cin >> your_age;
    myfile << your_age << std::endl;

    std::cout << "Enter your name: "; 
    std::cin.ignore(1,'\n'); //Ignore previous "\n" character
    std::cin.getline(your_name, sizeof(your_name));
    myfile << your_name << "\n";

    std::cout << "Saved your answers to file !"; 

    myfile.close();   // close file

    return 0;
}
#endif