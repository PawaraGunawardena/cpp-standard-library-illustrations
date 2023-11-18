#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>

template<typename T, typename  U>
auto print = [](const std::pair<T, U> value)
{
    std::cout << "(" << value.first << ", " << value.second<< ") ";
};

void mapInitializationDefaultConstructor()
{
    /**
     *  map()
    */

    std::cout << __func__ << std::endl;

    std::map<std::string, int> mapInstance;
    mapInstance.insert(std::pair<std::string, int>("first", 10));
    mapInstance.insert(std::pair<std::string, int>("second", 20));
    mapInstance.insert(std::pair<std::string, int>("second", 500));
    mapInstance["third"] = 40;
    mapInstance["third"] = 50;

    /*
     * first = 10
     * second = 20
     * third = 50
    */
    std::for_each(mapInstance.begin(), mapInstance.end(), print<std::string, int>);
    std::cout << std::endl;

    std::map<std::string, int>* pMapInstance = new std::map<std::string, int>();
    pMapInstance->insert(std::pair<std::string, int>("first", 100));
    pMapInstance->insert(std::pair<std::string, int>("second", 200));
    std::for_each(pMapInstance->begin(), pMapInstance->end(), print<std::string, int>);
    std::cout << std::endl;

    std::multimap<int, int> mmp;
    std::unordered_set<int> ust;
}

void mapInitializationComparatorAndAllocatorConstructor()
{
    /**
     *  explicit
        map(const _Compare& __comp, const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::greater<> gtr1;
    std::map<std::string, int, std::greater<>> mapInstance1(gtr1);
    mapInstance1.insert(std::pair<std::string, int>("first", 10));
    mapInstance1.insert(std::pair<std::string, int>("second", 20));
    mapInstance1["third"] = 50;
    std::for_each(mapInstance1.begin(), mapInstance1.end(), print<std::string, int>);
    std::cout << std::endl;

    std::greater<> gtr2;
    std::allocator<std::pair<const std::string, int>> alloc1;
    std::map<std::string, int, std::greater<>> mapInstance2(gtr2, alloc1);
    mapInstance2.insert(std::pair<std::string, int>("one_hundred", 100));
    mapInstance2.insert(std::pair<std::string, int>("two_hundred", 200));
    mapInstance2.insert(std::pair<std::string, int>("three_hundred", 300));
    mapInstance2.insert(std::pair<std::string, int>("four_hundred", 400));
    std::for_each(mapInstance2.begin(), mapInstance2.end(), print<std::string, int>);
    std::cout << std::endl;

    std::greater<> gtr3;
    std::allocator<std::pair<const std::string, int>> alloc2;
    std::map<std::string, int, std::greater<>, std::allocator<std::pair<const std::string, int>>> mapInstance3(gtr3, alloc2);
    mapInstance3.insert(std::pair<std::string, int>("fruits", 20));
    mapInstance3.insert(std::pair<std::string, int>("vegetables", 40));
    std::for_each(mapInstance3.begin(), mapInstance3.end(), print<std::string, int>);
    std::cout << std::endl;
}

void mapInitializationRangeConstructor()
{
    /**
    *   template<typename _InputIterator>
	    map(_InputIterator __first, _InputIterator __last)
    */

    std::cout << __func__ << std::endl;

    std::vector<std::pair<int, std::string>> vecInstance{{10, "ten"}, {30, "thirty"}, {20, "twenty"}};
    std::map<int, std::string> mapInstanceFromVec(vecInstance.begin(), vecInstance.end());
    std::for_each(mapInstanceFromVec.begin(), mapInstanceFromVec.end(), print<int, std::string>);
    std::cout << std::endl;

    std::pair<int, std::string> arrInstance[] = {{20, "apple"}, {10, "orange"}, {30, "pineapple"}};
    std::map<int, std::string> mapInstanceFromArr(arrInstance, arrInstance+3);
    std::for_each(mapInstanceFromArr.begin(), mapInstanceFromArr.end(), print<int, std::string>);
    std::cout << std::endl;
};

