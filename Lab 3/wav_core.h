#ifndef WAV_CORE_H
#define WAV_CORE_H

#include <vector>
#include <stdexcept>

#include "wav_header.h"


// TODO: Implement all this in the form of a class.
// TODO: Use an exception system to control errors.
// TODO: Make support for 8-bit PSM, not just 16-bit.
// TODO: Write a function to change the tone of the voice. (Interestingly, it's not too difficult?)


// *********************************************************************
// * Error handling
// *********************************************************************

class WavException : public std::runtime_error {
public:
    explicit WavException(const std::string &__arg) : runtime_error(__arg) {}
};
class AllIsFine : public WavException{
public:
	AllIsFine() : WavException("Program is finished, no errors accured"){}
	};
class IOException : public WavException {
public:
    explicit IOException() : WavException("IO_ERROR") {}
};

class BadFormatException : public WavException {
public:
    explicit BadFormatException() : WavException("BAD_FORMAT") {}
};

class UnsupportedFormatException : public WavException {
public:
    explicit UnsupportedFormatException() : WavException("UNSUPPORTED_FORMAT") {}
};

class BadParamsException : public WavException {
public:
    explicit BadParamsException() : WavException("BAD_PARAMS") {}
};

class WavHeaderException : public WavException {
public:
    explicit WavHeaderException(const std::string &__arg) : WavException(__arg) {}
};

class HeaderRiffException : public WavHeaderException {
public:
    explicit HeaderRiffException() : WavHeaderException("HEADER_RIFF_ERROR") {}
};

class HeaderFileSizeErrorException : public WavHeaderException {
public:
    explicit HeaderFileSizeErrorException() : WavHeaderException("HEADER_FILE_SIZE_ERROR") {}
};

class HeaderWaveErrorException : public WavHeaderException {
public:
    explicit HeaderWaveErrorException() : WavHeaderException("HEADER_WAVE_ERROR") {}
};

class HeaderFtmException : public WavHeaderException {
public:
    explicit HeaderFtmException() : WavHeaderException("HEADER_FMT_ERROR") {}
};

class HeaderNotPCMException : public WavHeaderException {
public:
    explicit HeaderNotPCMException() : WavHeaderException("HEADER_NOT_PCM") {}
};

class HeaderFirstSubchunkErrorException : public WavHeaderException {
public:
    explicit HeaderFirstSubchunkErrorException() : WavHeaderException("HEADER_SUBCHUNK1_ERROR") {}
};

class HeaderBytesRateErrorException : public WavHeaderException {
public:
    explicit HeaderBytesRateErrorException() : WavHeaderException("HEADER_BYTES_RATE_ERROR") {}
};

class HeaderBlockAlignErrorException : public WavHeaderException {
public:
    explicit HeaderBlockAlignErrorException() : WavHeaderException("HEADER_BLOCK_ALIGN_ERROR") {}
};

class HeaderSecondSubchunkErrorException : public WavHeaderException {
public:
    explicit HeaderSecondSubchunkErrorException() : WavHeaderException("HEADER_SUBCHUNK2_SIZE_ERROR") {}
};

class ReverberationException : public WavException {
public:
    explicit ReverberationException() : WavException("REVERBATION ERROR: DELAY IS GREATER THAN WAV'S DURATION") {}
};

// ************************************************************************
// * Functions for working with WAV file
// ************************************************************************

class wav_errors_e{
// Reads file 'filename' and puts header's data to 'header_ptr' address.
// Also checks header validity, returns 'WAV_OK' on success.
	const char* input_fname  = "c:\\temp\\0.wav";
    const char* output_fname = "c:\\temp\\out.wav";
	wav_header_s header;
void read_header( const char* filename, wav_header_s* header_ptr );

// Prints header's data from 'header_ptr' address.
void print_info( const wav_header_s* header_ptr );

// Reads file 'filename' and puts PCM data (raw sound data) to 'channels_data'.
// Also checks header validity, returns 'WAV_OK' on success.
void extract_data_int16( const char* filename, std::vector< std::vector<short> >& channels_data );


// Creates a new WAV file 'filename', using 'sample_rate' and PCM data from 'channels_data'.
// Returns 'WAV_OK' on success.
void make_wav_file( const char* filename, int sample_rate, const std::vector< std::vector<short> >& channels_data );


// ************************************************************************
// * Functions for working with sound PCM data - Digital Signal Processing
// ************************************************************************

// Makes mono PCM data from stereo 'source'.
// Returns 'WAV_OK' on success.
void make_mono( const std::vector< std::vector<short> >& source, std::vector< std::vector<short> >& dest_mono );

// Adds a reverberation (it's like an echo).
// Returns 'WAV_OK' on success.
void make_reverb(std::vector< std::vector<short> >& sounds, int sample_rate , double delay_seconds, float decay);


// ************************************************************************
// * Private functions
// ************************************************************************

// Fills header with zeroes.
void null_header( wav_header_s* header_ptr );

// Checks header validity.
// Returns 'WAV_OK' on success.
void check_header( const wav_header_s* header_ptr, size_t file_size_bytes );

// Fills header information, using input parameters. This function calls prefill_header() itself.
void fill_header( wav_header_s* header_ptr, int chan_count, int bits_per_sample, int sample_rate, int samples_count_per_chan );

// Fills 'header_ptr' with default values.
void prefill_header( wav_header_s* header_ptr );
};

#endif // WAV_CORE_H
