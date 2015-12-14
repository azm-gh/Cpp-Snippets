#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>

int rnd()
{
	std::random_device rseed;
	std::mt19937 mt(rseed());
	std::uniform_int_distribution<int>dist(0, 99);
	return(dist(mt));
}

void bubbleSort(std::vector<int>v, int size)
{
	int temp = 0;

	for (int loop = 0; loop < size; loop++) {
		for (int i = 0; i < size - 1; i++) {
			if (v[i] > v[i + 1])
			{
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
	}

	for (auto z : v)
	{
		std::cout << z << " ";
	}

}

int main()
{
	std::vector<int>vecArr[10];
	std::fill(std::begin(vecArr), std::end(vecArr), std::vector<int>(5));

	for (int i = 0; i < 10; i++)
	{
		std::generate(std::begin(vecArr[i]), std::end(vecArr[i]), rnd);
	}

	std::cout << "Unsorted vectors: \n" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		for (auto z : vecArr[i])
		{
			std::cout << z << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "=======\n" << std::endl;

	std::cout << "Sorted vectors: " << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		bubbleSort(vecArr[i], 5);
	}
	std::cout << std::endl;

	std::ofstream output_file("C:/C++/example.txt");
	std::ostream_iterator<int> output_iterator(output_file, " ");



	for (int i = 0; i < 10; i++)
	{
		std::copy(vecArr[i].begin(), vecArr[i].end(), output_iterator);
		output_file << '\n';

	}








	system("pause");
	return 0;
}
