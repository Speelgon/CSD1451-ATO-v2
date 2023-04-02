#pragma once
#include "allheaders.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <Windows.h>
//==========================================================
// file		: audio.hpp
// 
// author   : Tham Kwan Eu
// 
// email	: t.kwaneu@digipen.edu
//
// brief	: file that declares functions to be used in audio.cpp
//			  also references external variables to be used
//
// Copyright © 2023 DigiPen, All rights reserved.

//=========== AE AUDIO VARIABLES ===========//
extern int current;
extern bool portalled;
extern bool jumped;
extern bool trampolined;
extern bool blackholeTouched;
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
void playAudio(AEAudio const& audioList, AEAudioGroup group, double volume = 0.5, double pitch = 1, s32 loops = 0);


/***************************************
@brief		handle audio to be played on levels from input & events
***************************************/
void updateSound();

/***************************************
@brief		stops all sound groups and resets all external variables
***************************************/
void freeSound();