#include "stdafx.h"
#include "endingScene.h"


endingScene::endingScene()
{
}


endingScene::~endingScene()
{
}

HRESULT endingScene::init(void)
{
	pixel = IMAGEMANAGER->findImage("보스픽셀");
	bg = IMAGEMANAGER->findImage("엔딩배경최종");
	tree = IMAGEMANAGER->findImage("엔딩나무최종");
	alphaBg = IMAGEMANAGER->findImage("엔딩알파배경");
	SOUNDMANAGER->stop("보스배경사운드");


	_player = SAVEDATA->getPlayer();
	_player->setX(100);
	_player->setY(470);
	_player->setBgPixel(pixel);

	alpha = 255;
	index = count = 0;


	return S_OK;
}

void endingScene::release(void)
{
}

void endingScene::update(void)
{
	count++;


	_player->update();

	if (alpha == 0)
	{
		alpha = 0;

		bg->setFrameY(0);
		tree->setFrameY(0);
		

		if (count % 150 == 0)
		{
			index++;

			if (index > bg->getMaxFrameX())
			{
				index = bg->getMaxFrameX();
			}

			if (index > tree->getMaxFrameX())
			{
				index = tree->getMaxFrameX();
			}

		}
		bg->setFrameX(index);
		tree->setFrameX(index);


	}
	else
	{
		alpha -= 1;

	}

}

void endingScene::render(void)
{
	if (alpha == 0)
	{
		bg->frameRender(getMemDC(), 0, 0, bg->getFrameX(), bg->getFrameY());
		tree->frameRender(getMemDC(), 500, 0, tree->getFrameX(), tree->getFrameY());

	}
	else
	{
		bg->frameRender(getMemDC(), 0, 0, 0, 0);
		tree->frameRender(getMemDC(), 500, 0, 0, 0);
	}
	
	_player->render();

	alphaBg->alphaRender(getMemDC(), alpha);

}
