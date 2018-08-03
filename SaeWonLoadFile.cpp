#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::SaeWonImage()
{
	_loading->loadFrameImage("Idle", "resource/foxPlayer/nickIdle.bmp", 3600, 360, 20, 2, true, MAGENTA);
	_loading->loadFrameImage("Run", "resource/foxPlayer/run.bmp", 1440, 360, 8, 2, true, MAGENTA);
	_loading->loadFrameImage("Jump", "resource/foxPlayer/jump.bmp", 360, 360, 2, 2, true, MAGENTA);
	_loading->loadFrameImage("Jump2", "resource/foxPlayer/jump.bmp", 360, 360, 2, 2, true, MAGENTA);
	_loading->loadFrameImage("Fall", "resource/foxPlayer/fall.bmp", 720, 360, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Fall2", "resource/foxPlayer/fall.bmp", 720, 360, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Fire", "resource/foxPlayer/bowFire.bmp", 1440, 360, 8, 2, true, MAGENTA);
	_loading->loadFrameImage("UpAtt", "resource/foxPlayer/upAtt.bmp", 870, 348, 5, 2, true, MAGENTA);
	_loading->loadFrameImage("SitAtt", "resource/foxPlayer/sitAtt.bmp", 540, 360, 3, 2, true, MAGENTA);
	_loading->loadFrameImage("Sit", "resource/foxPlayer/sit.bmp", 540, 360, 3, 2, true, MAGENTA);
	_loading->loadFrameImage("JumpAtt", "resource/foxPlayer/jumpAtt.bmp", 2034, 360, 6, 2, true, MAGENTA);
	_loading->loadFrameImage("JumpAtt2", "resource/foxPlayer/jumpAtt2.bmp", 1704, 426, 8, 2, true, MAGENTA);
	_loading->loadFrameImage("DownAtt", "resource/foxPlayer/downAtt.bmp", 564, 318, 4, 2, true, MAGENTA);
	_loading->loadImage("Hurt", "resource/foxPlayer/hurt.bmp", 180, 180, true, MAGENTA);
	_loading->loadFrameImage("arrow", "resource/foxPlayer/arrow.bmp", 66, 46, 1, 2, true, MAGENTA);
}

void loadingScene::SaeWonSound()
{

}