void mapInitializationRangeConstructorWithComparatorAndAllocator()
{
    /**
     *  template<typename _InputIterator>
	    map(_InputIterator __first, _InputIterator __last,
        const _Compare& __comp, const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::vector<std::pair<int, std::string>> vecInstance{{10, "ten"}, {30, "thirty"}, {20, "twenty"}};
    std::map<int, std::string, std::greater<>> mapInstanceFromVec(vecInstance.begin(), vecInstance.end(), std::greater<>());
    std::for_each(mapInstanceFromVec.begin(), mapInstanceFromVec.end(), print<int, std::string>);
    std::cout << std::endl;

    std::allocator<std::pair<const int, std::string>> alloc;
    std::pair<int, std::string> arrInstance[] = {{20, "apple"}, {10, "orange"}, {30, "pineapple"}};
    std::map<int, std::string, std::greater<>, std::allocator<std::pair<const int, std::string>>> mapInstanceFromArr(arrInstance, arrInstance+3, std::greater<>(), alloc);
    std::for_each(mapInstanceFromArr.begin(), mapInstanceFromArr.end(), print<int, std::string>);
    std::cout << std::endl;
}

void mapInitializationCopyConstructor()
{
    /**
     *  map(const map&) = default
    */

    std::cout << __func__ << std::endl;

    std::map<std::string, int> originalMap;
    originalMap.insert({"first", 50});
    originalMap.insert({"second", 100});
    std::map<std::string, int> copyMap(originalMap);
    std::for_each(originalMap.begin(), originalMap.end(), print<std::string, int>);
    std::cout << std::endl;
    std::for_each(copyMap.begin(), copyMap.end(), print<std::string, int>);
    std::cout << std::endl;
}

void mapInitializationMoveConstructor()
{
    /**
     *  map(map&&) = default
    */

    std::cout << __func__ << std::endl;

    std::map<std::string, int> originalMap;
    originalMap.insert({"first", 500});
    originalMap.insert({"second", 1000});
    std::map<std::string, int> moveMap(std::move(originalMap));
    std::for_each(originalMap.begin(), originalMap.end(), print<std::string, int>);
    std::cout << std::endl;
    std::for_each(moveMap.begin(), moveMap.end(), print<std::string, int>);
    std::cout << std::endl;
    std::cout << "Original map size after move: " << moveMap.size() << std::endl;
}

void mapInitializationInitializerListConstructor()
{
    /**
     *  map(initializer_list<value_type> __l,
	    const _Compare& __comp = _Compare(),
	    const allocator_type& __a = allocator_type())
    */

    std::cout << __func__ << std::endl;

    std::map<std::string, int> initializerListMap1{{"first", 50}, {"second", 100}, {"third", 150}};
    std::for_each(initializerListMap1.begin(), initializerListMap1.end(), print<std::string, int>);
    std::cout << std::endl;

    std::map<std::string, int, std::greater<>> initializerListMap2{{"a", 10}, {"b", 20}, {"c", 30}, {"d", 40}, {"d", 50}};
    std::for_each(initializerListMap2.begin(), initializerListMap2.end(), print<std::string, int>);
    std::cout << std::endl;

    std::map<int, std::string, std::greater<>>
        initializerListMap3({{100, "hundred"}, {1000, "thousand"}, {10, "ten"}}, std::greater<>());
    std::for_each(initializerListMap3.begin(), initializerListMap3.end(), print<int, std::string>);
    std::cout << std::endl;

    std::map<std::string, int, std::greater<>, std::allocator<std::pair<const std::string, int>>>
        initializerListMap4{{"a", 10}, {"b", 20}, {"c", 30}, {"d", 40}, {"d", 50}};
    std::for_each(initializerListMap4.begin(), initializerListMap4.end(), print<std::string, int>);
    std::cout << std::endl;

    std::allocator<std::pair<const int, std::string>> alloc;
    std::map<int, std::string, std::greater<>, std::allocator<std::pair<const int, std::string>>>
            initializerListMap5({{100, "hundred"}, {1000, "thousand"}, {10, "ten"}}, std::greater<>(), alloc);
    std::for_each(initializerListMap5.begin(), initializerListMap5.end(), print<int, std::string>);
    std::cout << std::endl;
}

