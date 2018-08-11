#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::GeunHwaImage()
{
	_loading->loadImage("레이어1배경", "resource/스테이지1/레이어1 배경.bmp", 1280, 2550);
	_loading->loadImage("레이어1얼음배경", "resource/스테이지1/레이어1 얼음배경.bmp", 1280, 2550);
	_loading->loadImage("레이어2배경", "resource/스테이지1/레이어2 배경", 1280, 220, true, MAGENTA);
	
	// 스타트씬 이미지
	_loading->loadImage("스타트씬 배경", "resource/박근화/스타트씬/로비씬 배경.bmp", 1280, 720);
	_loading->loadImage("스타트씬 로고", "resource/박근화/스타트씬/로비씬 로고.bmp", 650, 274, true, MAGENTA);
	_loading->loadImage("스타트씬 여우", "resource/박근화/스타트씬/로비씬 여우.bmp", 400, 545, true, MAGENTA);
	_loading->loadImage("스타트씬 비둘기", "resource/박근화/스타트씬/로비씬 비둘기.bmp", 217, 228, true, MAGENTA);
	_loading->loadImage("스타트씬 버튼", "resource/박근화/스타트씬/로비씬 버튼.bmp", 130, 105, true, MAGENTA);
	
	//셀렉트씬 이미지
	_loading->loadImage("셀렉트씬 배경", "resource/박근화/스타트씬/셀렉트씬배경.bmp", 1280, 720);
	_loading->loadImage("셀렉트씬 셀렉창", "resource/박근화/스타트씬/셀렉트씬 셀렉창.bmp", 546, 299);
	_loading->loadImage("셀렉트씬 셀렉박스", "resource/박근화/스타트씬/셀렉트씬 셀렉박스.bmp", 480, 106, true, MAGENTA);
	//마을 이미지
	_loading->loadImage("마을배경", "resource/박근화/타운씬/마을배경.bmp", 1792, 720, true, MAGENTA);
	_loading->loadImage("마을레이어1", "resource/박근화/타운씬/마을레이어1.bmp", 1536, 720);
	_loading->loadImage("마을레이어2", "resource/박근화/타운씬/마을레이어2.bmp", 1792, 189, true, MAGENTA);
	_loading->loadImage("마을레이어3", "resource/박근화/타운씬/마을레이어3.bmp", 1792, 720, true, MAGENTA);
	_loading->loadImage("마을픽셀", "resource/박근화/타운씬/마을픽셀.bmp", 1792, 720, true, MAGENTA);

	//보스 이미지
	_loading->loadImage("보스여름", "resource/박근화/보스/보스여름.bmp", 1280, 720);
	_loading->loadImage("보스가을", "resource/박근화/보스/보스가을.bmp", 1280, 720);
	_loading->loadImage("보스픽셀", "resource/박근화/보스/보스픽셀.bmp", 1280, 720, true, MAGENTA);
	_loading->loadFrameImage("낙엽", "resource/박근화/보스/낙엽.bmp", 192, 48, 4, 1, true, MAGENTA);

	//월드맵 이미지
	_loading->loadFrameImage("월드맵배경", "resource/박근화/월드맵/월드맵.bmp", 5120, 720, 4, 1, true, MAGENTA);
	_loading->loadImage("타운포인트", "resource/박근화/월드맵/웨이포인트.bmp", 63, 45, true, MAGENTA);
	_loading->loadImage("월드맵로드", "resource/박근화/월드맵/wayroad.bmp", 183, 48, true, MAGENTA);
	_loading->loadImage("스테이지포인트", "resource/박근화/월드맵/스테이지포인트.bmp", 33, 27, true, MAGENTA);
	_loading->loadImage("월드맵타운", "resource/박근화/월드맵/포레스트플라자.bmp", 634, 50, true, MAGENTA);
	_loading->loadImage("월드맵스테이지", "resource/박근화/월드맵/스테이지1표시.bmp", 787, 50, true, MAGENTA);
	_loading->loadFrameImage("보스포인트", "resource/박근화/월드맵/보스포인트.bmp", 114, 57, 2, 1, true, MAGENTA);
	_loading->loadImage("보스로드", "resource/박근화/월드맵/보스로드.bmp", 207, 111, true, MAGENTA);
}

void loadingScene::GeunHwaSound()
{
	//BGM 관련##################################################################################################

	//스타트씬
	_loading->loadSound("스타트씬BGM", "resource/박근화/사운드리소스/스타트씬 배경 사운드.wav", true, true);
	_loading->loadSound("셀렉트효과음", "resource/박근화/사운드리소스/셀렉 사운드.wav");
	_loading->loadSound("셀렉이동사운드", "resource/박근화/사운드리소스/셀렉 이동 사운드.wav");

	//스테이지1
	_loading->loadSound("스테이지1 여름", "resource/박근화/사운드리소스/스테이지 1 배경 사운드.wav", true, true);
	_loading->loadSound("스테이지1 겨울", "resource/박근화/사운드리소스/겨울 배경 사운드.wav", true, true);

	//플레이어관련###############################################################################################

	//점프
	_loading->loadSound("점프사운드", "resource/박근화/사운드리소스/1단점프 사운드.wav");
	_loading->loadSound("2단점프사운드", "resource/박근화/사운드리소스/2단점프 사운드.wav");

	//점프공격
	_loading->loadSound("1단점프공격사운드", "resource/박근화/사운드리소스/1단점프 공격 사운드.wav");
	_loading->loadSound("2단점프공격사운드", "resource/박근화/사운드리소스/2단점프 공격 사운드.wav");

	//공격
	_loading->loadSound("화살발사사운드", "resource/박근화/사운드리소스/화살발사 효과사운드.wav");
	_loading->loadSound("화살펄스사운드", "resource/박근화/사운드리소스/화살발사 펄스 효과음.wav");
	_loading->loadSound("앉은공격사운드", "resource/박근화/사운드리소스/앉은공격 사운드.wav");

	//마나
	_loading->loadSound("마나획득사운드", "resource/박근화/사운드리소스/마나먹을때 싸운드.wav");
	_loading->loadSound("마나알람사운드", "resource/박근화/사운드리소스/마나 알람 사운드.wav", false, true);

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