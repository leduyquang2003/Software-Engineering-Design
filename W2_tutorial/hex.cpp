#include <iostream>
#include <string.h>

int main(int argc, char *argv[])
{
    char hex[255];
    char erase[1];
    char base[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    bool condition;
    bool check;
    for(int i = 1; i < argc; i++)
    {   
        strcpy(hex, argv[i]);
        //std::cout << hex << std::endl;
        for(int i = 0; i < 17; i++)
        {
            if(hex[2] == base[i] && hex[0] == '0' & (hex[1] == 'x' || hex[1] == 'X'))
            {
                condition = true;
                break;
            }
            else
            {
                condition = false;
            }
        }

        if(condition && hex[4] == '\0')
        {
            for(int i = 0; i < 17; i++)
            {
                if(hex[3] == base[i])
                {
                    std::cout << hex <<" is valid hex " <<std::endl;
                    check = true;
                }
                else
                {
                    check = false;
                }
            }
            if(!check)
            {
                std::cout <<"Error" << std::endl;
            }
        }
        else
        {
            std::cout <<"Error" << std::endl;
        }
        strcpy(hex, erase);
    }

    return 0;
}