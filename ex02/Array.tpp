/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:33:26 by rnovotny          #+#    #+#             */
/*   Updated: 2026/03/06 22:26:17 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array &other) : _array(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		if (_size > 0)
		{
			_array = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
		else
			_array = NULL;
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
const T &Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
size_t Array<T>::size() const
{
	return _size;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array index out of bounds";
}

#endif
