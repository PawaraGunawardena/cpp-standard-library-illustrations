#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
void printStack(std::stack<int, T>& stackInstance)
{
    if(stackInstance.empty())
    {
        return;
    }

    int top = stackInstance.top();
    std::cout << top << " ";

    stackInstance.pop();
    printStack(stackInstance);

    stackInstance.push(top);
};

void print (const int& value)
{
    std::cout << value << " ";
};

void stackInitializationDefaultConstructor()
{
    /**
     * stack()
    */

    std::cout << __func__ << std::endl;

    std::stack<int> stackInstance1;
    stackInstance1.push(5);
    stackInstance1.push(10);
    printStack(stackInstance1);
    std::cout << std::endl;

    std::stack<int>* pStackInstance = new std::stack<int>();
    pStackInstance->push(15);
    pStackInstance->push(20);
    printStack(*pStackInstance);
    std::cout << std::endl;

    std::stack<int, std::vector<int>> stackInstance2;
    stackInstance2.push(5);
    stackInstance2.push(10);
    printStack(stackInstance2);
    std::cout << std::endl;

    std::stack<int, std::list<int>> stackInstance3;
    stackInstance3.push(5);
    stackInstance3.push(10);
    printStack(stackInstance3);
    std::cout << std::endl;

    // deque is the default sequence container
    std::stack<int, std::deque<int>> stackInstance4;
    stackInstance4.push(5);
    stackInstance4.push(10);
    printStack(stackInstance4);
    std::cout << std::endl;
}

void stackInitializationInitializationConstructor()
{
    /**
     * explicit stack(const _Sequence& c)
    */

    std::cout << __func__ << std::endl;

    std::deque<int> dequeInstance1({10, 20, 30, 40, 50});
    std::stack<int> stackInstance1(dequeInstance1);
    std::cout << "Stack content: ";
    printStack(stackInstance1);
    std::cout << std::endl;
    std::cout << "Deque content: ";
    std::for_each(dequeInstance1.begin(), dequeInstance1.end(), print);
    std::cout << std::endl;

    std::vector<int> vectorInstance1({100, 200, 300, 400, 500});
    std::stack<int, std::vector<int>> stackInstance2(vectorInstance1);
    std::cout << "Stack content: ";
    printStack(stackInstance2);
    std::cout << std::endl;
    std::cout << "Vector content: ";
    std::for_each(vectorInstance1.begin(), vectorInstance1.end(), print);
    std::cout << std::endl;

    std::list<int> listInstance1({1000, 2000, 3000, 4000, 5000});
    std::stack<int, std::list<int>> stackInstance3(listInstance1);
    std::cout << "Stack content: ";
    printStack(stackInstance3);
    std::cout << std::endl;
    std::cout << "List content: ";
    std::for_each(listInstance1.begin(), listInstance1.end(), print);
    std::cout << std::endl;
}

void stackInitializationMoveInitializationConstructor()
{
    /**
     * explicit stack(_Sequence&& __c)
    */

    std::cout << __func__ << std::endl;

    std::deque<int> dequeInstance1({10, 20, 30, 40, 50});
    std::stack<int> stackInstance1(std::move(dequeInstance1));
    std::cout << "Stack content: ";
    printStack(stackInstance1);
    std::cout << std::endl;
    std::cout << "Deque content: ";
    std::for_each(dequeInstance1.begin(), dequeInstance1.end(), print);
    std::cout << std::endl;

    std::vector<int> vectorInstance1({100, 200, 300, 400, 500});
    std::stack<int, std::vector<int>> stackInstance2(std::move(vectorInstance1));
    std::cout << "Stack content: ";
    printStack(stackInstance2);
    std::cout << std::endl;
    std::cout << "Vector content: ";
    std::for_each(vectorInstance1.begin(), vectorInstance1.end(), print);
    std::cout << std::endl;

    std::list<int> listInstance1({1000, 2000, 3000, 4000, 5000});
    std::stack<int, std::list<int>> stackInstance3(std::move(listInstance1));
    std::cout << "Stack content: ";
    printStack(stackInstance3);
    std::cout << std::endl;
    std::cout << "List content: ";
    std::for_each(listInstance1.begin(), listInstance1.end(), print);
    std::cout << std::endl;
}

