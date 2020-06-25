#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"

using namespace std;

class kiwi {
public:

	kiwi(); //default constructor 
	void getMatrix(string filename);
	void outputMatrix(string outfile);
	void checkripeness();
	void updateArray();



private:
	int ripe = 0; //ripe per row 
	int rotten = 0;

	int row;

	int totalRipe = 0;
	int totalRotten = 0;

	int day=0;
	int count = 0; //to save the dimension of the matrix from file 
	int** myArray; // creating a 2d dynamic array to store the kiwi array
};

int main(int argc, char * argv[])
{

	ArgumentManager am(argc, argv);
	const string in = am.get("input");
	const string out = am.get("output");

	/*string in = "input2.txt";
	string out = "output.txt";*/

	kiwi object;
	object.getMatrix(in);

	object.checkripeness(); //day 0
	object.checkripeness(); //day 1
	object.checkripeness(); //day 2
	object.checkripeness(); //day 3
	object.checkripeness(); //day 4
	object.checkripeness(); //day 5
	object.checkripeness(); //day 6
	//object.checkripeness(); //day 7


	object.outputMatrix(out);

	system("pause");
	return 0;
}