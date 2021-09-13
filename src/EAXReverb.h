#ifndef EAXREVERB_H
#define EAXREVERB_H

#include "public.sdk/source/vst2.x/audioeffectx.h"
#include "ReverbEffect.h"

enum
{
	// Global
	kNumPrograms = 113,

	// Parameters Tags
	kDisable = 0,
	kDgain,
	kDensity, kDiffusion, kGain, kGainHF, kGainLF, kDecayTime, kDecayHFRatio, kDecayLFRatio, kReflectionsGain, kReflectionsDelay, kReflectionsPanX, kReflectionsPanY, kReflectionsPanZ, kLateReverbGain, kLateReverbDelay, kLateReverbPanX, kLateReverbPanY, kLateReverbPanZ, kEchoTime, kEchoDepth, kModulationTime, kModulationDepth, kAirAbsorptionGainHF, kHFReference, kLFReference, kRoomRolloffFactor, kDecayHFLimit,

	kNumParams
};

class EAXReverbProgram
{
public:	
	ReverbSettings settings;
	float DecayHFLimit;
	char name[32];
};

class EAXReverb : public AudioEffectX
{
public:
	EAXReverb (audioMasterCallback audioMaster);
	~EAXReverb ();
	virtual void setParameter (VstInt32 index, float value);
	virtual float getParameter (VstInt32 index);
	virtual void getParameterDisplay (VstInt32 index, char* text);
	virtual void getParameterLabel (VstInt32 index, char* label);
	virtual void getParameterName (VstInt32 index, char* text);
	virtual void setProgram (VstInt32 program);
	virtual void setProgramName (char* name);
	virtual void getProgramName (char* name);
	virtual bool getProgramNameIndexed (VstInt32 category, VstInt32 index, char* text);
	virtual bool getEffectName (char* name);
	virtual bool getVendorString (char* text);
	virtual bool getProductString (char* text);
	virtual VstInt32 getVendorVersion ();
	virtual VstPlugCategory getPlugCategory ();
	virtual void setSampleRate (float sampleRate);
	virtual void setBlockSize (VstInt32 blockSize);
	virtual void resume ();
	virtual void processReplacing (float** inputs, float** outputs, VstInt32 sampleFrames);
private:
	void SetDensity(float val);
	void SetDiffusion(float val);
	void SetGain(float val);
	void SetGainHF(float val);
	void SetGainLF(float val);
	void SetDecayTime(float val);
	void SetDecayHFRatio(float val);
	void SetDecayLFRatio(float val);
	void SetReflectionsGain(float val);
	void SetReflectionsDelay(float val);
	void SetReflectionsPanX(float val);
	void SetReflectionsPanY(float val);
	void SetReflectionsPanZ(float val);
	void SetLateReverbGain(float val);
	void SetLateReverbDelay(float val);
	void SetLateReverbPanX(float val);
	void SetLateReverbPanY(float val);
	void SetLateReverbPanZ(float val);
	void SetEchoTime(float val);
	void SetEchoDepth(float val);
	void SetModulationTime(float val);
	void SetModulationDepth(float val);
	void SetAirAbsorptionGainHF(float val);
	void SetHFReference(float val);
	void SetLFReference(float val);
	void SetRoomRolloffFactor(float val);
	void SetDecayHFLimit(float val);
	void SetEAXParams(float Density, float Diffusion, float Gain, float GainHF, float GainLF, float DecayTime, float DecayHFRatio, float DecayLFRatio, float ReflectionsGain, float ReflectionsDelay, float ReflectionsPanX, float ReflectionsPanY, float ReflectionsPanZ, float LateReverbGain, float LateReverbDelay, float LateReverbPanX, float LateReverbPanY, float LateReverbPanZ, float EchoTime, float EchoDepth, float ModulationTime, float ModulationDepth, float AirAbsorptionGainHF, float HFReference, float LFReference, float RoomRolloffFactor, float DecayHFLimit);
	void UpdateEffect();
	void SetReverbPreset(int preset);
	char *GetPresetName(int preset);
	ReverbEffect effect;
	float *floatSamplesIn;
	float floatSamplesOut[REVERB_BUFFERSIZE * OUTPUT_CHANNELS];
	EAXReverbProgram programs[kNumPrograms];
	float DisableEffect;
	float DryGain;
};

#endif
