#include <fstream>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include<iomanip>
#include<vector>
using namespace std;
int max_index(vector<int> &a)
{
	vector<int>::iterator it=a.begin();
	int temp = 0;
	for (int i : a)
	{
		if (i >= a[temp])
		{
			temp = i;
		}
	}
	it += temp;
	a.erase(it);
	return temp;
}
int main()
{
	int way_to_search;
	int lenth_of_suffix;
	string suffix;
	cout << "ways to choose,1 for lenth,2 for suffix" << endl;
	cin >> way_to_search;
	if (way_to_search == 1) {
		cout << "input the lenth:" << endl;
		cin >> lenth_of_suffix;
	}
	else if (way_to_search == 2) {
		cout << "input the suffix:" << endl;
		cin >> suffix;
		lenth_of_suffix = suffix.length();
	}
	set<string> words;
	string oneword;
	string file_name = "E://source tree//prac 12//EnglishWords.txt";
	ifstream dic;
	dic.open(file_name.data());
	while (getline(dic, oneword))
	{
		words.insert(oneword);
	}
	map<string, int>suffixes;
	map<string, int>::iterator it;
	for (string i : words)                                       //use map store suffixes and its quantity
	{
		if (i.length() >= lenth_of_suffix)
		{
			suffixes[i.substr(i.length() - lenth_of_suffix, lenth_of_suffix)] += 1;
		}
	}
	if (way_to_search == 1)
	{
		vector<string>suffix_to_sort;
		vector<int>suffix_num;
		it = suffixes.begin();
		while (it != suffixes.end())
		{
			suffix_num.push_back(it->second);
			suffix_to_sort.push_back(it->first);
		}
		if (suffixes.size() <= 10)
		{	
		   it = suffixes.begin();
		   while (it != suffixes.end())
		  {
			cout << it->first << "      number       " << it->second << endl;
			it++;
		  }
	    }
		else
		{
			vector<int>top_ten;
			for (int i = 0; i < 9; i++)
			{
				top_ten.push_back(max_index(suffix_num));
			}
			for (int i : top_ten)
			{
				cout << suffix_to_sort[i] << "   num     " << suffix_num[i];
			}
		}
	}
	if (way_to_search == 2)
	{
		cout << suffix << "  num   " << suffixes[suffix] << endl;
	}
	system("pause");
}