#pragma once
#include "WavException.h"
class WavHeaderException : public WavException {
public:
	WavHeaderException(const std::string &arg) : WavException(arg) {};
};

class HeaderRiffException : public WavHeaderException {
public:
	HeaderRiffException() : WavHeaderException("HeaderRiffError") {};
};

class HeaderFileSizeException : public WavHeaderException {
public:
	HeaderFileSizeException() : WavHeaderException("HeaderFileSizeError") {};
};

class HeaderWaveException : public WavHeaderException {
public:
	HeaderWaveException() : WavHeaderException("HeaderWaveError") {};
};

class HeaderFMTException : public WavHeaderException {
public:
	HeaderFMTException() : WavHeaderException("HeaderFMTError") {};
};

class HeaderNotPCMException : public WavHeaderException {
public:
	HeaderNotPCMException() : WavHeaderException("HeaderNotPCMError") {};
};

class HeaderSubchunk1Exception : public WavHeaderException {
public:
	HeaderSubchunk1Exception() : WavHeaderException("HeaderSubchunk1Error") {};
};

class HeaderBytesRateException : public WavHeaderException {
public:
	HeaderBytesRateException() : WavHeaderException("HeaderBytesRateError") {};
};

class HeaderBlockAlignException : public WavHeaderException {
public:
	HeaderBlockAlignException() : WavHeaderException("HeaderBlockAlignError") {};
};

class HeaderSubchunk2SizeException : public WavHeaderException {
public:
	HeaderSubchunk2SizeException() : WavHeaderException("HeaderSubchunk2SizeError") {};
};