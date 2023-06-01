#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;


set<set<string>> groupAnagrams(vector<string> const &words)
{
	set<set<string>> anagrams;
	vector<string> list(words);
	for (string &s: list) {		// don't forget to put `&`
		sort(s.begin(), s.end());
	}
	unordered_map<string, vector<int>> map;
	for (int i = 0; i < words.size(); i++) {
		map[list[i]].push_back(i);
	}
	for (auto itr: map)
	{
		set<string> anagram;
		for (int index: itr.second) {
			anagram.insert(words[index]);
		}
		if (anagram.size() > 1) {
			anagrams.insert(anagram);
		}
	}

	return anagrams;
}

int main()
{
	vector<string> words =
	{
		"Jeep", "PAID", "DUES", "NOSE", "SIGNED", "LAID", "PAIRED", "ARCS",
		"GRAB", "USES", "ONES", "BRAG", "SUED", "LEAN", "FEAR", "DESIGN"
	};

	set<set<string>> anagrams = groupAnagrams(words);

	for (set<string> anagram: anagrams) {
		for (string s: anagram) {
			cout << s << ' ';
		}
		cout << endl;
	}

	return 0;
}
