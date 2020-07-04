#pragma once

#ifndef GreekAlphabet
#define GreekAlphabet

#include <string>

#pragma region Description
/*
    * 너무나도 게으른 c++ 유저들을 위한 그리스 문자 헤더입니다.
    * 대문자는 G_로 시작하고, 소문자는 g_로 시작합니다.
    * Alpha, alpha와 같은 방식을 쓰지 않은 이유는 pi, delta, gamma 등을 변수명으로 사용할 수 있기 때문입니다.
    * 
    * 1. cmd에서 사용 시
    *   커맨드라인을 열자마자 chcp 65001을 치면 유니코드를 쓸 수 있는 커맨드 창이 나옵니다.
    *   이후 정상적으로 cout을 통해 쓸 수 있습니다.(wcout없어도 됩니다?)
    *   아니면 경로가 "C:\Windows\System32\cmd.exe /K chcp 65001"인 바로가기를 만드렁 사용하세요
    * 
    * 2. 파일 쓰기
    *   별다른 처리 없이도 std::ofstream 으로 쓸 수 있습니다.
    *   
    * 3. 비주얼 스튜디오 코드에서 사용 시
    *   ctrl + p에서 검색하여 settings.json파일을 열고
    *   "terminal.integrated.shellArgs.windows": ["/K", "chcp 65001"]
    *   을 추가해 줍니다.
    *   이후 cout으로 그리스 문자를 출력하기 전에 bool UseUnicodeInVSCode() 함수를 사용해 주세요.
*/

/*
    * 예시
    *   #include <iostream>
        #include <string>
        #include <fstream>
        #include "GreekAlphabet.h"

        int main()
        {
            //UseUnicodeInVSCode();
            
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
            fout<<G_Alpha<<G_Beta<<std::endl;
            fout.close();
            return 0;
        }
    *   
*/
#pragma endreigion

namespace Greek
{
    //A 
    const std::string Alpha("\u0391"); 
    //B 
    const std::string Beta("\u0392"); 
    //Γ 
    const std::string Gamma("\u0393"); 
    //Δ 
    const std::string Delta("\u0394"); 
    //Ε 
    const std::string Epsilon("\u0395"); 
    //Ζ 
    const std::string Zeta("\u0396"); 
    //Η 
    const std::string Eta("\u0397"); 
    //Θ 
    const std::string Theta("\u0398"); 
    //Ι 
    const std::string Iota("\u0399"); 
    //Κ 
    const std::string Kappa("\u039A"); 
    //Λ 
    const std::string Lambda("\u039B"); 
    //Μ 
    const std::string Mu("\u039C"); 
    //Ν 
    const std::string Nu("\u039D"); 
    //Ξ 
    const std::string Xi("\u039E"); 
    //Ο 
    const std::string Omicron("\u039F"); 
    //Π 
    const std::string Pi("\u03A0"); 
    //Ρ 
    const std::string Rho("\u03A1"); 
    //Σ 
    const std::string Sigma("\u03A3"); 
    //Τ 
    const std::string Tau("\u03A4"); 
    //Υ 
    const std::string Upsilon("\u03A5"); 
    //Φ 
    const std::string Phi("\u03A6"); 
    //Χ 
    const std::string Chi("\u03A7"); 
    //Ψ 
    const std::string Psi("\u03A8"); 
    //Ω 
    const std::string Omega("\u03A9");
    //α 
    const std::string alpha("\u03B1"); 
    //β 
    const std::string beta("\u03B2"); 
    //γ 
    const std::string gamma("\u03B3"); 
    //δ 
    const std::string delta("\u03B4"); 
    //ε 
    const std::string epsilon("\u03B5"); 
    //ζ 
    const std::string zeta("\u03B6"); 
    //η 
    const std::string eta("\u03B7"); 
    //θ 
    const std::string theta("\u03B8"); 
    //ι 
    const std::string iota("\u03B9"); 
    //κ 
    const std::string kappa("\u03BA"); 
    //λ 
    const std::string lambda("\u03BB"); 
    //μ 
    const std::string mu("\u03BC"); 
    //ν 
    const std::string nu("\u03BD"); 
    //ξ 
    const std::string xi("\u03BE"); 
    //ο 
    const std::string omicron("\u03BF"); 
    //π 
    const std::string pi("\u03C0"); 
    //ρ 
    const std::string rho("\u03C1"); 
    //σ 
    const std::string sigma("\u03C3"); 
    //τ 
    const std::string tau("\u03C4"); 
    //υ 
    const std::string upsilon("\u03C5"); 
    //φ 
    const std::string phi("\u03C6"); 
    //χ 
    const std::string chi("\u03C7"); 
    //ψ 
    const std::string psi("\u03C8"); 
    //ω 
    const std::string omega("\u03C9");
}

//VScode 터미널에서 유니코드를 출력시키기 전에 실행시켜줘야 합니다.
bool UseUnicodeInVSCode()
{
    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    return setvbuf(stdout, nullptr, _IOFBF, 1000)==0;
}

#endif