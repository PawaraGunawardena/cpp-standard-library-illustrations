#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

auto print = [](const int& value)
{
    std::cout << value << " ";
};

void vectorInitializationDefaultConstructor()
{
    /**
     *  vector()
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance;
    vectorInstance.push_back(5);
    vectorInstance.push_back(10);
    std::for_each(vectorInstance.begin(), vectorInstance.end(), print);
    std::cout << std::endl;

    std::vector<int>* pVectorInstance = new std::vector<int>();
    pVectorInstance->push_back(15);
    pVectorInstance->push_back(20);
    std::for_each(pVectorInstance->begin(), pVectorInstance->end(), print);
    std::cout << std::endl;
}

void vectorInitializationDefaultValueFillConstructor()
{
    /**
     * explicit
       vector(size_type __n, const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1(5);
    std::for_each(vectorInstance1.begin(), vectorInstance1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc1;
    std::vector<int> vectorInstance2(5,alloc1);
    std::for_each(vectorInstance2.begin(), vectorInstance2.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::vector<int, std::allocator<int>> vectorInstance3(5,alloc2);
    std::for_each(vectorInstance3.begin(), vectorInstance3.end(), print);
    std::cout << std::endl;
}

void vectorInitializationExemplaryValueFillConstructor()
{
    /**
     * vector(size_type __n, const value_type& __value,
       const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1(5,10);
    std::for_each(vectorInstance1.begin(), vectorInstance1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc1;
    std::vector<int> vectorInstance2(5,20,alloc1);
    std::for_each(vectorInstance2.begin(), vectorInstance2.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::vector<int, std::allocator<int>> vectorInstance3(5,30,alloc2);
    std::for_each(vectorInstance3.begin(), vectorInstance3.end(), print);
    std::cout << std::endl;
}

void vectorInitializationCopyConstructor()
{
    /**
     *  vector(const vector& __x)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> originalVector;
    originalVector.push_back(5);
    originalVector.push_back(10);
    std::vector<int> copyVector(originalVector);
    std::for_each(originalVector.begin(), originalVector.end(), print);
    std::cout << std::endl;
    std::for_each(copyVector.begin(), copyVector.end(), print);
    std::cout << std::endl;
}

void vectorInitializationMoveConstructor()
{
    /**
     *  vector(vector&&) noexcept = default
    */

    std::cout << __func__ << std::endl;

    std::vector<int> originalVector;
    originalVector.push_back(500);
    originalVector.push_back(1000);
    std::vector<int> moveVector(std::move(originalVector));
    std::for_each(originalVector.begin(), originalVector.end(), print);
    std::cout << std::endl;
    std::for_each(moveVector.begin(), moveVector.end(), print);
    std::cout << std::endl;
    std::cout << "Original vector size after move: " << originalVector.size() << std::endl;
}

