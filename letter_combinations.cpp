#include <map>
#include <string>
#include <vector>

/*
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 *
 */
std::vector<std::string> letterCombinations(std::string digits) {

    // Number Set
    const std::map<char, std::vector<std::string>> number_set = {
	    {'2', {"a","b","c"}},
	    {'3', {"d","e","f"}},
	    {'4', {"g","h","i"}},
	    {'5', {"j","k","l"}},
	    {'6', {"m","n","o"}},
	    {'7', {"p","q","r","s"}},
	    {'8', {"t","u","v"}},
	    {'9', {"w","x","y","z"}},
	};

	// Exception Handling
	if(digits.length() == 1)    return number_set.at(digits[0]);
	if(digits.length() == 0)    return std::vector<std::string>();

	// Combination Lambda
	auto combinations = [](std::vector<std::string> a, std::vector<std::string> b) {
        std::vector<std::string> temp;
	    for(int i = 0 ; i < a.size(); i++) {
		for(int j = 0; j < b.size(); j++) temp.push_back(a[i] + b[j]);
	    }
	    return temp;
	};

	// Iteration over digits
    std::vector<std::string> output = number_set.at(digits[0]);
	for (int i = 1; i < digits.length(); i++) {
	    output = combinations(output, number_set.at(digits[i]));
	}
	return output;
}
