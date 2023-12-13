#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

auto print = [](const int& value)
{
    std::cout << value << " ";
};

void listInitializationDefaultConstructor()
{
    /**
     *  list()
    */

    std::cout << __func__ << std::endl;

    std::list<int> listInstance;
    listInstance.push_back(5);
    listInstance.push_back(10);
    std::for_each(listInstance.begin(), listInstance.end(), print);
    std::cout << std::endl;

    std::list<int>* pListInstance = new std::list<int>();
    pListInstance->push_back(15);
    pListInstance->push_back(20);
    std::for_each(pListInstance->begin(), pListInstance->end(), print);
    std::cout << std::endl;
}

void listInitializationDefaultValueFillConstructor()
{
    /**
     * explicit
       list(size_type __n, const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::list<int> listInstance1(5);
    std::for_each(listInstance1.begin(), listInstance1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc1;
    std::list<int> listInstance2(5, alloc1);
    std::for_each(listInstance2.begin(), listInstance2.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::list<int, std::allocator<int>> listInstance3(5, alloc2);
    std::for_each(listInstance3.begin(), listInstance3.end(), print);
    std::cout << std::endl;
}

void listInitializationExemplaryValueFillConstructor()
{
    /**
     * list(size_type __n, const value_type& __value,
	   const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::list<int> listInstance1(5,10);
    std::for_each(listInstance1.begin(), listInstance1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc1;
    std::list<int> listInstance2(5,20,alloc1);
    std::for_each(listInstance2.begin(), listInstance2.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::list<int, std::allocator<int>> listInstance3(5,30,alloc2);
    std::for_each(listInstance3.begin(), listInstance3.end(), print);
    std::cout << std::endl;
}

void listInitializationCopyConstructor()
{
    /**
     *  list(const list& __x)
    */

    std::cout << __func__ << std::endl;

    std::list<int> originalList;
    originalList.push_back(5);
    originalList.push_back(10);
    std::list<int> copyList(originalList);
    std::for_each(originalList.begin(), originalList.end(), print);
    std::cout << std::endl;
    std::for_each(copyList.begin(), copyList.end(), print);
    std::cout << std::endl;
}

void listInitializationMoveConstructor()
{
    /**
     *  list(list&&) = default
    */

    std::cout << __func__ << std::endl;

    std::list<int> originalList;
    originalList.push_back(500);
    originalList.push_back(1000);
    std::list<int> moveList(std::move(originalList));
    std::for_each(originalList.begin(), originalList.end(), print);
    std::cout << std::endl;
    std::for_each(moveList.begin(), moveList.end(), print);
    std::cout << std::endl;
    std::cout << "Original list size after move: " << originalList.size() << std::endl;
}

