/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:41    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/19 02:41    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

#define SIZE 3

/**
 * @brief Increments the given parameter by 1.
 *
 * This template function increments the given parameter by 1.
 *
 * @tparam T The type of the parameter. The type T must support the += operator.
 * @param param A reference to the parameter to be incremented.
 */
template <typename T>
void    advance(T& param)
{
    param += 1;
}

/**
 * @brief Decrements the given parameter by 1.
 *
 * This template function decrements the given parameter by 1.
 *
 * @tparam T The type of the parameter. The type T must support the -= operator.
 * @param param A reference to the parameter to be decremented.
 */
template <typename T>
void    retreat(T& param)
{
    param -= 1;
}

/**
 * @brief Prints the elements of an array.
 *
 * This template function prints the elements of an array in a comma-separated 
 * format enclosed in curly braces.
 *
 * @tparam T The type of the elements in the array.
 * @param array Pointer to the first element of the array.
 * @param size The number of elements in the array.
 */
template <typename T>
void    printArray(T *array, int size)
{
    std::cout << "{";
    for (int i = 0; i < size; i ++)
    {
        std::cout << array[i];
        if (i != size - 1)
            std::cout << ", ";
    }
    std::cout << "}";
}

/**
 * @brief The main function demonstrating the usage of iter, advance, retreat, and printArray functions.
 *
 * This function tests the iter function with arrays of different types (int, double, char)
 * and applies the advance and retreat functions to each element of the arrays. It prints
 * the arrays before and after applying the functions to show the results.
 *
 * @return int Returns 0 upon successful completion.
 */
int main()
{
    std::cout << std::endl;
    std::cout << "=======TESTING THE ITER FUNCTION=======" << std::endl;
    std::cout << std::endl;
    int arrayInt[SIZE] = {1, 2, 3};
    printArray(arrayInt, SIZE);       
    std::cout << "\tFunction: progress_1\n";
    iter(arrayInt, SIZE, &advance);
    printArray(arrayInt, SIZE);
    std::cout << std::endl << std::endl;

    double arrayDouble[SIZE] = {0.5, 1.5, 2.5};
    printArray(arrayDouble, SIZE); 
    std::cout << "\tFunction: progress_1\n";
    iter(arrayDouble, SIZE, &advance);
    printArray(arrayDouble, SIZE);
    std::cout << std::endl << std::endl;

    char arrayChar[3] = {'a', 'b', 'c'};
    printArray(arrayChar, SIZE);
    std::cout << "\tFunction: progress_1\n";
    iter(arrayChar, 3, &advance);
    printArray(arrayChar, SIZE);
    std::cout << std::endl << std::endl;

    printArray(arrayInt, SIZE);
    std::cout << "\tFunction: regress_1\n";
    iter(arrayInt, 3, &retreat);
    printArray(arrayInt, SIZE);
    std::cout << std::endl << std::endl;

    printArray(arrayDouble, SIZE);
    std::cout << "\tFunction: regress_1\n";
    iter(arrayDouble, SIZE, &retreat);
    printArray(arrayDouble, SIZE);
    std::cout << std::endl << std::endl;

    printArray(arrayChar, SIZE);
    std::cout << "\tFunction: regress_1\n";
    iter(arrayChar, SIZE, &retreat);
    printArray(arrayChar, SIZE);
    std::cout << std::endl;
    
    return (0);
}
