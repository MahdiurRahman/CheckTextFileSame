//this program reads text files and tells you whether they match or not
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int length(string& s)
{
	int size = 0;
	while (s[size] != '\0')
	{
		size++;
	}
	return size;
}

bool comparison(string& a , string& b)
{
	int sizeA = 0, sizeB = 0;
	string dumA, dumB;
	ifstream fileA, fileB;
	fileA.open(a);
	fileB.open(b);
	while (!fileA.eof() and !fileB.eof())
	{
		getline(fileA, dumA);
		getline(fileB, dumB);
		sizeA = length(dumA), sizeB = length(dumB);
		//1. check for similar # of lines
		if (((!fileA.eof()) and (fileB.eof())) or ((fileA.eof()) and (!fileB.eof())))
		{
			return false;
		}
		//2. check for line of same size string
		else if (sizeA == sizeB)
		{
			for (int i = 0; i < sizeA; i++)
			{
				//2a. check for line having same content
				if (dumA[i] != dumB[i])
				{
					return false;
				}
			}
		}
		//3. this is not a check as much as it is a way to direct function to
		//'false' IF they have same # of lines but lines are different size
		//if it doesn't exist, then lines could be different size BUT program will
		//not return false. Will simply go down and return 'true' (line 55)
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string a, b;
	cout << "Enter first filename: ";
	cin >> a;
	cout << "Enter second filename: ";
	cin >> b;

	if (comparison(a, b))
	{
		cout << "They are the same!\n";
	}
	else
	{
		cout << "They are different!\n";
	}

	cout << endl;
	system("pause;");
	return 0;
}