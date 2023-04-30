#include "includes.h"
#include "my_list.h"

int main()
{
    list<int> lst;

    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(22); 

    std::cout << "size = " <<lst.size() << std::endl;
    std::cout << "lst[2] = " << lst[2] << std::endl;

    int16_t N = 10;
    for (int32_t i = 0; i < N; ++i)
        lst.push_back(rand() % 256 + 10);

    for (int32_t index = 0; index < lst.size(); ++index)
        std::cout << "lst[" << index << "] = " << lst[index];

    std::cout << std::endl << "size = " << lst.size() << std::endl;
    
    lst.pop_front();
    lst.clear();
    std::cout << "size = " << lst.size() << std::endl;

    return 0;
}
