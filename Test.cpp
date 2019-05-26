/**
 * A demo program for containers
 * @author Dana Morhaim
 * @since  2019-04
 */


#include <iostream>
#include <string>
using namespace std;

#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace itertools;

template<typename Iterable>
string iterable_to_string(const Iterable& iterable) {
    ostringstream ostr;
    for (decltype(*iterable.begin()) i: iterable)
        ostr << i << ",";
    string str= ostr.str();
    return str.substr(0,str.size()-1);
}

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	int rand1=0, rand2=0, rand3, rand4;
	char c1,c2;
	double fraction;
	string str="",str2="";
	if (signal == 0) {
        
		////***********testing range************////
		testcase.setname("range test integers");
        for(uint i=0; i<50;++i)
        {
			rand1 =rand()%100;
			rand2 =rand1+rand()%5+1;
            for(uint i=rand1; i<rand2;++i)
				str=str+to_string(i)+",";
			str=str.substr(0,str.size()-1);
			testcase.CHECK_OUTPUT(iterable_to_string(range(rand1,rand2)), str);
			str="";
        }

		testcase.setname("range test double");
		testcase.CHECK_OUTPUT(iterable_to_string(range(3.5,6.5)), "3.5,4.5,5.5");
		testcase.CHECK_OUTPUT(iterable_to_string(range(23.7,25.7)), "23.7,24.7");
		testcase.CHECK_OUTPUT(iterable_to_string(range(399.3,401.3)), "399.3,400.3");


		testcase.setname("range test chars");
        for(uint i=0; i<50;++i)
        {
			c1 ='a'+rand()%21;
			c2 =rand1+rand()%5+1;
            for(uint i=rand1; i<rand2;++i)
				str=str+to_string(i)+",";
			str=str.substr(0,str.size()-1);
			testcase.CHECK_OUTPUT(iterable_to_string(range(rand1,rand2)), str);
			str="";
        }

		////***********testing chain************////
		
        testcase.setname("Test chain");
           testcase.CHECK_OUTPUT(iterable_to_string(chain(range(5,7),range(5,7))), "5,6,5,6");
           testcase.CHECK_OUTPUT(iterable_to_string(chain(range(1.2, 4.2),range(4.2, 6.2))), "1.2,2.2,3.2,4.2,5.2");
		   testcase.CHECK_OUTPUT(iterable_to_string(chain(range('b','d'),range('b','d'))), "b,c,b,c");
           testcase.CHECK_OUTPUT(iterable_to_string(chain(string("dana"), string("dana"))), "d,a,n,a,d,a,n,a");
		   testcase.CHECK_OUTPUT(iterable_to_string(chain(string("mor"), string("haim"))), "m,o,r,h,a,i,m");
		   testcase.CHECK_OUTPUT(iterable_to_string(chain(string("lin"), string("dan"))), "l,i,n,d,a,n");

		////***********testing zip************////
//
        testcase.setname("Test zip");
           testcase.CHECK_OUTPUT(iterable_to_string(zip(range(5,7),range(5,7))), "5,5,6,6");
           testcase.CHECK_OUTPUT(iterable_to_string(zip(range(1.2, 4.2),range(2.2, 5.2))), "1.2,2.2,2.2,3.2,3.2,4.2");
           testcase.CHECK_OUTPUT(iterable_to_string(zip(range('b','d'),range(5,7))), "b,5,c,6");
		   testcase.CHECK_OUTPUT(iterable_to_string(zip(range('b','d'),range(5,7))), "b,5,c,6");
		   testcase.CHECK_OUTPUT(iterable_to_string(zip(range('b','d'),range('b','d'))), "b,b,c,c");
           testcase.CHECK_OUTPUT(iterable_to_string(zip(string("dana"), string("dana"))), "d,d,a,a,n,n,a,a");
		   testcase.CHECK_OUTPUT(iterable_to_string(zip(string("mram"), string("ohim"))), "m,o,r,h,a,i,m,m");
		   testcase.CHECK_OUTPUT(iterable_to_string(zip(string("lin"), string("dan"))), "l,d,i,a,n,n");
		

		////***********testing product ************////
//
		std::ostringstream intP1,intP2, doubleP1, doubleP2, sdoubleP1, sdoubleP2, sintP1,sintP2, icharP1;
        for (auto p : product(range(21, 23), range(7, 9))) intP1 << p << " ";
		for (auto p : product(range(4, 8), range(5, 8))) intP2 << p << " ";
        for (auto p : product(range(4.5, 6.5), range(6.2, 8.2))) doubleP1 << p << " ";
		for (auto p : product(range('n', 'p'), range(3.3, 5.3))) sdoubleP1 << p << " ";
        for (auto p : product(range(3.5, 5.5), range(4.2, 6.2))) doubleP2 << p << " ";
		for (auto p : product(range('l', 'n'), range(3.3, 5.3))) sdoubleP2 << p << " ";
		for (auto p : product(range('b', 'd'), range(5, 8))) sintP1 << p << " ";
		for (auto p : product(range('g', 'i'), range(3, 5))) sintP2 << p << " ";
		for (auto p : product(range(25, 27), range('b', 'd')))icharP1 << p << " ";

        testcase.setname("Test product")
            .CHECK_OUTPUT(intP1.str(), "21,7 21,8 22,7 22,8 ")
			.CHECK_OUTPUT(intP2.str(), "4,5 4,6 4,7 5,5 5,6 5,7 6,5 6,6 6,7 7,5 7,6 7,7 ")
            .CHECK_OUTPUT(doubleP1.str(), "4.5,6.2 4.5,7.2 5.5,6.2 5.5,7.2 ")
			.CHECK_OUTPUT(doubleP2.str(), "3.5,4.2 3.5,5.2 4.5,4.2 4.5,5.2 ")
            .CHECK_OUTPUT(sdoubleP1.str(), "n,3.3 n,4.3 o,3.3 o,4.3 ")
			.CHECK_OUTPUT(sdoubleP2.str(), "l,3.3 l,4.3 m,3.3 m,4.3 ")
            .CHECK_OUTPUT(sintP1.str(), "b,5 b,6 b,7 c,5 c,6 c,7 ")
			.CHECK_OUTPUT(sintP2.str(), "g,3 g,4 h,3 h,4 ")
			.CHECK_OUTPUT(icharP1.str(), "25,b 25,c 26,b 26,c ");

		////***********testing powerset ************////
//
       std::ostringstream stringPs1, stringPs2, intPs1,intPs2,  doublePowerset, chainPowerset_1,charPowerset;

        for (auto s : powerset(string("dan")))stringPs1 << s << " ";
		for (auto s : powerset(string("lin")))stringPs2 << s << " ";
		for (auto s : powerset(range(5, 7)))intPs1 << s << " ";
		for (auto s : powerset(range(22, 24)))intPs2 << s << " ";
        for(auto s : powerset(range(6.5,7.5)))doublePowerset<<s<<" ";
        for(auto s : powerset(range('b','d')))charPowerset<<s<<" ";    
        for(auto s : powerset(chain(range('g','i'),range('b','d'))))chainPowerset_1<<s<<" "; 

        testcase.setname("Test powerset")
            .CHECK_OUTPUT(stringPs1.str(), "{} {d} {a} {d,a} {n} {d,n} {a,n} {d,a,n} ")
			.CHECK_OUTPUT(stringPs2.str(), "{} {l} {i} {l,i} {n} {l,n} {i,n} {l,i,n} ")
            .CHECK_OUTPUT(intPs1.str(), "{} {5} {6} {5,6} ")
			.CHECK_OUTPUT(intPs2.str(), "{} {22} {23} {22,23} ")
            .CHECK_OUTPUT(doublePowerset.str(), "{} {6.5} ")
            .CHECK_OUTPUT(chainPowerset_1.str(), "{} {g} {h} {g,h} {b} {g,b} {h,b} {g,h,b} {c} {g,c} {h,c} {g,h,c} {b,c} {g,b,c} {h,b,c} {g,h,b,c} ")
			.CHECK_OUTPUT(charPowerset.str(), "{} {b} {c} {b,c} ");


        
			
		






    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
