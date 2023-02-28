#include "audio.hpp"

#define SoundGroups 2
#define maxSoundAssets 6

AEAudio soundList[6];

AEAudio jump; //temporary variable


//===================================//
//			Sound Groups			 //
//===================================//
//Group numbering: 
//	0 - bgm
//	1 - sfx;
AEAudioGroup soundGroups[SoundGroups];

bool bgmPlayed{ false }, jumped{ false }, hooked{ true };

void initAudioList() {
	soundList[0] = AEAudioLoadSound("Assets/Sound/bounce.wav");
	soundList[1] = AEAudioLoadSound("Assets/Sound/level1bgm.wav");
	soundList[2] = AEAudioLoadSound("Assets/Sound/nodeCollide.wav");
	soundList[3] = AEAudioLoadSound("Assets/Sound/portalCollision.wav");
	soundList[4] = AEAudioLoadSound("Assets/Sound/collectibleCollision.wav");
	soundList[5] = AEAudioLoadSound("Assets/Sound/platformDisappear.wav");

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
	}
	
	
	/*for (int i{ 0 }; i < maxAudio; ++i) {
	}*/
}

void playAudio(AEAudio const& audio, AEAudioGroup group, float volume, float pitch, s32 loop) {
	if (!AEAudioIsValidAudio(audio)) {
		return;
	}
	AEAudioPlay(audio, soundGroups[0], volume, pitch, loop);
}

void updateSound() {
	//============ BGM ============//
	if (!bgmPlayed) {
		playAudio(soundList[1], soundGroups[0], 1, 1, -1);
		bgmPlayed = true;
	}
	//=============================//
	//
	//
	//
	// 
	// 
	//======= Detect collision events ========//
	//nodes
	if (hookCollisionFlag) hooked = false;
	if (AEInputCheckTriggered(AEVK_LBUTTON) && !hooked) {
		playAudio(soundList[2], soundGroups[1]);
		if (!hookCollisionFlag) {
			hooked = true;
		}
	}
	
	//collectible small fix needed
	/*if (collectibleHit) {
		playAudio(soundList[4], soundGroups[1]);
		collectibleHit = false;
	}*/

	//portal
	if (portalled) {
		playAudio(soundList[3], soundGroups[1]);
		portalled = false;
	}
	if (platformDisappear) {
		playAudio(soundList[5], soundGroups[1]);
		platformDisappear = false;
	}
	//========================================//
	//
	//
	// 
	// 
	// 
	//======= Input detection =======//
	//jump detection
	if (jumptoken) jumped = false;
	if (AEInputCheckTriggered(AEVK_SPACE) && !jumped) {
		//play jump sound
		playAudio(soundList[0], soundGroups[1]);
		if (jumptoken == 0) {
			jumped = true;
		}
	}
	//===============================//

}