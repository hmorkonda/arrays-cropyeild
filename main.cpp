#include "Header.h"
#include <sstream>
#include <string>
#include <iostream>



ifstream readfile;

kiwi::kiwi() {
	day = 0;
}
void kiwi::getMatrix(string filename) {

	readfile.open(filename); //opening the file 

	if (readfile.is_open()) {
		cout << "open" << endl;
		string line;
		getline(readfile, line);//to get the first line
		istringstream iss(line);//converting first line from string to int 
		iss >> count; //saving the int 
		cout << count << "= dimension of the array" << endl;

		myArray = new int*[count];
		for (int i = 0; i < count; i++) { //already created myArray in header file
			myArray[i] = new int[count];
		}
	
		while (!readfile.eof()) {
			for (int i = 0; i < count; i++) { // readfile into the array
				for (int j = 0; j < count; j++) {
					readfile >> myArray[i][j]; //adding all the elements from the input file into my array
				}
			}
		}

		cout << endl << endl;
		for (int i = 0; i < count; i++) { //prints out array 
			for (int j = 0; j < count; j++) {
				cout << myArray[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
void kiwi::checkripeness() {
	//getMatrix(in);
	int half;
	half = count/2;

	cout << "this is 50% of row: "<< half << endl;

	if (day==0)
	{
		cout << "day number : " << day << endl;

		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (myArray[i][j] >= 6 && myArray[i][j] <= 8) {
					ripe += 1;
					//totalRipe += 1;
				}
				if (myArray[i][j] >= 9) {
					rotten += 1;
					//totalRotten += 1;
				}
			}
			//if (ripe >= half || rotten >= half || rotten + ripe >= half) { //harvesting row 
			if (rotten + ripe >= half) { //harvesting row 

				totalRipe = ripe + totalRipe;
				totalRotten = rotten + totalRotten;
				cout << "number of ripe in row " << i << " is: " << ripe + rotten << " and ready to be harvested." << endl;
				row = i;
				for (int k = 0; k < count; k++) {
					myArray[row][k] = 0;
				}
			}
			else {
				row = i;
				for (int l = 0; l < count; l++) {
					myArray[row][l] += 1;

				}
			}
			ripe = 0;//after every row, ripe is assigned to 0 again to assess a new row. 
			rotten = 0;//after every row, rotten is assigned to 0 again to assign a new row. 
		}

		cout << endl << "total ripe on day 0:" << totalRipe;
		cout << endl << "total rotten on day 0:" << totalRotten;


		updateArray();// calling the update array function to print and day increments by 1
		cout << endl;
	}

	if (day > 0 && day <= 7) {
		//cout << "day number : " << day << endl;

		if (day != 7) {
			for (int i = 0; i < count; i++) {
				for (int j = 0; j < count; j++) {
					if (myArray[i][j] >= 6 && myArray[i][j] <= 8) {
						ripe += 1;
						/*totalRipe += 1;*/
					}
					if (myArray[i][j] >= 9) {
						rotten += 1;
						/*totalRotten += 1;*/
					}
					
				}
				//if (ripe >= half || rotten >= half || rotten + ripe >= half) { //harvesting row 
				if (rotten + ripe >= half) { //harvesting row 

					totalRipe = ripe + totalRipe;
					totalRotten = rotten + totalRotten;
					cout << "number of ripe in row " << i << " is: " << ripe + rotten << " and ready to be harvested." << endl;
					row = i;
					for (int k = 0; k < count; k++) {
						myArray[row][k] = 0;
					}

					//updateArray();
				}
				else {
					/*totalRipe = ripe + totalRipe;
					totalRotten = rotten + totalRotten;*/
					row = i;
					for (int l = 0; l < count; l++) {
						myArray[row][l] += 1;

					}


				}
				ripe = 0;
				rotten = 0;
			}
			updateArray();
		}
		else { //if day is 7, you keep the array as it is while still counting ripe and rotten
			for (int i = 0; i < count; i++) {
				for (int j = 0; j < count; j++) {
					if (myArray[i][j] >= 6 && myArray[i][j] <= 8) {
						ripe += 1;
						//totalRipe += 1;
					}
					if (myArray[i][j] >= 9) {
						rotten += 1;
						//totalRotten += 1;
					}
				
				}
				if (rotten + ripe >= half) { //harvesting row 

					cout << endl << rotten + ripe << endl;
					totalRipe = ripe + totalRipe;
					totalRotten = rotten + totalRotten;

					row = i;
					for (int k = 0; k < count; k++) {
						myArray[row][k] = 0;
					}
				}
				else {
					totalRipe = ripe + totalRipe;
					totalRotten = rotten + totalRotten;
				}

				ripe = 0;
				rotten = 0;

			}

			//if (ripe >= half || rotten >= half || rotten + ripe >= half) { //harvesting row 
			

			updateArray();

		}
	}
}
void kiwi::updateArray() { //prints out the updated array

	cout << "day number: " << day << endl << endl;
	cout << "updated array: " << endl;
	for (int i = 0; i < count; i++) { //prints out updated array 
		for (int j = 0; j < count; j++) {
			cout << myArray[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "Harvested kiwis: " << totalRipe << endl;
	cout << "Rotten kiwis: " << totalRotten << endl << endl;

	day = day + 1; //update the day 


}
//
void kiwi:: outputMatrix(string outfile) {

	ofstream myoutputfile; 
	myoutputfile.open(outfile);

	if (myoutputfile.is_open())
	{
		//cout << "my output file is open" << endl; //testing
		//myoutputfile << "This is a line.\n";
		//myoutputfile << "This is another line.\n";

		for (int i = 0; i < count; i++) { //prints out updated array 
			for (int j = 0; j < count; j++) {
				myoutputfile << myArray[i][j] << " ";
			}
			myoutputfile << endl;
		}
		myoutputfile << endl;


		myoutputfile << "Harvested kiwis: "  << totalRipe << endl;
		myoutputfile << "Rotten kiwis: " << totalRotten << endl << endl;




		myoutputfile.close();
	}
	else cout << "Unable to open file";
	myoutputfile.close();

}









