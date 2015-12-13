#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include <array>
#include <sstream>
#include <streambuf>

//Never use this code for anything serious! Its a crappy code

//What this code does(with bugs): It takes list of scrambled words from txt file, compares them to a Wordlist 
//and returns vector with unscrambled words.

//This code needs fixes, using proper tokenizer, and get rid of the unecessary code
//Main bug: If scrambled word is eg. aadcan, using this code it will match with three words from a wordlist: canada, canced, dancer
//It is becuase all letters from canada can be found even in canced or dancer. If the amount of letters matches, its taken as same word.
//This is obviously not correct :)

std::vector<std::string> split(const std::string& s)
{
	std::vector<std::string> ret;
	typedef std::string::size_type string_size;
	string_size i = 0;

	while (i != s.size())
	{
		while (i != s.size() && isspace(s[i]))
		{
			++i;
			//std::cout << "i is: " << i << std::endl;
		}

		string_size j = i;

		while (j != s.size() && !isspace(s[j]))
		{
			j++;
			//std::cout << "j is: " << j << std::endl;
		}

		if (i != j)
		{
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}



int main()
{
	typedef std::string::size_type string_size;

	std::vector<std::string> matchedWords;
	std::string scramb;
	std::string orig;
	int matched = 0;


	std::ifstream input1("D:/C++/scrambledWords.txt");
	std::stringstream buffer1;
	buffer1 << input1.rdbuf();
	std::string scrambled = buffer1.str();

	std::ifstream input2("D:/C++/wordlist.txt");
	std::stringstream buffer2;
	buffer2 << input2.rdbuf();
	std::string wordlist = buffer2.str();
	
	for (int top = 0; top < split(wordlist).size(); top++)
	{
		orig = split(wordlist)[top];
		
		for (int i = 0; i < split(scrambled).size(); i++)
		{
			scramb = split(scrambled)[i];

			if (scramb.size() == orig.size())
			{

				for (int i = 0; i < scramb.size(); i++)
				{
					for (int j = 0; j < orig.size(); j++)
					{
						if (scramb[i] == orig[j])
						{
							matched++;
							break;
						}
					}
				}

				if (orig.size() == matched)
				{
					
					std::cout << scramb << " == " << orig << std::endl;
					matchedWords.push_back(orig);
					break;
				}
			}
		

			matched = 0;
		}
	}
	std::cout << std::endl;
	for (auto z : matchedWords)
		std::cout << z << ", ";

	std::cout << std::endl;

	
	system("pause");
	return 0;
}
