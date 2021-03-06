//----------------------------------------------------------
// name: "phaser2_demo"
//
// Code generated with Faust 0.9.95 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>
#ifndef FAUSTPOWER
#define FAUSTPOWER
#include <cmath>
template <int N> inline int faustpower(int x)              { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline int faustpower<0>(int x)            { return 1; }
template <> 	 inline int faustpower<1>(int x)            { return x; }
template <> 	 inline int faustpower<2>(int x)            { return x*x; }
template <int N> inline float faustpower(float x)            { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline float faustpower<0>(float x)          { return 1; }
template <> 	 inline float faustpower<1>(float x)          { return x; }
template <> 	 inline float faustpower<2>(float x)          { return x*x; }
#endif
/************************************************************************

	IMPORTANT NOTE : this file contains two clearly delimited sections :
	the ARCHITECTURE section (in two parts) and the USER section. Each section
	is governed by its own copyright and license. Please check individually
	each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

	EXCEPTION : As a special exception, you may create a larger work
	that contains this FAUST architecture section and distribute
	that work under terms of your choice, so long as this FAUST
	architecture section is not modified.


	************************************************************************
	************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <sndfile.h>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <iostream>

#include "faust/gui/console.h"
#include "faust/gui/FUI.h"
#include "faust/dsp/dsp.h"
#include "faust/misc.h"

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

#define READ_SAMPLE sf_readf_float
//#define READ_SAMPLE sf_readf_double

/******************************************************************************
*******************************************************************************

VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	int 	iVec0[2];
	FAUSTFLOAT 	fslider0;
	float 	fConst0;
	float 	fConst1;
	float 	fRec5[2];
	float 	fRec6[2];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT 	fslider4;
	float 	fConst2;
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fcheckbox0;
	FAUSTFLOAT 	fslider6;
	float 	fRec4[3];
	float 	fRec3[3];
	float 	fRec2[3];
	float 	fRec1[3];
	float 	fRec0[2];
	FAUSTFLOAT 	fslider7;
	FAUSTFLOAT 	fcheckbox1;
	FAUSTFLOAT 	fcheckbox2;
	float 	fRec11[3];
	float 	fRec10[3];
	float 	fRec9[3];
	float 	fRec8[3];
	float 	fRec7[2];
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("name", "phaser2_demo");
		m->declare("phafla.lib/name", "Faust Phaser and Flanger Library");
		m->declare("phafla.lib/version", "0.0");
		m->declare("miscoscillator.lib/name", "Faust Oscillator Library");
		m->declare("miscoscillator.lib/version", "0.0");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/version", "2.0");
		m->declare("math.lib/name", "Faust Math Library");
		m->declare("math.lib/version", "2.0");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("basic.lib/name", "Faust Basic Element Library");
		m->declare("basic.lib/version", "0.0");
		m->declare("route.lib/name", "Faust Signal Routing Library");
		m->declare("route.lib/version", "0.0");
		m->declare("signal.lib/name", "Faust Signal Routing Library");
		m->declare("signal.lib/version", "0.0");
	}

	virtual int getNumInputs() { return 2; }
	virtual int getNumOutputs() { return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(1.92e+05f, max(1.0f, (float)fSamplingFreq));
		fConst1 = (6.2831855f / fConst0);
		fConst2 = (1.0f / fConst0);
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 0.5f;
		fslider1 = 1e+02f;
		fslider2 = 8e+02f;
		fslider3 = 1.5f;
		fslider4 = 1e+03f;
		fslider5 = 0.0f;
		fcheckbox0 = 0.0;
		fslider6 = 0.0f;
		fslider7 = 1.0f;
		fcheckbox1 = 0.0;
		fcheckbox2 = 0.0;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) iVec0[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<3; i++) fRec2[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<3; i++) fRec11[i] = 0;
		for (int i=0; i<3; i++) fRec10[i] = 0;
		for (int i=0; i<3; i++) fRec9[i] = 0;
		for (int i=0; i<3; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	virtual mydsp* clone() {
		return new mydsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
	}
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->declare(0, "tooltip", "Reference:    https://ccrma.stanford.edu/~jos/pasp/Flanging.html");
		ui_interface->openVerticalBox("PHASER2");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fcheckbox0, "0", "");
		ui_interface->declare(&fcheckbox0, "tooltip", "When this is checked, the phaser    has no effect");
		ui_interface->addCheckButton("Bypass", &fcheckbox0);
		ui_interface->declare(&fcheckbox2, "1", "");
		ui_interface->addCheckButton("Invert Internal Phaser Sum", &fcheckbox2);
		ui_interface->declare(&fcheckbox1, "2", "");
		ui_interface->addCheckButton("Vibrato Mode", &fcheckbox1);
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fslider0, "1", "");
		ui_interface->declare(&fslider0, "style", "knob");
		ui_interface->declare(&fslider0, "unit", "Hz");
		ui_interface->addHorizontalSlider("Speed", &fslider0, 0.5f, 0.0f, 1e+01f, 0.001f);
		ui_interface->declare(&fslider7, "2", "");
		ui_interface->declare(&fslider7, "style", "knob");
		ui_interface->addHorizontalSlider("Notch Depth (Intensity)", &fslider7, 1.0f, 0.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider5, "3", "");
		ui_interface->declare(&fslider5, "style", "knob");
		ui_interface->addHorizontalSlider("Feedback Gain", &fslider5, 0.0f, -0.999f, 0.999f, 0.001f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fslider4, "1", "");
		ui_interface->declare(&fslider4, "scale", "log");
		ui_interface->declare(&fslider4, "style", "knob");
		ui_interface->declare(&fslider4, "unit", "Hz");
		ui_interface->addHorizontalSlider("Notch width", &fslider4, 1e+03f, 1e+01f, 5e+03f, 1.0f);
		ui_interface->declare(&fslider1, "2", "");
		ui_interface->declare(&fslider1, "scale", "log");
		ui_interface->declare(&fslider1, "style", "knob");
		ui_interface->declare(&fslider1, "unit", "Hz");
		ui_interface->addHorizontalSlider("Min Notch1 Freq", &fslider1, 1e+02f, 2e+01f, 5e+03f, 1.0f);
		ui_interface->declare(&fslider2, "3", "");
		ui_interface->declare(&fslider2, "scale", "log");
		ui_interface->declare(&fslider2, "style", "knob");
		ui_interface->declare(&fslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("Max Notch1 Freq", &fslider2, 8e+02f, 2e+01f, 1e+04f, 1.0f);
		ui_interface->declare(&fslider3, "4", "");
		ui_interface->declare(&fslider3, "style", "knob");
		ui_interface->addHorizontalSlider("Notch Freq Ratio: NotchFreq(n+1)/NotchFreq(n)", &fslider3, 1.5f, 1.1f, 4.0f, 0.001f);
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fslider6, "unit", "dB");
		ui_interface->addHorizontalSlider("Phaser Output Level", &fslider6, 0.0f, -6e+01f, 1e+01f, 0.1f);
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (fConst1 * float(fslider0));
		float 	fSlow1 = cosf(fSlow0);
		float 	fSlow2 = sinf(fSlow0);
		float 	fSlow3 = (0 - fSlow2);
		float 	fSlow4 = float(fslider1);
		float 	fSlow5 = (0.5f * (0 - (fConst1 * (fSlow4 - max(fSlow4, float(fslider2))))));
		float 	fSlow6 = (fConst1 * fSlow4);
		float 	fSlow7 = float(fslider3);
		float 	fSlow8 = expf((fConst2 * (0 - (3.1415927f * float(fslider4)))));
		float 	fSlow9 = (0 - (2 * fSlow8));
		float 	fSlow10 = faustpower<2>(fSlow8);
		float 	fSlow11 = float(fslider5);
		int 	iSlow12 = int(float(fcheckbox0));
		float 	fSlow13 = powf(10,(0.05f * float(fslider6)));
		float 	fSlow14 = faustpower<2>(fSlow7);
		float 	fSlow15 = faustpower<3>(fSlow7);
		float 	fSlow16 = faustpower<4>(fSlow7);
		float 	fSlow17 = (0.5f * ((int(float(fcheckbox1)))?2:float(fslider7)));
		float 	fSlow18 = ((int(float(fcheckbox2)))?(0 - fSlow17):fSlow17);
		float 	fSlow19 = (1 - fSlow17);
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			fRec5[0] = ((fSlow2 * fRec6[1]) + (fSlow1 * fRec5[1]));
			fRec6[0] = (((fSlow1 * fRec6[1]) + (fSlow3 * fRec5[1])) + (1 - iVec0[1]));
			float fTemp0 = (fSlow6 + (fSlow5 * (1 - fRec5[0])));
			float fTemp1 = (fRec4[1] * cosf((fSlow7 * fTemp0)));
			float fTemp2 = (float)input0[i];
			float fTemp3 = ((iSlow12)?0:fTemp2);
			fRec4[0] = (((fSlow13 * fTemp3) + (fSlow11 * fRec0[1])) - ((fSlow10 * fRec4[2]) + (fSlow9 * fTemp1)));
			float fTemp4 = (fRec3[1] * cosf((fSlow14 * fTemp0)));
			fRec3[0] = ((fRec4[2] + (fSlow9 * (fTemp1 - fTemp4))) - (fSlow10 * (fRec3[2] - fRec4[0])));
			float fTemp5 = (fRec2[1] * cosf((fSlow15 * fTemp0)));
			fRec2[0] = ((fRec3[2] + (fSlow9 * (fTemp4 - fTemp5))) - (fSlow10 * (fRec2[2] - fRec3[0])));
			float fTemp6 = (fRec1[1] * cosf((fSlow16 * fTemp0)));
			fRec1[0] = ((fRec2[2] + (fSlow9 * (fTemp5 - fTemp6))) - (fSlow10 * (fRec1[2] - fRec2[0])));
			fRec0[0] = ((fSlow9 * fTemp6) + (fRec1[2] + (fSlow10 * fRec1[0])));
			output0[i] = (FAUSTFLOAT)((iSlow12)?fTemp2:((fSlow13 * (fTemp3 * fSlow19)) + (fSlow18 * fRec0[0])));
			float fTemp7 = (fSlow6 + (fSlow5 * (1 - fRec6[0])));
			float fTemp8 = (fRec11[1] * cosf((fSlow7 * fTemp7)));
			float fTemp9 = (float)input1[i];
			float fTemp10 = ((iSlow12)?0:fTemp9);
			fRec11[0] = (((fSlow13 * fTemp10) + (fSlow11 * fRec7[1])) - ((fSlow10 * fRec11[2]) + (fSlow9 * fTemp8)));
			float fTemp11 = (fRec10[1] * cosf((fSlow14 * fTemp7)));
			fRec10[0] = ((fRec11[2] + (fSlow9 * (fTemp8 - fTemp11))) - (fSlow10 * (fRec10[2] - fRec11[0])));
			float fTemp12 = (fRec9[1] * cosf((fSlow15 * fTemp7)));
			fRec9[0] = ((fRec10[2] + (fSlow9 * (fTemp11 - fTemp12))) - (fSlow10 * (fRec9[2] - fRec10[0])));
			float fTemp13 = (fRec8[1] * cosf((fSlow16 * fTemp7)));
			fRec8[0] = ((fRec9[2] + (fSlow9 * (fTemp12 - fTemp13))) - (fSlow10 * (fRec8[2] - fRec9[0])));
			fRec7[0] = ((fSlow9 * fTemp13) + (fRec8[2] + (fSlow10 * fRec8[0])));
			output1[i] = (FAUSTFLOAT)((iSlow12)?fTemp9:((fSlow13 * (fTemp10 * fSlow19)) + (fSlow18 * fRec7[0])));
			// post processing
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1]; fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1]; fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1]; fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1]; fRec11[1] = fRec11[0];
			fRec0[1] = fRec0[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			iVec0[1] = iVec0[0];
		}
	}
};



/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

mydsp	DSP;

class Separator
{
  int		fNumFrames;
  int		fNumInputs;
  int		fNumOutputs;

  FAUSTFLOAT*	fInput;
  FAUSTFLOAT*	fOutputs[256];

public:

  Separator(int numFrames, int numInputs, int numOutputs)
  {
    fNumFrames 	= numFrames;
    fNumInputs 	= numInputs;
    fNumOutputs = max(numInputs, numOutputs);

    // allocate interleaved input channel
    fInput = (FAUSTFLOAT*) calloc(fNumFrames * fNumInputs, sizeof(FAUSTFLOAT));

    // allocate separate output channels
    for (int i = 0; i < fNumOutputs; i++) {
      fOutputs[i] = (FAUSTFLOAT*) calloc (fNumFrames, sizeof(FAUSTFLOAT));
    }
  }

  ~Separator()
  {
    // free interleaved input channel
    free(fInput);

    // free separate output channels
    for (int i = 0; i < fNumOutputs; i++) {
      free(fOutputs[i]);
    }
  }

  FAUSTFLOAT*	input()		{ return fInput; }

  FAUSTFLOAT** outputs()	{ return fOutputs; }

  void 	separate()
  {
    for (int s = 0; s < fNumFrames; s++) {
      for (int c = 0; c < fNumInputs; c++) {
        fOutputs[c][s] = fInput[c + s*fNumInputs];
      }
    }
  }
};

class Interleaver
{
  int fNumFrames;
  int fNumChans;

  FAUSTFLOAT* fInputs[256];
  FAUSTFLOAT* fOutput;

public:

  Interleaver(int numFrames, int numChans)
  {
    fNumFrames = numFrames;
    fNumChans  = numChans;

    // allocate separate input channels
    for (int i = 0; i < fNumChans; i++) {
      fInputs[i] = (FAUSTFLOAT*) calloc (fNumFrames, sizeof(FAUSTFLOAT));
    }

    // allocate interleaved output channel
    fOutput = (FAUSTFLOAT*) calloc(fNumFrames * fNumChans, sizeof(FAUSTFLOAT));

  }

  ~Interleaver()
  {
    // free separate input channels
    for (int i = 0; i < fNumChans; i++) {
      free(fInputs[i]);
    }

    // free interleaved output channel
    free(fOutput);
  }

  FAUSTFLOAT**	inputs()		{ return fInputs; }

  FAUSTFLOAT* 	output()		{ return fOutput; }

  void interleave()
  {
    for (int s = 0; s < fNumFrames; s++) {
      for (int c = 0; c < fNumChans; c++) {
        fOutput[c + s*fNumChans] = fInputs[c][s];
      }
    }
  }
};

#define kFrames 512

// loptrm : Scan command-line arguments and remove and return long int value when found
long loptrm(int *argcP, char *argv[], const char* longname, const char* shortname, long def)
{
  int argc = *argcP;
  for (int i=2; i<argc; i++) {
    if (strcmp(argv[i-1], shortname) == 0 || strcmp(argv[i-1], longname) == 0) {
      int optval = atoi(argv[i]);
      for (int j=i-1; j<argc-2; j++) {  // make it go away for sake of "faust/gui/console.h"
        argv[j] = argv[j+2];
      }
      *argcP -= 2;
      return optval;
    }
  }
  return def;
}

int main(int argc, char *argv[])
{
  SNDFILE*	in_sf;
  SNDFILE*	out_sf;
  SF_INFO	in_info;
  SF_INFO	out_info;
  unsigned int nAppend = 0; // number of frames to append beyond input file

  if (argc < 3) {
    fprintf(stderr,"*** USAGE: %s input_soundfile output_soundfile\n",argv[0]);
    exit(1);
  }

  nAppend = loptrm(&argc, argv, "--continue", "-c", 0);
    
  CMDUI* interface = new CMDUI(argc, argv);
  DSP.buildUserInterface(interface);
  interface->process_command();

  // open input file
  in_info.format = 0;
  in_sf = sf_open(interface->input_file(), SFM_READ, &in_info);
  if (in_sf == NULL) {
    fprintf(stderr,"*** Input file not found.\n");
    sf_perror(in_sf); 
    exit(1); 
  }

  // open output file
  out_info = in_info;
  out_info.format = in_info.format;
  out_info.channels = DSP.getNumOutputs();
  out_sf = sf_open(interface->output_file(), SFM_WRITE, &out_info);
  if (out_sf == NULL) { 
    fprintf(stderr,"*** Cannot write output file.\n");
    sf_perror(out_sf); 
    exit(1); 
  }

  // create separator and interleaver
  Separator   sep(kFrames, in_info.channels, DSP.getNumInputs());
  Interleaver ilv(kFrames, DSP.getNumOutputs());

  // init signal processor
  DSP.init(in_info.samplerate);
  //DSP.buildUserInterface(interface);
  interface->process_init();

  // process all samples
  int nbf;
  do {
    nbf = READ_SAMPLE(in_sf, sep.input(), kFrames);
    sep.separate();
    DSP.compute(nbf, sep.outputs(), ilv.inputs());
    ilv.interleave();
    sf_writef_float(out_sf, ilv.output(), nbf);
    //sf_write_raw(out_sf, ilv.output(), nbf);
  } while (nbf == kFrames);

  sf_close(in_sf);

  // compute tail, if any
  if (nAppend>0) {
    FAUSTFLOAT *input = (FAUSTFLOAT*) calloc(nAppend * DSP.getNumInputs(), sizeof(FAUSTFLOAT));
    FAUSTFLOAT *inputs[1] = { input };
    Interleaver ailv(nAppend, DSP.getNumOutputs());
    DSP.compute(nAppend, inputs, ailv.inputs());
    ailv.interleave();
    sf_writef_float(out_sf, ailv.output(), nAppend);
  }

  sf_close(out_sf);
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/
