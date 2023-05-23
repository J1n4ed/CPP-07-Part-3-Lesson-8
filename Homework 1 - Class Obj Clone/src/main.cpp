#include "..\headers\tridiagonal_matrix.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();

    std::cout << "\nTest:\n\n";

    std::cout << "m_down: ";
    for (auto& elem : matrix_clone->m_down) 
    {
        std::cout << elem << ' ';
    } std::cout << '\n';

    std::cout << "m_middle: ";
    for (auto& elem : matrix_clone->m_middle)
    {
        std::cout << elem << ' ';
    } std::cout << '\n';

    std::cout << "m_upper: ";
    for (auto& elem : matrix_clone->m_upper)
    {
        std::cout << elem << ' ';
    } std::cout << '\n';

    return 0;
}