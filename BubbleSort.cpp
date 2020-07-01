#include <iostream>
#include <vector>
#include <algorithm>

//g++ 컴파일, 실행
/*
  g++ -o .\BubbleSort.exe BubbleSort.cpp
  .\BubbleSort.exe
*/

/** bidirection bubble sort, cocktail sort
 * @param target_vector vector to sort
 * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
*/
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
bool Bigger(const T & frt, const T & bck)
{
   return frt >= bck;
}

template<typename T>
bool Smaller(const T& frt, const T& bck)
{
   return bck >= frt;
}

int main()
{
    std::vector<int> a = {4,1,3,2,4,6,6,7,1,9,3,5,1,0};
    for(int i:a)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::cout<<IsSorted<int>(a, &Bigger<int>)<<std::endl;
    //BubbleSort<int>(a, &Bigger<int>);
    ShakerSort<int>(a, [](const int & lsv, const int & rsv)->bool{return lsv>=rsv;});
    //ShakerSort<int>(a, &Bigger<int>);
    for(int i:a)
    {
       std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::cout<<IsSorted<int>(a, &Bigger<int>)<<std::endl;
    return 0;
}