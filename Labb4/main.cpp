#include "mailbox.h"
#include <iostream>
#include <vector>
#include <functional>

void show(const vector<Email>& src);

int main()
{
	Mailbox mailbox;

	std::for_each(mailbox.begin(), mailbox.end(), show);

	return 0;
}

void show(const Email& src)
{
	std::cout << email << std::endl;
}
