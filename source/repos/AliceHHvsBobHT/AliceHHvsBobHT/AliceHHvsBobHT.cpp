// AliceHHvsBobHT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Program to brute force the HH vs HT statistics problem
//Given a sequence of random, fair coin flips, Alice earns a point for each sequence of HH, Bob earns a point for each HT
//proves that Bob is more likely to win
// 0 = H, 1 = T

#include <iostream>
#include <string>
#include<vector>
using namespace std;

int Alice_Wins = 0;
int Bob_Wins = 0;

void tallyPoints(vector<int> binary)
{
	
	int Alice = 0;
	int Bob = 0;
	for (size_t i = 1; i < binary.size(); i++)
	{
		
		if (binary[i] == 0)
		{
			if (binary[i-1] == 0)
			{
				Alice++;
			}
			else
			{
				Bob++;
			}
		}
	}
	if (Bob > Alice)
	{
		Bob_Wins++;
	}
	else if (Alice > Bob)
	{
		Alice_Wins++;
	}
	
}

void generateBinaryStrings(vector<int> binary, int n)
{
	if (binary.size() == n)
	{
		/*for (int i : binary)
		{
			cout << i;
		}
		cout << endl; */ 
		tallyPoints(binary);
		return;
	}

	binary.push_back(0);
	generateBinaryStrings(binary, n);

	binary.pop_back();
	binary.push_back(1);
	generateBinaryStrings(binary, n);
	binary.pop_back();

}


int main(void) {
   
	vector<int> binary;
	const int n = 30;
	generateBinaryStrings(binary, n);
	cout << "Done" << endl;
	cout << "Alice Wins: " << Alice_Wins << endl;
	cout << "Bob Wins: " << Bob_Wins << endl;
}

