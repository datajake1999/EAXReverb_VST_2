#include "EAXReverb.h"

void EAXReverb::SetDensity (float val)
{
	if (val > EAXREVERB_MAX_DENSITY)
	{
		val = EAXREVERB_MAX_DENSITY;
	}
	else if (val < EAXREVERB_MIN_DENSITY)
	{
		val = EAXREVERB_MIN_DENSITY;
	}
	programs[curProgram].settings.Density = val;
}

void EAXReverb::SetDiffusion (float val)
{
	if (val > EAXREVERB_MAX_DIFFUSION)
	{
		val = EAXREVERB_MAX_DIFFUSION;
	}
	else if (val < EAXREVERB_MIN_DIFFUSION)
	{
		val = EAXREVERB_MIN_DIFFUSION;
	}
	programs[curProgram].settings.Diffusion = val;
}

void EAXReverb::SetGain (float val)
{
	if (val > EAXREVERB_MAX_GAIN)
	{
		val = EAXREVERB_MAX_GAIN;
	}
	else if (val < EAXREVERB_MIN_GAIN)
	{
		val = EAXREVERB_MIN_GAIN;
	}
	programs[curProgram].settings.Gain = val;
}

void EAXReverb::SetGainHF (float val)
{
	if (val > EAXREVERB_MAX_GAINHF)
	{
		val = EAXREVERB_MAX_GAINHF;
	}
	else if (val < EAXREVERB_MIN_GAINHF)
	{
		val = EAXREVERB_MIN_GAINHF;
	}
	programs[curProgram].settings.GainHF = val;
}

void EAXReverb::SetGainLF (float val)
{
	if (val > EAXREVERB_MAX_GAINLF)
	{
		val = EAXREVERB_MAX_GAINLF;
	}
	else if (val < EAXREVERB_MIN_GAINLF)
	{
		val = EAXREVERB_MIN_GAINLF;
	}
	programs[curProgram].settings.GainLF = val;
}

void EAXReverb::SetDecayTime (float val)
{
	if (val > EAXREVERB_MAX_DECAY_TIME)
	{
		val = EAXREVERB_MAX_DECAY_TIME;
	}
	else if (val < EAXREVERB_MIN_DECAY_TIME)
	{
		val = EAXREVERB_MIN_DECAY_TIME;
	}
	programs[curProgram].settings.DecayTime = val;
}

void EAXReverb::SetDecayHFRatio (float val)
{
	if (val > EAXREVERB_MAX_DECAY_HFRATIO)
	{
		val = EAXREVERB_MAX_DECAY_HFRATIO;
	}
	else if (val < EAXREVERB_MIN_DECAY_HFRATIO)
	{
		val = EAXREVERB_MIN_DECAY_HFRATIO;
	}
	programs[curProgram].settings.DecayHFRatio = val;
}

void EAXReverb::SetDecayLFRatio (float val)
{
	if (val > EAXREVERB_MAX_DECAY_LFRATIO)
	{
		val = EAXREVERB_MAX_DECAY_LFRATIO;
	}
	else if (val < EAXREVERB_MIN_DECAY_LFRATIO)
	{
		val = EAXREVERB_MIN_DECAY_LFRATIO;
	}
	programs[curProgram].settings.DecayLFRatio = val;
}

void EAXReverb::SetReflectionsGain (float val)
{
	if (val > EAXREVERB_MAX_REFLECTIONS_GAIN)
	{
		val = EAXREVERB_MAX_REFLECTIONS_GAIN;
	}
	else if (val < EAXREVERB_MIN_REFLECTIONS_GAIN)
	{
		val = EAXREVERB_MIN_REFLECTIONS_GAIN;
	}
	programs[curProgram].settings.ReflectionsGain = val;
}

void EAXReverb::SetReflectionsDelay (float val)
{
	if (val > EAXREVERB_MAX_REFLECTIONS_DELAY)
	{
		val = EAXREVERB_MAX_REFLECTIONS_DELAY;
	}
	else if (val < EAXREVERB_MIN_REFLECTIONS_DELAY)
	{
		val = EAXREVERB_MIN_REFLECTIONS_DELAY;
	}
	programs[curProgram].settings.ReflectionsDelay = val;
}

