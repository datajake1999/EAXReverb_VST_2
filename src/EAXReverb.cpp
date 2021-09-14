#include "EAXReverb.h"

EAXReverb::EAXReverb (audioMasterCallback audioMaster)
: AudioEffectX (audioMaster, kNumPrograms, kNumParams)
{
	// init
	effect.Create((int)sampleRate);
	floatSamplesIn = NULL;
	floatSamplesIn = new float[blockSize];
	if (floatSamplesIn)
	{
		memset(floatSamplesIn, 0, 4*blockSize);
	}
	for (int i = 0; i < numPrograms; i++)
	{
		curProgram = i;
		SetReverbPreset (i);
		setProgramName (GetPresetName(i));
	}
	curProgram = 0;
	setNumInputs (2);	// stereo input
	setNumOutputs (2);	// stereo output
	setUniqueID ('EAX');
	canProcessReplacing ();
	DisableEffect = 0;
	DryGain = 1;
}

EAXReverb::~EAXReverb ()
{
	if (floatSamplesIn)
	{
		delete[] floatSamplesIn;
		floatSamplesIn = NULL;
	}
	effect.Destroy();
}

void EAXReverb::setParameter (VstInt32 index, float value)
{
	switch (index)
	{
	case kDisable :    DisableEffect = value;					break;
	case kDgain :    DryGain = value;					break;
	case kDensity :    SetDensity (value*EAXREVERB_MAX_DENSITY);					break;
	case kDiffusion :    SetDiffusion (value*EAXREVERB_MAX_DIFFUSION);					break;
	case kGain :    SetGain (value*EAXREVERB_MAX_GAIN);					break;
	case kGainHF :    SetGainHF (value*EAXREVERB_MAX_GAINHF);					break;
	case kGainLF :    SetGainLF (value*EAXREVERB_MAX_GAINLF);					break;
	case kDecayTime :    SetDecayTime (value*EAXREVERB_MAX_DECAY_TIME);					break;
	case kDecayHFRatio :    SetDecayHFRatio (value*EAXREVERB_MAX_DECAY_HFRATIO);					break;
	case kDecayLFRatio :    SetDecayLFRatio (value*EAXREVERB_MAX_DECAY_LFRATIO);					break;
	case kReflectionsGain :    SetReflectionsGain (value*EAXREVERB_MAX_REFLECTIONS_GAIN);					break;
	case kReflectionsDelay :    SetReflectionsDelay (value*EAXREVERB_MAX_REFLECTIONS_DELAY);					break;
	case kReflectionsPanX :    SetReflectionsPanX (value);					break;
	case kReflectionsPanY :    SetReflectionsPanY (value);					break;
	case kReflectionsPanZ :    SetReflectionsPanZ (value);					break;
	case kLateReverbGain :    SetLateReverbGain (value*EAXREVERB_MAX_LATE_REVERB_GAIN);					break;
	case kLateReverbDelay :    SetLateReverbDelay (value*EAXREVERB_MAX_LATE_REVERB_DELAY);					break;
	case kLateReverbPanX :    SetLateReverbPanX (value);					break;
	case kLateReverbPanY :    SetLateReverbPanY (value);					break;
	case kLateReverbPanZ :    SetLateReverbPanZ (value);					break;
	case kEchoTime :    SetEchoTime (value*EAXREVERB_MAX_ECHO_TIME);					break;
	case kEchoDepth :    SetEchoDepth (value*EAXREVERB_MAX_ECHO_DEPTH);					break;
	case kModulationTime :    SetModulationTime (value*EAXREVERB_MAX_MODULATION_TIME);					break;
	case kModulationDepth :    SetModulationDepth (value*EAXREVERB_MAX_MODULATION_DEPTH);					break;
	case kAirAbsorptionGainHF :    SetAirAbsorptionGainHF (value*EAXREVERB_MAX_AIR_ABSORPTION_GAINHF);					break;
	case kHFReference :    SetHFReference (value*EAXREVERB_MAX_HFREFERENCE);					break;
	case kLFReference :    SetLFReference (value*EAXREVERB_MAX_LFREFERENCE);					break;
	case kRoomRolloffFactor :    SetRoomRolloffFactor (value*EAXREVERB_MAX_ROOM_ROLLOFF_FACTOR);					break;
	case kDecayHFLimit :    SetDecayHFLimit (value);					break;
	}
	if (index >= kDensity && index < kNumParams)
	{
		UpdateEffect();
	}
}

