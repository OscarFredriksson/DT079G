#include "email.h"
#include <iostream>

void show(const vector<Email>& src);

int main()
{
	return 0;
}

void show(const vector<Email>& src)
{
	for (auto& email : src) std::cout << email << std::endl;
}
