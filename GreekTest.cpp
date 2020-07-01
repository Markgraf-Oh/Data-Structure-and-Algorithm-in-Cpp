#include <iostream>
#include <string>
#include <fstream>
#include "GreekAlphabet.h"

int main()
{
    UseUnicodeInVSCode();
    
    std::string test = g_Tau;
    std::cout << test << std::endl;
    std::cout << std::string(g_Lambda) <<std::endl;
    std::cout << std::string("2").append(g_Pi) <<std::endl;
    std::cout<<g_Mu<<std::endl;

    test+=G_Tau;
    std::cout<<test<<std::endl;
    std::ofstream fout;
    fout.open(".\\GreekTest.txt");
    fout<<test<<std::endl;
    fout<<G_Alpha<<G_Eta<<std::endl;
    fout.close();
    return 0;
}