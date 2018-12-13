#include "email.h"
#include <iostream>

Email::Email(std::string who, std::string date, std::string subject):
	who(who),
	date(date),
	subject(subject)
{}

std::ostream& operator<<(std::ostream& stream, const Email& rhs)
{
	stream << rhs.who << "\t" << rhs.date << "\t" << rhs.subject;
	return stream;
}



bool CompWhoDateSubject::operator()(const Email& lhs, const Email& rhs) const
{
	if (lhs.who < rhs.who) return true;
	else if (lhs.who == rhs.who)
	{
		if (lhs.date < rhs.date) return true;
		else if (lhs.date == rhs.date)
			if (lhs.subject < rhs.subject) return true;
	}
	return false;
}



bool CompDateWhoSubject::operator()(const Email& lhs, const Email& rhs) const
{
	if (lhs.date < rhs.date) return true;
	else if (lhs.date == rhs.date)
	{
		if (lhs.who < rhs.who) return true;
		else if (lhs.who == rhs.who)
			if (lhs.subject < rhs.subject) return true;
	}
	return false;
}



bool CompSubjectWhoDate::operator()(const Email& lhs, const Email& rhs) const
{
	if (lhs.subject < rhs.subject) return true;
	else if (lhs.subject == rhs.subject)
	{
		if (lhs.who < rhs.who) return true;
		else if (lhs.who == rhs.who)
			if (lhs.date < rhs.date) return true;
	}
	return false;
}
