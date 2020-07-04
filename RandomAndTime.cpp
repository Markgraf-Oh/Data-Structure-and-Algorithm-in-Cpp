#include <iostream>
#include <iomanip>//간격지정에 쓰임
#include <random>
#include <chrono>
#include <map>
#include <string>
#include "GreekAlphabet.h"
//https://modoocode.com/304#page-heading-4
int main()
{
    //_wsetlocale(LC_ALL, L"Korean");
    #define N_EXECUTE 50000
    /*
        시스템(하드 등)의 노이즈로 부터 시드를 얻는 random device 객체. random 헤더에 들어있다.
        완벽한 난수지만, 생성속도가 매우 느리기 때문에 seed를 구하는 데에만 쓰인다.
    */
    std::random_device rande;

    /*
        난수 생성 엔진 객체를 생성. c++에서는 다양한 난수생성 엔진을 제공
        https://en.cppreference.com/w/cpp/numeric/random
        제너레이터 생성자에는 인수로 seed가 들어간다. 직접 넣을 수도 있지만, 위의 random_device를 쓰자
    */

    //minstd_rand : C언어 rand함수에서도 쓰이는 선형 합동 알고리즘을 이용
    std::minstd_rand generator_basic(rande());

    //mt19937 : 메르센 트위스터 알고리즘 사용. 객체 크기가 2KB이기에 메모리가 부족한 곳엔 비추.
    std::mt19937 generator(rande());

    //0~99의 균등 분포
    std::uniform_int_distribution<int> dist_uniform_int(0,99);

    std::uniform_real_distribution<float> dist_uniform_float(0.0f, 99.0f);

    std::normal_distribution<double> dist_normal(/*평균*/0.0, /*분산*/1.0);

    /*
        chrono
        high_resolution_clock은 ms, us 등의 정밀한 시스템 시간을 측정한느데 쓰이고,
        system_clock은 일반적인 초 이상 단위의 시간에 사용됨
    */

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point 
        = std::chrono::high_resolution_clock::now();

    std::map<float, int> histogram{};
    for(int i=0; i < N_EXECUTE; i++)
    {
        ++histogram[std::round(dist_normal(generator)*pow(10,1))/pow(10,1)];
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> end_point
        = std::chrono::high_resolution_clock::now();

    for(auto pair : histogram)
    {
        std::cout << std::setw(5) << pair.first << ' ' << std::setw(5) << pair.second << ' ' << std::string(pair.second/50, '*') << std::endl;
    }

    auto deltatime = end_point - start_point;
    GreekAlphabet::UseUnicodeInVSCode();
    auto deltamicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(deltatime);
    std::cout<<"time = "<<deltamicroseconds.count()<< Greek::mu << "s"<<std::endl;
    
    std::chrono::milliseconds deltamilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end_point - start_point);
    std::cout<<"time = "<<deltamilliseconds.count()<<"ms"<<std::endl;
}