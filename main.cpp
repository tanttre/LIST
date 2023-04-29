#include "includes.h"
#include "my_list.h"

int main()
{
    list<int> lst;

    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(22); 

    std::cout << lst.GetSize() << std::endl;
    std::cout << lst[2] << std::endl;

    int16_t N = 10;
    for (int32_t i = 0; i < N; ++i)
        lst.push_back(rand() % 256 + 10);

    for (int32_t index = 0; index < lst.GetSize(); ++index)
        std::cout << lst[index];

    std::cout << std::endl << lst.GetSize() << std::endl;
    
    return 0;
}
