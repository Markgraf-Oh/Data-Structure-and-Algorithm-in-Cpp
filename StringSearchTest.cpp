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
    
    
    const std::string & test_string = TestString::StarCountingNight;
    std::string test_string_title = "별 헤는 밤";
    const std::string & key_string = "별";

    std::cout<< std::endl << "length of target string : " << test_string.length() << " / length of keyword : " << key_string.length() << std::endl;
    std::cout<< std::string(30, '-') << std::endl;

    StringSearch::TestStringSearchAlgorithm(StringSearch::BruteForceSearch, "Brute Force", test_string, key_string, test_string_title);

    StringSearch::TestStringSearchAlgorithm(StringSearch::BoyerMooreSearch, "Boyer Moore", test_string, key_string, test_string_title);

    //Lorem ipsum 8000자
    StringSearch::TestStringSearchAlgorithm(StringSearch::BruteForceSearch, "Brute Force", TestString::LoremIpsum, "ipsum", "Lorem Ipsum");

    StringSearch::TestStringSearchAlgorithm(StringSearch::BoyerMooreSearch, "Boyer Moore", TestString::LoremIpsum, "ipsum", "Lorem Ipsum");

}