#include "vector.h"
#include "email.h"


class MailBox
{
	MailBox(size_t size = 0);

	void push(const Email& email);

	void sortWho;

	void sortDate;

	void sortSubject;

private:
	std::vector<Email> emails;
};