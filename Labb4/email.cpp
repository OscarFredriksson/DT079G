#include "email.h"

Email::Email(std::string who, std::string date, std::string subject):
	who(who),
	date(date),
	subject(subject)
{}

std::ostream& operator<<(std::ostream&, const Email& rhs)
{
	std::cout << rhs.who << " " << rhs.date << " " << rhs.subject << std::endl;
}


struct CompWhoDateSubject
{
	bool operator(const Email& lhs, const Email& rhs) const
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
};

struct CompDateWhoSubject
{
	bool operator()
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
};

struct CompSubjectWhoDate
{
	bool operator()
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
};