void stackInitializationAllocatorExtendedDefaultConstructor()
{
    /**
     * explicit stack(const Alloc& a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1;
    std::stack<int, std::vector<int, std::allocator<int>>> stackInstance1(alloc1);
    stackInstance1.push(5);
    stackInstance1.push(10);
    printStack(stackInstance1);
    std::cout << std::endl;

    std::allocator<int> alloc2;
    std::stack<int, std::list<int, std::allocator<int>>> stackInstance2(alloc2);
    stackInstance2.push(5);
    stackInstance2.push(10);
    printStack(stackInstance2);
    std::cout << std::endl;

    std::allocator<int> alloc3;
    std::stack<int, std::deque<int, std::allocator<int>>> stackInstance3(alloc2);
    stackInstance3.push(5);
    stackInstance3.push(10);
    printStack(stackInstance3);
    std::cout << std::endl;
}

void stackInitializationAllocatorExtendedInitializationConstructor()
{
    /**
     * stack(const _Sequence& __c, const _Alloc& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1, alloc2;
    std::deque<int, std::allocator<int>> dequeInstance1({10, 20, 30, 40, 50}, alloc1);
    std::stack<int, std::deque<int, std::allocator<int>>> stackInstance1(dequeInstance1, alloc2);
    std::cout << "Stack content: ";
    printStack(stackInstance1);
    std::cout << std::endl;
    std::cout << "Deque content: ";
    std::for_each(dequeInstance1.begin(), dequeInstance1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc3, alloc4;
    std::vector<int, std::allocator<int>> vectorInstance1({100, 200, 300, 400, 500}, alloc3);
    std::stack<int, std::vector<int, std::allocator<int>>> stackInstance2(vectorInstance1, alloc4);
    std::cout << "Stack content: ";
    printStack(stackInstance2);
    std::cout << std::endl;
    std::cout << "Vector content: ";
    std::for_each(vectorInstance1.begin(), vectorInstance1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc5, alloc6;
    std::list<int, std::allocator<int>> listInstance1({1000, 2000, 3000, 4000, 5000}, alloc5);
    std::stack<int, std::list<int, std::allocator<int>>> stackInstance3(listInstance1, alloc6);
    std::cout << "Stack content: ";
    printStack(stackInstance3);
    std::cout << std::endl;
    std::cout << "List content: ";
    std::for_each(listInstance1.begin(), listInstance1.end(), print);
    std::cout << std::endl;
}

void stackInitializationAllocatorExtendedMoveInitializationConstructor()
{
    /**
     * stack(_Sequence&& __c, const _Alloc& __a)
    */

    std::cout << __func__ << std::endl;

    std::allocator<int> alloc1, alloc2;
    std::deque<int, std::allocator<int>> dequeInstance1({10, 20, 30, 40, 50}, alloc1);
    std::stack<int, std::deque<int, std::allocator<int>>> stackInstance1(std::move(dequeInstance1), alloc2);
    std::cout << "Stack content: ";
    printStack(stackInstance1);
    std::cout << std::endl;
    std::cout << "Deque content: ";
    std::for_each(dequeInstance1.begin(), dequeInstance1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc3, alloc4;
    std::vector<int, std::allocator<int>> vectorInstance1({100, 200, 300, 400, 500}, alloc3);
    std::stack<int, std::vector<int, std::allocator<int>>> stackInstance2(std::move(vectorInstance1), alloc4);
    std::cout << "Stack content: ";
    printStack(stackInstance2);
    std::cout << std::endl;
    std::cout << "Vector content: ";
    std::for_each(vectorInstance1.begin(), vectorInstance1.end(), print);
    std::cout << std::endl;

    std::allocator<int> alloc5, alloc6;
    std::list<int, std::allocator<int>> listInstance1({1000, 2000, 3000, 4000, 5000}, alloc5);
    std::stack<int, std::list<int, std::allocator<int>>> stackInstance3(std::move(listInstance1), alloc6);
    std::cout << "Stack content: ";
    printStack(stackInstance3);
    std::cout << std::endl;
    std::cout << "List content: ";
    std::for_each(listInstance1.begin(), listInstance1.end(), print);
    std::cout << std::endl;
}

void stackInitializationCopyConstructor()
{
    /**
     * stack(const stack& __q, const _Alloc& __a)
    */

    std::cout << __func__ << std::endl;

    std::stack<int> originalStackInstance1;
    originalStackInstance1.push(5);
    originalStackInstance1.push(10);
    std::stack<int> copyStackInstance1(originalStackInstance1);
    std::cout << "Original stack content: ";
    printStack(originalStackInstance1);
    std::cout << std::endl;
    std::cout << "Copy stack content: ";
    printStack(copyStackInstance1);
    std::cout << std::endl;

    std::allocator<int> alloc1;
    std::stack<int, std::vector<int, std::allocator<int>>> originalStackInstance2(alloc1);
    originalStackInstance2.push(50);
    originalStackInstance2.push(100);
    std::stack<int, std::vector<int, std::allocator<int>>> copyStackInstance2(originalStackInstance2);
    std::cout << "Original stack content: ";
    printStack(originalStackInstance2);
    std::cout << std::endl;
    std::cout << "Copy stack content: ";
    printStack(copyStackInstance2);
    std::cout << std::endl;

    std::allocator<int> alloc2, alloc3;
    std::stack<int, std::vector<int, std::allocator<int>>> originalStackInstance3(alloc2);
    originalStackInstance3.push(500);
    originalStackInstance3.push(1000);
    std::stack<int, std::vector<int, std::allocator<int>>> copyStackInstance3(originalStackInstance3, alloc3);
    std::cout << "Original stack content: ";
    printStack(originalStackInstance3);
    std::cout << std::endl;
    std::cout << "Copy stack content: ";
    printStack(copyStackInstance3);
    std::cout << std::endl;
};
void stackInitializationMoveConstructor()
{
    /**
     * stack(stack&& __q, const _Alloc& __a)
    */

    std::cout << __func__ << std::endl;

    std::stack<int> originalStackInstance1;
    originalStackInstance1.push(5);
    originalStackInstance1.push(10);
    std::stack<int> moveStackInstance1(std::move(originalStackInstance1));
    std::cout << "Original stack content: ";
    printStack(originalStackInstance1);
    std::cout << std::endl;
    std::cout << "Move stack content: ";
    printStack(moveStackInstance1);
    std::cout << std::endl;

    std::allocator<int> alloc1;
    std::stack<int, std::vector<int, std::allocator<int>>> originalStackInstance2(alloc1);
    originalStackInstance2.push(50);
    originalStackInstance2.push(100);
    std::stack<int, std::vector<int, std::allocator<int>>> moveStackInstance2(std::move(originalStackInstance2));
    std::cout << "Original stack content: ";
    printStack(originalStackInstance2);
    std::cout << std::endl;
    std::cout << "Move stack content: ";
    printStack(moveStackInstance2);
    std::cout << std::endl;

    std::allocator<int> alloc2, alloc3;
    std::stack<int, std::vector<int, std::allocator<int>>> originalStackInstance3(alloc2);
    originalStackInstance3.push(500);
    originalStackInstance3.push(1000);
    std::stack<int, std::vector<int, std::allocator<int>>> moveStackInstance3(std::move(originalStackInstance3), alloc3);
    std::cout << "Original stack content: ";
    printStack(originalStackInstance3);
    std::cout << std::endl;
    std::cout << "Move stack content: ";
    printStack(moveStackInstance3);
    std::cout << std::endl;
};

int main()
{
    stackInitializationDefaultConstructor();
    stackInitializationInitializationConstructor();
    stackInitializationMoveInitializationConstructor();
    stackInitializationAllocatorExtendedDefaultConstructor();
    stackInitializationAllocatorExtendedInitializationConstructor();
    stackInitializationAllocatorExtendedMoveInitializationConstructor();
    stackInitializationCopyConstructor();
    stackInitializationMoveConstructor();

    return 0;
}
