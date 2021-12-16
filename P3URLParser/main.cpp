//
// main.cpp
// URLParser
// CSCI 151
// Created by Yuna Kim on 12/10/21
// 

#include <iostream>
#include <string>

int main() {
	// asks user to input url
	std::cout << "Please enter a URL: ";
	std::string url;
	std::cin >> url;

	// count keeps track of number of time the character '/' comes up in the url
	int count = 0;
	// numInBetween keeps track of the number of character before count gets to 3
	int numInBetween = 0;
	// num keeps track of the number of characters before count gets to 1 
	int num = 0;


	for (int i = 0; i < url.size(); i++) {
		if (url[i] == '/') {
			count++;
		}

		else if (count < 3) {
			numInBetween++;

			if (count < 1) {
				num++;
			}
		}
	}

	int lastIndexOfAuthority = (numInBetween + 2) - num;
	// substrings of each part of the URL
	std::string scheme = url.substr(0, url.find_first_of("/"));
	std::string authority = url.substr(url.find_first_of("/"), lastIndexOfAuthority);
	std::string path = url.substr(authority.size() + scheme.size(), url.size());

	// prints out the scheme, authority, and path of a URL
	std::cout << "scheme = " << scheme << "\n";
	std::cout << "authority = " << authority << "\n";
	std::cout << "path = " << path << "\n";

}