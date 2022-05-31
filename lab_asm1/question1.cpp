/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 1
  Author: Nguyen Tuong Khang
  ID: s3927112
  Compiler used: Compiler version (e.g. gcc 8.1.0)
  Created  date: 4/9/2022
  Acknowledgement: https://stackoverflow.com/questions/43435147/reading-text-file-into-string-array
*/
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <list>
#define MAXSIZE 225

/*Write a C++ program which can work with command line arguments below:
    • Get three hexadecimal numbers and print out their sum 
    (all must be preceded by "0x").
    ./a.exe 0x12 0xAC 0xB3
    Sum is: 0x171
*/


int convert_hex_to_dec(std::string str)
{
    int val;
    std::stringstream sstr;
    //hexaStr in format of hexanumber
    sstr << std::hex << str; //Input the string insize the stringstream
    sstr >> val; // extract value from the stringstream(with int format)
    return val;
}


/* Write all arguments (except the first one) into a file namely "data.txt", 
each argument into a line, if the first argument is "-w". 
./a.exe -w GoodMorning. HowAreYouToday 12345*/
void readFile(const char* filename, std::list<std::string>& lines)
{
    lines.clear();
    std::ifstream file(filename);
    std::string s;
    while (std::getline(file, s))
        lines.push_back(s);
}

int highest(int arr[], int cnt)
{
    int highest = arr[0];
    for(int i = 1; i < cnt; i++)
    {
        if(highest < arr[i])
        {
            highest = arr[i];
        }
    }
    return highest;
}

int main(int argc, char *argv[])
{
    bool questionC, questionA;
    int sum = 0;
    std::fstream myFile;
    std::string str;
    for(int i = 1; i < argc; i++)
    {
        if(argv[i][1] == 'x')
        {
            sum = sum + convert_hex_to_dec(argv[i]);
            questionA = true;
        }
        else if(argv[1][0] == '-' && argv[1][1] == 'w')
        {
            myFile.open("data.txt", std::ios::out);
            for(int j = 1; j < argc; j++)
            {
                myFile << argv[i + j] << std::endl;
            }
            myFile.close();
            break;
        }
        else if(argv[1][0] == '-' && argv[1][1] == 'r')
        {
           questionC = true;
        }   
    }

    /*• Read from the file, and print out the longest line, 
    if the first argument is "-r"
    ./a.exe -r
    Longest line: HowAreYouToday*/
    if(questionA)
    {
        std::cout << std::showbase << std::hex << "Sum is: " << sum << std::endl;
    }

    if(questionC)
    {
        #if 0
        std::list<std::string> lines;
        readFile("data.txt", lines);
        std::cout << "read " << lines.size() << std::endl;
        const int num = lines.size();
        int arr[MAXSIZE];
        int cnt = 0;
        for (const auto& line : lines)
        {
            // std::cout << line.length() << std::endl;
            arr[cnt] = line.length();
            cnt++;
        }
        for(const auto& line : lines)
        {
            if(line.length() == highest(arr, cnt))
            {
                std::cout << line << std::endl;
            }
        }
        #endif

        #if 1
        std::string line;
        std::string *p = &line;
        std::string highest_str;
        int highest_length = p->length();
        int length;
        int cnt = 0;
        myFile.open("data.txt", std::ios::in);
        while(std::getline(myFile, line))
        {
            length = line.length();
            if(highest_length < length)
            {
                highest_length = length;
                highest_str = line;
            } 
            cnt++;          
        }
        std::cout << "Longest line is: ";
        std::cout << highest_str << std::endl;
        #endif



        
     
        #if 0
        int len = 0;
        myFile.open("data.txt", std::ios::in);
        for(int i = 1; i < argc; i++)
        {
            std::getline(myFile, str, '\n');
            len = str.length();
            
        }



        std::getline(myFile, str, '\n');
        std::cout << str << std::endl;
        #endif
        myFile.close();
    }

    return 0;
}