#include "EAXReverb.h"

void EAXReverb::SetReverbPreset(int preset) {
	//set a preset
	if (preset == 0)
	{
		SetEAXParams(EFX_REVERB_PRESET_GENERIC);
	}
	else if (preset == 1)
	{
		SetEAXParams(EFX_REVERB_PRESET_PADDEDCELL);
	}
	else if (preset == 2)
	{
		SetEAXParams(EFX_REVERB_PRESET_ROOM);
	}
	else if (preset == 3)
	{
		SetEAXParams(EFX_REVERB_PRESET_BATHROOM);
	}
	else if (preset == 4)
	{
		SetEAXParams(EFX_REVERB_PRESET_LIVINGROOM);
	}
	else if (preset == 5)
	{
		SetEAXParams(EFX_REVERB_PRESET_STONEROOM);
	}
	else if (preset == 6)
	{
		SetEAXParams(EFX_REVERB_PRESET_AUDITORIUM);
	}
	else if (preset == 7)
	{
		SetEAXParams(EFX_REVERB_PRESET_CONCERTHALL);
	}
	else if (preset == 8)
	{
		SetEAXParams(EFX_REVERB_PRESET_CAVE);
	}
	else if (preset == 9)
	{
		SetEAXParams(EFX_REVERB_PRESET_ARENA);
	}
	else if (preset == 10)
	{
		SetEAXParams(EFX_REVERB_PRESET_HANGAR);
	}
	else if (preset == 11)
	{
		SetEAXParams(EFX_REVERB_PRESET_CARPETEDHALLWAY);
	}
	else if (preset == 12)
	{
		SetEAXParams(EFX_REVERB_PRESET_HALLWAY);
	}
	else if (preset == 13)
	{
		SetEAXParams(EFX_REVERB_PRESET_STONECORRIDOR);
	}
	else if (preset == 14)
	{
		SetEAXParams(EFX_REVERB_PRESET_ALLEY);
	}
	else if (preset == 15)
	{
		SetEAXParams(EFX_REVERB_PRESET_FOREST);
	}
	else if (preset == 16)
	{
		SetEAXParams(EFX_REVERB_PRESET_CITY);
	}
	else if (preset == 17)
	{
		SetEAXParams(EFX_REVERB_PRESET_MOUNTAINS);
	}
	else if (preset == 18)
	{
		SetEAXParams(EFX_REVERB_PRESET_QUARRY);
	}
	else if (preset == 19)
	{
		SetEAXParams(EFX_REVERB_PRESET_PLAIN);
	}
	else if (preset == 20)
	{
		SetEAXParams(EFX_REVERB_PRESET_PARKINGLOT);
	}
	else if (preset == 21)
	{
		SetEAXParams(EFX_REVERB_PRESET_SEWERPIPE);
	}
	else if (preset == 22)
	{
		SetEAXParams(EFX_REVERB_PRESET_UNDERWATER);
	}
	else if (preset == 23)
	{
		SetEAXParams(EFX_REVERB_PRESET_DRUGGED);
	}
	else if (preset == 24)
	{
		SetEAXParams(EFX_REVERB_PRESET_DIZZY);
	}
	else if (preset == 25)
	{
		SetEAXParams(EFX_REVERB_PRESET_PSYCHOTIC);
	}
	else if (preset == 26)
	{
		SetEAXParams(EFX_REVERB_PRESET_CASTLE_SMALLROOM);
	}
	else if (preset == 27)
	{
		SetEAXParams(EFX_REVERB_PRESET_CASTLE_SHORTPASSAGE);
	}
	else if (preset == 28)
	{
		SetEAXParams(EFX_REVERB_PRESET_CASTLE_MEDIUMROOM);
	}
	else if (preset == 29)
	{
		SetEAXParams(EFX_REVERB_PRESET_CASTLE_LARGEROOM);
	}
	else if (preset == 30)
	{
		SetEAXParams(EFX_REVERB_PRESET_CASTLE_LONGPASSAGE);
	}
	else if (preset == 31)
	{
		SetEAXParams(EFX_REVERB_PRESET_CASTLE_HALL);
	}
	else if (preset == 32)
	{
		SetEAXParams(EFX_REVERB_PRESET_CASTLE_CUPBOARD);
	}
	else if (preset == 33)
	{
		SetEAXParams(EFX_REVERB_PRESET_CASTLE_COURTYARD);
	}
	else if (preset == 34)
	{
		SetEAXParams(EFX_REVERB_PRESET_CASTLE_ALCOVE);
	}
	else if (preset == 35)
	{
		SetEAXParams(EFX_REVERB_PRESET_FACTORY_SMALLROOM);
	}
	else if (preset == 36)
	{
		SetEAXParams(EFX_REVERB_PRESET_FACTORY_SHORTPASSAGE);
	}
	else if (preset == 37)
	{
		SetEAXParams(EFX_REVERB_PRESET_FACTORY_MEDIUMROOM);
	}
	else if (preset == 38)
	{
		SetEAXParams(EFX_REVERB_PRESET_FACTORY_LARGEROOM);
	}
	else if (preset == 39)
	{
		SetEAXParams(EFX_REVERB_PRESET_FACTORY_LONGPASSAGE);
	}
	else if (preset == 40)
	{
		SetEAXParams(EFX_REVERB_PRESET_FACTORY_HALL);
	}
	else if (preset == 41)
	{
		SetEAXParams(EFX_REVERB_PRESET_FACTORY_CUPBOARD);
	}
	else if (preset == 42)
	{
		SetEAXParams(EFX_REVERB_PRESET_FACTORY_COURTYARD);
	}
	else if (preset == 43)
	{
		SetEAXParams(EFX_REVERB_PRESET_FACTORY_ALCOVE);
	}
	else if (preset == 44)
	{
		SetEAXParams(EFX_REVERB_PRESET_ICEPALACE_SMALLROOM);
	}
	else if (preset == 45)
	{
		SetEAXParams(EFX_REVERB_PRESET_ICEPALACE_SHORTPASSAGE);
	}
	else if (preset == 46)
	{
		SetEAXParams(EFX_REVERB_PRESET_ICEPALACE_MEDIUMROOM);
	}
	else if (preset == 47)
	{
		SetEAXParams(EFX_REVERB_PRESET_ICEPALACE_LARGEROOM);
	}
	else if (preset == 48)
	{
		SetEAXParams(EFX_REVERB_PRESET_ICEPALACE_LONGPASSAGE);
	}
	else if (preset == 49)
	{
		SetEAXParams(EFX_REVERB_PRESET_ICEPALACE_HALL);
	}
	else if (preset == 50)
	{
		SetEAXParams(EFX_REVERB_PRESET_ICEPALACE_CUPBOARD);
	}
	else if (preset == 51)
	{
		SetEAXParams(EFX_REVERB_PRESET_ICEPALACE_COURTYARD);
	}
	else if (preset == 52)
	{
		SetEAXParams(EFX_REVERB_PRESET_ICEPALACE_ALCOVE);
	}
	else if (preset == 53)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPACESTATION_SMALLROOM);
	}
	else if (preset == 54)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPACESTATION_SHORTPASSAGE);
	}
	else if (preset == 55)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPACESTATION_MEDIUMROOM);
	}
	else if (preset == 56)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPACESTATION_LARGEROOM);
	}
	else if (preset == 57)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPACESTATION_LONGPASSAGE);
	}
	else if (preset == 58)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPACESTATION_HALL);
	}
	else if (preset == 59)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPACESTATION_CUPBOARD);
	}
	else if (preset == 60)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPACESTATION_ALCOVE);
	}
	else if (preset == 61)
	{
		SetEAXParams(EFX_REVERB_PRESET_WOODEN_SMALLROOM);
	}
	else if (preset == 62)
	{
		SetEAXParams(EFX_REVERB_PRESET_WOODEN_SHORTPASSAGE);
	}
	else if (preset == 63)
	{
		SetEAXParams(EFX_REVERB_PRESET_WOODEN_MEDIUMROOM);
	}
	else if (preset == 64)
	{
		SetEAXParams(EFX_REVERB_PRESET_WOODEN_LARGEROOM);
	}
	else if (preset == 65)
	{
		SetEAXParams(EFX_REVERB_PRESET_WOODEN_LONGPASSAGE);
	}
	else if (preset == 66)
	{
		SetEAXParams(EFX_REVERB_PRESET_WOODEN_HALL);
	}
	else if (preset == 67)
	{
		SetEAXParams(EFX_REVERB_PRESET_WOODEN_CUPBOARD);
	}
	else if (preset == 68)
	{
		SetEAXParams(EFX_REVERB_PRESET_WOODEN_COURTYARD);
	}
	else if (preset == 69)
	{
		SetEAXParams(EFX_REVERB_PRESET_WOODEN_ALCOVE);
	}
	else if (preset == 70)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPORT_EMPTYSTADIUM);
	}
	else if (preset == 71)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPORT_SQUASHCOURT);
	}
	else if (preset == 72)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPORT_SMALLSWIMMINGPOOL);
	}
	else if (preset == 73)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPORT_LARGESWIMMINGPOOL);
	}
	else if (preset == 74)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPORT_GYMNASIUM);
	}
	else if (preset == 75)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPORT_FULLSTADIUM);
	}
	else if (preset == 76)
	{
		SetEAXParams(EFX_REVERB_PRESET_SPORT_STADIUMTANNOY);
	}
	else if (preset == 77)
	{
		SetEAXParams(EFX_REVERB_PRESET_PREFAB_WORKSHOP);
	}
	else if (preset == 78)
	{
		SetEAXParams(EFX_REVERB_PRESET_PREFAB_SCHOOLROOM);
	}
	else if (preset == 79)
	{
		SetEAXParams(EFX_REVERB_PRESET_PREFAB_PRACTISEROOM);
	}
	else if (preset == 80)
	{
		SetEAXParams(EFX_REVERB_PRESET_PREFAB_OUTHOUSE);
	}
	else if (preset == 81)
	{
		SetEAXParams(EFX_REVERB_PRESET_PREFAB_CARAVAN);
	}
	else if (preset == 82)
	{
		SetEAXParams(EFX_REVERB_PRESET_DOME_TOMB);
	}
	else if (preset == 83)
	{
		SetEAXParams(EFX_REVERB_PRESET_PIPE_SMALL);
	}
	else if (preset == 84)
	{
		SetEAXParams(EFX_REVERB_PRESET_DOME_SAINTPAULS);
	}
	else if (preset == 85)
	{
		SetEAXParams(EFX_REVERB_PRESET_PIPE_LONGTHIN);
	}
	else if (preset == 86)
	{
		SetEAXParams(EFX_REVERB_PRESET_PIPE_LARGE);
	}
	else if (preset == 87)
	{
		SetEAXParams(EFX_REVERB_PRESET_PIPE_RESONANT);
	}
	else if (preset == 88)
	{
		SetEAXParams(EFX_REVERB_PRESET_OUTDOORS_BACKYARD);
	}
	else if (preset == 89)
	{
		SetEAXParams(EFX_REVERB_PRESET_OUTDOORS_ROLLINGPLAINS);
	}
	else if (preset == 90)
	{
		SetEAXParams(EFX_REVERB_PRESET_OUTDOORS_DEEPCANYON);
	}
	else if (preset == 91)
	{
		SetEAXParams(EFX_REVERB_PRESET_OUTDOORS_CREEK);
	}
	else if (preset == 92)
	{
		SetEAXParams(EFX_REVERB_PRESET_OUTDOORS_VALLEY);
	}
	else if (preset == 93)
	{
		SetEAXParams(EFX_REVERB_PRESET_MOOD_HEAVEN);
	}
	else if (preset == 94)
	{
		SetEAXParams(EFX_REVERB_PRESET_MOOD_HELL);
	}
	else if (preset == 95)
	{
		SetEAXParams(EFX_REVERB_PRESET_MOOD_MEMORY);
	}
	else if (preset == 96)
	{
		SetEAXParams(EFX_REVERB_PRESET_DRIVING_COMMENTATOR);
	}
	else if (preset == 97)
	{
		SetEAXParams(EFX_REVERB_PRESET_DRIVING_PITGARAGE);
	}
	else if (preset == 98)
	{
		SetEAXParams(EFX_REVERB_PRESET_DRIVING_INCAR_RACER);
	}
	else if (preset == 99)
	{
		SetEAXParams(EFX_REVERB_PRESET_DRIVING_INCAR_SPORTS);
	}
	else if (preset == 100)
	{
		SetEAXParams(EFX_REVERB_PRESET_DRIVING_INCAR_LUXURY);
	}
	else if (preset == 101)
	{
		SetEAXParams(EFX_REVERB_PRESET_DRIVING_FULLGRANDSTAND);
	}
	else if (preset == 102)
	{
		SetEAXParams(EFX_REVERB_PRESET_DRIVING_EMPTYGRANDSTAND);
	}
	else if (preset == 103)
	{
		SetEAXParams(EFX_REVERB_PRESET_DRIVING_TUNNEL);
	}
	else if (preset == 104)
	{
		SetEAXParams(EFX_REVERB_PRESET_CITY_STREETS);
	}
	else if (preset == 105)
	{
		SetEAXParams(EFX_REVERB_PRESET_CITY_SUBWAY);
	}
	else if (preset == 106)
	{
		SetEAXParams(EFX_REVERB_PRESET_CITY_MUSEUM);
	}
	else if (preset == 107)
	{
		SetEAXParams(EFX_REVERB_PRESET_CITY_LIBRARY);
	}
	else if (preset == 108)
	{
		SetEAXParams(EFX_REVERB_PRESET_CITY_UNDERPASS);
	}
	else if (preset == 109)
	{
		SetEAXParams(EFX_REVERB_PRESET_CITY_ABANDONED);
	}
	else if (preset == 110)
	{
		SetEAXParams(EFX_REVERB_PRESET_DUSTYROOM);
	}
	else if (preset == 111)
	{
		SetEAXParams(EFX_REVERB_PRESET_CHAPEL);
	}
	else if (preset == 112)
	{
		SetEAXParams(EFX_REVERB_PRESET_SMALLWATERROOM);
	}
	else
	{
		SetEAXParams(EFX_REVERB_PRESET_GENERIC);
	}
}

