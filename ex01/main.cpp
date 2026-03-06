/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:29:55 by rnovotny          #+#    #+#             */
/*   Updated: 2026/03/06 22:26:17 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

// Test function templates
template <typename T>
void printElement(T const &element)
{
	std::cout << element << " ";
}

template <typename T>
void increment(T &element)
{
	element++;
}

void toUpperCase(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

int main(void)
{
	std::cout << "=== Test 1: Int array with const function ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Original: ";
	::iter(intArray, 5, printElement<int>);
	std::cout << std::endl;
	
	std::cout << "=== Test 2: Int array with non-const function ===" << std::endl;
	::iter(intArray, 5, increment<int>);
	std::cout << "After increment: ";
	::iter(intArray, 5, printElement<int>);
	std::cout << std::endl;
	
	std::cout << "=== Test 3: String array ===" << std::endl;
	std::string strArray[] = {"Hello", "World", "Templates", "Are", "Cool"};
	::iter(strArray, 5, printElement<std::string>);
	std::cout << std::endl;
	
	std::cout << "=== Test 4: Double array ===" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;
	
	std::cout << "=== Test 5: Char array with modification ===" << std::endl;
	char charArray[] = {'h', 'e', 'l', 'l', 'o'};
	std::cout << "Original: ";
	::iter(charArray, 5, printElement<char>);
	std::cout << std::endl;
	::iter(charArray, 5, toUpperCase);
	std::cout << "After toUpperCase: ";
	::iter(charArray, 5, printElement<char>);
	std::cout << std::endl;
	
	return 0;
}