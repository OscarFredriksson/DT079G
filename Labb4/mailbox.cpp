#include "mailbox.h"

Mailbox::Mailbox(size_t size):
	emails(size)
{}

void Mailbox::push(const Email& email)
{
	emails.push_back(email);
}

Email* begin() const
{
	return emails.begin();
}

Email* end() const
{
	return emails.end();
}

void Mailbox::sortWho()
{
	CompWhoDateSubject comp;
	std::sort(emails.begin(), emails.end(), comp);
}

void Mailbox::sortDate()
{
	CompDateWhoSubject comp;
	std::sort(emails.begin(), emails.end(), comp);
}

void Mailbox::sortSubject()
{
	CompSubjectWhoDate comp;
	std::sort(emails.begin(), emails.end(), comp);
}