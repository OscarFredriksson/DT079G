#include <string>
#include <iostream>

struct CompWhoDateSubject;
struct CompDateWhoSubject;
struct CompSubjectWhoDate;

struct Email
{
public:
	Email(std::string who = "", std::string date = "", std::string subject = "");

	friend std::ostream& operator<<(std::ostream&, const Email& rhs);
	
	friend CompWhoDateSubject;
	friend CompDateWhoSubject;
	friend CompSubjectWhoDate;

private:
	std::string who;
	std::string date;
	std::string subject;


};

std::ostream& operator<<(std::ostream&, const Email& rhs);

struct CompWhoDateSubject
{
	bool operator(const Email& lhs, const Email& rhs);
};

struct CompDateWhoSubject 
{
	bool operator(const Email& lhs, const Email& rhs);
};

struct CompSubjectWhoDate
{
	bool operator(const Email& lhs, const Email& rhs);
};