#include <iostream>
#include <iomanip>
#include <exception>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
#include "GreekAlphabet.h"

//g++ 컴파일, 실행
/*
  g++ -o .\BubbleSort.exe BubbleSort.cpp
  .\BubbleSort.exe
*/

//mix vector randomly
template<typename T>
void MixVector(std::vector<T>& target_vector)
{
    std::random_device rande;
    std::minstd_rand generator(rande());
    std::uniform_int_distribution<int> unif_dist(0,target_vector.size()-1);
    for(int i=0; i<target_vector.size(); i++)
    {
        std::swap(target_vector[i], target_vector[unif_dist(generator)]);
    }
}

//return true if vector is sorted by compare rull
template<typename T>
bool IsSorted(std::vector<T>& target_vector, bool(*compare)(const T&, const T&))
{
    for(int i=0; i<target_vector.size()-1; i++)
    {
        if(!compare(target_vector[i], target_vector[i+1]))
        {
           return false;
        }
    }
    return true;
}

/** bidirection bubble sort, cocktail sort
 * @param target_vector vector to sort
 * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
*/
template<typename T>
void ShakerSort(std::vector<T>& target_vector, bool(*compare)(const T&, const T&))
{
    bool left_start = true;
    int l_last_swap = 0;
    int r_last_swap = target_vector.size()-1;
    int cur_swap;
    while(r_last_swap>0 && l_last_swap<target_vector.size()-1)
    {
        if(left_start)
        {
            cur_swap = 0;
            for(int i = cur_swap; i<r_last_swap; i++)
            {
                if(!compare(target_vector[i], target_vector[i+1]))
                {
                    std::swap(target_vector[i], target_vector[i+1]);
                    cur_swap = i;
                }
            }
            r_last_swap = cur_swap;
        }
        else
        {
            cur_swap = target_vector.size()-1;
            for(int i = cur_swap; i>l_last_swap; i--)
            {
                if(!compare(target_vector[i-1], target_vector[i]))
                {
                    std::swap(target_vector[i-1], target_vector[i]);
                    cur_swap = i;
                }
            }
            l_last_swap = cur_swap;
        }
    }
}

//설명이 필요한지?
template<typename T>
void BubbleSort(std::vector<T>& target_vector, bool(*compare)(const T&, const T&))
{
    int last_swap = 0;
    while(last_swap<target_vector.size()-1)
    {
        int current_swap = target_vector.size()-1;
        for(int i = current_swap; i>last_swap; i--)
        {
            if(!compare(target_vector[i-1], target_vector[i]))
            {
                std::swap(target_vector[i-1], target_vector[i]);
                current_swap = i;
            }
        }
        last_swap = current_swap;
    }
}

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
    //UseUnicodeInVSCode();
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

    std::cout<<"size of vector : "<<size_n<<", maximum number : "<<max_number<<"\n\n";
    
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
    std::cout<<std::endl;
    std::cout<<(IsSorted<int>(numbers, &Bigger<int>) ? "sorted" : "unsorted")<<std::endl;
    
    //Shaker Sort

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point 
        = std::chrono::high_resolution_clock::now();
    
    ShakerSort<int>(numbers, [](const int & lsv, const int & rsv)->bool{return lsv>=rsv;});
    
    std::chrono::time_point<std::chrono::high_resolution_clock> end_point 
        = std::chrono::high_resolution_clock::now();
    
    //그냥 실전에선 auto 쓰자...
    //std::chrono::duration<long long, std::nano>
    auto deltatime = end_point - start_point;
    
    std::cout<<std::endl
        <<"Shaker Sort run-time : "
        <<std::chrono::duration_cast<std::chrono::microseconds>(deltatime).count()
        <<" " << Greek::mu<< "s" <<std::endl;

    std::cout<<(IsSorted<int>(numbers, &Bigger<int>) ? "sorted" : "unsorted") <<std::endl;

    //Vector Mixer
    start_point = std::chrono::high_resolution_clock::now();
    
    MixVector(numbers);
    
    end_point = std::chrono::high_resolution_clock::now();
    
    deltatime = end_point - start_point;
    
    std::cout<<std::endl
        <<"Vector Mixer run-time : "
        <<std::chrono::duration_cast<std::chrono::microseconds>(deltatime).count()
        <<" "<<Greek::mu<< "s" <<std::endl;
    
    std::cout<<(IsSorted<int>(numbers, &Bigger<int>) ? "sorted" : "unsorted") <<std::endl;


    //BubbleSort
    start_point = std::chrono::high_resolution_clock::now();
    
    BubbleSort<int>(numbers, [](const int & lsv, const int & rsv)->bool{return lsv>=rsv;});
    
    end_point = std::chrono::high_resolution_clock::now();
    
    deltatime = end_point - start_point;
    
    std::cout<<std::endl
        <<"Bubble Sort run-time : "
        <<std::chrono::duration_cast<std::chrono::microseconds>(deltatime).count()
        <<" "<<Greek::mu<< "s" <<std::endl;
    
    std::cout<<(IsSorted<int>(numbers, &Bigger<int>) ? "sorted" : "unsorted") <<std::endl;
    
    return 0;
}