void EAXReverb::SetReflectionsPanX (float val)
{
	programs[curProgram].settings.ReflectionsPan[0] = val;
}

void EAXReverb::SetReflectionsPanY (float val)
{
	programs[curProgram].settings.ReflectionsPan[1] = val;
}

void EAXReverb::SetReflectionsPanZ (float val)
{
	programs[curProgram].settings.ReflectionsPan[2] = val;
}

void EAXReverb::SetLateReverbGain (float val)
{
	if (val > EAXREVERB_MAX_LATE_REVERB_GAIN)
	{
		val = EAXREVERB_MAX_LATE_REVERB_GAIN;
	}
	else if (val < EAXREVERB_MIN_LATE_REVERB_GAIN)
	{
		val = EAXREVERB_MIN_LATE_REVERB_GAIN;
	}
	programs[curProgram].settings.LateReverbGain = val;
}

void EAXReverb::SetLateReverbDelay (float val)
{
	if (val > EAXREVERB_MAX_LATE_REVERB_DELAY)
	{
		val = EAXREVERB_MAX_LATE_REVERB_DELAY;
	}
	else if (val < EAXREVERB_MIN_LATE_REVERB_DELAY)
	{
		val = EAXREVERB_MIN_LATE_REVERB_DELAY;
	}
	programs[curProgram].settings.LateReverbDelay = val;
}

void EAXReverb::SetLateReverbPanX (float val)
{
	programs[curProgram].settings.LateReverbPan[0] = val;
}

void EAXReverb::SetLateReverbPanY (float val)
{
	programs[curProgram].settings.LateReverbPan[1] = val;
}

void EAXReverb::SetLateReverbPanZ (float val)
{
	programs[curProgram].settings.LateReverbPan[2] = val;
}

void EAXReverb::SetEchoTime (float val)
{
	if (val > EAXREVERB_MAX_ECHO_TIME)
	{
		val = EAXREVERB_MAX_ECHO_TIME;
	}
	else if (val < EAXREVERB_MIN_ECHO_TIME)
	{
		val = EAXREVERB_MIN_ECHO_TIME;
	}
	programs[curProgram].settings.EchoTime = val;
}

void EAXReverb::SetEchoDepth (float val)
{
	if (val > EAXREVERB_MAX_ECHO_DEPTH)
	{
		val = EAXREVERB_MAX_ECHO_DEPTH;
	}
	else if (val < EAXREVERB_MIN_ECHO_DEPTH)
	{
		val = EAXREVERB_MIN_ECHO_DEPTH;
	}
	programs[curProgram].settings.EchoDepth = val;
}

void EAXReverb::SetModulationTime (float val)
{
	if (val > EAXREVERB_MAX_MODULATION_TIME)
	{
		val = EAXREVERB_MAX_MODULATION_TIME;
	}
	else if (val < EAXREVERB_MIN_MODULATION_TIME)
	{
		val = EAXREVERB_MIN_MODULATION_TIME;
	}
	programs[curProgram].settings.ModulationTime = val;
}

void EAXReverb::SetModulationDepth (float val)
{
	if (val > EAXREVERB_MAX_MODULATION_DEPTH)
	{
		val = EAXREVERB_MAX_MODULATION_DEPTH;
	}
	else if (val < EAXREVERB_MIN_MODULATION_DEPTH)
	{
		val = EAXREVERB_MIN_MODULATION_DEPTH;
	}
	programs[curProgram].settings.ModulationDepth = val;
}

void EAXReverb::SetAirAbsorptionGainHF (float val)
{
	if (val > EAXREVERB_MAX_AIR_ABSORPTION_GAINHF)
	{
		val = EAXREVERB_MAX_AIR_ABSORPTION_GAINHF;
	}
	else if (val < EAXREVERB_MIN_AIR_ABSORPTION_GAINHF)
	{
		val = EAXREVERB_MIN_AIR_ABSORPTION_GAINHF;
	}
	programs[curProgram].settings.AirAbsorptionGainHF = val;
}

