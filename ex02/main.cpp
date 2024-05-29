/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:08    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/22 18:08    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/**
 * @brief The main function demonstrating the usage of the Array class.
 *
 * This function performs various operations on instances of the Array class,
 * including construction, data recording, copying, assignment, indexing, exception handling, 
 * and destruction. It demonstrates the default constructor, parameterized constructor,
 * copy constructor, assignment operator, and destructor, as well as legitimate 
 * and illegitimate indexing.
 *
 * @return Returns 0 upon successful completion.
 */
int main()
{
    int int_data[4] = {1, 2, 3, 4};
    int size_int_data = sizeof(int_data) / sizeof(int_data[0]);
    
    char char_data[4] = {'a', 'b', 'c', 'd'};
    int size_char_data = sizeof(char_data) / sizeof(char_data[0]);
    
    std::string string_data[4] = {"Istanbul", "Ankara", "Izmir", "Denizli"};
    int size_string_data = sizeof(string_data) / sizeof(string_data[0]);

    //Default Constructor
    std::cout << "=======DEFAULT CONSTRUCTOR (2 INSTANCES)=======" << std::endl; 
    Array<std::string> stringArray1;

    //Parametized Constructor
    std::cout << "=======PARAMETIZED CONSTRUCTOR (3 INSTANCES)=======" << std::endl; 
    Array<char> *charArray2 = new Array<char>(4);
    Array<int> *intArray1 = new Array<int>(4);
    Array<std::string> *stringArray2 = new Array<std::string>(4);

    //Returning sizes
    std::cout << "=======ARRAY SIZES=======" << std::endl; 
    std::cout << "EMPTY CASES (1 INSTANCE)" << std::endl;
    std::cout << "Size for stringArray1\t:" << stringArray1.size() << std::endl;

    //recording data into arrays.
    std::cout << "=======RECORDING DATA INTO ARRAY(3 INSTANCES)=======" << std::endl;
    std::cout << "INT ARRAY" << std::endl;
    intArray1->setArray(int_data, size_int_data);
    std::cout << "Size for intArray1\t:" << intArray1->size() << std::endl;
    
    std::cout << "CHAR ARRAY" << std::endl;
    charArray2->setArray(char_data, size_char_data);
    std::cout << "Size for charArray2\t:" << charArray2->size() << std::endl;
    
    std::cout << "STRING ARRAY" << std::endl;
    stringArray2->setArray(string_data, size_string_data);
    std::cout << "Size for stringArray2\t:" << stringArray2->size() << std::endl;

    //copy constructing
    std::cout << "=======COPY CONSTRUCTING (3 INSTANCES)=======" << std::endl;
    std::cout << "INT ARRAY" << std::endl; 
    Array<int> intArray2(*intArray1);
    std::cout << "CHAR ARRAY" << std::endl;
    Array<char> charArray1(*charArray2);

    //Assignment
    std::cout << "=======ASSIGNMENT (1 INSTANCE)=======" << std::endl;
    std::cout << "STRING ARRAY" << std::endl;
    stringArray1 = *stringArray2;

    //Indexing and Excepti*ons
    std::cout << "=======LEGITIMATE INDEXING (Index 0) (3 INSTANCES)=======" << std::endl;
    std::cout << "INT ARRAY" << std::endl;
    std::cout << intArray2[0] << std::endl;
    std::cout << "CHAR ARRAY" << std::endl;
    std::cout << charArray1[0] << std::endl;
    std::cout << "STRING ARRAY" << std::endl;
    std::cout << stringArray1[0] << std::endl;
    std::cout << "=======ILLEGITIMATE INDEXING (Index 0) (3 INSTANCES)=======" << std::endl;
    std::cout << "INT ARRAY" << std::endl;
    try
    {
        std::cout << intArray2[4] << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "CHAR ARRAY" << std::endl;
    try
    {
        std::cout << charArray1[5] << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "STRING ARRAY" << std::endl;
    try
    {
        std::cout << stringArray1[-1] << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=======DESTRUCTOR (3 DEEP INSTANCES)=======" << std::endl;

    delete intArray1;
    delete charArray2;
    delete stringArray2;
    std::cout << "=======DESTRUCTOR (3 LOCAL INSTANCES)=======" << std::endl;
    
    return (0);
}
