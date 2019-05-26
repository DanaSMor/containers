
#include <iostream>
//#include "range.hpp"
#include <utility>
#include <bits/stdc++.h>
using namespace std;
namespace itertools {

    
    template<typename T, typename U>
    class zip {
        const T x;
        const U y;
    public:
        zip(const T& a, const  U& b) : x(a), y(b) {}
 
        zip(){

        }

        class iterator {
            decltype(x.begin()) xStart;
            decltype(x.end()) xEnd;
            decltype(y.begin()) yStart;
            decltype(y.end()) yEnd;

        public:
            iterator(const T& x,const  U& y) : xStart(x.begin()),xEnd(x.end()),yStart(y.begin()),yEnd(y.end()) {}

            iterator(const T& x,const  U& y,bool isEnd) : xStart(x.end()),xEnd(x.end()),yStart(y.end()),yEnd(y.end()) {}

            iterator(){

            }

            auto operator*()  {
                    return make_pair(*xStart,*yStart);
            }

            iterator& operator++() {
                if (xEnd != xStart)
                    ++xStart;
                    ++yStart;
                return *this;
            }

            bool operator!=(const iterator &other)  {
                 return ((xStart != other.xStart)&&(yStart != other.yStart));
            }

//            
        };

        //iterator begin() {
            auto begin() const {
            return iterator(x, y);
        }

        //iterator end() {
            auto end()const {
            return iterator(x, y, false);
        }
        


    };



    // template<typename T, typename U>zipC<T,U> zip(T x, U y) {
    //     return zipC<T,U>(x, y);

    // }

        template<typename T, typename U> ostream &operator<<(ostream &output, const pair<T,U> &p) 
        {
            output << p.first << "," 
            << p.second;
            return output;
        }
}
