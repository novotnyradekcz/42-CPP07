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

#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "=== Test 1: Empty array ===\n";
	Array<int> emptyArray;
	std::cout << "Size: " << emptyArray.size() << std::endl;
	
	std::cout << "\n=== Test 2: Int array with size ===\n";
	Array<int> intArray(5);
	std::cout << "Size: " << intArray.size() << std::endl;
	std::cout << "Default values: ";
	for (size_t i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	
	std::cout << "\n=== Test 3: Modify array ===\n";
	for (size_t i = 0; i < intArray.size(); i++)
		intArray[i] = i * 10;
	std::cout << "Modified values: ";
	for (size_t i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	
	std::cout << "\n=== Test 4: Copy constructor ===\n";
	Array<int> copyArray(intArray);
	std::cout << "Copy size: " << copyArray.size() << std::endl;
	std::cout << "Copy values: ";
	for (size_t i = 0; i < copyArray.size(); i++)
		std::cout << copyArray[i] << " ";
	std::cout << std::endl;
	
	std::cout << "\n=== Test 5: Modify original after copy ===\n";
	intArray[0] = 999;
	std::cout << "Original[0]: " << intArray[0] << std::endl;
	std::cout << "Copy[0]: " << copyArray[0] << std::endl;
	
	std::cout << "\n=== Test 6: Assignment operator ===\n";
	Array<int> assignArray;
	assignArray = intArray;
	std::cout << "Assigned size: " << assignArray.size() << std::endl;
	std::cout << "Assigned values: ";
	for (size_t i = 0; i < assignArray.size(); i++)
		std::cout << assignArray[i] << " ";
	std::cout << std::endl;
	
	std::cout << "\n=== Test 7: String array ===\n";
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	std::cout << "String array: ";
	for (size_t i = 0; i < strArray.size(); i++)
		std::cout << strArray[i] << " ";
	std::cout << std::endl;
	
	std::cout << "\n=== Test 8: Out of bounds exception ===\n";
	try
	{
		std::cout << "Trying to access index 10...\n";
		std::cout << intArray[10] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 9: Const array ===\n";
	const Array<int> constArray(intArray);
	std::cout << "Const array[0]: " << constArray[0] << std::endl;
	
	return 0;
}