float EAXReverb::getParameter (VstInt32 index)
{
	EAXReverbProgram* ap = &programs[curProgram];
	float v = 0;
	switch (index)
	{
	case kDisable :    v = DisableEffect;	break;
	case kDgain :    v = DryGain;	break;
	case kDensity :    v = ap->settings.Density/EAXREVERB_MAX_DENSITY;	break;
	case kDiffusion :    v = ap->settings.Diffusion/EAXREVERB_MAX_DIFFUSION;	break;
	case kGain :    v = ap->settings.Gain/EAXREVERB_MAX_GAIN;	break;
	case kGainHF :    v = ap->settings.GainHF/EAXREVERB_MAX_GAINHF;	break;
	case kGainLF :    v = ap->settings.GainLF/EAXREVERB_MAX_GAINLF;	break;
	case kDecayTime :    v = ap->settings.DecayTime/EAXREVERB_MAX_DECAY_TIME;	break;
	case kDecayHFRatio :    v = ap->settings.DecayHFRatio/EAXREVERB_MAX_DECAY_HFRATIO;	break;
	case kDecayLFRatio :    v = ap->settings.DecayLFRatio/EAXREVERB_MAX_DECAY_LFRATIO;	break;
	case kReflectionsGain :    v = ap->settings.ReflectionsGain/EAXREVERB_MAX_REFLECTIONS_GAIN;	break;
	case kReflectionsDelay :    v = ap->settings.ReflectionsDelay/EAXREVERB_MAX_REFLECTIONS_DELAY;	break;
	case kReflectionsPanX :    v = ap->settings.ReflectionsPan[0];	break;
	case kReflectionsPanY :    v = ap->settings.ReflectionsPan[1];	break;
	case kReflectionsPanZ :    v = ap->settings.ReflectionsPan[2];	break;
	case kLateReverbGain :    v = ap->settings.LateReverbGain/EAXREVERB_MAX_LATE_REVERB_GAIN;	break;
	case kLateReverbDelay :    v = ap->settings.LateReverbDelay/EAXREVERB_MAX_LATE_REVERB_DELAY;	break;
	case kLateReverbPanX :    v = ap->settings.LateReverbPan[0];	break;
	case kLateReverbPanY :    v = ap->settings.LateReverbPan[1];	break;
	case kLateReverbPanZ :    v = ap->settings.LateReverbPan[2];	break;
	case kEchoTime :    v = ap->settings.EchoTime/EAXREVERB_MAX_ECHO_TIME;	break;
	case kEchoDepth :    v = ap->settings.EchoDepth/EAXREVERB_MAX_ECHO_DEPTH;	break;
	case kModulationTime :    v = ap->settings.ModulationTime/EAXREVERB_MAX_MODULATION_TIME;	break;
	case kModulationDepth :    v = ap->settings.ModulationDepth/EAXREVERB_MAX_MODULATION_DEPTH;	break;
	case kAirAbsorptionGainHF :    v = ap->settings.AirAbsorptionGainHF/EAXREVERB_MAX_AIR_ABSORPTION_GAINHF;	break;
	case kHFReference :    v = ap->settings.HFReference/EAXREVERB_MAX_HFREFERENCE;	break;
	case kLFReference :    v = ap->settings.LFReference/EAXREVERB_MAX_LFREFERENCE;	break;
	case kRoomRolloffFactor :    v = ap->settings.RoomRolloffFactor/EAXREVERB_MAX_ROOM_ROLLOFF_FACTOR;	break;
	case kDecayHFLimit :    v = ap->DecayHFLimit;	break;
	}
	return v;
}

