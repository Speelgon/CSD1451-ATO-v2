#pragma once
#include "allheaders.hpp"

//=========== AE AUDIO VARIABLES ===========//

//======= END OF AE AUDIO VARIABLES ========//

/***************************************
@brief		loading the list of sound assets to be used in the game
@params[in]	AEAudio soundList pointer to the variable containing the list of sound assets
***************************************/
void initAudioList();


/***************************************
@brief		play sound using AEAudioPlay
@params[in]	AEAudio soundList pointer to the variable containing the list of sound assets
***************************************/
void playAudio(AEAudio const& audioList, AEAudioGroup group, float volume = 1, float pitch = 1, s32 loops = 0);


/***************************************
@brief		handle audio to be played on levels from input & events
***************************************/
void updateSound();