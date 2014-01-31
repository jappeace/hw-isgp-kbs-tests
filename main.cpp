/* 
 * File:   main.cpp
 * Author: jappie
 *
 * Created on January 31, 2014, 9:10 AM
 */

#include <cstdlib>
#include <iostream>
#include "Grid.h"
using namespace std;

void PrintLine(int stars){
	for(int i = 0; i < stars; i++){
		cout << "*" ;
		for(int j = 0; j < i; j++){
			cout << "**";
		}
		cout << endl;
	}
}
/*
 * 
 */
int main(int argc, char** argv) {
	string s;
	string p;
	for(char i = 33; i < 127; i++){
		s += i;
	}
	for(char i = 33; i < 127; i++){
		p += i;
	}
	void (*func)(int) = PrintLine;
	func(30);
	s.append(p);

	cout << s;
	
#ifdef poep
	for(int i = 0; i < argc; i++){
		cout << i << " " << argv[i] << endl;
	}
	PrintLine(50);
	char* c = new char[5];
	cin >> c;
	cout << c;
	
	return 1;  
	
#endif
	
}