void EAXReverb::getParameterDisplay (VstInt32 index, char *text)
{
	EAXReverbProgram* ap = &programs[curProgram];
	switch (index)
	{
	case kDisable :
		if (DisableEffect >= 0.5)	
		{
			strcpy (text, "ON");					
		}
		else
		{
			strcpy (text, "OFF");					
		}
		break;
	case kDgain : float2string (DryGain, text, kVstMaxParamStrLen);	break;
	case kDensity : float2string (ap->settings.Density, text, kVstMaxParamStrLen);	break;
	case kDiffusion : float2string (ap->settings.Diffusion, text, kVstMaxParamStrLen);	break;
	case kGain : float2string (ap->settings.Gain, text, kVstMaxParamStrLen);	break;
	case kGainHF : float2string (ap->settings.GainHF, text, kVstMaxParamStrLen);	break;
	case kGainLF : float2string (ap->settings.GainLF, text, kVstMaxParamStrLen);	break;
	case kDecayTime : float2string (ap->settings.DecayTime, text, kVstMaxParamStrLen);	break;
	case kDecayHFRatio : float2string (ap->settings.DecayHFRatio, text, kVstMaxParamStrLen);	break;
	case kDecayLFRatio : float2string (ap->settings.DecayLFRatio, text, kVstMaxParamStrLen);	break;
	case kReflectionsGain : float2string (ap->settings.ReflectionsGain, text, kVstMaxParamStrLen);	break;
	case kReflectionsDelay : float2string (ap->settings.ReflectionsDelay, text, kVstMaxParamStrLen);	break;
	case kReflectionsPanX : float2string (ap->settings.ReflectionsPan[0], text, kVstMaxParamStrLen);	break;
	case kReflectionsPanY : float2string (ap->settings.ReflectionsPan[1], text, kVstMaxParamStrLen);	break;
	case kReflectionsPanZ : float2string (ap->settings.ReflectionsPan[2], text, kVstMaxParamStrLen);	break;
	case kLateReverbGain : float2string (ap->settings.LateReverbGain, text, kVstMaxParamStrLen);	break;
	case kLateReverbDelay : float2string (ap->settings.LateReverbDelay, text, kVstMaxParamStrLen);	break;
	case kLateReverbPanX : float2string (ap->settings.LateReverbPan[0], text, kVstMaxParamStrLen);	break;
	case kLateReverbPanY : float2string (ap->settings.LateReverbPan[1], text, kVstMaxParamStrLen);	break;
	case kLateReverbPanZ : float2string (ap->settings.LateReverbPan[2], text, kVstMaxParamStrLen);	break;
	case kEchoTime : float2string (ap->settings.EchoTime, text, kVstMaxParamStrLen);	break;
	case kEchoDepth : float2string (ap->settings.EchoDepth, text, kVstMaxParamStrLen);	break;
	case kModulationTime : float2string (ap->settings.ModulationTime, text, kVstMaxParamStrLen);	break;
	case kModulationDepth : float2string (ap->settings.ModulationDepth, text, kVstMaxParamStrLen);	break;
	case kAirAbsorptionGainHF : float2string (ap->settings.AirAbsorptionGainHF, text, kVstMaxParamStrLen);	break;
	case kHFReference : float2string (ap->settings.HFReference, text, kVstMaxParamStrLen);	break;
	case kLFReference : float2string (ap->settings.LFReference, text, kVstMaxParamStrLen);	break;
	case kRoomRolloffFactor : float2string (ap->settings.RoomRolloffFactor, text, kVstMaxParamStrLen);	break;
	case kDecayHFLimit :
		if (ap->DecayHFLimit >= 0.5)	
		{
			strcpy (text, "ON");					
		}
		else
		{
			strcpy (text, "OFF");					
		}
		break;
	}
}

void EAXReverb::getParameterLabel (VstInt32 index, char *label)
{
	switch (index)
	{
	case kDgain :    strcpy (label, "F");		break;
	case kDensity :    strcpy (label, "F");		break;
	case kDiffusion :    strcpy (label, "F");		break;
	case kGain :    strcpy (label, "F");		break;
	case kGainHF :    strcpy (label, "F");		break;
	case kGainLF :    strcpy (label, "F");		break;
	case kDecayTime :    strcpy (label, "Seconds");		break;
	case kDecayHFRatio :    strcpy (label, "F");		break;
	case kDecayLFRatio :    strcpy (label, "F");		break;
	case kReflectionsGain :    strcpy (label, "F");		break;
	case kReflectionsDelay :    strcpy (label, "Seconds");		break;
	case kReflectionsPanX :    strcpy (label, "F");		break;
	case kReflectionsPanY :    strcpy (label, "F");		break;
	case kReflectionsPanZ :    strcpy (label, "F");		break;
	case kLateReverbGain :    strcpy (label, "F");		break;
	case kLateReverbDelay :    strcpy (label, "Seconds");		break;
	case kLateReverbPanX :    strcpy (label, "F");		break;
	case kLateReverbPanY :    strcpy (label, "F");		break;
	case kLateReverbPanZ :    strcpy (label, "F");		break;
	case kEchoTime :    strcpy (label, "Seconds");		break;
	case kEchoDepth :    strcpy (label, "F");		break;
	case kModulationTime :    strcpy (label, "Seconds");		break;
	case kModulationDepth :    strcpy (label, "F");		break;
	case kAirAbsorptionGainHF :    strcpy (label, "F");		break;
	case kHFReference :    strcpy (label, "Hz");		break;
	case kLFReference :    strcpy (label, "Hz");		break;
	case kRoomRolloffFactor :    strcpy (label, "F");		break;
	}
}

