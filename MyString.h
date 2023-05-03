#pragma once
#include <iostream>

class MyString
{
private:
	size_t length;
	char* str;

public:

	MyString()
	{
		str = nullptr;
	}

	MyString(const char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];

		for (size_t i = 0; i < length; i++)
			this->str[i] = str[i];

		this->str[length] = '\0';
	}

	~MyString()
	{
		delete[] this->str;
	}


	MyString(const MyString& other)
	{
		this->length = other.length;
		this->str = new char[length + 1];

		for (size_t i = 0; i < length; i++)
			this->str[i] = other.str[i];

		this->str[length] = '\0';

	}


	MyString& operator =(const MyString& other)
	{
		if (this->str != nullptr)
			delete[] this->str;

		this->length = other.length;
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
			this->str[i] = other.str[i];

		this->str[length] = '\0';
		return *this;

	}

	MyString operator +(const MyString& other)
	{
		if (this->str == nullptr)
		{
			this->length = other.length;
			str = new char[this->length + 1];

			for (size_t i = 0; i < this->length; i++)
				str[i] = other.str[i];

			str[this->length] = '\0';
			return *this;
		}

		size_t length_this = this->length;
		this->length += other.length;
		char* temp = new char[length_this + 1];

		for (int i = 0; i < length_this; i++)
			temp[i] = this->str[i];

		temp[length_this] = '\0';
		delete[] this->str;
		this->str = new char[length + 1];

		for (size_t i = 0; i < length_this; i++)
			this->str[i] = temp[i];

		delete[] temp;

		for (size_t i = length_this, j = 0; i < this->length; i++, j++)
			this->str[i] = other.str[j];

		str[length] = '\0';
		return *this;

	}

	MyString operator +=(const MyString& other)
	{	
		return this->operator+(other);
	}

	bool operator ==(const MyString& other)
	{
		if (this->length != other.length)
			return false;

		for (size_t i = 0; i < length; i++)
			if (this->str[i] != other.str[i])
				return false;

		return true;
	}


	bool operator !=(const MyString& other)
	{
		if (this->length != other.length)
			return true;

		for (size_t i = 0; i < length; i++)
			if (this->str[i] != other.str[i])
				return true;

		return false;
	}

	size_t size()
	{
		return length;
	}

	void append(const char* str)
	{
		if (this->str == nullptr)
		{
			this->length = strlen(str);
			this->str = new char[length + 1];
			for (size_t i = 0; i < length; i++)
				this->str[i] = str[i];
			this->str[length] = '\0';
			return;
		}
		size_t length_this = length;
		size_t length_str = strlen(str);
		this->length += length_str;

		char* temp = new char [length_this+1];
		for (size_t i = 0; i < length_this; i++)
			temp[i] = this->str[i];
		temp[length_this] = '\0';

		if (this->str != nullptr)
			delete[] this->str;
		this->str = new char [length+1];

		for (size_t i = 0; i < length_this; i++)
			this->str[i] = temp[i];

		delete[] temp;

		for (size_t i = length_this,j = 0; i < length; i++,j++)
			this->str[i] = str[j];

		this->str[length] = '\0';

	}

	friend std::ostream& operator <<(std::ostream& os, const MyString& ms);

};

std::ostream& operator <<(std::ostream& os, const MyString& ms)
{
	os << ms.str;
	return os;
}