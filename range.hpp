#pragma once
#include <iostream>

namespace itertools{
template<typename T>
class range {
private:
   const T x;
   const T y;


public:
    range(const T& i, const T& j) : x(i), y(j) {}

class iterator {

	private:
		T m_pointer;

	public:
//*
        iterator(const T& ptr)
	    {
           m_pointer=ptr;
 		 //cout << "**this=" << *(*this) << endl;
		}

		T& operator*()  {
			return m_pointer;
		}

		iterator& operator++() {
			m_pointer++;
			return *this;
		}

	 	const iterator operator++(int) {
			iterator tmp= *this;
			m_pointer++;
			return tmp;
		}

		bool operator==(const iterator& rhs)  {
			return m_pointer == rhs.m_pointer;
		}

		bool operator!=(const iterator& rhs) {
			return m_pointer != rhs.m_pointer;
		}
	};  // END OF CLASS ITERATOR

public:
    //iterator begin() const{
		auto begin() const {
			//cout << "x=" << x << endl;
		auto result= iterator(x);
		//cout << "result=" << *result << endl;
		return result;
	}

	//iterator end() const{
		auto end()const {
		return iterator(y);
	}

};

    // template<typename T>rangeC<T> range(T a, T b) {
    //     return rangeC<T>(a, b);

    // }
} 
