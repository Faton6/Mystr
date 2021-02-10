#include <iostream>
#include "Mystr.hpp"

int main()
{
	Mystr string1("Hello, ");
	Mystr string2("world!");
	Mystr string1_test = string1;
	Mystr res = string1 +string2;
	int size = res.Mystrlen(res);
	std::cout << res << '\n';
	bool omg_false = (string2 == string1);
	bool omg_true = (string1_test == string1);
	bool omg_false2 = (string1_test != string1);
	std::cout <<"false  == :\t" << omg_false << '\n';
	std::cout <<"true   == :\t" << omg_true <<'\n';
	std::cout <<"false2 != :\t" << omg_false2 << '\n';
	std::cout <<"true   != :\t"<< (string1!=string2)<<'\n';
	//std::cout << res << '\n';
	Mystr test;
	std::cin >> test;
	std::cout << test;
	return 0;
}