void listInitializationAllocatorExtendedDefaultConstructor()
{
    /**
     * explicit
       list(const allocator_type& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::list<int> listInstance1(alloc1);
    listInstance1.push_back(5000);
    listInstance1.push_back(10000);
    std::for_each(listInstance1.begin(), listInstance1.end(), print);
    std::cout << std::endl;

    // instead of default constructor, it can pass custom allocator
    std::allocator<int> alloc2;
    std::list<int, std::allocator<int>> listInstance2(alloc2);
    listInstance2.push_back(2);
    listInstance2.push_back(1);
    std::for_each(listInstance2.begin(), listInstance2.end(), print);
    std::cout << std::endl;
}

void listInitializationInitializerListConstructor()
{
    /**
     * list(initializer_list<value_type> __l, const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::list<int> listInstance1{5, 10, 15, 20, 25};
    std::for_each(listInstance1.begin(), listInstance1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc1;
    std::list<int> listInstance2({50, 100, 150, 200, 250}, alloc1);
    std::for_each(listInstance2.begin(), listInstance2.end(), print);
    std::cout << std::endl;

    std::list<int, std::allocator<int>> listInstance3{10, 20, 30, 40, 50};
    std::for_each(listInstance3.begin(), listInstance3.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::list<int, std::allocator<int>> listInstance4({100, 200, 300, 400, 500}, alloc2);
    std::for_each(listInstance4.begin(), listInstance4.end(), print);
    std::cout << std::endl;
}

void listInitializationRangeConstructor()
{
    /**
     * list(_InputIterator __first, _InputIterator __last, const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    int arrInstance1[] = {1, 3, 5};
    std::list<int> listInstanceFromArr1(arrInstance1, arrInstance1+3);
    std::for_each(listInstanceFromArr1.begin(), listInstanceFromArr1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc1;
    int arrInstance2[] = {1, 3, 5};
    std::list<int> listInstanceFromArr2(arrInstance2, arrInstance2+3, alloc1);
    std::for_each(listInstanceFromArr2.begin(), listInstanceFromArr2.end(), print);
    std::cout << std::endl;

    int arrInstance3[] = {1, 3, 5};
    std::list<int, std::allocator<int>> listInstanceFromArr3(arrInstance3, arrInstance3+3);
    std::for_each(listInstanceFromArr3.begin(), listInstanceFromArr3.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    int arrInstance4[] = {1, 3, 5};
    std::list<int, std::allocator<int>> listInstanceFromArr4(arrInstance4, arrInstance4+3, alloc2);
    std::for_each(listInstanceFromArr4.begin(), listInstanceFromArr4.end(), print);
    std::cout << std::endl;

    std::vector<int> vectorInstance1{2, 4, 6};
    std::list<int> listInstanceFromVector1(vectorInstance1.begin(), vectorInstance1.end());
    std::for_each(listInstanceFromVector1.begin(), listInstanceFromVector1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc3;
    std::vector<int> vectorInstance2{2, 4, 6};
    std::list<int> listInstanceFromVector2(vectorInstance2.begin(), vectorInstance2.end(), alloc3);
    std::for_each(listInstanceFromVector2.begin(), listInstanceFromVector2.end(), print);
    std::cout << std::endl;

    std::vector<int> vectorInstance3{2, 4, 6};
    std::list<int, std::allocator<int>> listInstanceFromVector3(vectorInstance3.begin(), vectorInstance3.end());
    std::for_each(listInstanceFromVector3.begin(), listInstanceFromVector3.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc4;
    std::vector<int> vectorInstance4{2, 4, 6};
    std::list<int, std::allocator<int>> listInstanceFromVector4(vectorInstance4.begin(), vectorInstance4.end(), alloc4);
    std::for_each(listInstanceFromVector4.begin(), listInstanceFromVector4.end(), print);
    std::cout << std::endl;
}

void listInitializationAllocatorExtendedCopyConstructor()
{
    /**
     * list(const list& __x, const __type_identity_t<allocator_type>& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::list<int> originalList1;
    originalList1.push_back(5);
    originalList1.push_back(10);
    std::list<int> copyList1(originalList1, alloc1);
    std::for_each(originalList1.begin(), originalList1.end(), print);
    std::cout << std::endl;
    std::for_each(copyList1.begin(), copyList1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::list<int, std::allocator<int>> originalList2;
    originalList2.push_back(5);
    originalList2.push_back(10);
    std::list<int, std::allocator<int>> copyList2(originalList2);
    std::for_each(originalList2.begin(), originalList2.end(), print);
    std::cout << std::endl;
    std::for_each(copyList2.begin(), copyList2.end(), print);
    std::cout << std::endl;
}

void listInitializationAllocatorExtendedMoveConstructor()
{
    /**
     *  list(list&& __x, const __type_identity_t<allocator_type>& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::list<int> originalList1;
    originalList1.push_back(500);
    originalList1.push_back(1000);
    std::list<int> moveList1(std::move(originalList1), alloc1);
    std::for_each(originalList1.begin(), originalList1.end(), print);
    std::cout << std::endl;
    std::for_each(moveList1.begin(), moveList1.end(), print);
    std::cout << std::endl;
    std::cout << "Original list size after move: " << originalList1.size() << std::endl;

    std::allocator<int> alloc2;
    std::list<int, std::allocator<int>> originalList2;
    originalList2.push_back(500);
    originalList2.push_back(1000);
    std::list<int, std::allocator<int>> moveList2(std::move(originalList2), alloc2);
    std::for_each(originalList2.begin(), originalList2.end(), print);
    std::cout << std::endl;
    std::for_each(moveList2.begin(), moveList2.end(), print);
    std::cout << std::endl;
    std::cout << "Original list size after move: " << originalList2.size() << std::endl;
}

int main()
{
    listInitializationDefaultConstructor();
    listInitializationDefaultValueFillConstructor();
    listInitializationExemplaryValueFillConstructor();
    listInitializationCopyConstructor();
    listInitializationMoveConstructor();
    listInitializationAllocatorExtendedDefaultConstructor();
    listInitializationInitializerListConstructor();
    listInitializationRangeConstructor();
    listInitializationAllocatorExtendedCopyConstructor();
    listInitializationAllocatorExtendedMoveConstructor();

    return 0;
}
