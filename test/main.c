#include <stdio.h>
#include "Audio/AudioManager.h"
#include <rxi-log/log.h>


int main(int argc, char **argv)
{
	if(!AudioManager_Init())
		return -1;

	//AudioManager_SwitchSoundFile("alphabeat.mp3");
	// see why it dosen't play i mean it dosen't hear anything

	//AudioManager_CallPlay();
	
	AudioManager_SwitchSoundFile("ab.mp3");
	AudioManager_CallPlay();
	getchar();
	AudioManager_CallStop();
	getchar();
	AudioManager_SwitchSoundFile("alphabeat.mp3");
	AudioManager_CallPlay();
	log_info("Click to end playback .");
	getchar();
	AudioManager_CallPause();
	getchar();
	AudioManager_CallResume();
	getchar();
	AudioManager_CallStop();

	AudioManager_Deinit();
	return 0;
}
