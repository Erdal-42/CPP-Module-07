/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekocak <ekocak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:51:00 by ekocak            #+#    #+#             */
/*   Updated: 2023/09/20 16:50:35 by ekocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/** @brief Swaps the values of two variables.

  This function takes two references to variables of type `T` and swaps their values.
  It achieves this by using a temporary variable to hold the value of one variable
  while the other is assigned a new value. Finally, the temporary variable's value
  is assigned to the remaining variable, effectively completing the swap.

  @param[in,out] a1 The first variable to be swapped.
  @param[in,out] a2 The second variable to be swapped.
*/
template <typename T>
void    swap(T &a1, T &a2)
{
    T temp;

    temp = a1;
    a1 = a2;
    a2 = temp; 
}

/** @brief Returns the minimum value of two arguments.

  This function takes two arguments of type `T` and compares them. 
  If `a1` is less than `a2`, it returns `a1`. Otherwise, it returns `a2`.

  @param a1 The first value to compare.
  @param a2 The second value to compare.
  @return The minimum value of `a1` and `a2`.
*/
template <typename T>
T   min(T a1, T a2)
{
    if (a1 < a2)
        return (a1);
    return (a2);
}

/** @brief Returns the maximum value of two arguments.

  This function takes two arguments of type `T` and compares them. 
  If `a1` is greater than `a2`, it returns `a1`. Otherwise, it returns `a2`.

  @param a1 The first value to compare.
  @param a2 The second value to compare.
  @return The maximum value of `a1` and `a2`.
*/
template <typename T>
T   max(T a1, T a2)
{
    if (a1 > a2)
        return (a1);
    return (a2);
}