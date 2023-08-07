/*
Author - Isaac Richards
Date - 15JUL23
Assignment - Object Oriented Math Library Program
Description - Menu for the Math Library Program.  This menu is a Python to C++ port of the menu from my assignments from CMIT-135-40B.
    The menu lists available options for functions to perform on a list of numbers.  The user can select an option by entering the number for
    the desired function.  Each entry from the user is checked for validity.  The user will continue to be prompted until a valid entry is made.

Update 06AUG23 - Removed specific functions for the Math Library Program and Quit, and added the get_t_input() function.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include "Menu.h"

using namespace std;

#pragma region GeneralMenuFunctions

int get_option(const vector<string>& option_list) {
    // List of all options with number labels
    vector<string> options;
    for (int i = 0; i < option_list.size(); i++) {
        options.push_back(to_string(i + 1) + ". " + option_list[i]);
    }

    string prompt = join(options) + "\n";
    return get_integer_input_in_range(prompt, 1, option_list.size()) - 1;
}

/*Not needed
void get_float_inputs_until_blank(const string& prompt, vector<float>& floats) {
    int count = scores.size();
    get_float_inputs(prompt, scores);
    if (count == scores.size())
        return;

    return get_float_inputs_until_blank(prompt, floats);
}
*/

string get_integer_inputs(const string& prompt, vector<int>& integers) {
    cout << prompt << endl;
    string answer;
    getline(cin, answer);
    vector<string> answer_list;
    stringstream ss(answer);
    string temp;
    while (getline(ss, temp, ' ')) {
        answer_list.push_back(temp);
    }

    for (const auto& str : answer_list) {
        string stripped_str = str;
        stripped_str.erase(remove(stripped_str.begin(), stripped_str.end(), ','), stripped_str.end());
        if (is_integer(stripped_str))
            integers.push_back(stoi(stripped_str));
    }

    return answer;
}

int get_integer_input(const string& prompt) {
    vector<int> integers;
    string answer = get_integer_inputs(prompt, integers);

    if (integers.size() == 1) {
        return integers[0];
    }
    else if (integers.size() > 1) {
        cout << "Received multiple numbers." << endl;
    }
    else {
        cout << answer << " is not a whole number." << endl;
    }

    return get_integer_input(prompt);
}

string get_binary_inputs(const string& prompt, vector<int>& binaries) {
    cout << prompt << endl;
	string answer;
	getline(cin, answer);
	vector<string> answer_list;
	stringstream ss(answer);
	string temp;
    while (getline(ss, temp, ' ')) {
		answer_list.push_back(temp);
	}

    for (const auto& str : answer_list) {
		string stripped_str = str;
		stripped_str.erase(remove(stripped_str.begin(), stripped_str.end(), ','), stripped_str.end());
		if (is_binary(stripped_str))
			binaries.push_back(stoi(stripped_str, nullptr, 2));
	}

	return answer;
}

int get_binary_input(const string& prompt) {
    vector<int> binaries;
    string answer = get_binary_inputs(prompt, binaries);

    if (binaries.size() == 1) {
        return binaries[0];
    }
    else if (binaries.size() > 1) {
        cout << "Received multiple numbers." << endl;
    }
    else {
        cout << answer << " is not a binary number." << endl;
    }

    return get_binary_input(prompt);
}

string get_float_inputs(const string& prompt, vector<float>& floats) {
    cout << prompt << endl;
    string answer;
    getline(cin, answer);
    vector<string> answer_list;
    stringstream ss(answer);
    string temp;
    while (getline(ss, temp, ' ')) {
        answer_list.push_back(temp);
    }

    for (const auto& str : answer_list) {
        string stripped_str = str;
        stripped_str.erase(remove(stripped_str.begin(), stripped_str.end(), ','), stripped_str.end());
        if (is_float(stripped_str))
            floats.push_back(stof(stripped_str));
    }

    return answer;
}

float get_float_input(const string& prompt) {
    vector<float> floats;
    string answer = get_float_inputs(prompt, floats);

    if (floats.size() == 1) {
        return floats[0];
    }
    else if (floats.size() > 1) {
        cout << "Received multiple numbers." << endl;
    }
    else {
        cout << answer << " is not a number." << endl;
    }

    return get_float_input(prompt);
}

bool is_integer(const string& str) {
    if (str.empty())
        return false;

    bool found_minus = (str[0] == '-');
    for (int i = (found_minus ? 1 : 0); i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }

    return true;
}

bool is_binary(const string& str) {
	if (str.empty())
		return false;

    for (size_t i = 0; i < str.length(); i++) {
		if (str[i] != '0' && str[i] != '1')
			return false;
	}

	return true;
}

bool is_float(const std::string& str) {
    if (str.empty())
        return false;

    bool is_negative = (str[0] == '-');
    bool has_decimal = false;
    int digit_count = 0;
    for (size_t i = is_negative ? 1 : 0; i < str.length(); i++) {
        if (str[i] == '.') {
            if (has_decimal)
                return false;// Multiple decimal points

            has_decimal = true;
        }
        else if (!std::isdigit(str[i])) {
            return false;
        }
        else {
            digit_count++;
        }
    }

    //Prevent strings like "." or "-." from being considered floats
    return digit_count > 0;
}

int get_integer_input_in_range(const string& prompt, int range_min, int range_max) {
    int value = -1;
    bool getting_input = true;
    while (getting_input) {
        value = get_integer_input(prompt);
        if (value < range_min || value > range_max) {
            cout << value << " is out of range." << endl;
        }
        else {
            getting_input = false;
        }
    }

    return value;
}

float get_float_input_in_range(const string& prompt, float range_min, float range_max) {
    float value = -1.0f;
    bool getting_input = true;
    while (getting_input) {
        value = get_float_input(prompt);
        if (value < range_min || value > range_max) {
            cout << value << " is out of range." << endl;
        }
        else {
            getting_input = false;
        }
    }

    return value;
}

string join(const vector<string>& list_strings, const string& separator) {
    string result = "";
    bool first = true;
    for (const auto& s : list_strings) {
        if (first) {
            first = false;
        }
        else {
            result += separator;
        }

        result += s;
    }

    return result;
}

/*
void stop_running() {
    cout << "Goodbye" << endl;
    running = false;
}
*/

#pragma endregion