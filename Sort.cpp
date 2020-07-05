#include <iostream>
#include <iomanip>
#include <exception>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "GreekAlphabet.h"

//g++ 컴파일, 실행
/*
  g++ -o .\BubbleSort.exe BubbleSort.cpp
  .\BubbleSort.exe
*/

//mix vector randomly
template<typename T>
void MixVector(std::vector<T>& target_vector);

//return true if vector is sorted by compare rull
template<typename T>
bool IsSorted(std::vector<T>& target_vector, bool(*compare)(const T&, const T&));


/*설명이 필요한지?
 * @param target_vector vector to sort
 * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
*/
template<typename T>
void BubbleSort(std::vector<T>& target_vector, bool(*compare)(const T&, const T&));


/** bidirection bubble sort, cocktail sort
 * @param target_vector vector to sort
 * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
*/
template<typename T>
void ShakerSort(std::vector<T>& target_vector, bool(*compare)(const T&, const T&));

/** 셸 정렬 알고리즘. 단순 삽입 정렬 알고리즘의 업그레이드 버젼. Quicksort 이전 까진 최고.
 * @param target_vector vector to sort
 * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
*/
template<typename T>
void ShellSort1(std::vector<T>& target_vector,  bool(*compare)(const T&, const T&));


/** 셸 정렬 알고리즘2. 단순 삽입 정렬 알고리즘의 업그레이드 버젼. Quicksort 이전 까진 최고. O^1.25
 * @param target_vector vector to sort
 * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
*/
template<typename T>
void ShellSort2(std::vector<T>& target_vector,  bool(*compare)(const T&, const T&));

/** 엄청빠른 퀵 솔트!
 * @param target_vector vector to sort
 * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
*/
template<typename T>
void QuickSort(std::vector<T>& target_vector,  bool(*compare)(const T&, const T&));

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

template<typename T>
void TestSortingAlgorithm(std::vector<T>& target_vector,
                          void(*sorting_algo)(std::vector<T>&, bool(*)(const T&, const T&)),
                          bool(*compare)(const T&, const T&), const std::string algo_name);

int main(int argc, char* argv[])
{
    UseUnicodeInVSCode();
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
    /*
    TestSortingAlgorithm<int>(numbers,
                              &BubbleSort<int>,
                              [](const int & lsv, const int & rsv)->bool{return lsv>=rsv;},
                              "Bubble Sort");

    TestSortingAlgorithm<int>(numbers,
                              &ShakerSort<int>,
                              [](const int & lsv, const int & rsv)->bool{return lsv>=rsv;},
                              "Shaker Sort");

    TestSortingAlgorithm<int>(numbers,
                              &ShellSort1<int>,
                              [](const int & lsv, const int & rsv)->bool{return lsv>=rsv;},
                              "Shell Sort #1");
    */
    TestSortingAlgorithm<int>(numbers,
                              &ShellSort2<int>,
                              [](const int& lsv, const int & rsv)->bool{return lsv>=rsv;},
                              "Sheel Sort #2");

    TestSortingAlgorithm<int>(numbers,
                              &QuickSort<int>,
                              [](const int& lsv, const int & rsv)->bool{return lsv>=rsv;},
                              "Quick Sort");
    return 0;
}

template<typename T>
void TestSortingAlgorithm(std::vector<T>& target_vector, void(*sorting_algo)(std::vector<T>&, bool(*)(const T&, const T&)), bool(*compare)(const T&, const T&), const std::string algo_name)
{
    std::cout<<algo_name<<" Test"<<std::endl;
    MixVector(target_vector);
    std::cout<<(IsSorted<T>(target_vector, &Bigger<int>) ? "sorted" : "unsorted") <<std::endl;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point 
        = std::chrono::high_resolution_clock::now();
    
    sorting_algo(target_vector, compare);
    
    std::chrono::time_point<std::chrono::high_resolution_clock> end_point 
        = std::chrono::high_resolution_clock::now();
    
    //std::chrono::duration<long long, std::nano>
    auto deltatime = end_point - start_point;
    
    std::cout<<"run-time : "
             <<std::chrono::duration_cast<std::chrono::microseconds>(deltatime).count()
             <<" " << Greek::mu<< "s" <<std::endl;

    std::cout<<(IsSorted<T>(target_vector, compare) ? "sorted" : "unsorted") <<std::endl;
    std::cout<<std::string(30, '-')<<std::endl;
}

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

template<typename T>
void ShellSort1(std::vector<T>& target_vector,  bool(*compare)(const T&, const T&))
{
    //증분값, 컨테이너를 자를 단위이자 비교할 숫자들 사이의 간격
    int h = 1;
    int n = target_vector.size();
    while(h<n/9) h = h*3 +1;
    for(; h>0; h/=3)
    {
        //각 그룹별로 하면 아래와 같이 해야하지만, 어차피 j는 h~n-1까지 한번씩만 거친다. 따라서 두 loop르 하나로 합칠 수 있다.
        for(int i=0; i<n; i+=h)
        {
            for(int j=i+h; j<n; j+=h)
            {
                T temp = target_vector[j];
                int k=j;
                while((k-h>=0)&&(!compare(target_vector[k-h], temp)))
                {
                    target_vector[k] = target_vector[k-h];
                    k-=h;
                }
                target_vector[k] = temp;   
            }
        }
    }
}

template<typename T>
void ShellSort2(std::vector<T>& target_vector,  bool(*compare)(const T&, const T&))
{
    //증분값, 컨테이너를 자를 단위이자 비교할 숫자들 사이의 간격
    int h = 1;
    int n = target_vector.size();
    while(h<n/9) h = h*3 +1;
    for(; h>0; h/=3)
    {
        for(int i = h; i<n; i++)
        {
            T temp = target_vector[i];
            int j = i;
            while(j>=h)
            {
                if(!compare(target_vector[j-h], temp))
                {
                    target_vector[j] = target_vector[j-h];
                    j-=h;
                }
                else break;
            }
            target_vector[j] = temp;
        }
    }
}

template<typename T>
void QuickSort(std::vector<T>& target_vector,  bool(*compare)(const T&, const T&))
{
    //stack을 활용한 비재귀적 방식.

    struct SortingGroup
    {
        int left_point;
        int right_point;
        SortingGroup(int left_point, int right_point) : left_point(left_point), right_point(right_point){}
    };

    std::stack<SortingGroup> group_stack;
    group_stack.push(SortingGroup(0, target_vector.size()-1));

    while(!group_stack.empty())
    {
        SortingGroup current_group = group_stack.top();
        group_stack.pop();
        int left_point = current_group.left_point;
        int right_point = current_group.right_point;
        int pivot = target_vector[(left_point+right_point)/2];

        do
        {
            while(compare(target_vector[left_point], pivot)&&(target_vector[left_point]!=pivot)) left_point++;
            while(compare(pivot, target_vector[right_point])&&(target_vector[right_point]!=pivot)) right_point--;
            if(left_point<=right_point)
            {
                std::swap(target_vector[left_point], target_vector[right_point]);
                left_point++; right_point--;
            }
        }while(left_point<=right_point);

        if(current_group.left_point<right_point)
        {
            group_stack.push(SortingGroup(current_group.left_point, right_point));
        }

        if(left_point<current_group.right_point)
        {
            group_stack.push(SortingGroup(left_point, current_group.right_point));
        }
    }
}