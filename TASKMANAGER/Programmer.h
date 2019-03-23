#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

class Programmer
{
private:
	std::string name;
	int id;
public:
	Programmer() {}
	Programmer(string n, int i) :name(n), id(i) {}
	~Programmer() {}

	std::string getName() const { return this->name; }
	int getId() const { return this->id; }

	friend istream& operator>>(std::istream& is, Programmer& p)
	{
		std::string line;
		getline(is, line);
		std::stringstream ss(line);
		std::vector<string> temp;
		std::string attribute;
		while (getline(ss, attribute, ','))
		{
			temp.push_back(attribute);
		}

		if (temp.size() != 2)
			return is;

		p.name = temp.at(0);
		p.id = std::stoi(temp.at(1));

		return is;
	}

	friend ostream& operator<<(ostream& os, const Programmer& p)
	{
		os << p.name << "," << to_string(p.id) << "\n";
	}
};