void vectorInitializationAllocatorExtendedDefaultConstructor()
{
    /**
     *  explicit
        vector(const allocator_type& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::vector<int> vectorInstance1(alloc1);
    vectorInstance1.push_back(5000);
    vectorInstance1.push_back(10000);
    std::for_each(vectorInstance1.begin(), vectorInstance1.end(), print);
    std::cout << std::endl;

    // instead of default constructor, it can pass custom allocator
    std::allocator<int> alloc2;
    std::vector<int, std::allocator<int>> vectorInstance2(alloc2);
    vectorInstance2.push_back(2);
    vectorInstance2.push_back(1);
    std::for_each(vectorInstance2.begin(), vectorInstance2.end(), print);
    std::cout << std::endl;
}

void vectorInitializationInitializerListConstructor()
{
    /**
     * vector(initializer_list<value_type> __l, const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vectorInstance1{5, 10, 15, 20, 25};
    std::for_each(vectorInstance1.begin(), vectorInstance1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc1;
    std::vector<int> vectorInstance2({50, 100, 150, 200, 250}, alloc1);
    std::for_each(vectorInstance2.begin(), vectorInstance2.end(), print);
    std::cout << std::endl;

    std::vector<int, std::allocator<int>> vectorInstance3{10, 20, 30, 40, 50};
    std::for_each(vectorInstance3.begin(), vectorInstance3.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::vector<int, std::allocator<int>> vectorInstance4({100, 200, 300, 400, 500}, alloc2);
    std::for_each(vectorInstance4.begin(), vectorInstance4.end(), print);
    std::cout << std::endl;
}

void vectorInitializationRangeConstructor()
{
    /**
     * vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    int arrInstance1[] = {1, 3, 5};
    std::vector<int> vectorInstanceFromArr1(arrInstance1, arrInstance1+3);
    std::for_each(vectorInstanceFromArr1.begin(), vectorInstanceFromArr1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc1;
    int arrInstance2[] = {1, 3, 5};
    std::vector<int> vectorInstanceFromArr2(arrInstance2, arrInstance2+3, alloc1);
    std::for_each(vectorInstanceFromArr2.begin(), vectorInstanceFromArr2.end(), print);
    std::cout << std::endl;

    int arrInstance3[] = {1, 3, 5};
    std::vector<int, std::allocator<int>> vectorInstanceFromArr3(arrInstance3, arrInstance3+3);
    std::for_each(vectorInstanceFromArr3.begin(), vectorInstanceFromArr3.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    int arrInstance4[] = {1, 3, 5};
    std::vector<int, std::allocator<int>> vectorInstanceFromArr4(arrInstance4, arrInstance4+3, alloc2);
    std::for_each(vectorInstanceFromArr4.begin(), vectorInstanceFromArr4.end(), print);
    std::cout << std::endl;

    std::list<int> listInstance1{2, 4, 6};
    std::vector<int> vectorInstanceFromList1(listInstance1.begin(), listInstance1.end());
    std::for_each(vectorInstanceFromList1.begin(), vectorInstanceFromList1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc3;
    std::list<int> listInstance2{2, 4, 6};
    std::vector<int> vectorInstanceFromList2(listInstance2.begin(), listInstance2.end(), alloc3);
    std::for_each(vectorInstanceFromList2.begin(), vectorInstanceFromList2.end(), print);
    std::cout << std::endl;

    std::list<int> listInstance3{2, 4, 6};
    std::vector<int, std::allocator<int>> vectorInstanceFromList3(listInstance3.begin(), listInstance3.end());
    std::for_each(vectorInstanceFromList3.begin(), vectorInstanceFromList3.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc4;
    std::list<int> listInstance4{2, 4, 6};
    std::vector<int, std::allocator<int>> vectorInstanceFromList4(listInstance4.begin(), listInstance4.end(), alloc4);
    std::for_each(vectorInstanceFromList4.begin(), vectorInstanceFromList4.end(), print);
    std::cout << std::endl;
}

void vectorInitializationAllocatorExtendedCopyConstructor()
{
    /**
     * vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::vector<int> originalVector1;
    originalVector1.push_back(5);
    originalVector1.push_back(10);
    std::vector<int> copyVector1(originalVector1, alloc1);
    std::for_each(originalVector1.begin(), originalVector1.end(), print);
    std::cout << std::endl;
    std::for_each(copyVector1.begin(), copyVector1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::vector<int, std::allocator<int>> originalVector2;
    originalVector2.push_back(5);
    originalVector2.push_back(10);
    std::vector<int, std::allocator<int>> copyVector2(originalVector2);
    std::for_each(originalVector2.begin(), originalVector2.end(), print);
    std::cout << std::endl;
    std::for_each(copyVector2.begin(), copyVector2.end(), print);
    std::cout << std::endl;
}

void vectorInitializationAllocatorExtendedMoveConstructor()
{
    /**
     *  vector(vector&& __rv, const __type_identity_t<allocator_type>& __m)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::vector<int> originalVector1;
    originalVector1.push_back(500);
    originalVector1.push_back(1000);
    std::vector<int> moveVector1(std::move(originalVector1), alloc1);
    std::for_each(originalVector1.begin(), originalVector1.end(), print);
    std::cout << std::endl;
    std::for_each(moveVector1.begin(), moveVector1.end(), print);
    std::cout << std::endl;
    std::cout << "Original vector size after move: " << originalVector1.size() << std::endl;

    std::allocator<int> alloc2;
    std::vector<int, std::allocator<int>> originalVector2;
    originalVector2.push_back(500);
    originalVector2.push_back(1000);
    std::vector<int, std::allocator<int>> moveVector2(std::move(originalVector2), alloc2);
    std::for_each(originalVector2.begin(), originalVector2.end(), print);
    std::cout << std::endl;
    std::for_each(moveVector2.begin(), moveVector2.end(), print);
    std::cout << std::endl;
    std::cout << "Original vector size after move: " << originalVector2.size() << std::endl;
}

int main()
{
    vectorInitializationDefaultConstructor();
    vectorInitializationDefaultValueFillConstructor();
    vectorInitializationExemplaryValueFillConstructor();
    vectorInitializationCopyConstructor();
    vectorInitializationMoveConstructor();
    vectorInitializationAllocatorExtendedDefaultConstructor();
    vectorInitializationInitializerListConstructor();
    vectorInitializationRangeConstructor();
    vectorInitializationAllocatorExtendedCopyConstructor();
    vectorInitializationAllocatorExtendedMoveConstructor();

    return 0;
}