void mapInitializationAllocatorExtendedDefaultConstructor()
{
    /**
     *  explicit
        map(const allocator_type& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<std::pair<const std::string, int>> alloc1;
    std::map<std::string, int> mapInstance1(alloc1);
    mapInstance1.insert({"first", 50});
    mapInstance1.insert({"second", 100});
    std::for_each(mapInstance1.begin(), mapInstance1.end(), print<std::string, int>);
    std::cout << std::endl;

    // instead of default allocator type, it can pass a custom allocator type
    std::allocator<std::pair<const std::string, int>> alloc2;
    std::map<std::string, int, std::greater<>, std::allocator<std::pair<const std::string, int>>> mapInstance2(alloc2);
    mapInstance2.insert({"first", 50});
    mapInstance2.insert({"second", 100});
    std::for_each(mapInstance2.begin(), mapInstance2.end(), print<std::string, int>);
    std::cout << std::endl;
}

void mapInitializationAllocatorExtendedCopyConstructor()
{
    /**
     *  map(const map& __m, const __type_identity_t<allocator_type>& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<std::pair<const std::string, int>> alloc1;
    std::map<std::string, int> originalMap1;
    originalMap1.insert({"first", 50});
    originalMap1.insert({"second", 100});
    std::map<std::string, int> copyMap1(originalMap1, alloc1);
    std::for_each(originalMap1.begin(), originalMap1.end(), print<std::string, int>);
    std::cout << std::endl;
    std::for_each(copyMap1.begin(), copyMap1.end(), print<std::string, int>);
    std::cout << std::endl;

    std::allocator<std::pair<const std::string, int>> alloc2;
    std::map<std::string, int, std::greater<>, std::allocator<std::pair<const std::string, int>>> originalMap2;
    originalMap1.insert({"first", 50});
    originalMap1.insert({"second", 100});
    std::map<std::string, int, std::greater<>, std::allocator<std::pair<const std::string, int>>> copyMap2(originalMap2, alloc2);
    std::for_each(originalMap2.begin(), originalMap2.end(), print<std::string, int>);
    std::cout << std::endl;
    std::for_each(copyMap2.begin(), copyMap2.end(), print<std::string, int>);
    std::cout << std::endl;
}

void mapInitializationAllocatorExtendedMoveConstructor()
{
    /**
     *  map(map&& __m, const __type_identity_t<allocator_type>& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<std::pair<const std::string, int>> alloc1;
    std::map<std::string, int> originalMap1;
    originalMap1.insert({"first", 500});
    originalMap1.insert({"second", 1000});
    std::map<std::string, int> moveMap1(std::move(originalMap1), alloc1);
    std::for_each(originalMap1.begin(), originalMap1.end(), print<std::string, int>);
    std::cout << std::endl;
    std::for_each(moveMap1.begin(), moveMap1.end(), print<std::string, int>);
    std::cout << std::endl;
    std::cout << "Original map size after move: " << originalMap1.size() << std::endl;


    std::allocator<std::pair<const std::string, int>> alloc2;
    std::map<std::string, int, std::greater<>, std::allocator<std::pair<const std::string, int>>> originalMap2;
    originalMap2.insert({"first", 500});
    originalMap2.insert({"second", 1000});
    std::map<std::string, int, std::greater<>, std::allocator<std::pair<const std::string, int>>> moveMap2(std::move(originalMap2), alloc2);
    std::for_each(originalMap2.begin(), originalMap2.end(), print<std::string, int>);
    std::cout << std::endl;
    std::for_each(moveMap2.begin(), moveMap2.end(), print<std::string, int>);
    std::cout << std::endl;
    std::cout << "Original map size after move: " << originalMap2.size() << std::endl;
}

void mapInitializationAllocatorExtendedInitializerListConstructor()
{
    /**
     *  map(initializer_list<value_type> __l, const allocator_type& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<std::pair<const std::string, int>> alloc1;
    std::map<std::string, int> initializerListMap1({{"first", 50}, {"second", 100}, {"third", 150}}, alloc1);
    std::for_each(initializerListMap1.begin(), initializerListMap1.end(), print<std::string, int>);
    std::cout << std::endl;

    std::allocator<std::pair<const std::string, int>> alloc2;
    std::map<std::string, int, std::greater<>> initializerListMap2({{"a", 10}, {"b", 20}, {"c", 30}, {"d", 40}, {"d", 50}}, alloc2);
    std::for_each(initializerListMap2.begin(), initializerListMap2.end(), print<std::string, int>);
    std::cout << std::endl;

    std::allocator<std::pair<const int, std::string>> alloc3;
    std::map<int, std::string, std::greater<>, std::allocator<std::pair<const int, std::string>>> initializerListMap3({{100, "hundred"}, {1000, "thousand"}, {10, "ten"}}, alloc3);
    std::for_each(initializerListMap3.begin(), initializerListMap3.end(), print<int, std::string>);
    std::cout << std::endl;
}

void mapInitializationAllocatorExtendedRangeConstructor()
{
    /**
     *  template<typename _InputIterator>
	    map(_InputIterator __first, _InputIterator __last, const allocator_type& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<std::pair<const std::string, int>> alloc1;
    std::vector<std::pair<std::string, int>> vecInstance1{{"ten", 10}, {"thirty", 30}, {"twenty", 20}};
    std::map<std::string, int> mapInstanceFromVec1(vecInstance1.begin(), vecInstance1.end(), alloc1);
    std::for_each(mapInstanceFromVec1.begin(), mapInstanceFromVec1.end(), print<std::string, int>);
    std::cout << std::endl;

    std::allocator<std::pair<const std::string, int>> alloc2;
    std::vector<std::pair<std::string, int>> vecInstance2{{"apple", 20}, {"orange", 10}, {"pineapple", 30}};
    std::map<std::string, int, std::greater<>, std::allocator<std::pair<const std::string, int>>> mapInstanceFromVec2(vecInstance2.begin(), vecInstance2.end(), alloc2);
    std::for_each(mapInstanceFromVec2.begin(), mapInstanceFromVec2.end(), print<std::string, int>);
    std::cout << std::endl;

    std::allocator<std::pair<const std::string, int>> alloc3;
    std::pair<std::string, int> arrInstance1[] = {{"ten", 10}, {"thirty", 30}, {"twenty", 20}};
    std::map<std::string, int> mapInstanceFromArr1(arrInstance1, arrInstance1+3, alloc3);
    std::for_each(mapInstanceFromArr1.begin(), mapInstanceFromArr1.end(), print<std::string, int>);
    std::cout << std::endl;

    std::allocator<std::pair<const std::string, int>> alloc4;
    std::pair<std::string, int> arrInstance2[] = {{"apple", 20}, {"orange", 10}, {"pineapple", 30}};
    std::map<std::string, int, std::greater<>, std::allocator<std::pair<const std::string, int>>> mapInstanceFromArr2(arrInstance2, arrInstance2+3, alloc4);
    std::for_each(mapInstanceFromArr2.begin(), mapInstanceFromArr2.end(), print<std::string, int>);
    std::cout << std::endl;
};

int main()
{
    mapInitializationDefaultConstructor();
    mapInitializationComparatorAndAllocatorConstructor();
    mapInitializationRangeConstructor();
    mapInitializationRangeConstructorWithComparatorAndAllocator();
    mapInitializationCopyConstructor();
    mapInitializationMoveConstructor();
    mapInitializationInitializerListConstructor();
    mapInitializationAllocatorExtendedDefaultConstructor();
    mapInitializationAllocatorExtendedCopyConstructor();
    mapInitializationAllocatorExtendedMoveConstructor();
    mapInitializationAllocatorExtendedInitializerListConstructor();
    mapInitializationAllocatorExtendedRangeConstructor();

    return 0;
}
