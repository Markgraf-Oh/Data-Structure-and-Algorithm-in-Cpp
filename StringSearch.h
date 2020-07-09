#ifndef StringSearchDef
#define StringSearchDef

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <climits>
#include "GreekAlphabet.h"

namespace StringSearch
{
    //VScode의 내장 터미널에서 출력시킬 때 UTF-8을 잘라먹는 문제를 방지하기 위해 버퍼를 활성화 합니다.
    bool UseUnicodeInVSCode()
    {
        // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
        return setvbuf(stdout, nullptr, _IOFBF, 1000)==0;
    }

    /** Brute Force Algorithm으로 1대1 비교를 통해 문자열에서 키워드의 위치를 찾습니다.
     * @param target_string 단어를 찾을 문자열입니다.
     * @param key_string    찾을 단어의 문자열입니다.
     * @return  std::vector<int>형태로 반환합니다. 안에는 key_string이 target_string 상에서 존재하는 위치 index들이 들어 있습니다.
     *          return.size()를 통해 들어있는 횟수를 알 수 있습니다.
     * @remark  const std::string &를 통해 문자열을 받지만, 만약 멀티스레드에서 돌아갈 떄와 같이, 
     *          본 함수가 돌아가는 동안 해당 문자열이 다른 함수에 의해 변형될 가능성이 있다면 const std::string으로 바꿔주면 됩니다.
    */
    std::vector<int> BruteForceSearch(const std::string & target_string, const std::string & key_string);

    /** Boyer-Moore Algorithm으로 문자열에서 빠르게 키워드의 위치를 찾습니다.
     * @param target_string 단어를 찾을 문자열입니다.
     * @param key_string    찾을 단어의 문자열입니다.
     * @return  std::vector<int>형태로 반환합니다. 안에는 key_string이 target_string 상에서 존재하는 위치 index들이 들어 있습니다.
     *          return.size()를 통해 들어있는 횟수를 알 수 있습니다.
     * @remark  const std::string &를 통해 문자열을 받지만, 만약 멀티스레드에서 돌아갈 떄와 같이,
     *          본 함수가 돌아가는 동안 해당 문자열이 다른 함수에 의해 변형될 가능성이 있다면 const std::string으로 바꿔주면 됩니다.
    */
    std::vector<int> BoyerMooreSearch(const std::string & target_string, const std::string & key_string);
    /** Boyer-Moore Algorithm으로 문자열에서 빠르게 키워드의 위치를 찾습니다.
     * @param searching_algo    문자열 탐색 알고리즘 입니다. target_string에서 찾은 모든 key_string의 위치들을 vector<int>에 넣어 return 합니다.
     * @param algo_name         콘솔에 보여질 알고리즘의 이름입니다.
     * @param target_string     단어를 찾을 문자열입니다.
     * @param key_string        찾을 단어의 문자열입니다.
     * @param target_title      탐색 문자열의 제목입니다. default 값은 "Target String"입니다.
    */
    void TestStringSearchAlgorithm(std::vector<int> (*searching_algo)(const std::string &/*target string*/, const std::string &/*key string*/),
                                   const std::string & algo_name,
                                   const std::string & target_string,
                                   const std::string & key_string,
                                   const std::string target_title = "Target String");
}

#include "StringSearch.hpp"

#endif