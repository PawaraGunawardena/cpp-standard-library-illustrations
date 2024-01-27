#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

void allOf()
{
    /**
     * template<typename _InputIterator, typename _Predicate>
       inline bool all_of(_InputIterator __first, _InputIterator __last, _Predicate __pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{3, 5, 7};
    bool allOfResult1 = std::all_of(vectorInstance1.begin(), vectorInstance1.end(), [](const int& value){return value%2;});
    if(allOfResult1)
    {
        std::cout << "All of - fulfill the predicate" << std::endl;
    }
    else
    {
        std::cout << "All of - not fulfill the predicate" << std::endl;
    }

    std::vector<int> vectorInstance2{2, 5, 7};
    bool allOfResult2 = std::all_of(vectorInstance2.begin(), vectorInstance2.end(), [](const int& value){return value%2;});
    if(allOfResult2)
    {
        std::cout << "All of - fulfill the predicate" << std::endl;
    }
    else
    {
        std::cout << "All of - not fulfill the predicate" << std::endl;
    }
}

void anyOf()
{
    /**
     * template<typename _InputIterator, typename _Predicate>
       inline bool any_of(_InputIterator __first, _InputIterator __last, _Predicate __pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 8};
    bool anyOfResult1 = std::any_of(vectorInstance1.begin(), vectorInstance1.end(), [](const int& value){return value%2;});
    if(anyOfResult1)
    {
        std::cout << "Any of - fulfill the predicate" << std::endl;
    }
    else
    {
        std::cout << "Any of - not fulfill the predicate" << std::endl;
    }

    std::vector<int> vectorInstance2{2, 6, 8};
    bool anyOfResult2 = std::all_of(vectorInstance2.begin(), vectorInstance2.end(), [](const int& value){return value%2;});
    if(anyOfResult2)
    {
        std::cout << "Any of - fulfill the predicate" << std::endl;
    }
    else
    {
        std::cout << "Any of - not fulfill the predicate" << std::endl;
    }
}

void noneOf()
{
    /**
     * template<typename _InputIterator, typename _Predicate>
       inline bool none_of(_InputIterator __first, _InputIterator __last, _Predicate __pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 8};
    bool noneOfResult1 = std::none_of(vectorInstance1.begin(), vectorInstance1.end(), [](const int& value){return value%2;});
    if(noneOfResult1)
    {
        std::cout << "None of - fulfill the predicate" << std::endl;
    }
    else
    {
        std::cout << "None of - not fulfill the predicate" << std::endl;
    }

    std::vector<int> vectorInstance2{2, 6, 8};
    bool noneOfResult2 = std::none_of(vectorInstance2.begin(), vectorInstance2.end(), [](const int& value){return value%2;});
    if(noneOfResult2)
    {
        std::cout << "None of - fulfill the predicate" << std::endl;
    }
    else
    {
        std::cout << "None of - not fulfill the predicate" << std::endl;
    }
}

void forEach()
{
    /**
     * template<typename _InputIterator, typename _Function>
       _Function for_each(_InputIterator __first, _InputIterator __last, _Function __f)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 8};
    std::function unaryFunctionInput = [](const int& value){ std::cout << value << " ";};
    std::function unaryFunctionOutput = std::for_each(vectorInstance1.begin(), vectorInstance1.end(), unaryFunctionInput);
}

void forEachN()
{
    /**
     * template<typename _InputIterator, typename _Size, typename _Function>
       _InputIterator for_each_n(_InputIterator __first, _Size __n, _Function __f)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 8};
    std::function unaryFunctionInput = [](const int& value){ std::cout << value << " ";};
    std::vector<int>::iterator vectorIterator = std::for_each_n(vectorInstance1.begin(), 2, unaryFunctionInput);
}

void findValue()
{
    /**
     * template<typename _InputIterator, typename _Tp>
       inline _InputIterator
       find(_InputIterator __first, _InputIterator __last, const _Tp& __val)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 6, 8};
    std::vector<int>::iterator iteratorOfTheValue = std::find(vectorInstance1.begin(), vectorInstance1.end(), 10);

    if(iteratorOfTheValue != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue << std::endl;
    }
    else
    {
        std::cout << "Not exist" << *iteratorOfTheValue << std::endl;
    }
}

void findIf()
{
    /**
     * template<typename _InputIterator, typename _Predicate>
       inline _InputIterator
       find_if(_InputIterator __first, _InputIterator __last, _Predicate __pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 8};
    std::vector<int>::iterator iteratorOfTheValue = std::find_if(vectorInstance1.begin(), vectorInstance1.end(), [](const int value){return value%2;});

    if(iteratorOfTheValue != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue << std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void findIfNot()
{
    /**
     * template<typename _InputIterator, typename _Predicate>
       inline _InputIterator
       find_if_not(_InputIterator __first, _InputIterator __last, _Predicate __pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 8};
    std::vector<int>::iterator iteratorOfTheValue = std::find_if_not(vectorInstance1.begin(), vectorInstance1.end(), [](const int value){return value%2;});

    if(iteratorOfTheValue != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue << std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void findFirstOf()
{
    /**
     * template<typename _InputIterator, typename _ForwardIterator>
       _InputIterator
       find_first_of(_InputIterator __first1, _InputIterator __last1,
       _ForwardIterator __first2, _ForwardIterator __last2)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 8, 10, 15, 20, 50, 100};
    std::vector<int> vectorInstance2{10, 15, 20};
    std::vector<int>::iterator iteratorOfTheValue1 = std::find_first_of(vectorInstance1.begin(), vectorInstance1.end(), vectorInstance2.begin(), vectorInstance2.end());

    if(iteratorOfTheValue1 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue1 << std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }

    std::vector<int> vectorInstance3{100, 15, 20};
    std::vector<int>::iterator iteratorOfTheValue2 = std::find_first_of(vectorInstance1.begin(), vectorInstance1.end(), vectorInstance3.begin(), vectorInstance3.end());

    if(iteratorOfTheValue2 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue2 << std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }

    std::vector<int> vectorInstance4{500, 1000, 1500};
    std::vector<int>::iterator iteratorOfTheValue3 = std::find_first_of(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance4.begin(),
            vectorInstance4.end());

    if(iteratorOfTheValue3 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue3 << std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void findFirstOfWithPredicate()
{
    /**
     * template<typename _InputIterator, typename _ForwardIterator, typename _BinaryPredicate>
       _InputIterator
       find_first_of(_InputIterator __first1, _InputIterator __last1,
       _ForwardIterator __first2, _ForwardIterator __last2, _BinaryPredicate __comp)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 8, 10, 15, 20, 50, 100};
    std::vector<int> vectorInstance2{10, 150, 200};
    std::vector<int>::iterator iteratorOfTheValue1 = std::find_first_of(
            vectorInstance1.begin(), vectorInstance1.end(),
            vectorInstance2.begin(), vectorInstance2.end(),
            [](const int value1, const int value2){return value1 < value2;}
    );

    if(iteratorOfTheValue1 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue1 << std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }

    std::vector<int> vectorInstance3{1, 50, 30};
    std::vector<int>::iterator iteratorOfTheValue2 = std::find_first_of(
            vectorInstance1.begin(), vectorInstance1.end(),
            vectorInstance3.begin(), vectorInstance3.end(),
            [](const int value1, const int value2){return value1 < value2;}
    );

    if(iteratorOfTheValue2 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue2 << std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }

    std::vector<int> vectorInstance4{1, 2, 0};
    std::vector<int>::iterator iteratorOfTheValue3 = std::find_first_of(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance4.begin(),
            vectorInstance4.end(),
            [](const int value1, const int value2){return value1 < value2;}
    );

    if(iteratorOfTheValue3 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue3 << std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void findEnd()
{
    /**
     * template<typename _ForwardIterator1, typename _ForwardIterator2>
       inline _ForwardIterator1
       find_end(_ForwardIterator1 __first1, _ForwardIterator1 __last1,_ForwardIterator2 __first2, _ForwardIterator2 __last2)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 8, 10, 15, 20, 50, 100, 10, 15, 20, 50};
    std::vector<int> vectorInstance2{10, 15, 20};
    std::vector<int>::iterator iteratorOfTheValue1 = std::find_end(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            vectorInstance2.end());

    if(iteratorOfTheValue1 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue1 << " | Index: " << iteratorOfTheValue1-vectorInstance1.begin()<< std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }

    std::vector<int> vectorInstance3{10, 20, 30};
    std::vector<int>::iterator iteratorOfTheValue2 = std::find_end(vectorInstance1.begin(), vectorInstance1.end(), vectorInstance3.begin(), vectorInstance3.end());

    if(iteratorOfTheValue2 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue2 << std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void findEndWithPredicate()
{
    /**
     * template<typename _ForwardIterator1, typename _ForwardIterator2, typename _BinaryPredicate>
       inline _ForwardIterator1
       find_end(_ForwardIterator1 __first1, _ForwardIterator1 __last1, _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __comp)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 8, 10, 15, 20, 50, 100};
    std::vector<int> vectorInstance2{10, 15, 20};
    std::vector<int>::iterator iteratorOfTheValue1 = std::find_end(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            vectorInstance2.end(),
            [](const int value1, const int value2){return value1 < value2;}
            );

    if(iteratorOfTheValue1 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue1 << std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }

    std::vector<int> vectorInstance3{10, 50, 30};
    std::vector<int>::iterator iteratorOfTheValue2 = std::find_end(
            vectorInstance1.begin(), vectorInstance1.end(),
            vectorInstance3.begin(), vectorInstance3.end(),
            [](const int value1, const int value2){return value1 > value2;}
    );

    if(iteratorOfTheValue2 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue2 << std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void adjacentFind()
{
    /**
     * template<typename _ForwardIterator>
       inline _ForwardIterator
       adjacent_find(_ForwardIterator __first, _ForwardIterator __last)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 5};
    std::vector<int>::iterator iteratorOfTheValue = std::adjacent_find(vectorInstance1.begin(), vectorInstance1.end());

    if(iteratorOfTheValue != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue  << " | Index: " << iteratorOfTheValue-vectorInstance1.begin()<< std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void adjacentFindWithPredicate()
{
    /**
     * template<typename _ForwardIterator, typename _BinaryPredicate>
       inline _ForwardIterator
       adjacent_find(_ForwardIterator __first, _ForwardIterator __last, _BinaryPredicate __binary_pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 5};
    std::vector<int>::iterator iteratorOfTheValue = std::adjacent_find(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            [](const int value1, const int value2){return value1 < value2;}
            );

    if(iteratorOfTheValue != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue << " | Index: " << iteratorOfTheValue-vectorInstance1.begin()<< std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void isPermutation()
{
    /**
     * template<typename _ForwardIterator1, typename _ForwardIterator2>
       inline bool
       is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
       _ForwardIterator2 __first2, _ForwardIterator2 __last2)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    std::vector<int> vectorInstance2{ 50, 45, 40, 35, 30, 25, 20, 15, 10, 5};
    bool isPermutationVectors = std::is_permutation(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            vectorInstance2.end());

    if(isPermutationVectors)
    {
        std::cout << "A permutation" << std::endl;
    }
    else
    {
        std::cout << "Not a permutation" << std::endl;
    }
}

void isPermutationSequenceContain()
{
    /**
     * template<typename _ForwardIterator1, typename _ForwardIterator2>
       inline bool
       is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
       _ForwardIterator2 __first2)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    std::vector<int> vectorInstance2{ 50, 45, 40, 35, 30, 25, 20, 15, 10, 5, 6, 7, 8, 9, 4, 3, 2, 2};
    bool isPermutationVectors = std::is_permutation(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin());

    if(isPermutationVectors)
    {
        std::cout << "A permutation" << std::endl;
    }
    else
    {
        std::cout << "Not a permutation" << std::endl;
    }
}

void isPermutationSequenceWithPredicate()
{
    /**
     * template<typename _ForwardIterator1, typename _ForwardIterator2, typename _BinaryPredicate>
       inline bool
       is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
       _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate __pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    std::vector<int> vectorInstance2{ 150, 145, 140, 135, 130, 125, 120, 115, 110, 105};
    bool isPermutationVectors = std::is_permutation(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            vectorInstance2.end(),
            [](const int value1, const int value2){return value1 % 10 == value2 % 10;});

    if(isPermutationVectors)
    {
        std::cout << "A permutation" << std::endl;
    }
    else
    {
        std::cout << "Not a permutation" << std::endl;
    }
}

void isPermutationSequenceContainWithPredicate()
{
    /**
     * template<typename _ForwardIterator1, typename _ForwardIterator2, typename _BinaryPredicate>
       inline bool
       is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
       _ForwardIterator2 __first2, _BinaryPredicate __pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    std::vector<int> vectorInstance2{ 150, 145, 140, 135, 130, 125, 120, 115, 110, 15, 5};
    bool isPermutationVectors = std::is_permutation(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            [](const int value1, const int value2){return value1 % 10 == value2 % 10;});

    if(isPermutationVectors)
    {
        std::cout << "A permutation" << std::endl;
    }
    else
    {
        std::cout << "Not a permutation" << std::endl;
    }
}

void countValue()
{
    /**
     * template<typename _InputIterator, typename _Tp>
       inline typename iterator_traits<_InputIterator>::difference_type
       count(_InputIterator __first, _InputIterator __last, const _Tp& __value)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 5, 5};
    long countValue = std::count(vectorInstance1.begin(), vectorInstance1.end(), 5);

    std::cout << "Count:" << countValue << std::endl;
}

void countIf()
{
    /**
     * template<typename _InputIterator, typename _Predicate>
       inline typename iterator_traits<_InputIterator>::difference_type
       count_if(_InputIterator __first, _InputIterator __last, _Predicate __pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{2, 5, 15, 25};
    long countValue = std::count_if(vectorInstance1.begin(), vectorInstance1.end(),
                        [](const int value1){return value1 %2;});

    std::cout << "Count:" << countValue << std::endl;
}

void searchSequence()
{
    /**
     * template<typename _ForwardIterator1, typename _ForwardIterator2>
       inline _ForwardIterator1
       search(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
       _ForwardIterator2 __first2, _ForwardIterator2 __last2)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    std::vector<int> vectorInstance2{ 20, 25, 30 };
    std::vector<int>::iterator iteratorOfTheValue1 = std::search(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            vectorInstance2.end());

    if(iteratorOfTheValue1 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue1 << " | Index: " << iteratorOfTheValue1-vectorInstance1.begin()<< std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void searchWithPredicate()
{
    /**
     * template<typename _ForwardIterator1, typename _ForwardIterator2, typename _BinaryPredicate>
       inline _ForwardIterator1
       search(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
	   _ForwardIterator2 __first2, _ForwardIterator2 __last2, _BinaryPredicate  __predicate)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    std::vector<int> vectorInstance2{ 20, 25, 30 };
    std::vector<int>::iterator iteratorOfTheValue1 = std::search(
        vectorInstance1.begin(),
        vectorInstance1.end(),
        vectorInstance2.begin(),
        vectorInstance2.end(),
        [](const int value1, const int value2){return value1 % 10 == value2 % 10;}
    );

    if(iteratorOfTheValue1 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue1 << " | Index: " << iteratorOfTheValue1-vectorInstance1.begin()<< std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void searchValue()
{
    /**
     * template<typename _ForwardIterator, typename _Integer, typename _Tp>
       inline _ForwardIterator
       search_n(_ForwardIterator __first, _ForwardIterator __last, _Integer __count, const _Tp& __val)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 5, 10, 5, 5};
    std::vector<int>::iterator iteratorOfTheValue1 = std::search_n(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            2,
            5);

    if(iteratorOfTheValue1 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue1 << " | Index: " << iteratorOfTheValue1-vectorInstance1.begin()<< std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void searchValueWithPredicate()
{
    /**
     * template<typename _ForwardIterator, typename _Integer, typename _Tp, typename _BinaryPredicate>
       inline _ForwardIterator
       search_n(_ForwardIterator __first, _ForwardIterator __last, _Integer __count, const _Tp& __val, _BinaryPredicate __binary_pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 5, 10, 5, 5};
    std::vector<int>::iterator iteratorOfTheValue1 = std::search_n(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            2,
            5,
            [](const int value1, const int value2){return value1 % 10 == value2 % 10;});

    if(iteratorOfTheValue1 != vectorInstance1.end())
    {
        std::cout << "Exist:" << *iteratorOfTheValue1 << " | Index: " << iteratorOfTheValue1-vectorInstance1.begin()<< std::endl;
    }
    else
    {
        std::cout << "Not exist" << std::endl;
    }
}

void equalRanges()
{
    /**
     * template<typename _II1, typename _II2>
       inline bool
       equal(_II1 __first1, _II1 __last1, _II2 __first2)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20};
    std::vector<int> vectorInstance2{ 5, 10, 15, 20, 30};

    bool compareResult = std::equal(vectorInstance1.begin(), vectorInstance1.end(), vectorInstance2.begin());

    if(compareResult)
    {
        std::cout << "Equal" << std::endl;
    }
    else
    {
        std::cout << "Not equal" << std::endl;
    }
}

void equalRangesWithPredicate()
{
    /**
     * template<typename _IIter1, typename _IIter2, typename _BinaryPredicate>
       inline bool
       equal(_IIter1 __first1, _IIter1 __last1, _IIter2 __first2, _BinaryPredicate __binary_pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20};
    std::vector<int> vectorInstance2{ 105, 110, 115, 120};

    bool compareResult = std::equal(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            [](const int value1, const int value2){return value1 % 10 == value2 % 10;});

    if(compareResult)
    {
        std::cout << "Equal" << std::endl;
    }
    else
    {
        std::cout << "Not equal" << std::endl;
    }
}

void equalSequence()
{
    /**
     * template<typename _II1, typename _II2>
       inline bool
       equal(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20};
    std::vector<int> vectorInstance2{5, 10, 15, 20, 25};

    bool compareResult = std::equal(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            vectorInstance2.end()-1
            );

    if(compareResult)
    {
        std::cout << "Equal" << std::endl;
    }
    else
    {
        std::cout << "Not equal" << std::endl;
    }
}

void equalSequenceWithPredicate()
{
    /**
     * template<typename _IIter1, typename _IIter2, typename _BinaryPredicate>
       inline bool
       equal(_IIter1 __first1, _IIter1 __last1, _IIter2 __first2, _IIter2 __last2, _BinaryPredicate __binary_pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20};
    std::vector<int> vectorInstance2{ 105, 110, 115, 120, 125};

    bool compareResult = std::equal(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            vectorInstance2.end()-1,
            [](const int value1, const int value2){return value1 % 10 == value2 % 10;}
    );

    if(compareResult)
    {
        std::cout << "Equal" << std::endl;
    }
    else
    {
        std::cout << "Not equal" << std::endl;
    }
}

void mismatch()
{
    /**
     * template<typename _InputIterator1, typename _InputIterator2>
       inline pair<_InputIterator1, _InputIterator2>
       mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20};
    std::vector<int> vectorInstance2{ 5, 10, 15, 20, 25};

    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> compareResult = std::mismatch(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin()
    );

    if(compareResult.first != vectorInstance1.end())
    {
        std::cout << "Mismatch Vector 1: " << *compareResult.first << std::endl;
    }
    else
    {
        std::cout << "Not mismatch" << std::endl;
    }

    if(compareResult.second != vectorInstance2.end())
    {
        std::cout << "Mismatch Vector 2: " << *compareResult.second << std::endl;
    }
    else
    {
        std::cout << "Not mismatch" << std::endl;
    }
}

void mismatchWithPredicate()
{
    /**
     * template<typename _InputIterator1, typename _InputIterator2, typename _BinaryPredicate>
       inline pair<_InputIterator1, _InputIterator2>
       mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _BinaryPredicate __binary_pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20};
    std::vector<int> vectorInstance2{ 105, 110, 115, 120, 125};

    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> compareResult = std::mismatch(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            [](const int &value1, const int &value2){ return value1%5 == value2%5;}
    );

    if(compareResult.first != vectorInstance1.end())
    {
        std::cout << "Mismatch Vector 1: " << *compareResult.first << std::endl;
    }
    else
    {
        std::cout << "Not mismatch" << std::endl;
    }

    if(compareResult.second != vectorInstance2.end())
    {
        std::cout << "Mismatch Vector 2: " << *compareResult.second << std::endl;
    }
    else
    {
        std::cout << "Not mismatch" << std::endl;
    }
}

void mismatchSequence()
{
    /**
     * template<typename _InputIterator1, typename _InputIterator2>
       inline pair<_InputIterator1, _InputIterator2>
       mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20, 30};
    std::vector<int> vectorInstance2{ 5, 10, 15, 20};

    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> compareResult = std::mismatch(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            vectorInstance2.end()
    );

    if(compareResult.first != vectorInstance1.end())
    {
        std::cout << "Mismatch Vector 1: " << *compareResult.first << std::endl;
    }
    else
    {
        std::cout << "Not mismatch" << std::endl;
    }

    if(compareResult.second != vectorInstance2.end())
    {
        std::cout << "Mismatch Vector 2: " << *compareResult.second << std::endl;
    }
    else
    {
        std::cout << "Not mismatch" << std::endl;
    }
}

void mismatchSequenceWithPredicate()
{
    /**
     * template<typename _InputIterator1, typename _InputIterator2, typename _BinaryPredicate>
       inline pair<_InputIterator1, _InputIterator2>
       mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _InputIterator2 __last2, _BinaryPredicate __binary_pred)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20, 30};
    std::vector<int> vectorInstance2{ 105, 110, 115, 120};

    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> compareResult = std::mismatch(
            vectorInstance1.begin(),
            vectorInstance1.end(),
            vectorInstance2.begin(),
            vectorInstance2.end(),
            [](const int &value1, const int &value2){ return value1%5 == value2%5;}
    );

    if(compareResult.first != vectorInstance1.end())
    {
        std::cout << "Mismatch Vector 1: " << *compareResult.first << std::endl;
    }
    else
    {
        std::cout << "Not mismatch" << std::endl;
    }

    if(compareResult.second != vectorInstance2.end())
    {
        std::cout << "Mismatch Vector 2: " << *compareResult.second << std::endl;
    }
    else
    {
        std::cout << "Not mismatch" << std::endl;
    }
}

int main()
{
    allOf();
    std::cout << std::endl;
    anyOf();
    std::cout << std::endl;
    noneOf();
    std::cout << std::endl;

    forEach();
    std::cout << std::endl;
    forEachN();
    std::cout << std::endl;

    findValue();
    std::cout << std::endl;
    findIf();
    std::cout << std::endl;
    findIfNot();
    std::cout << std::endl;
    findFirstOf();
    std::cout << std::endl;
    findFirstOfWithPredicate();
    std::cout << std::endl;
    findEnd();
    std::cout << std::endl;
    findEndWithPredicate();
    std::cout << std::endl;
    adjacentFind();
    std::cout << std::endl;
    adjacentFindWithPredicate();
    std::cout << std::endl;

    isPermutation();
    std::cout << std::endl;
    isPermutationSequenceContain();
    std::cout << std::endl;
    isPermutationSequenceWithPredicate();
    std::cout << std::endl;
    isPermutationSequenceContainWithPredicate();
    std::cout << std::endl;

    countValue();
    std::cout << std::endl;
    countIf();
    std::cout << std::endl;

    searchSequence();
    std::cout << std::endl;
    searchWithPredicate();
    std::cout << std::endl;
    searchValue();
    std::cout << std::endl;
    searchValueWithPredicate();
    std::cout << std::endl;

    equalRanges();
    std::cout << std::endl;
    equalRangesWithPredicate();
    std::cout << std::endl;
    equalSequence();
    std::cout << std::endl;
    equalSequenceWithPredicate();
    std::cout << std::endl;
    mismatch();
    std::cout << std::endl;
    mismatchWithPredicate();
    std::cout << std::endl;
    mismatchSequence();
    std::cout << std::endl;
    mismatchSequenceWithPredicate();
    std::cout << std::endl;

    return 0;
}
