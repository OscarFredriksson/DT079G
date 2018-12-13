#include "mailbox.h"

Mailbox::Mailbox(size_t size):
	emails(size)
{}

void Mailbox::push(const Email& email)
{
	emails.push_back(email);
}

std::vector<Email>::iterator Mailbox::begin()
{
	return emails.begin();
}

std::vector<Email>::iterator Mailbox::end()
{
	return emails.end();
}

Email& Mailbox::operator[](size_t pos)
{
	return emails[pos];
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