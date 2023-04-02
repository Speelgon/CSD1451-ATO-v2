#include "audio.hpp"
//==========================================================
// file		: audio.cpp
// 
// author   : Tham Kwan Eu
// 
// email	: t.kwaneu@digipen.edu
//
// brief	: file that handles the background music and sound effects for the game
//
// Copyright © 2023 DigiPen, All rights reserved.
//==========================================================
// 
//===================================//
//			Sound Groups enum		 //
//===================================//
//Group numbering: 
//	0 - bgm
//	1 - sfx;
enum soundGrouping {
	BGM, SFX, MAXGROUPS = 2
};

//===================================//
//			Sound Types enum		 //
//===================================//
enum soundType {
	bounce, menubgm, level1bgm, level4bgm, level5bgm, level7bgm, nodeCollide, portalCollision, collectibleCollision, platformDisappeared, win, spawn, MAXASSETS
};

AEAudio soundList[MAXASSETS];

AEAudioGroup soundGroups[MAXGROUPS];

bool bgmPlayed{ false }, jumped{ false };

HWND windowHandle;

/*!
\brief	function that loads all sound assets into the game
		and sets the soundgroups for background music and sound effects
*/
void initAudioList() {
	//soundListVector.push_back(AEAudioLoadSound("Assets/Sound/bounce.wav"));
	soundList[bounce] = AEAudioLoadSound("Assets/Sound/bounce.wav");
	soundList[menubgm] = AEAudioLoadSound("Assets/Sound/menuBGM.wav");
	soundList[level1bgm] = AEAudioLoadSound("Assets/Sound/level1bgm.wav");
	soundList[level4bgm] = AEAudioLoadSound("Assets/Sound/level4bgm.wav");
	soundList[level5bgm] = AEAudioLoadSound("Assets/Sound/level5bgm.wav");
	soundList[level7bgm] = AEAudioLoadSound("Assets/Sound/level7bgm.wav");
	soundList[nodeCollide] = AEAudioLoadSound("Assets/Sound/nodeCollide.wav");
	soundList[portalCollision] = AEAudioLoadSound("Assets/Sound/portalCollision.wav");
	soundList[collectibleCollision] = AEAudioLoadSound("Assets/Sound/collectibleCollision.wav");
	soundList[platformDisappeared] = AEAudioLoadSound("Assets/Sound/platformDisappear.wav");
	soundList[win] = AEAudioLoadSound("Assets/Sound/win.wav");
	soundList[spawn] = AEAudioLoadSound("Assets/Sound/spawn.wav");

	//check that all audio is valid, else exit
	for (int i{ 0 }; i < MAXASSETS; ++i) {	
		if (!AEAudioIsValidAudio(soundList[i])) {
			std::cout << "INVALID AUDIO\n";
			continue;
		}
	}

	//======================================//
	//			Sound Group Creation		//
	//======================================//
	//Set all sound group to default volume and pitch to be 1
	//** Required else sound will never play
	for (int i{ 0 }; i < MAXGROUPS; ++i) {
		soundGroups[i] = AEAudioCreateGroup();
		if (AEAudioIsValidGroup(soundGroups[i])) {
			AEAudioSetGroupPitch(soundGroups[i], 1);
			AEAudioSetGroupVolume(soundGroups[i], 1);
		}
	}
}

/*!
\brief	function that calls the AEAudioPlay function and allows the customisation of volume, pitch and loop
		also has default values for volume, pitch and loop
*/
void playAudio(AEAudio const& audio, AEAudioGroup group, double volume, double pitch, s32 loop) {
	if (!AEAudioIsValidAudio(audio)) {
		return;
	}
	AEAudioPlay(audio, group, static_cast<float>(volume), static_cast<float>(pitch), loop);
}

