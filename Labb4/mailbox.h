#ifndef MAILBOX_H
#define MAILBOX_H

#include <vector>
#include "email.h"

class Mailbox
{
public:
	Mailbox(size_t size = 0);

	void push(const Email& email);

	std::vector<Email>::iterator begin();

	std::vector<Email>::iterator end();

	Email& operator[](size_t pos);

	void sortWho();

	void sortDate();

	void sortSubject();

private:
	std::vector<Email> emails;
};

#endif