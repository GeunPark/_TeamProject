#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::GeunHwaImage()
{
	_loading->loadImage("레이어1배경", "resource/스테이지1/레이어1 배경.bmp", 1280, 2550);
	_loading->loadImage("레이어1얼음배경", "resource/스테이지1/레이어1 얼음배경.bmp", 1280, 2550);
	_loading->loadImage("레이어2배경", "resource/스테이지1/레이어2 배경", 1280, 220, true, MAGENTA);
}

void loadingScene::GeunHwaSound()
{

}