void EAXReverb::getParameterName (VstInt32 index, char *text)
{
	switch (index)
	{
	case kDisable :    strcpy (text, "DisableEffect");		break;
	case kDgain :    strcpy (text, "DryGain");		break;
	case kDensity :    strcpy (text, "Density");		break;
	case kDiffusion :    strcpy (text, "Diffusion");		break;
	case kGain :    strcpy (text, "Gain");		break;
	case kGainHF :    strcpy (text, "GainHF");		break;
	case kGainLF :    strcpy (text, "GainLF");		break;
	case kDecayTime :    strcpy (text, "DecayTime");		break;
	case kDecayHFRatio :    strcpy (text, "DecayHFRatio");		break;
	case kDecayLFRatio :    strcpy (text, "DecayLFRatio");		break;
	case kReflectionsGain :    strcpy (text, "ReflectionsGain");		break;
	case kReflectionsDelay :    strcpy (text, "ReflectionsDelay");		break;
	case kReflectionsPanX :    strcpy (text, "ReflectionsPanX");		break;
	case kReflectionsPanY :    strcpy (text, "ReflectionsPanY");		break;
	case kReflectionsPanZ :    strcpy (text, "ReflectionsPanZ");		break;
	case kLateReverbGain :    strcpy (text, "LateReverbGain");		break;
	case kLateReverbDelay :    strcpy (text, "LateReverbDelay");		break;
	case kLateReverbPanX :    strcpy (text, "LateReverbPanX");		break;
	case kLateReverbPanY :    strcpy (text, "LateReverbPanY");		break;
	case kLateReverbPanZ :    strcpy (text, "LateReverbPanZ");		break;
	case kEchoTime :    strcpy (text, "EchoTime");		break;
	case kEchoDepth :    strcpy (text, "EchoDepth");		break;
	case kModulationTime :    strcpy (text, "ModulationTime");		break;
	case kModulationDepth :    strcpy (text, "ModulationDepth");		break;
	case kAirAbsorptionGainHF :    strcpy (text, "AirAbsorptionGainHF");		break;
	case kHFReference :    strcpy (text, "HFReference");		break;
	case kLFReference :    strcpy (text, "LFReference");		break;
	case kRoomRolloffFactor :    strcpy (text, "RoomRolloffFactor");		break;
	case kDecayHFLimit :    strcpy (text, "DecayHFLimit");		break;
	}
}

void EAXReverb::setProgram (VstInt32 program)
{
	curProgram = program;
	UpdateEffect();
}

void EAXReverb::setProgramName (char *name)
{
	strcpy (programs[curProgram].name, name);
}

void EAXReverb::getProgramName (char *name)
{
	strcpy (name, programs[curProgram].name);
}

bool EAXReverb::getProgramNameIndexed (VstInt32 category, VstInt32 index, char* text)
{
	if (index < kNumPrograms)
	{
		strcpy (text, programs[index].name);
		return true;
	}
	return false;
}

bool EAXReverb::getEffectName (char* name)
{
	strcpy (name, "EAXReverb");
	return true;
}

bool EAXReverb::getProductString (char* text)
{
	strcpy (text, "EAXReverb");
	return true;
}

bool EAXReverb::getVendorString (char* text)
{
	strcpy (text, "Datajake");
	return true;
}

VstInt32 EAXReverb::getVendorVersion ()
{
	return 1000;
}

VstPlugCategory EAXReverb::getPlugCategory ()
{
	return kPlugCategEffect;
}