char *EAXReverb::GetPresetName(int preset) {
	//get the name of a preset
	if (preset == 0)
	{
		return "GENERIC";
	}
	else if (preset == 1)
	{
		return "PADDEDCELL";
	}
	else if (preset == 2)
	{
		return "ROOM";
	}
	else if (preset == 3)
	{
		return "BATHROOM";
	}
	else if (preset == 4)
	{
		return "LIVINGROOM";
	}
	else if (preset == 5)
	{
		return "STONEROOM";
	}
	else if (preset == 6)
	{
		return "AUDITORIUM";
	}
	else if (preset == 7)
	{
		return "CONCERTHALL";
	}
	else if (preset == 8)
	{
		return "CAVE";
	}
	else if (preset == 9)
	{
		return "ARENA";
	}
	else if (preset == 10)
	{
		return "HANGAR";
	}
	else if (preset == 11)
	{
		return "CARPETEDHALLWAY";
	}
	else if (preset == 12)
	{
		return "HALLWAY";
	}
	else if (preset == 13)
	{
		return "STONECORRIDOR";
	}
	else if (preset == 14)
	{
		return "ALLEY";
	}
	else if (preset == 15)
	{
		return "FOREST";
	}
	else if (preset == 16)
	{
		return "CITY";
	}
	else if (preset == 17)
	{
		return "MOUNTAINS";
	}
	else if (preset == 18)
	{
		return "QUARRY";
	}
	else if (preset == 19)
	{
		return "PLAIN";
	}
	else if (preset == 20)
	{
		return "PARKINGLOT";
	}
	else if (preset == 21)
	{
		return "SEWERPIPE";
	}
	else if (preset == 22)
	{
		return "UNDERWATER";
	}
	else if (preset == 23)
	{
		return "DRUGGED";
	}
	else if (preset == 24)
	{
		return "DIZZY";
	}
	else if (preset == 25)
	{
		return "PSYCHOTIC";
	}
	else if (preset == 26)
	{
		return "CASTLE_SMALLROOM";
	}
	else if (preset == 27)
	{
		return "CASTLE_SHORTPASSAGE";
	}
	else if (preset == 28)
	{
		return "CASTLE_MEDIUMROOM";
	}
	else if (preset == 29)
	{
		return "CASTLE_LARGEROOM";
	}
	else if (preset == 30)
	{
		return "CASTLE_LONGPASSAGE";
	}
	else if (preset == 31)
	{
		return "CASTLE_HALL";
	}
	else if (preset == 32)
	{
		return "CASTLE_CUPBOARD";
	}
	else if (preset == 33)
	{
		return "CASTLE_COURTYARD";
	}
	else if (preset == 34)
	{
		return "CASTLE_ALCOVE";
	}
	else if (preset == 35)
	{
		return "FACTORY_SMALLROOM";
	}
	else if (preset == 36)
	{
		return "FACTORY_SHORTPASSAGE";
	}
	else if (preset == 37)
	{
		return "FACTORY_MEDIUMROOM";
	}
	else if (preset == 38)
	{
		return "FACTORY_LARGEROOM";
	}
	else if (preset == 39)
	{
		return "FACTORY_LONGPASSAGE";
	}
	else if (preset == 40)
	{
		return "FACTORY_HALL";
	}
	else if (preset == 41)
	{
		return "FACTORY_CUPBOARD";
	}
	else if (preset == 42)
	{
		return "FACTORY_COURTYARD";
	}
	else if (preset == 43)
	{
		return "FACTORY_ALCOVE";
	}
	else if (preset == 44)
	{
		return "ICEPALACE_SMALLROOM";
	}
	else if (preset == 45)
	{
		return "ICEPALACE_SHORTPASSAGE";
	}
	else if (preset == 46)
	{
		return "ICEPALACE_MEDIUMROOM";
	}
	else if (preset == 47)
	{
		return "ICEPALACE_LARGEROOM";
	}
	else if (preset == 48)
	{
		return "ICEPALACE_LONGPASSAGE";
	}
	else if (preset == 49)
	{
		return "ICEPALACE_HALL";
	}
	else if (preset == 50)
	{
		return "ICEPALACE_CUPBOARD";
	}
	else if (preset == 51)
	{
		return "ICEPALACE_COURTYARD";
	}
	else if (preset == 52)
	{
		return "ICEPALACE_ALCOVE";
	}
	else if (preset == 53)
	{
		return "SPACESTATION_SMALLROOM";
	}
	else if (preset == 54)
	{
		return "SPACESTATION_SHORTPASSAGE";
	}
	else if (preset == 55)
	{
		return "SPACESTATION_MEDIUMROOM";
	}
	else if (preset == 56)
	{
		return "SPACESTATION_LARGEROOM";
	}
	else if (preset == 57)
	{
		return "SPACESTATION_LONGPASSAGE";
	}
	else if (preset == 58)
	{
		return "SPACESTATION_HALL";
	}
	else if (preset == 59)
	{
		return "SPACESTATION_CUPBOARD";
	}
	else if (preset == 60)
	{
		return "SPACESTATION_ALCOVE";
	}
	else if (preset == 61)
	{
		return "WOODEN_SMALLROOM";
	}
	else if (preset == 62)
	{
		return "WOODEN_SHORTPASSAGE";
	}
	else if (preset == 63)
	{
		return "WOODEN_MEDIUMROOM";
	}
	else if (preset == 64)
	{
		return "WOODEN_LARGEROOM";
	}
	else if (preset == 65)
	{
		return "WOODEN_LONGPASSAGE";
	}
	else if (preset == 66)
	{
		return "WOODEN_HALL";
	}
	else if (preset == 67)
	{
		return "WOODEN_CUPBOARD";
	}
	else if (preset == 68)
	{
		return "WOODEN_COURTYARD";
	}
	else if (preset == 69)
	{
		return "WOODEN_ALCOVE";
	}
	else if (preset == 70)
	{
		return "SPORT_EMPTYSTADIUM";
	}
	else if (preset == 71)
	{
		return "SPORT_SQUASHCOURT";
	}
	else if (preset == 72)
	{
		return "SPORT_SMALLSWIMMINGPOOL";
	}
	else if (preset == 73)
	{
		return "SPORT_LARGESWIMMINGPOOL";
	}
	else if (preset == 74)
	{
		return "SPORT_GYMNASIUM";
	}
	else if (preset == 75)
	{
		return "SPORT_FULLSTADIUM";
	}
	else if (preset == 76)
	{
		return "SPORT_STADIUMTANNOY";
	}
	else if (preset == 77)
	{
		return "PREFAB_WORKSHOP";
	}
	else if (preset == 78)
	{
		return "PREFAB_SCHOOLROOM";
	}
	else if (preset == 79)
	{
		return "PREFAB_PRACTISEROOM";
	}
	else if (preset == 80)
	{
		return "PREFAB_OUTHOUSE";
	}
	else if (preset == 81)
	{
		return "PREFAB_CARAVAN";
	}
	else if (preset == 82)
	{
		return "DOME_TOMB";
	}
	else if (preset == 83)
	{
		return "PIPE_SMALL";
	}
	else if (preset == 84)
	{
		return "DOME_SAINTPAULS";
	}
	else if (preset == 85)
	{
		return "PIPE_LONGTHIN";
	}
	else if (preset == 86)
	{
		return "PIPE_LARGE";
	}
	else if (preset == 87)
	{
		return "PIPE_RESONANT";
	}
	else if (preset == 88)
	{
		return "OUTDOORS_BACKYARD";
	}
	else if (preset == 89)
	{
		return "OUTDOORS_ROLLINGPLAINS";
	}
	else if (preset == 90)
	{
		return "OUTDOORS_DEEPCANYON";
	}
	else if (preset == 91)
	{
		return "OUTDOORS_CREEK";
	}
	else if (preset == 92)
	{
		return "OUTDOORS_VALLEY";
	}
	else if (preset == 93)
	{
		return "MOOD_HEAVEN";
	}
	else if (preset == 94)
	{
		return "MOOD_HELL";
	}
	else if (preset == 95)
	{
		return "MOOD_MEMORY";
	}
	else if (preset == 96)
	{
		return "DRIVING_COMMENTATOR";
	}
	else if (preset == 97)
	{
		return "DRIVING_PITGARAGE";
	}
	else if (preset == 98)
	{
		return "DRIVING_INCAR_RACER";
	}
	else if (preset == 99)
	{
		return "DRIVING_INCAR_SPORTS";
	}
	else if (preset == 100)
	{
		return "DRIVING_INCAR_LUXURY";
	}
	else if (preset == 101)
	{
		return "DRIVING_FULLGRANDSTAND";
	}
	else if (preset == 102)
	{
		return "DRIVING_EMPTYGRANDSTAND";
	}
	else if (preset == 103)
	{
		return "DRIVING_TUNNEL";
	}
	else if (preset == 104)
	{
		return "CITY_STREETS";
	}
	else if (preset == 105)
	{
		return "CITY_SUBWAY";
	}
	else if (preset == 106)
	{
		return "CITY_MUSEUM";
	}
	else if (preset == 107)
	{
		return "CITY_LIBRARY";
	}
	else if (preset == 108)
	{
		return "CITY_UNDERPASS";
	}
	else if (preset == 109)
	{
		return "CITY_ABANDONED";
	}
	else if (preset == 110)
	{
		return "DUSTYROOM";
	}
	else if (preset == 111)
	{
		return "CHAPEL";
	}
	else if (preset == 112)
	{
		return "SMALLWATERROOM";
	}
	return "GENERIC";
}
