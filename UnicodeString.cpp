#include <iostream>
#include <string>
#include <codecvt>
#include <locale>
#include "GreekAlphabet.h"

/** convert between string and wstring
 * using codecvt : https://stackoverflow.com/questions/2573834/c-convert-string-or-char-to-wstring-or-wchar-t
 * 
*/
int main(int argc, char* argv[])
{

    setvbuf(stdout, nullptr, _IOFBF, 1000);
    
    //std::string은 1바이트 char형에 대응한다.
    //std::wstring은 wchar_t로 이루어져 있으며 2바이트 UTF-16에 대응한다.

    /** ASCI는 1바이트로 크기가 고정되어 있으며 std::string 및 char형과 호환할 수 있다.
     * 
     * UTF-8은 1~4바이트로 크기가 불규칙 하나 1바이트 크기의 문자는 ASCI와 일치한다.
     * 즉 UTF-8로 인코딩 되어 있는 소스파일도 ASCI문자만 친다면 아무런 문제없이 char 및 std::string을 쓸 수 있다.
     * 
     * UTF-16은 2 또는 4바이트 크기를 가지나, 대부분은 2바이트로 배정되어 있다. 일부 한자, 이모지 등은 4바이트를 차지한다.
     * 즉 wchar_t, wstring하고 만 호환되며, ASCI에 속하는 문자들도 동일하게 2바이트에 배정되어 있으므로 ASCI와 호환이 안된다.
     * 
     * 일반적인 ""문자열은 char string이다.
     * L""문자열을 통해 UTF-16문자열을 만들고, 이를 통해 wchar string에 할당할 수 있다.
     * 
     * 단어 단위로 끊어야할 필요가 없다면 UTF-8은 단순히 char string을 통해 출력 가능하다.
     * 어찌되었든 출력데이터를 받아든 콘솔에서 받은 UTF-8 char string을 UTF-8 형식으로 디코딩하기만 하면 정상적으로 보인다.
     * ASCI문자열의 경우 콘솔에서 ASCI로 디코딩하던 UTF-8로 디코딩하던 호환성덕에 정상적으로 보인다.
     * 
     * 하지만 UTF-16 문자열은 UTF-16으로만 디코딩되어야 정상적으로 보인다.
     * 
     * 문자열 비교, 검색의 경우 비교하려는 두 문자열이 같은 형식(ASCI든 UTF-8이든 UTF-16이든)이기만 하면 된다.
     * 일단 같은 문자열이면 데이터를 1바이트 char단위로 끊어서 비교해버리면 된다.
    */
    std::cout<< "English string" << std::endl;
    std::string eng = "abc123";
    std::cout<< eng << std::endl;
    for(int i = 0; i < eng.length() ; i++) std::cout<< eng[i] << "/";
    std::cout<< std::endl;
    /*  UTF-8(cmd chcp 65001) 출력 결과 :
        English string
        abc123
        a/b/c/1/2/3/
    */

    std::cout<< std::string(30, '-') << std::endl;

    std::cout<< "한글문자열" <<std::endl;
    std::string kor = "abc가나다123";
    std::cout<< kor << std::endl;
    for(int i = 0; i < kor.length() ; i++) std::cout<< kor[i] << "/";
    std::cout<< std::endl;
    /*  UTF-8(cmd chcp 65001) 출력 결과 :
        한글문자열
        abc가나다123
        a/b/c//////////1/2/3/
        한글 부분은 3바이트 짜리 한글이 1바이트 단위로 쪼개졌기 때문에 제대로 디코딩 되지 않았으며, 세글자가 3*3으로 총 9번에 걸쳐 출력된걸 볼 수 있다.
    */
}