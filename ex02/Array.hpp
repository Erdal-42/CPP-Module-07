/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:08:00 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/20 17:08:46 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <string>

int COMMENT=1;


template <typename T>


/**
 * @brief A template class for a dynamically allocated array.
 *
 * This class provides a template for creating and managing a dynamically allocated array.
 * It includes various constructors, a destructor, and methods for accessing and modifying the array.
 */
class Array
{
    private:
        T       *_data;
        unsigned _size;
    public:

        /**
        * @brief Default constructor for the Array class.
        *
        * This constructor initializes the Array with a size of 0 and sets the data pointer to NULL.
        * It also prints a message if the COMMENT macro is defined.
        */
                Array(): _data(NULL), _size(0)
        {
            if (COMMENT)
            {
                std::cout << "Default constructor has constructed an instance of class Array." << std::endl; 
            }
        }

        /**
        * @brief Parameterized constructor for the Array class.
        *
        * This constructor initializes the Array with a specified size and allocates memory for the elements.
        * It also prints a message if the COMMENT macro is defined.
        *
        * @param n The number of elements to allocate for the Array.
        */
        Array<T>(unsigned n)
        {
            _data = new T[n];
            _size = n;
            if (COMMENT)
            {
                std::cout << "Parametized constructor has constructed an instance of class Array with " 
                          << n << " elements." << std::endl; 
            }
        }

        /**
        * @brief Destructor for the Array class.
        *
        * This destructor frees the allocated memory for the Array elements.
        * It also prints a message if the COMMENT macro is defined.
        */
        ~Array() 
        {
            if (COMMENT)
            {
                std::cout << "Deleting Array\t" << *this << std::endl; 
            }
            delete [] _data;
        };

        /**
        * @brief Copy constructor for the Array class.
        *
        * This constructor creates a new Array as a copy of an existing Array.
        * It also prints a message if the COMMENT macro is defined.
        *
        * @param other The Array to copy from.
        */
        Array(const Array& other)
        {
            this->_data = new T[other._size];
            for (unsigned i = 0; i < other._size; i ++)
                _data[i] = other._data[i];
            this->_size = other._size;
            if (COMMENT)
            {
                std::cout << "Copy constructed an instance of class Array\t" << *this << std::endl; 
            }
        }

        /**
        * @brief Assignment operator for the Array class.
        *
        * This operator assigns the contents of one Array to another.
        * It also prints a message if the COMMENT macro is defined.
        *
        * @param other The Array to assign from.
        * @return A reference to the assigned Array.
        */
        Array& operator=(const Array &other)
        {
            if (this != &other)
            {
                delete [] _data;
                this->_data = new T[other._size];
                for (unsigned i = 0; i < other._size; i ++)
                    _data[i] = other._data[i];
                this->_size = other._size;
            }
            if (COMMENT)
            {
                std::cout << "Assigned Array\t" << *this << std::endl; 
            }
            return (*this);
        }

        /**
        * @brief Subscript operator for the Array class.
        *
        * This operator provides access to the elements of the Array.
        * It throws an exception if the index is out of bounds.
        *
        * @param index The index of the element to access.
        * @return A reference to the element at the specified index.
        * @throws OutOfBoundsException if the index is out of bounds.
        */
        T& operator[](unsigned index)
        {
            if (index >= _size)
                throw (OutOfBoundsException());
            return (_data[index]);
        }

        /**
        * @brief Gets the underlying array.
        *
        * This method returns a pointer to the underlying array.
        *
        * @return A pointer to the underlying array.
        */
        T *getArray() const
        {
            return  (_data);
        }

        /**
        * @brief Sets the underlying array.
        *
        * This method sets the underlying array to a new array of specified size.
        *
        * @param theData A pointer to the new array.
        * @param theSize The size of the new array.
        */
        void setArray(T *theData, unsigned theSize)
        {    
            delete [] _data;
            _data = new T[_size];
            for (unsigned i = 0; i < _size && i < theSize; i ++)
            {
                _data[i] = theData[i];
            }
        }


        /**
        * @brief Gets the size of the Array.
        *
        * This method returns the number of elements in the Array.
        *
        * @return The number of elements in the Array.
        */
        unsigned size() const
        {
            return (_size);
        }

        /**
        * @brief Exception class for out of bounds access.
        *
        * This class represents an exception that is thrown when an attempt is made to access an element
        * outside the bounds of the Array.
        */
        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Index is out of bounds.");
                }
        };
};

/**
 * @brief Overloads the stream insertion operator for the Array class.
 *
 * This function overloads the stream insertion operator to allow printing 
 * the elements of the Array in a comma-separated format enclosed in curly braces.
 *
 * @tparam T The type of the elements in the Array.
 * @param os The output stream to which the Array will be printed.
 * @param obj The Array object to be printed.
 * @return A reference to the output stream.
 */
template <typename T>
std::ostream &	operator<<(std::ostream &os, Array<T> &obj) 
{
    os << "{";
    for (unsigned int i = 0; i < obj.size(); ++i) {
        os << obj[i];
        if (i != obj.size() - 1)
            os << ", ";    
    }
    os << "}";
    return (os);
}
