#include "audio.hpp"

#define maxSoundAssets 8

//===================================//
//			Sound Groups enum		 //
//===================================//
//Group numbering: 
//	0 - bgm
//	1 - sfx;
enum soundGrouping {
	BGM, SFX, MAXGROUPS = 2
};

AEAudio soundList[maxSoundAssets];

//std::vector<AEAudio> soundListVector;


AEAudioGroup soundGroups[MAXGROUPS];

bool bgmPlayed{ false }, jumped{ false }, hooked{ true };

void initAudioList() {
	//soundListVector.push_back(AEAudioLoadSound("Assets/Sound/bounce.wav"));
	soundList[0] = AEAudioLoadSound("Assets/Sound/bounce.wav");
	soundList[1] = AEAudioLoadSound("Assets/Sound/level1bgm.wav");
	soundList[2] = AEAudioLoadSound("Assets/Sound/nodeCollide.wav");
	soundList[3] = AEAudioLoadSound("Assets/Sound/portalCollision.wav");
	soundList[4] = AEAudioLoadSound("Assets/Sound/collectibleCollision.wav");
	soundList[5] = AEAudioLoadSound("Assets/Sound/platformDisappear.wav");
	soundList[6] = AEAudioLoadSound("Assets/Sound/spawn.wav");

	//check that all audio is valid, else exit
	for (int i{ 0 }; i < 1; ++i) {	
		if (!AEAudioIsValidAudio(soundList[i])) {
			std::cout << "INVALID AUDIO\n";
			return;
		}
	}
	//======================================//
	//			Sound Group Creation		//
	//======================================//
	//Set all sound group to default volume and pitch to be 1
	//** Required else sound will never play
	for (int i{ 0 }; i < 2; ++i) {
		soundGroups[i] = AEAudioCreateGroup();
		if (AEAudioIsValidGroup(soundGroups[i])) {
			AEAudioSetGroupPitch(soundGroups[i], 1);
			AEAudioSetGroupVolume(soundGroups[i], 1);
		}
		if (current == GS_LEVEL2) {
			AEAudioResumeGroup(soundGroups[i]);
		}
	}
	
	
	/*for (int i{ 0 }; i < maxAudio; ++i) {
	}*/
}

void playAudio(AEAudio const& audio, AEAudioGroup group, double volume, double pitch, s32 loop) {
	if (!AEAudioIsValidAudio(audio)) {
		return;
	}
	AEAudioPlay(audio, soundGroups[0], volume, pitch, loop);
}

void updateSound() {
	//============ BGM ============//
	if (!bgmPlayed) {
		switch (current) {
		case GS_LEVEL1:
			playAudio(soundList[1], soundGroups[BGM], 0.4, 1, -1);
			break;
		case GS_LEVEL2:
			playAudio(soundList[1], soundGroups[BGM], 0.4, 1, -1);
			break;
		case GS_LEVEL3:
			playAudio(soundList[1], soundGroups[BGM], 0.4, 1, -1);
			break;
		/*case GS_LEVEL4: break;
		case GS_LEVEL5: break;
		case GS_LEVEL6: break;
		case GS_LEVEL7: break;
		case GS_LEVEL8: break;
		case GS_LEVEL9: break;
		case GS_LEVEL10: break;*/
		}
		//if (gAEGameStateCurr == GS_LEVEL1) {
		//	playAudio(soundList[1], soundGroups[0], 1, 1, -1);
		//}
		//if (gAEGameStateCurr == GS_LEVEL2) {
		//	//play level 2 sound
		//}
		bgmPlayed = true;
	}

	
	//=============================//
	





	//======= Detect Collision Events ========//
	//Collision objects: Portal, Exit Door, Collectibles, Nodes
	//nodes
	if (hookCollisionFlag) hooked = false;
	if (AEInputCheckTriggered(AEVK_LBUTTON) && !hooked) {
		playAudio(soundList[2], soundGroups[SFX], 0.4);
		if (!hookCollisionFlag) {
			hooked = true;
		}
	}
	
	//collectible small fix needed
	/*if (collectibleHit) {
		playAudio(soundList[4], soundGroups[1]);
		collectibleHit = false;
	}*/

	if (current == GS_RESTART) {
		playAudio(soundList[6], soundGroups[SFX], 0.4);
	}

	if (platformDisappear) {
		playAudio(soundList[5], soundGroups[SFX], 0.4);
		platformDisappear = false;
	}
	//========================================//
	
	
	
	
	//======= Input detection =======//
	//jump detection
	if (jumptoken) jumped = false;
	if (AEInputCheckTriggered(AEVK_W) && !jumped) {
		//play jump sound
		playAudio(soundList[0], soundGroups[SFX], 0.4);
		if (jumptoken == 0) {
			jumped = true;
		}
	}

	
	if (AEInputCheckTriggered(AEVK_E)) {
		if (portalled) {
			playAudio(soundList[3], soundGroups[SFX], 0.4);
			portalled = false;
		}
	}
	//===============================//

}

void freeSound() {
	for (int i{ 0 }; i < 2; ++i) {
		AEAudioStopGroup(soundGroups[i]);
		AEAudioSetGroupPitch(soundGroups[i], 0);
		AEAudioSetGroupVolume(soundGroups[i], 0);
	}
}