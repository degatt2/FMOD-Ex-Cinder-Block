/*
 *  fmodexPlayer.h
 *  basicApp
 *
 *  Created by Roger Palà on 21/03/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "fmod.h"
#include "fmod_errors.h"
#include "cinder/Utilities.h"
#include "cinder/app/AppBasic.h"

void fmodexStopAll();
void fmodexSetVolume(float vol);
void fmodexUpdate();						// calls FMOD update.
float * fmodexGetSpectrum(int nBands);		// max 512...


// --------------------- player functions:
class fmodexPlayer {
	
public:
	
	fmodexPlayer();
	virtual ~fmodexPlayer();
	
	void loadSound(std::string fileName, bool stream = false);
	void unloadSound();
	void play();
	void stop();
	
	void setVolume(float vol);
	void setPan(float vol);
	void setSpeed(float spd);
	void setPaused(bool bP);
	void setLoop(bool bLp);
	void setMultiPlay(bool bMp);
	void setPosition(float pct); // 0 = start, 1 = end;
	
	float getPosition();
	bool getIsPlaying();
	float getSpeed();
	float getPan();
	
	static void initializeFmod();
	static void closeFmod();
	
	bool isStreaming;
	bool bMultiPlay;
	bool bLoop;
	bool bLoadedOk;
	bool bPaused;
	float pan; // 0 - 1
	float volume; // 0 - 1
	float internalFreq; // 44100 ?
	float speed; // -n to n, 1 = normal, -1 backwards
	unsigned int length; // in samples;
	

	FMOD_RESULT result;
	FMOD_CHANNEL * channel;
	FMOD_SOUND * sound;

};

