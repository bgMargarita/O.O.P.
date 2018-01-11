#pragma once
#include <exception>
#include <stdexcept>
class WavException : public std::runtime_error {
public:
	explicit WavException(const std::string &arg) : runtime_error(arg) {};
};

class IOException : public WavException {
public:
	IOException() : WavException("IOERROR") {};
};

class BadFormatException : public WavException {
public:
	BadFormatException() : WavException("BadFormatError") {};
};

class UnsupportedFormatException : public WavException {
public:
	UnsupportedFormatException() : WavException("UnsupportedFormatError") {};
};

class BadParamException : public WavException {
public:
	BadParamException() : WavException("BadParamError") {};
};

class DataSizeException : public WavException {
public:
	DataSizeException() : WavException("DataSizeError") {};
};
