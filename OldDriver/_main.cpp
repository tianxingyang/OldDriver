////将磁力链转换成ASCII码的二进制形式，统一省略高位0，也就是七位代表一字，然后将其中的1表示为nico，0表示为ni。
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//
//using namespace std;
//
//int decimalToBinary(int decimal)
//{
//	int binary = 0;
//	int remainder = 0;
//	for (int times = 0; decimal != 0 ; times++)
//	{
//		remainder = decimal % 2;
//		decimal = decimal / 2;
//		binary += remainder * pow(10, times);
//	}
//	return binary;
//}
//
//char encoder(string *magnetURL)
//{
//	vector <int> tempDecimal;
//	vector <int> tempBinary;
//	char fileName[] = "D:\\Desktop\\demo.txt";
//	ofstream file(fileName);
//	for (int i = 0; i < (*magnetURL).length(); i++)
//	{
//		tempDecimal.push_back((*magnetURL).at(i));
//		tempBinary.push_back(decimalToBinary(tempDecimal[i]));
//		for (int j = 7; j > 0; j--)
//		{
//			if (int(tempBinary[i]/pow(10, j - 1)) == 1)
//			{
//				file << "nico";
//				tempBinary[i] = tempBinary[i] - pow(10, j - 1);
//			}
//			else
//			{
//				file << "ni";
//			}
//		}
//	}
//	return 0;
//}
//
//char decoder(string interestingCode)
//{
//	//cout << "decode" << endl;
//	for (int i = 0; i < interestingCode.size(); i++)
//	{
//
//	}
//	return 0;
//}
//
//int main()
//{
//	//options
//	char *purpose = new char[2];
//	cout << "**********************************" << endl;
//	cout << "         ENCODE OR DECODE        " << endl;
//	cout << "Input EN for ENCODE, DE for DECODE" << endl;
//	cout << "**********************************" << endl;
//	cin >> purpose;
//
//	if (strcmp(purpose, "EN") == 0)
//	{
//		string *temp = new string();
//		cout << "Input the interesting code" << endl;
//		cin >> *temp;
//		encoder(temp);
//	}
//	else if (strcmp(purpose, "DE") == 0)
//		{
//			cout << "Input the magnet URL" << endl;
//			decoder("test");
//		}
//	else
//		cout << "Wrong input" << endl;
//
//	return 0;
//}