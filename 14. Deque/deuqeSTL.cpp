
#include <iostream>
#include <deque>

int main()
{
    std::deque<int> myDeque;

    myDeque.push_back(10);
    myDeque.push_front(20);
    myDeque.push_back(30);

    std::cout << "Front: " << myDeque.front() << std::endl;
    std::cout << "Back: " << myDeque.back() << std::endl;
    std::cout << "Size: " << myDeque.size() << std::endl;

    myDeque.pop_front();

    std::cout << "Front after pop: " << myDeque.front() << std::endl;
    std::cout << "Size after pop: " << myDeque.size() << std::endl;

    while (!myDeque.empty())
    {
        std::cout << myDeque.front() << " ";
        myDeque.pop_front();
    }

    return 0;
}
