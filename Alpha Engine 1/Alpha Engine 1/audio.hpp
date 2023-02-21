#pragma once
#include "allheaders.hpp"

//=========== AE AUDIO VARIABLES ===========//
const int maxAudio{ 10 };

AEAudio soundList[maxAudio];

AEAudio jump; //temporary variable

//======= END OF AE AUDIO VARIABLES ========//

/***************************************

@brief		loading the list of sound assets to be used in the game

@params[in]	AEAudio soundList pointer to the variable containing the list of sound assets


***************************************/
void initAudioList(AEAudio* soundList);


/***************************************

@brief		play sound using AEAudioPlay

@params[in]	AEAudio soundList pointer to the variable containing the list of sound assets


***************************************/
void playAudio(const AEAudio *audioList);


/***************************************

@brief		handle audio to be played on levels from detecting input/events

***************************************/
void updateAudio();