#include<iostream>
#include<string>
#include<vector>
#include<map>
int main()
{
	std::vector<std::string> v = {"hello","world","hello","what", "world"};
	std::map<std::string, int> word_map;
	for(int i=0;i<v.size();i++)
		word_map[v[i]]++;
	for(std::map<std::string,int>::iterator itr = word_map.begin(); itr != word_map.end(); ++itr)
		std::cout << itr->first << ' ' << itr->second << std::endl;
return 0;
}	
