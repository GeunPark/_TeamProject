#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::SaeWonImage()
{
	_loading->loadFrameImage("Idle", "resource/foxPlayer/nickIdle.bmp", 3600, 360, 20, 2, true, MAGENTA);
	_loading->loadFrameImage("Run", "resource/foxPlayer/run.bmp", 1440, 360, 8, 2, true, MAGENTA);
	_loading->loadFrameImage("Jump", "resource/foxPlayer/jump.bmp", 180, 360, 1, 2, true, MAGENTA);
	_loading->loadFrameImage("Jump2", "resource/foxPlayer/jump.bmp", 180, 360, 1, 2, true, MAGENTA);
	_loading->loadFrameImage("Fall", "resource/foxPlayer/fall.bmp", 720, 360, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Fall2", "resource/foxPlayer/fall.bmp", 720, 360, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Fire", "resource/foxPlayer/bowFire.bmp", 1440, 360, 8, 2, true, MAGENTA);
	_loading->loadFrameImage("UpAtt", "resource/foxPlayer/upAtt.bmp", 870, 348, 5, 2, true, MAGENTA);
	_loading->loadFrameImage("SitAtt", "resource/foxPlayer/sitAtt.bmp", 852, 360, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Sit", "resource/foxPlayer/sit.bmp", 540, 360, 3, 2, true, MAGENTA);
	_loading->loadFrameImage("JumpAtt", "resource/foxPlayer/jumpAtt.bmp", 2034, 360, 6, 2, true, MAGENTA);
	_loading->loadFrameImage("JumpAtt2", "resource/foxPlayer/jumpAtt2.bmp", 1704, 426, 8, 2, true, MAGENTA);
	_loading->loadFrameImage("DownAtt", "resource/foxPlayer/downAtt.bmp", 564, 318, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Hurt", "resource/foxPlayer/hurt.bmp", 180, 360, 1, 2, true, MAGENTA);
	_loading->loadFrameImage("arrow", "resource/foxPlayer/arrow.bmp", 66, 46, 1, 2, true, MAGENTA);
	_loading->loadFrameImage("Weather", "resource/foxPlayer/weather.bmp", 1620, 360, 9, 2, true, MAGENTA);
	_loading->loadFrameImage("Die", "resource/foxPlayer/dead.bmp", 720, 360, 4, 2, true, MAGENTA);
	_loading->loadFrameImage("Twinkle", "resource/foxPlayer/twinkle.bmp", 5805, 384, 15, 1, true, MAGENTA);
	_loading->loadImage("Cuticle", "resource/foxPlayer/cuticle.bmp", 21, 21, true, MAGENTA);
	_loading->loadFrameImage("Poison", "resource/foxPlayer/poison2.bmp", 350, 140, 5, 2, true, MAGENTA);
	

	_loading->loadFrameImage("번개마법1", "resource/foxPlayer/번개마법1.bmp", 864, 960, 9, 1, true, MAGENTA);
	_loading->loadFrameImage("토네이도", "resource/foxPlayer/토네이도.bmp", 648, 636, 2, 1, true, MAGENTA);

	_loading->loadImage("나이트메어", "resource/foxPlayer/나이트메어.bmp", 417, 447, true, MAGENTA);
	_loading->loadImage("나이트메어 그림자", "resource/foxPlayer/나이트메어 그림자.bmp", 417, 447, true, MAGENTA);
}

void loadingScene::SaeWonSound()
{
	//계절 체인지################################################################################################
	_loading->loadSound("계절변경사운드", "resource/박근화/사운드리소스/계절 바꿀때 사운드.wav");
	_loading->loadSound("계절해제사운드", "resource/박근화/사운드리소스/계절 해제할때 사운드.wav");

	//마을씬 관련 ################################################################################################
	_loading->loadSound("마을배경사운드", "resource/박근화/사운드리소스/마을 배경 사운드.wav", true, true);
	_loading->loadSound("마을상점선택사운드", "resource/박근화/사운드리소스/마을 상점 셀렉 사운드.wav");
	_loading->loadSound("마을상점캔슬사운드", "resource/박근화/사운드리소스/마을 상점 캔슬 사운드.wav");
	_loading->loadSound("돈모자를때사운드", "resource/박근화/사운드리소스/노코인사운드.wav");

	//월드맵 관련##################################################################################################
	_loading->loadSound("월드맵배경사운드", "resource/박근화/사운드리소스/월드맵 배경 사운드.wav", true, true);

	//에너미 관련 사운드
	_loading->loadSound("에너미죽는사운드", "resource/박근화/사운드리소스/에너미 죽는 사운드.wav");
	_loading->loadSound("코인생성사운드", "resource/박근화/사운드리소스/코인 젠됬을때 사운드.wav");
	_loading->loadSound("코인획득사운드", "resource/박근화/사운드리소스/코인 먹었을때 사운드.wav");
}
