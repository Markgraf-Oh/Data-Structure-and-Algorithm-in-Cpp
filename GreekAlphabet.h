#ifndef GreekAlphabet
#define GreekAlphabet

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

#pragma region Greek_Capital
//A 
 #define G_Alpha u8"\u0391" 
//B 
 #define G_Beta u8"\u0392" 
//Γ 
 #define G_Gamma u8"\u0393" 
//Δ 
 #define G_Delta u8"\u0394" 
//Ε 
 #define G_Epsilon u8"\u0395" 
//Ζ 
 #define G_Zeta u8"\u0396" 
//Η 
 #define G_Eta u8"\u0397" 
//Θ 
 #define G_Theta u8"\u0398" 
//Ι 
 #define G_Iota u8"\u0399" 
//Κ 
 #define G_Kappa u8"\u039A" 
//Λ 
 #define G_Lambda u8"\u039B" 
//Μ 
 #define G_Mu u8"\u039C" 
//Ν 
 #define G_Nu u8"\u039D" 
//Ξ 
 #define G_Xi u8"\u039E" 
//Ο 
 #define G_Omicron u8"\u039F" 
//Π 
 #define G_Pi u8"\u03A0" 
//Ρ 
 #define G_Rho u8"\u03A1" 
//Σ 
 #define G_Sigma u8"\u03A3" 
//Τ 
 #define G_Tau u8"\u03A4" 
//Υ 
 #define G_Upsilon u8"\u03A5" 
//Φ 
 #define G_Phi u8"\u03A6" 
//Χ 
 #define G_Chi u8"\u03A7" 
//Ψ 
 #define G_Psi u8"\u03A8" 
//Ω 
 #define G_Omega u8"\u03A9" 
#pragma endregion 그리스어대문자

#pragma region Greek_Small
//α 
 #define g_Alpha u8"\u03B1" 
//β 
 #define g_Beta u8"\u03B2" 
//γ 
 #define g_Gamma u8"\u03B3" 
//δ 
 #define g_Delta u8"\u03B4" 
//ε 
 #define g_Epsilon u8"\u03B5" 
//ζ 
 #define g_Zeta u8"\u03B6" 
//η 
 #define g_Eta u8"\u03B7" 
//θ 
 #define g_Theta u8"\u03B8" 
//ι 
 #define g_Iota u8"\u03B9" 
//κ 
 #define g_Kappa u8"\u03BA" 
//λ 
 #define g_Lambda u8"\u03BB" 
//μ 
 #define g_Mu u8"\u03BC" 
//ν 
 #define g_Nu u8"\u03BD" 
//ξ 
 #define g_Xi u8"\u03BE" 
//ο 
 #define g_Omicron u8"\u03BF" 
//π 
 #define g_Pi u8"\u03C0" 
//ρ 
 #define g_Rho u8"\u03C1" 
//σ 
 #define g_Sigma u8"\u03C3" 
//τ 
 #define g_Tau u8"\u03C4" 
//υ 
 #define g_Upsilon u8"\u03C5" 
//φ 
 #define g_Phi u8"\u03C6" 
//χ 
 #define g_Chi u8"\u03C7" 
//ψ 
 #define g_Psi u8"\u03C8" 
//ω 
 #define g_Omega u8"\u03C9" 
#pragma endregion 그리스어 소문자

//VScode 터미널에서 유니코드를 출력시키기 전에 실행시켜줘야 합니다.
bool UseUnicodeInVSCode()
{
    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    return setvbuf(stdout, nullptr, _IOFBF, 1000)==0;
}

#endif