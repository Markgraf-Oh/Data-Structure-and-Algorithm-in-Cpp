#ifndef vectorsortheader
#define vectorsortheader

#include <iostream>
#include <exception>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "GreekAlphabet.h"

namespace VectorSort
{
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

    /** 셸 정렬 알고리즘. 단순 삽입 정렬 알고리즘의 업그레이드 버젼. Quicksort 이전 까진 최고. O^1.25
     * @param target_vector vector to sort
     * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
    */
    template<typename T>
    void ShellSort(std::vector<T>& target_vector,  bool(*compare)(const T&, const T&));

    /** 엄청빠른 퀵 솔트!
     * @param target_vector vector to sort
     * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
    */
    template<typename T>
    void QuickSort(std::vector<T>& target_vector,  bool(*compare)(const T&, const T&));

    /** 머지솔트 실행 함수
     * @param target_vector vector to sort
     * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
    */
    template<typename T>
    void MergeSort(std::vector<T>& target_vector, bool(*compare)(const T&, const T&));

    /** MergeSort 내부에서 돌아갈 재귀함수
     * @param target_vector vector to sort
     * @param buff          buff vector for merging. should reserve capacity as much as the size of target_vector
     * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
    */
    template<typename T>
    void __RecurMergesort(std::vector<T>& target_vector, bool(*compare)(const T&, const T&), std::vector<T>& buff, int left_end, int right_end);

    /** std::vector를 힙형태로 정렬하는 함수
     * @param heap_vector   vector to rearange by heap rule
     * @param compare       compare function's pointer. bool(*)(const T& child, const T& parent) return true if Hierarchically correct.
     *                      bool(*)(const T& child, const T& parent), 둘의 계층관계가 올바르면 true를 return 합니다.
     * @param top           아래쪽으로 내려보낼 목표의 heap_vector상에서의 위치
     * @param bottom        heap_vector의 바닥. 목표는 이 지점까지만 내려갈 수 있습니다.
    */
    template<typename T>
    void __DownHeap(std::vector<T>& heap_vector, bool(*compare)(const T&/*child*/, const T&/*parent*/), int top, int bottom);

    /** std::vector를 힙형태로 정렬하는 함수
     * @param heap_vector   vector to rearange by heap rule
     * @param compare       compare function's pointer. bool(*)(const T& child, const T& parent) return true if Hierarchically correct.
    */
    template<typename T>
    void RearangeHeapVector(std::vector<T>& heap_vector, bool(*compare)(const T&/*child*/, const T&/*parent*/));

    /** 힙솔트 실행함수.
     * @param target_vector vector to sort
     * @param compare       compare function's pointer. get left side value and right side value. returns true if sorted, false if needs swap;
    */
    template<typename T>
    void HeapSort(std::vector<T>& target_vector, bool(*compare)(const T&, const T&));

    /** 솔팅 알고리즘을 테스트합니다. 먼저 벡터를 랜덤하게 섞고, 주어진 알고리즘으로 벡터를 정렬한 뒤, 걸린 시간을 출력하고 제대로 정렬되었는지 검증합니다.
     * @param target_vector 정렬할 테스트용 벡터입니다.
     * @param sorting_algo  사용할 알고리즘 함수의 포인터입니다.
     * @param compare       정렬의 기준이 되는 비교함수입니다. 왼쪽값과 오른쪽값을 받아서 정렬된 상태면 true를, 바꿀 필요가 있으면 false를 반환합니다.
     * @param algo_name     출력할 때 사용할 알고리즘의 이름입니다.
    */
    template<typename T>
    void TestSortingAlgorithm(std::vector<T>& target_vector,
                                void(*sorting_algo)(std::vector<T>&, bool(*)(const T&, const T&)),
                                bool(*compare)(const T&, const T&),
                                const std::string algo_name);
}

#include "VectorSort.hpp"

#endif