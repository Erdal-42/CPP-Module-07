/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak@student.42.org.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 02:41    by ekocak            #+#    #+#             */
/*   Updated: 2023/08/19 02:41    by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>


template <typename T>
void    progress(T &);
template <typename T>
void    regress(T &);


/**
 * @brief Applies a given function to each element of an array.
 *
 * This template function iterates over an array and applies a provided 
 * function to each element.
 *
 * @tparam T The type of the elements in the array.
 * @param array Pointer to the first element of the array.
 * @param size The number of elements in the array.
 * @param function A function pointer to a function that takes a reference 
 * to an element of type T and returns void.
 */
template <typename T>
void    iter(T *array, int size, void (*function)(T&))
{
    for (int i = 0; i < size; i ++)
    {
        function(array[i]);
    }
}


#endif
