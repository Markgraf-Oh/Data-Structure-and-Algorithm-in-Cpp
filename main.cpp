#include <iostream>
#include <exception>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "GreekAlphabet.h"
#include "VectorSort.h"

//ftr >= bck
template<typename T>
bool Bigger(const T & frt, const T & bck)
{
   return frt >= bck;
}

//frt <= bck
template<typename T>
bool Smaller(const T& frt, const T& bck)
{
   return frt <= bck;
}

int main(int argc, char* argv[])
{
    Greek::UseUnicodeInVSCode();
    //input
    int size_n = 0;
    int max_number = 0;
    try
    {
        if(argc>=2 && argv[1]!=nullptr)
        {
            size_n = std::atoi(argv[1]);
        }
        else throw std::string("입력이 없습니다.");
    }
    catch(std::string& s)
    {
        std::cout<<"argv1 : "<<s<<std::endl;
        size_n = 100;
    }
    catch(std::exception& excep)
    {
        std::cout<<"argv1 : "<<excep.what()<<std::endl;
        size_n = 100;
    }
    catch(...)
    {
        std::cout<<"argv1 : unknown error"<<std::endl;
        size_n = 100;
    }

    try{
        if(argc>=3 && argv[2]!=nullptr)
        {
            max_number = std::atoi(argv[2]);
        }
        else throw std::string("입력이 없습니다.");
    }
    catch(std::string& s)
    {
        std::cout<<"argv2 : "<<s<<std::endl;
        max_number = 100;
    }
    catch(std::exception& excep)
    {
        std::cout<<"argv2 : "<<excep.what()<<std::endl;
        max_number = 100;
    }
    catch(...)
    {
        std::cout<<"argv1 : unknown error"<<std::endl;
        size_n = 100;
    }
    //long to int exception catch https://stackoverflow.com/questions/11387370/how-can-i-safely-convert-unsigned-long-int-to-int

    
    std::cout<<std::string(30, '-')<<std::endl;
    std::cout<<"size of vector : "<<size_n<<", maximum number : "<<max_number<<std::endl;
    
    std::random_device rande;
    std::minstd_rand generator(rande());
    std::uniform_int_distribution<int> unif_dist(0,max_number);

    /*
        vector 초기화
        std::vector<int> a(크기, 초기화값);
        a.assign(크기, 초기화값)
    */
    std::vector<int> numbers;
    numbers.assign(size_n, 0);
    for(auto iter = numbers.begin(); iter!=numbers.end(); iter++)
    {
        *iter = unif_dist(generator);
        //std::cout<<*iter<< " ";
    }
    std::cout<<std::string(30, '-')<<std::endl;
    
    VectorSort::TestSortingAlgorithm<int>(numbers,
                                          &VectorSort::BubbleSort<int>,
                                          [](const int & lsv, const int & rsv)->bool{return lsv>=rsv;},
                                          "Bubble Sort");

    VectorSort::TestSortingAlgorithm<int>(numbers,
                                          &VectorSort::ShakerSort<int>,
                                          [](const int & lsv, const int & rsv)->bool{return lsv>=rsv;},
                                          "Shaker Sort");
    
    VectorSort::TestSortingAlgorithm<int>(numbers,
                                          &VectorSort::ShellSort<int>,
                                          [](const int& lsv, const int & rsv)->bool{return lsv>=rsv;},
                                          "Shell Sort");

    VectorSort::TestSortingAlgorithm<int>(numbers,
                                          &VectorSort::QuickSort<int>,
                                          [](const int& lsv, const int & rsv)->bool{return lsv>=rsv;},
                                          "Quick Sort");

    VectorSort::TestSortingAlgorithm<int>(numbers,
                                          &VectorSort::MergeSort<int>,
                                          [](const int& lsv, const int & rsv)->bool{return lsv>=rsv;},
                                          "Merge Sort");

    VectorSort::TestSortingAlgorithm<int>(numbers,
                                          &VectorSort::HeapSort<int>,
                                          [](const int& lsv, const int & rsv)->bool{return lsv>=rsv;},
                                          "Heap Sort");

}