/*!
\brief	function that handles majority of the audio playback for bgm and sfx
		
*/
void updateSound() {
	//============ BGM ============//
	if (!bgmPlayed) {
		switch (current) {
		case GS_LEVEL1:
			playAudio(soundList[level1bgm], soundGroups[BGM], 0.4f, 1, -1);
			break;
		case GS_LEVEL2:
			playAudio(soundList[level1bgm], soundGroups[BGM], 0.4f, 0.9f, -1);
			break;
		case GS_LEVEL3:
			playAudio(soundList[level4bgm], soundGroups[BGM], 0.4f, 1, -1);
			break;
		case GS_LEVEL4:
			playAudio(soundList[level4bgm], soundGroups[BGM], 0.4f, 0.9f, -1);
			break;
		case GS_LEVEL5:
			playAudio(soundList[level5bgm], soundGroups[BGM], 0.4f, 1, -1);
			break;
		case GS_LEVEL6: 
			playAudio(soundList[level5bgm], soundGroups[BGM], 0.4f, 0.9f, -1);
			break;
		case GS_LEVEL7: 
			playAudio(soundList[level7bgm], soundGroups[BGM], 0.4f, 1, -1);
			break;
		case GS_LEVELSELECTOR:
		case GS_MAINMENU:
			playAudio(soundList[menubgm], soundGroups[BGM], 0.4f, 1, -1);
			break;
		case GS_WINSCREEN:
			playAudio(soundList[win], soundGroups[SFX], 0.4f, 1, 0);
			break;
		/*
		case GS_LEVEL8: 
		playAudio(soundList[level7bgm], soundGroups[BGM], 0.4f, 0.9f, -1);
		break;
		*/
		}
		bgmPlayed = true;
	}
	//=============================//



	//======= Detect Collision Events ========//
	//Collision objects: Portal, Collectibles, Nodes
	
	//nodes
	if (AEInputCheckTriggered(AEVK_LBUTTON) && hookCollisionFlag) {
		playAudio(soundList[nodeCollide], soundGroups[SFX], 0.4);
	}
	
	//collectible small fix needed
	if (collectibleHit) {
		playAudio(soundList[collectibleCollision], soundGroups[1]);
		collectibleHit = false;
	}

	//platform disappearing
	if (platformDisappear) {
		playAudio(soundList[platformDisappeared], soundGroups[SFX], 0.4);
		platformDisappear = false;
	}

	//trampoline
	if (trampolined) {
		playAudio(soundList[bounce], soundGroups[SFX], 0.4f, 0.8f);
		trampolined = false;
	}

	//blackhole
	if (blackholeTouched) {
		playAudio(soundList[spawn], soundGroups[SFX], 0.4f);
		
	}
	//========================================//

	
	//======= Input detection =======//
	//jump detection
	if (jumptoken) jumped = false;
	if (AEInputCheckTriggered(AEVK_W) && !jumped) {
		//play jump sound
		playAudio(soundList[bounce], soundGroups[SFX], 0.4);
		if (jumptoken == 0) {
			jumped = true;
		}
	}

	//if (AEInputCheckTriggered(AEVK_E)) {
	if (portalled) {
		playAudio(soundList[portalCollision], soundGroups[SFX], 0.4);
		portalled = false;
	}
	//}
	//===============================//

	//======== Window Minimized Check =========//
	/*!
	\brief	checks if window is minimized using IsIconic in window.h
			pauses all sound groups if minimized
			resumes all sound groups when window is focused
	*/
	windowHandle = AESysGetWindowHandle();
	if (IsIconic(windowHandle)) {
		for (int i{ 0 }; i < MAXGROUPS; ++i) {
			AEAudioPauseGroup(soundGroups[i]);
		}
	}
	else {
		for (int i{ 0 }; i < MAXGROUPS; ++i) {
			AEAudioResumeGroup(soundGroups[i]);
		}
	}
	//============================================//
}

/*!
\brief	resets all flags to false and stops all soundgroups from playing audio
		resets all soundgroup pitch and volume to 0
*/
void freeSound() {
	bgmPlayed = false;
	jumped = false;
	for (int i{ 0 }; i < MAXGROUPS; ++i) {
		AEAudioStopGroup(soundGroups[i]);
		AEAudioSetGroupPitch(soundGroups[i], 0);
		AEAudioSetGroupVolume(soundGroups[i], 0);
	}
}