#include "EAXReverb.h"

void EAXReverb::UpdateEffect()
{
	effect.LoadPreset
	(
	programs[curProgram].settings.Density,
	programs[curProgram].settings.Diffusion,
	programs[curProgram].settings.Gain,
	programs[curProgram].settings.GainHF,
	programs[curProgram].settings.GainLF,
	programs[curProgram].settings.DecayTime,
	programs[curProgram].settings.DecayHFRatio,
	programs[curProgram].settings.DecayLFRatio,
	programs[curProgram].settings.ReflectionsGain,
	programs[curProgram].settings.ReflectionsDelay,
	programs[curProgram].settings.ReflectionsPan[0],
	programs[curProgram].settings.ReflectionsPan[1],
	programs[curProgram].settings.ReflectionsPan[2],
	programs[curProgram].settings.LateReverbGain,
	programs[curProgram].settings.LateReverbDelay,
	programs[curProgram].settings.LateReverbPan[0],
	programs[curProgram].settings.LateReverbPan[1],
	programs[curProgram].settings.LateReverbPan[2],
	programs[curProgram].settings.EchoTime,
	programs[curProgram].settings.EchoDepth,
	programs[curProgram].settings.ModulationTime,
	programs[curProgram].settings.ModulationDepth,
	programs[curProgram].settings.AirAbsorptionGainHF,
	programs[curProgram].settings.HFReference,
	programs[curProgram].settings.LFReference,
	programs[curProgram].settings.RoomRolloffFactor,
	programs[curProgram].settings.DecayHFLimit
	);
	effect.Update((int)sampleRate);
}

void EAXReverb::setSampleRate (float sampleRate)
{
	AudioEffectX::setSampleRate (sampleRate);
	effect.Destroy();
	effect.Create((int)sampleRate);
	UpdateEffect();
}

void EAXReverb::setBlockSize (VstInt32 blockSize)
{
	if (floatSamplesIn)
	{
		delete floatSamplesIn;
		floatSamplesIn = NULL;
	}
	floatSamplesIn = new float[blockSize];
	if (floatSamplesIn)
	{
		memset(floatSamplesIn, 0, 4*blockSize);
	}
}

void EAXReverb::processReplacing (float** inputs, float** outputs, VstInt32 sampleFrames)
{
	float* in1 = inputs[0];
	float* in2 = inputs[1];
	float* out1 = outputs[0];
	float* out2 = outputs[1];
	int i;
	if (DisableEffect >= 0.5)
	{
		for (i=0; i<sampleFrames; i++)
		{
			out1[i] = in1[i];
			out2[i] = in2[i];
		}
		return;
	}
	if (floatSamplesIn == NULL)
	{
		return;
	}
	if (sampleFrames > blockSize)
	{
		sampleFrames = blockSize;
	}
	//convert stereo samples into mono
	for (i=0; i<sampleFrames; i++)
	{
		floatSamplesIn[i] = (in1[i] + in2[i]) / 2;
	}
	//set the offset for the audio buffer
	int offset = 0;
	do {
		//set the amount of samples to process at a time
		int workSamples = REVERB_BUFFERSIZE / 4;
		if (workSamples>sampleFrames)
		{
			workSamples = sampleFrames;
		}
		//process the effect
		effect.Process(workSamples, &floatSamplesIn[offset],  floatSamplesOut);
		//apply gain to dry samples
		for (i=0; i<workSamples; i++)
		{
			in1[i] = in1[i] * DryGain;
			in2[i] = in2[i] * DryGain;
		}
		//write to the audio buffer
		for (i=0; i<workSamples; i++)
		{
			out1[i] = in1[i] + floatSamplesOut[i*2 + 0];
			out2[i] = in2[i] + floatSamplesOut[i*2 + 1];
		}
		//update the sample counters
		sampleFrames -= workSamples;
		offset += workSamples;
	} while (sampleFrames>0);
}
