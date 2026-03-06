/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:33:12 by rnovotny          #+#    #+#             */
/*   Updated: 2026/03/06 22:26:17 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstddef>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T &operator[](size_t index);
		const T &operator[](size_t index) const;
		size_t size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		T *_array;
		size_t _size;
};

# include "Array.tpp"

#endif
