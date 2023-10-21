#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

auto print = [](const int& value)
{
    std::cout << value << " ";
};

void setInitializationDefaultConstructor()
{
    /**
     *  set()
    */

    std::cout << __func__ << std::endl;

    std::set<int> setInstance;
    setInstance.insert(5);
    setInstance.insert(10);
    std::for_each(setInstance.begin(), setInstance.end(), print);
    std::cout << std::endl;

    std::set<int>* pSetInstance = new std::set<int>();
    pSetInstance->insert(15);
    pSetInstance->insert(20);
    std::for_each(pSetInstance->begin(), pSetInstance->end(), print);
    std::cout << std::endl;
}

void setInitializationComparatorAndAllocatorConstructor()
{
    /**
     *  explicit
        set (const _Compare& __comp, const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::greater<> gtr1;
    std::set<int, std::greater<>> setInstance1(gtr1);
    setInstance1.insert(5);
    setInstance1.insert(10);
    std::for_each(setInstance1.begin(), setInstance1.end(), print);
    std::cout << std::endl;

    std::greater<> gtr2;
    std::allocator<int> alloc1;
    std::set<int, std::greater<>> setInstance2(gtr2, alloc1);
    setInstance2.insert(200);
    setInstance2.insert(400);
    setInstance2.insert(200);
    setInstance2.insert(100);
    std::for_each(setInstance2.begin(), setInstance2.end(), print);
    std::cout << std::endl;

    std::greater<> gtr3;
    std::allocator<int> alloc2;
    std::set<int, std::greater<>, std::allocator<int>> setInstance3(gtr3, alloc2);
    setInstance3.insert(20);
    setInstance3.insert(40);
    setInstance3.insert(20);
    setInstance3.insert(10);
    std::for_each(setInstance3.begin(), setInstance3.end(), print);
    std::cout << std::endl;
}

void setInitializationRangeConstructor()
{
    /**
     *  template<typename _InputIterator>
	    set(_InputIterator __first, _InputIterator __last)
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vecInstance{2, 4, 6};
    std::set<int> setInstanceFromVec(vecInstance.begin(), vecInstance.end());
    std::for_each(setInstanceFromVec.begin(), setInstanceFromVec.end(), print);
    std::cout << std::endl;

    int arrInstance[] = {1, 3, 5};
    std::set<int> setInstanceFromArr(arrInstance, arrInstance+3);
    std::for_each(setInstanceFromArr.begin(), setInstanceFromArr.end(), print);
    std::cout << std::endl;
};

void setInitializationRangeConstructorWithComparatorAndAllocator()
{
    /**
     *  template<typename _InputIterator>
	    set(_InputIterator __first, _InputIterator __last,
	    const _Compare& __comp, const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::vector<int> vecInstance{2, 4, 6};
    std::set<int, std::greater<>> setInstanceFromVec(vecInstance.begin(), vecInstance.end(), std::greater<>());
    std::for_each(setInstanceFromVec.begin(), setInstanceFromVec.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc;
    int arrInstance[] = {1, 3, 5};
    std::set<int, std::greater<>, std::allocator<int>> setInstanceFromArr(arrInstance, arrInstance+3, std::greater<>(), alloc);
    std::for_each(setInstanceFromArr.begin(), setInstanceFromArr.end(), print);
    std::cout << std::endl;
}

void setInitializationCopyConstructor()
{
    /**
     *  set(const set&) = default;
    */

    std::cout << __func__ << std::endl;

    std::set<int> originalSet;
    originalSet.insert(50);
    originalSet.insert(100);
    std::set<int> copySet(originalSet);
    std::for_each(originalSet.begin(), originalSet.end(), print);
    std::cout << std::endl;
    std::for_each(copySet.begin(), copySet.end(), print);
    std::cout << std::endl;
}

void setInitializationMoveConstructor()
{
    /**
     *  set(set&&) = default;
    */

    std::cout << __func__ << std::endl;

    std::set<int> originalSet;
    originalSet.insert(500);
    originalSet.insert(1000);
    std::set<int> moveSet(std::move(originalSet));
    std::for_each(originalSet.begin(), originalSet.end(), print);
    std::cout << std::endl;
    std::for_each(moveSet.begin(), moveSet.end(), print);
    std::cout << std::endl;
    std::cout << "Original set size after move: " << originalSet.size() << std::endl;
}

