#pragma once
#include <vector>
#include <string>
#include "WavHeaderException.h"
#include "WavException.h"
class WavCore
{
public:
	WavCore(const std::string &);
	~WavCore();
	// Reads file 'filename' and puts PCM data (raw sound data) to 'channelsData'.
	// Also checks header validity, returns 'WAV_OK' on success.
	void Create( const std::string &)
		throw (IOException, BadFormatException, WavHeaderException, UnsupportedFormatException);
	void nullHeader();
	// Prints header's data from 'header_ptr' address.
	void GetInfo() const;
	void extractDataInt16(const std::string &filename);
	// Creates a new WAV file 'filename', using 'sampleRate' and PCM data from 'channelsData'.
	// Returns 'WAV_OK' on success.
	void MakeWavFile(const std::string filename)
		throw (IOException, BadParamException, UnsupportedFormatException);

	// ************************************************************************
	// * Functions for working with sound PCM data - Digital Signal Processing
	// ************************************************************************

	// Makes mono PCM data from stereo 'source'.
	// Returns 'WAV_OK' on success.

	void makeMono()
		throw (BadParamException);


private:
	
	struct WavHeader {
		char chunkId[4];
		uint32_t chunkSize;
		char format[4];
		char subchunk1Id[4];
		uint32_t subchunk1Size;
		uint16_t audioFormat;
		uint16_t numChannels;
		uint32_t sampleRate;
		uint32_t byteRate;
		uint16_t blockAlign;
		uint16_t bitsPerSample;
		char subchunk2Id[4];
		uint32_t subchunk2Size;
	};

	// Checks header validity.
	// Returns 'WAV_OK' on success.
	void checkHeader( size_t );

	// Fills header information, using input parameters. This function calls prefillHeader() itself.
	void fillHeader(int chanCount, int bitsPerSample, int sampleRate, int samplesCountPerChan)
		throw(BadParamException, UnsupportedFormatException);

	// Fills 'header_ptr' with default values.
	void prefillHeader();
	std::vector<std::vector<short>> channelsData;
	WavHeader header;
	 const int headerSize = 44;
//	const short headerSize = 44;
	// ƒалее следуют непосредственно Wav данные.
};
