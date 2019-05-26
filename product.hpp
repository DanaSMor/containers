
#include <iostream>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
namespace itertools {

    using namespace std;

    template<typename T, typename U>
    class product {
        const T x;
        const U y;
    public:
        product(const T& a, const  U& b) : x(a), y(b) {}
 
        product(){}

        class iterator {
            decltype(x.begin()) xStart;
            decltype(x.end()) xEnd;
            decltype(y.begin()) yStart;
            decltype(y.end()) yEnd;
            decltype(y.begin()) originalYstart;
            decltype(y.begin()) originalYend;


        public:
            
            iterator(const T& x, const U& y) : xStart(x.begin()),xEnd(x.end()),yStart(y.begin()),yEnd(y.end()),originalYstart(y.begin()),originalYend(y.end()) {}
            iterator(const T& x,  const U& y,bool isEnd) : xStart(x.end()),xEnd(x.end()),yStart(y.end()),yEnd(y.end()),originalYstart(y.begin()),originalYend(y.end()) {}
            iterator(){}

            auto operator*()  {
                return make_pair(*xStart,*yStart);
            }

            iterator& operator++() {
                ++yStart;
                if (yStart == originalYend)
                { 
                    ++xStart;
                    yStart = originalYstart;
                }
                   
                return *this;
            }

            bool operator!=(const iterator &other)  {
                return ((xStart != other.xStart)&&(yStart != other.yStart));
            
            }
            bool operator==(const iterator &other)  {
                return ((xStart == other.xStart)||(yStart == other.yStart));
            }
        };

        
            auto begin() const {
            return iterator(x, y);
        }

  
            auto end()const {
            return iterator(x, y, false);
        }

    };

    // template<typename T, typename U>productC<T,U> product(T x, U y) {
    //     return productC<T,U>(x, y);

    // }
}