void EAXReverb::SetHFReference (float val)
{
	if (val > EAXREVERB_MAX_HFREFERENCE)
	{
		val = EAXREVERB_MAX_HFREFERENCE;
	}
	else if (val < EAXREVERB_MIN_HFREFERENCE)
	{
		val = EAXREVERB_MIN_HFREFERENCE;
	}
	programs[curProgram].settings.HFReference = val;
}

void EAXReverb::SetLFReference (float val)
{
	if (val > EAXREVERB_MAX_LFREFERENCE)
	{
		val = EAXREVERB_MAX_LFREFERENCE;
	}
	else if (val < EAXREVERB_MIN_LFREFERENCE)
	{
		val = EAXREVERB_MIN_LFREFERENCE;
	}
	programs[curProgram].settings.LFReference = val;
}

void EAXReverb::SetRoomRolloffFactor (float val)
{
	if (val > EAXREVERB_MAX_ROOM_ROLLOFF_FACTOR)
	{
		val = EAXREVERB_MAX_ROOM_ROLLOFF_FACTOR;
	}
	else if (val < EAXREVERB_MIN_ROOM_ROLLOFF_FACTOR)
	{
		val = EAXREVERB_MIN_ROOM_ROLLOFF_FACTOR;
	}
	programs[curProgram].settings.RoomRolloffFactor = val;
}

void EAXReverb::SetDecayHFLimit (float val)
{
	programs[curProgram].DecayHFLimit = val;
	if (programs[curProgram].DecayHFLimit >= 0.5)
	{
		programs[curProgram].settings.DecayHFLimit = EAXREVERB_MAX_DECAY_HFLIMIT;
	}
	else
	{
		programs[curProgram].settings.DecayHFLimit = EAXREVERB_MIN_DECAY_HFLIMIT;
	}
}

void EAXReverb::SetEAXParams(float Density, float Diffusion, float Gain, float GainHF, float GainLF, float DecayTime, float DecayHFRatio, float DecayLFRatio, float ReflectionsGain, float ReflectionsDelay, float ReflectionsPanX, float ReflectionsPanY, float ReflectionsPanZ, float LateReverbGain, float LateReverbDelay, float LateReverbPanX, float LateReverbPanY, float LateReverbPanZ, float EchoTime, float EchoDepth, float ModulationTime, float ModulationDepth, float AirAbsorptionGainHF, float HFReference, float LFReference, float RoomRolloffFactor, float DecayHFLimit)
{
	SetDensity(Density);
	SetDiffusion(Diffusion);
	SetGain(Gain);
	SetGainHF(GainHF);
	SetGainLF(GainLF);
	SetDecayTime(DecayTime);
	SetDecayHFRatio(DecayHFRatio);
	SetDecayLFRatio(DecayLFRatio);
	SetReflectionsGain(ReflectionsGain);
	SetReflectionsDelay(ReflectionsDelay);
	SetReflectionsPanX(ReflectionsPanX);
	SetReflectionsPanY(ReflectionsPanY);
	SetReflectionsPanZ(ReflectionsPanZ);
	SetLateReverbGain(LateReverbGain);
	SetLateReverbDelay(LateReverbDelay);
	SetLateReverbPanX(LateReverbPanX);
	SetLateReverbPanY(LateReverbPanY);
	SetLateReverbPanZ(LateReverbPanZ);
	SetEchoTime(EchoTime);
	SetEchoDepth(EchoDepth);
	SetModulationTime(ModulationTime);
	SetModulationDepth(ModulationDepth);
	SetAirAbsorptionGainHF(AirAbsorptionGainHF);
	SetHFReference(HFReference);
	SetLFReference(LFReference);
	SetRoomRolloffFactor(RoomRolloffFactor);
	SetDecayHFLimit(DecayHFLimit);
}