void setInitializationInitializerListConstructor()
{
    /**
     *  set(initializer_list<value_type> __l,
        const _Compare& __comp = _Compare(),
        const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::set<int> initializerListSet1{5, 10, 2};
    std::for_each(initializerListSet1.begin(), initializerListSet1.end(), print);
    std::cout << std::endl;

    std::set<int, std::greater<>> initializerListSet2{2, 10, 2, 3, 2};
    std::for_each(initializerListSet2.begin(), initializerListSet2.end(), print);
    std::cout << std::endl;

    std::set<int, std::greater<>> initializerListSet3({5, 10, 7, 5, 7}, std::greater<>());
    std::for_each(initializerListSet3.begin(), initializerListSet3.end(), print);
    std::cout << std::endl;

    std::set<int, std::greater<>, std::allocator<int>> initializerListSet4({5, 10, 2, 2, 3, 4}, std::greater<>());
    std::for_each(initializerListSet4.begin(), initializerListSet4.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc;
    std::set<int, std::greater<>, std::allocator<int>> initializerListSet5({50, 100, 20, 20, 30, 40}, std::greater<>(), alloc);
    std::for_each(initializerListSet5.begin(), initializerListSet5.end(), print);
    std::cout << std::endl;
}


void setInitializationAllocatorExtendedDefaultConstructor()
{
    /**
     *  explicit
        set(const allocator_type& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::set<int> setInstance1(alloc1);
    setInstance1.insert(5000);
    setInstance1.insert(10000);
    std::for_each(setInstance1.begin(), setInstance1.end(), print);
    std::cout << std::endl;

    // instead of default constructor, it can pass custom allocator
    std::allocator<int> alloc2;
    std::set<int, std::greater<>, std::allocator<int>> setInstance2(alloc2);
    setInstance2.insert(2);
    setInstance2.insert(1);
    std::for_each(setInstance2.begin(), setInstance2.end(), print);
    std::cout << std::endl;
}

void setInitializationAllocatorExtendedCopyConstructor()
{
    /**
     *  set(const set& __x, const __type_identity_t<allocator_type>& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::set<int> originalSet1;
    originalSet1.insert(50);
    originalSet1.insert(100);
    std::set<int> copySet1(originalSet1, alloc1);
    std::for_each(originalSet1.begin(), originalSet1.end(), print);
    std::cout << std::endl;
    std::for_each(copySet1.begin(), copySet1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::set<int, std::greater<>, std::allocator<int>> originalSet2;
    originalSet2.insert(50);
    originalSet2.insert(100);
    std::set<int, std::greater<>, std::allocator<int>> copySet2(originalSet2, alloc2);
    std::for_each(originalSet2.begin(), originalSet2.end(), print);
    std::cout << std::endl;
    std::for_each(copySet2.begin(), copySet2.end(), print);
    std::cout << std::endl;
}

void setInitializationAllocatorExtendedMoveConstructor()
{
    /**
     *  set(set&& __x, const __type_identity_t<allocator_type>& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::set<int> originalSet1;
    originalSet1.insert(500);
    originalSet1.insert(1000);
    std::set<int> moveSet1(std::move(originalSet1), alloc1);
    std::for_each(originalSet1.begin(), originalSet1.end(), print);
    std::cout << std::endl;
    std::for_each(moveSet1.begin(), moveSet1.end(), print);
    std::cout << std::endl;
    std::cout << "Original set size after move: " << originalSet1.size() << std::endl;


    std::allocator<int> alloc2;
    std::set<int, std::greater<>, std::allocator<int>> originalSet2;
    originalSet2.insert(50);
    originalSet2.insert(100);
    std::set<int, std::greater<>, std::allocator<int>> moveSet2(std::move(originalSet2), alloc2);
    std::for_each(originalSet2.begin(), originalSet2.end(), print);
    std::cout << std::endl;
    std::for_each(moveSet2.begin(), moveSet2.end(), print);
    std::cout << std::endl;
    std::cout << "Original set size after move: " << originalSet2.size() << std::endl;
}

void setInitializationAllocatorExtendedInitializerListConstructor()
{
    /**
     *  set(initializer_list<value_type> __l, const allocator_type& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::set<int> initialiazerListSet1({5, 10, 2}, alloc1);
    std::for_each(initialiazerListSet1.begin(), initialiazerListSet1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::set<int, std::greater<>> initializerListSet2({2, 10, 2, 3, 2}, alloc2);
    std::for_each(initializerListSet2.begin(), initializerListSet2.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc3;
    std::set<int, std::greater<>, std::allocator<int>> initializerListSet3({5, 10, 2, 2, 3, 4}, alloc3);
    std::for_each(initializerListSet3.begin(), initializerListSet3.end(), print);
    std::cout << std::endl;
}

void setInitializationAllocatorExtendedRangeConstructor()
{
    /**
     *  template<typename _InputIterator>
        set(_InputIterator __first, _InputIterator __last, const allocator_type& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::vector<int> vecInstance1{2, 4, 6};
    std::set<int> setInstanceFromVec1(vecInstance1.begin(), vecInstance1.end(), alloc1);
    std::for_each(setInstanceFromVec1.begin(), setInstanceFromVec1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::vector<int> vecInstance2{2, 2, 4, 4, 6, 6};
    std::set<int, std::greater<>, std::allocator<int>> setInstanceFromVec2(vecInstance2.begin(), vecInstance2.end(), alloc2);
    std::for_each(setInstanceFromVec2.begin(), setInstanceFromVec2.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc3;
    int arrInstance1[] = {1, 3, 5};
    std::set<int> setInstanceFromArr1(arrInstance1, arrInstance1+3, alloc3);
    std::for_each(setInstanceFromArr1.begin(), setInstanceFromArr1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc4;
    int arrInstance2[] = {1, 1, 3, 3, 5, 5};
    std::set<int, std::greater<>, std::allocator<int>> setInstanceFromArr2(arrInstance2, arrInstance2+6, alloc4);
    std::for_each(setInstanceFromArr2.begin(), setInstanceFromArr2.end(), print);
    std::cout << std::endl;
};

int main()
{
    setInitializationDefaultConstructor();
    setInitializationComparatorAndAllocatorConstructor();
    setInitializationRangeConstructor();
    setInitializationRangeConstructorWithComparatorAndAllocator();
    setInitializationCopyConstructor();
    setInitializationMoveConstructor();
    setInitializationInitializerListConstructor();
    setInitializationAllocatorExtendedDefaultConstructor();
    setInitializationAllocatorExtendedCopyConstructor();
    setInitializationAllocatorExtendedMoveConstructor();
    setInitializationAllocatorExtendedInitializerListConstructor();
    setInitializationAllocatorExtendedRangeConstructor();

    return 0;
}
