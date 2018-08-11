#include <iostream>
int main()
{
    int value = 2;
    int power = 10;
    int result = 1;
    for (int cnt = 0; cnt !=power; ++cnt)
        result *= value;
    std::cout << value
              << " raised to the power of "
              << power << ": \t"
              << result << std::endl;
    return 0;
}
