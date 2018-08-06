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
}

void loadingScene::GeunHwaSound()
{
	_loading->loadSound("스타트씬BGM", "resource/박근화/사운드리소스/스타트씬 배경 사운드.wav", true, true);
	_loading->loadSound("셀렉트효과음", "resource/박근화/사운드리소스/셀렉 사운드.wav");
	_loading->loadSound("셀렉이동사운드", "resource/박근화/사운드리소스/셀렉 이동 사운드.wav");

	//스테이지1
	_loading->loadSound("스테이지1 여름", "resource/박근화/사운드리소스/스테이지 1 배경 사운드.wav", true, true);
}