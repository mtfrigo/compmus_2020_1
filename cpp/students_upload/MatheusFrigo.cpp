
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

#include "../read_write_wav.h"

using namespace std;

//helper functions
float midi2freq(int m)
{
    return 440*pow(2,(m-69.0f)/12.0f);
}

float freq2midi(float freq)
{
    return 12*log2( freq/440) + 69;
}
//


class SoundProcessor  
{
    public:

        virtual void process(float*, int)
        {
        }
};


class SineOscillator : public SoundProcessor
{
    public: 

        float freq;
        float amp;
        float Fs;


        SineOscillator(int nota_midi, float _amp, float _Fs)
        {
            freq = midi2freq(nota_midi);
            amp = _amp;
            Fs = _Fs;
        }

        ~SineOscillator()
        {
        }   

        void process(float* audio_buffer, int buffer_len) 
        {
            cout << "sine class -> call process: "<<  buffer_len << " amp: "<<  amp << " freq: "<< freq << "  Fs: " << Fs << endl;
            for (int n=0; n<buffer_len; n++)
            {
                //audio_buffer[n] += amp * sin(2*M_PI*freq*(((float)n)/Fs)); 
                audio_buffer[n] = amp * sin(2*M_PI*freq*(((float)n)/Fs)); 
            }
        }

};

class MusicNote
{
    public:
        float start_time; // pos in seconds
        float end_time; // pos in seconds
        SoundProcessor* sp;   

    MusicNote(SoundProcessor *o, float s, float e):sp(o), start_time(s), end_time(e)
    {
    }
};



int main(int c, char** argv)
{
    const float duration = 3.5; //seconds
    const float Fs = 44100; //sample rate (samples /second)
    const int buffer_len = round(duration*Fs); // samples
    float *audio_buffer;
    vector<MusicNote> notes;

    float time_p = 0.2;
    int note_count = 0;


    for(int rep = 0; rep < 3; rep++) {

        int oct = 0;

        if(rep > 1) oct = 1;

        int A = 57;
        int B = 59;
        int C = 60;
        int D = 62;
        int E = 64;
        int Fhash = 66;
        int G = 67;

        //===============================
        SineOscillator* B3 = new SineOscillator(B + (12*oct), 0.5, Fs);
        SineOscillator* B4 = new SineOscillator(B+12 + (12*oct), 0.5, Fs);
        SineOscillator* E4 = new SineOscillator(E + (12*oct), 0.5, Fs);
        SineOscillator* C4 = new SineOscillator(C + (12*oct), 0.5, Fs);
        SineOscillator* A3 = new SineOscillator(A + (12*oct), 0.5, Fs);
        SineOscillator* Fhash3 = new SineOscillator(Fhash-12 + (12*oct), 0.5, Fs);
        SineOscillator* Fhash4 = new SineOscillator(Fhash + (12*oct), 0.5, Fs);
        SineOscillator* G3 = new SineOscillator(G-12 + (12*oct), 0.5, Fs);
        SineOscillator* D4 = new SineOscillator(D + (12*oct), 0.5, Fs);
        SineOscillator* A4 = new SineOscillator(A+12 + (12*oct), 0.5, Fs);


        //===============================


        for(int k = 0; k < 4; k++) {
            MusicNote m1(B3, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m1);
            note_count++;

            MusicNote m2(E4, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m2);
            note_count++;

            MusicNote m3(B4, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m3);
            note_count++;
        }

        MusicNote m4(B3, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m4);
        note_count++;

        MusicNote m5(E4, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m5);
        note_count++;

        MusicNote m6(C4, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m6);
        note_count++;

        MusicNote m7(E4, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m7);
        note_count++;


        for(int k = 0; k < 4; k++) {
            MusicNote m8(B3, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m8);
            note_count++;

            MusicNote m9(E4, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m9);
            note_count++;

            MusicNote m10(B4, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m10);
            note_count++;
        }

        MusicNote m11(B3, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m11);
        note_count++;

        MusicNote m12(E4, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m12);
        note_count++;

        MusicNote m13(A3, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m13);
        note_count++;

        MusicNote m14(E4, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m14);
        note_count++;
        
        for(int k = 0; k < 4; k++) {
            MusicNote m15(Fhash3, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m15);
            note_count++;

            MusicNote m16(B3, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m16);
            note_count++;

            MusicNote m17(Fhash4, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m17);
            note_count++;
        }

        MusicNote m18(Fhash3, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m18);
        note_count++;

        MusicNote m19(B3, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m19);
        note_count++;

        MusicNote m20(G3, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m20);
        note_count++;

        MusicNote m21(B3, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m21);
        note_count++;

        for(int k = 0; k < 4; k++) {
            MusicNote m22(A3, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m22);
            note_count++;

            MusicNote m23(D4, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m23);
            note_count++;

            MusicNote m24(A4, time_p*note_count, time_p*(note_count+1));
            notes.push_back(m24);
            note_count++;
        }

        MusicNote m25(A3, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m25);
        note_count++;

        MusicNote m26(D4, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m26);
        note_count++;

        MusicNote m27(G3, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m27);
        note_count++;

        MusicNote m28(D4, time_p*note_count, time_p*(note_count+1));
        notes.push_back(m28);
        note_count++;
    }
    


    //===============================
    // get max signal duration
    int max_pos = 0;
    for (int k=0; k<notes.size(); k++)
    {
        max_pos = std::max((float)max_pos, (float)round(notes[k].end_time*Fs));
    }
    audio_buffer = new float[max_pos];
    memset(audio_buffer, 0, max_pos);

    cout << "maxPos: " << max_pos <<  endl;
    // write the notes into the audio buffer
    for (int k=0; k<notes.size(); k++)
    {
        int startPos = notes[k].start_time*Fs;
        int endPos = notes[k].end_time*Fs;
        cout << "startPos: " << startPos << endl;
        cout << "endPos: " << endPos << endl;
        cout << "opa" << endl;
        notes[k].sp->process(audio_buffer + startPos, endPos-startPos);
    }

    // ============================
    // save output wave
    string wav_name = "melody.wav";
    write_wave_file (wav_name.c_str(), audio_buffer, max_pos, Fs);
    cout << "done." << endl;
    delete [] audio_buffer;
    return 0;
}



