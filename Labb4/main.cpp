#include "mailbox.h"
#include <iostream>
#include <vector>
#include <functional>
#include "email.h"

void show(const Email& email)
{
	std::cout << email << std::endl;
}

int main()
{
	Mailbox mailbox(3);

	mailbox[0] = Email("Oscar", "2018-12-11", "Första mailet!");
	mailbox[1] = Email("Test", "2018-12-12", "Är dem sorterade?");
	mailbox[2] = Email("Alfred", "2018-12-12", "Viktigt!");

	mailbox.push(Email("Sture", "2018-12-13"));
	mailbox.push(Email("Oscar", "2018-12-14", "Är labben klar?"));

	mailbox.sortWho();
	std::cout << "Sorterad på avsändare:" << std::endl;
	std::for_each(mailbox.begin(), mailbox.end(), show);
	std::cout << std::endl;

	mailbox.sortDate();
	std::cout << "Sorterad på datum:" << std::endl;
	std::for_each(mailbox.begin(), mailbox.end(), show);
	std::cout << std::endl;

	mailbox.sortSubject();
	std::cout << "Sorterad på ämne:" << std::endl;
	std::for_each(mailbox.begin(), mailbox.end(), show);
	std::cout << std::endl;

	return 0;
}
