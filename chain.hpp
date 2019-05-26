
#include <iostream>
//#include "range.hpp"
#include <bits/stdc++.h>
//using namespace std;
namespace itertools {

    //using namespace std;

    template<typename T, typename U>
    class chain {
        const T x;
        const U y;
    public:
        chain(const T& a, const  U& b) : x(a), y(b) {}
 
        chain(){

        }

        class iterator {
            decltype(x.begin()) xStart;
            decltype(x.end()) xEnd;
            decltype(y.begin()) yStart;
            decltype(y.end()) yEnd;

        public:
            iterator(const T& xx, const U& yy) : xStart(xx.begin()),xEnd(xx.end()),yStart(yy.begin()),yEnd(yy.end()) 
            {
                //std::cout<<"xStart="<<*xStart<<endl;
                //std::cout<<"yStart="<<*yStart<<endl;
            }

            iterator(const T& xx, const U& yy, bool isEnd) : xStart(xx.end()),xEnd(xx.end()),yStart(yy.end()),yEnd(yy.end()) {}

            iterator(){

            }

            auto operator*()  {
                if(xStart!=xEnd)
                    return *xStart;
                else {
                    //std::cout<<"star"<<*yStart<<endl;
                    return *yStart;
                }
            }

            iterator& operator++() {
                if (xEnd != xStart)
                    ++xStart;
                else
                    ++yStart;
                return *this;
            }

            bool operator!=(const iterator &other)  {
                return ((xStart != other.xStart)||(yStart != other.yStart));
            }

//            }
        };

        // begin() {
            iterator begin()const {
            return iterator{x, y};
        }

        //iterator end() {
            iterator end()const {
            return iterator{x, y, false};
        }

    };

//     template<typename T, typename U>chainC<T,U> chain(T x, U y) {
//         return chainC<T,U>{x, y};

//     }
 }
