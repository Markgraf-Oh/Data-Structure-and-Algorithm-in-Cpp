#include <iostream>
#include <string>
#include "GreekAlphabet.h"
#include "StringSearch.h"
#include "TestString.h"

/** convert between string and wstring
 * using codecvt : https://stackoverflow.com/questions/2573834/c-convert-string-or-char-to-wstring-or-wchar-t
 * 
*/
int main()//int argc, char* argv[])
{
    StringSearch::UseUnicodeInVSCode();
    /*
    //input
    int string_length = 0;
    int key_length = 0;
    try
    {
        if(argc >= 2 && argv[1] != nullptr)
        {
            string_length = std::atoi(argv[1]);
        }
        else throw std::string("입력이 없습니다.");
    }
    catch(std::string& s)
    {
        std::cout<< "argv1 : " << s << std::endl;
    }
    catch(std::exception& excep)
    {
        std::cerr<< "argv1 : " << excep.what() << std::endl;
    }
    catch(...)
    {
        std::cerr<< "argv1 : unknown error" << std::endl;
    }

    if(string_length == 0) string_length = 1000;

    try{
        if(argc >= 3 && argv[2] != nullptr)
        {
            key_length = std::atoi(argv[2]);
        }
        else throw std::string("입력이 없습니다.");
    }
    catch(std::string& s)
    {
        std::cout<< "argv2 : " << s << std::endl;
    }
    catch(std::exception& excep)
    {
        std::cerr<< "argv2 : " << excep.what() << std::endl;
    }
    catch(...)
    {
        std::cerr<< "argv2 : unknown error" << std::endl;
    }

    if(key_length == 0 || key_length >= (string_length / 50)) key_length = 5;
    */
    
    const std::string & test_string = TestString::StarCountingNight;
    const std::string key_string = "별";

    std::cout<< "length of target string : " << test_string.length() << " / length of keyword : " << key_string.length() << std::endl;


    std::vector<int> search = StringSearch::BoyerMooreSearch(test_string, key_string);

    std::cout<< "BoyerMooreFound " << search.size() << " of " << key_string << std::endl;

    std::vector<int> search2 = StringSearch::BruteForceSearch(test_string, key_string);
    std::cout<< "BruteForceFound " << search2.size() << " of " << key_string << std::endl;
}