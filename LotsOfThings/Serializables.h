#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <array>

template< typename T>
class SPrimitive
{
public:
	T value;
	std::string name;

	SPrimitive( T value, const char* name )
	{
		this->value = value;
		this->name = name;
	}

	SPrimitive& operator=( const T& other )
	{
		value = other;
		return *this;
	}

	bool evaluate( const std::string& token, std::fstream& stream )
	{
		if( token == name )
		{
			stream >> value;
			return true;
		}
		return false;
	}
};

template< typename T, std::size_t L>
class SPrimitiveArray
{
public:
	std::array<T,L> values;
	std::string name;

	SPrimitiveArray( const std::array<T, L>& values, const char* name )
	{
		this->values = values;
		this->name = name;
	}

	SPrimitiveArray& operator=( const std::array<T, L>& other )
	{
		this->values = other;
		return *this;
	}

	bool evaluate( const std::string& token, std::fstream& stream )
	{
		if( token == name )
		{
			for( int i = 0; i < L; i++ )
			{
				stream >> values[i];
			}
			return true;
		}
		return false;
	}
};