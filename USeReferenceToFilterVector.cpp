#include <iostream>
#include <vector>

void FilterOdds(std::vector<int> &inputVec)
{
	for (size_t i = 0; i < inputVec.size(); i++)
	{
		if (inputVec[i] % 2 != 0)
		{
			inputVec.erase(inputVec.begin()+i);
		}
	}
}


int main()
{

	std::vector<int> testVec {1, 2, 3, 4, 5,6,7};
	FilterOdds(testVec);
	
	for (auto z : testVec)
		std::cout << z << " ";
	
	std::cout << std::endl;

	system("pause");
	return 0;
}
