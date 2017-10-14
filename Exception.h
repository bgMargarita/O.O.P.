#pragma once
#include <exception>
class Iniexception : public std::exception {

	//Myexception() = default;
	char *error;
public:
	Iniexception(char *error) {
		this->error = error;
	}
	char *what() {
		return error;
	};

};
class NoSuchSection : public Iniexception {
public:
	NoSuchSection(char *error) : Iniexception(error) {};
};
class NoSuchParam : public Iniexception {
public:
	NoSuchParam(char *error) : Iniexception(error) {};
};
class wrongFile : public Iniexception {
public:
	wrongFile(char *error) : Iniexception(error) {};
};
class wrongType : public Iniexception {
public:
	wrongType(char *error) : Iniexception(error) {};
};
