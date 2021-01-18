// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int Number1(std::vector<int> vect) {
	int current = vect[0];
	int i = 1;
	while (i < vect.size())
	{
		if (current + 1 == vect[i]) {
			current = vect[i];
		}
		else {
			break;
		}
		i++;
	}
	return vect[i - 1] + 1;
}

std::vector<std::vector<int>> Number2(std::vector<int> vect, int input) {
	std::vector<std::vector<int>> myVect(1, std::vector<int>());
	int j;
	int k = 0;
	for (int i = 0; i < vect.size() - 1; i++)
	{
		j = i + 1;
		while (j < vect.size())
		{
			if (vect[i] + vect[j] == input) {
				myVect.resize(k + 1);
				myVect[k].push_back(vect[i]);
				myVect[k].push_back(vect[j]);
				k++;
			}
			j++;
		}
	}
	return myVect;
}

void Number3(std::vector<int> colMap, int rowTotal)
{
	std::vector<std::vector<std::vector<int>>> parent(2, std::vector<std::vector<int>>(3, std::vector<int>(colMap[0])));

	int z = 0;

	for (int i = 0; i < rowTotal; i++)
	{

		for (int j = 0; j < colMap[0] + colMap[1]; j++)
		{
			if (j < colMap[0]) {
				parent[0][i][j] = j + 1 + z;
			}
			else {
				parent[1][i][j - colMap[0]] = j + 1 + z;
			}
		}
		z += 5;
	}
	for (int i = 0; i < parent.size(); i++)
	{
		for (int j = 0; j < parent[0].size(); j++)
		{
			for (int k = 0; k < parent[0][0].size(); k++)
			{
				if (parent[i][j][k] != 0)
					std::cout << parent[i][j][k] << " ";
			}
			std::cout << "\n";
		}
		std::cout << std::endl;
	}
}

void Number4()
{
	int TotalJarak = 500;
	int MaxTank = 180;
	std::vector<int> JarakSpbu = { 100, 140, 150, 200, 330, 360, 400 };
	std::vector<int> Harga = { 1000, 2000, 5000, 1000, 6000, 4000, 1000 };

	int i = 0;
	int currentJarak = 180;
	int cost = 0;
	int totalHarga = 0;

	for (int j = 0; j < JarakSpbu.size(); j += 2)
	{
		if (currentJarak >= 500) {
			break;
		}
		else {
			currentJarak += JarakSpbu[j];
		}
		totalHarga += JarakSpbu[i] * Harga[i];
	}
	std::cout << "Price = " << totalHarga;
}

int main()
{
	/// <summary>
	/// Number 1
	/// </summary>
	/// <returns></returns>
	std::cout << "Number 1: " << std::endl;
	std::vector<int> vect{ 1, 2, 3, 4, 5, 6, 8, 9, 10 };
	std::cout << Number1(vect);
	std::cout << "\n\n";

	/// <summary>
	/// Number 2
	/// </summary>
	/// <returns></returns>
	std::cout << "Number 2: " << std::endl;
	vect = { 1, 5, 6, 1, 0, 1 };
	std::vector<std::vector<int>> result = Number2(vect, 6);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
		{
			if (result[i].size() > 0)
				std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n";

	/// <summary>
	/// Number 3
	/// </summary>
	/// <returns></returns>
	std::cout << "Number 3: " << std::endl;
	std::vector<int> colMap = { 3, 2 };
	int rowTotal = 3;
	Number3(colMap, rowTotal);
	std::cout << "\n\n";


	/// <summary>
	/// Number 4
	/// </summary>
	/// <returns></returns>
	std::cout << "Number 4: " << std::endl;
	Number4();
	std::cout << "\n\n";


}