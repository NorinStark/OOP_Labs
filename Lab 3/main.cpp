#include <iostream>

#include "wav_core.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "************** | WavCore | **************" << endl;


    // ################  Tests for WavCore  ################

	wav_errors_e w;
	
try{

    // #### Opening WAV file, checking header.
    w.read_header( the.input_fname, &the.header );


    // #### Printing header.
    w.print_info(&the.header);


    // #### Reading PCM data from file.
    vector< vector<short> > chans_data;
    w.extract_data_int16( the.input_fname, chans_data );
    
    cout << endl << "********************" << endl;


    // #### Make several changes to PCM data.

    // # Making signal mono from stereo.
    vector< vector<short> > edited_data;
    w.make_mono( chans_data, edited_data );

    // # Add a reverberation
    w.make_reverb(edited_data, header.sampleRate, 0.5, 0.6f);


    // #### Making new WAV file using edited PCM data.
    w.make_wav_file(the.output_fname, the.header.sampleRate, edited_data);


    // #### Reading the file just created to check its header corectness.
   	w.read_header(the.output_fname, &the.header);
    w.print_info(&the.header);

}
catch (WavException a) {cout << a.what();}

    return 0;
}
