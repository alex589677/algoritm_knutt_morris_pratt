// author A.C. Gadiatulin, group CPLUS-1006, block algoritms C++
#include <iostream>
#include <string>

void computeLPS(std::string pat, int* lps) {
	// table lps(largest prefix suffix)
	int j = 0;
	lps[0] = 0;		// lps[0] is always 0
	int i = 1;
	while (i < pat.size()) {
		if (pat[i] == pat[j]) {
			j++;
			lps[i] = j;
			i++;
		}
		else {
			if (j != 0) {
				j = lps[j - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void isKPeriodic(int koef, const std::string& txt) {
	// algoritm search Knuth-Morris-Pratt
	if (koef <= 0) {
		std::cout << "koef > 0. Try again." << std::endl;
		return;
	}
	std::string str;
	for (int i = 0; i < koef; i++) {
		str.push_back(txt[i]);
	}
	int* lps = new int[str.size()];
	computeLPS(str, lps);
	int i = 0;
	int j = 0;
	int my_counter = 0;
	while (i < txt.size()) {
		if (str[j] == txt[i]) {
			j++;
			i++;
		}
		if (j == str.size()) {
			// increment my_counter
			my_counter++;
			j = lps[j - 1];
		}
		else if (j < txt.size() && str[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	std::cout << "chislo povtorenii " << my_counter << " podstroki v stroke." << std::endl;
	// proverka ravenstva podstroki koefficienty
	if (str.length() == koef) {
		std::cout << "stroka " << txt << " kratna chisly " << koef << std::endl;
	}
	else {
		std::cout << "stroka " << txt << " ne kratna chisly " << koef << std::endl;
	}
	delete[] lps;
}

int main() {
	std::string txt = "ABCABCABC";
	isKPeriodic(3, txt);
	return 0;
}
