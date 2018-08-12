#include "stdafx.h"
#include "worldMapScene.h"


worldMapScene::worldMapScene()
{
}


worldMapScene::~worldMapScene()
{
}

HRESULT worldMapScene::init(void)
{
	ZeroMemory(&_backGround, sizeof(tagWorld));

	_backGround.img = IMAGEMANAGER->findImage("월드맵배경");
	
	_wayPoint.img = IMAGEMANAGER->findImage("타운포인트");
	_wayPoint.x = WINSIZEX / 2 - 30;
	_wayPoint.y = WINSIZEY / 2 + 15;

	_wayRoad.img = IMAGEMANAGER->findImage("월드맵로드");
	_wayRoad.x = WINSIZEX / 2 + 30;
	_wayRoad.y = WINSIZEY / 2 + 15;

	_stagePoint.img = IMAGEMANAGER->findImage("스테이지포인트");
	_stagePoint.x = _wayRoad.x + 183;
	_stagePoint.y = _wayRoad.y + 10;
	_stagePoint.alpha = 255;

	ZeroMemory(&_player, sizeof(tagWorld));
	_player.img = IMAGEMANAGER->findImage("Run");
	_player.x = _wayPoint.x - 50;
	_player.y = WINSIZEY / 2 - 150;
	move = false;
	_player.img->setFrameY(0);

	_townTxt.img = IMAGEMANAGER->findImage("월드맵타운");

	_stageTxt.img = IMAGEMANAGER->findImage("월드맵스테이지");

	ZeroMemory(&_bossPoint, sizeof(tagWorld));
	_bossPoint.img = IMAGEMANAGER->findImage("보스포인트");
	_bossPoint.x = 280;
	_bossPoint.y = 180;
	
	_bossRoad.img = IMAGEMANAGER->findImage("보스로드");
	_bossRoad.x = _wayPoint.x - _bossRoad.img->getWidth();
	_bossRoad.y = _wayPoint.y - (_bossRoad.img->getHeight() / 2 + 20);

	_fox = SAVEDATA->getPlayer();


	//테스트임시변수
	clearCount = 0;
	loopCount = 0;

	return S_OK;
}

void worldMapScene::release(void)
{
}

void worldMapScene::update(void)
{
	_backGround.count++;
	_backGround.img->setFrameY(0);
	if (_backGround.count % 5 == 0)
	{
		_backGround.index++;
		if (_backGround.index >= _backGround.img->getMaxFrameX())
		{
			_backGround.index = 0;
		}
		_backGround.img->setFrameX(_backGround.index);
	}

	if (_player.img->getFrameY() == 0)
	{
		_player.count++;
		if (_player.count % 5 == 0)
		{
			_player.index++;
			if (_player.index > _player.img->getMaxFrameX())
			{
				_player.index = 0;
			}
			_player.img->setFrameX(_player.index);
		}
	}
	else
	{
		_player.count++;
		if (_player.count % 5 == 0)
		{
			_player.index--;
			if (_player.index < 0)
			{
				_player.index = _player.img->getMaxFrameX();
			}
			_player.img->setFrameX(_player.index);
		}
	}

	if (_fox->getClearCount() > 0)
	{
		_bossPoint.count++;
		_bossPoint.img->setFrameY(0);
		if (_bossPoint.count % 50 == 0)
		{
			_bossPoint.index++;
			if (_bossPoint.index > _bossPoint.img->getMaxFrameX())
			{
				_bossPoint.index = 0;
			}
			_bossPoint.img->setFrameX(_bossPoint.index);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_player.img->setFrameY(0);
		move = true;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_player.img->setFrameY(1);
		move = true;
	}

	if (move && _player.img->getFrameY() == 0)
	{
		if (_player.x >= _wayPoint.x - 50)
		{
			_player.x += 2;
			if (_player.x + 50 >= _stagePoint.x)
			{
				_player.x = _stagePoint.x - 50;
				move = false;
			}
		}
		if (_player.x >= _bossPoint.x - 50 && _player.x <= _wayPoint.x -50 && clearCount > 0)
		{
			_player.x += 2;
			_player.y += 0.5f;
			if (_player.x >= _wayPoint.x - 50)
			{
				_player.x = _wayPoint.x - 50;
				move = false;
			}
		}
	}
	else if (move && _player.img->getFrameY() == 1)
	{
		if (_player.x <= _stagePoint.x - 50 && _player.x >= _wayPoint.x-50)
		{
			_player.x -= 2;
			if (_player.x <= _wayPoint.x - 50)
			{
				_player.x = _wayPoint.x - 50;
				move = false;
			}
		}
		if (_player.x <= _wayPoint.x - 50 && _player.x >= _bossPoint.x &&  clearCount > 0)
		{
			_player.x -= 2;
			_player.y -= 0.5f;
			if (_player.x <= _bossPoint.x)
			{
				_player.x = _bossPoint.x;
				move = false;
			}
		}
	}


	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (_player.x == _wayPoint.x - 50)
		{
			SCENEMANAGER->loadScene("타운씬");
		}
		else if (_player.x == _stagePoint.x - 50)
		{
			SCENEMANAGER->loadScene("스테이지1");
		}
		else if (_player.x == _bossPoint.x)
		{
			SCENEMANAGER->loadScene("보스");
		}
	}


	//알파 테스트##############################################################################################################################################################################
	if (_fox->getClearCount() <= 0)
	{
		loopCount++;
		if (loopCount % 40 == 0)
		{
			_stagePoint.alpha = 0;
		}
		if (loopCount % 80 == 0)
		{
			_stagePoint.alpha = 255;
		}
	}
	else
	{
		_stagePoint.alpha = 255;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_fox->setClearCount(1);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		_fox->setClearCount(0);
	}
	//#########################################################################################################################################################################################
}

void worldMapScene::render(void)
{
	_backGround.img->frameRender(getMemDC(), 0, 0);
	_wayPoint.img->render(getMemDC(), _wayPoint.x, _wayPoint.y);
	_wayRoad.img->render(getMemDC(), _wayRoad.x, _wayRoad.y);
	_stagePoint.img->alphaRender(getMemDC(), _stagePoint.x, _stagePoint.y, _stagePoint.alpha);
	_player.img->frameRender(getMemDC(), _player.x, _player.y, _player.img->getFrameX(), _player.img->getFrameY());
	if(_player.x == _wayPoint.x - 50)
		_townTxt.img->render(getMemDC(), WINSIZEX / 2 - (_townTxt.img->getWidth() / 2), 200);
	if (_player.x == _stagePoint.x - 50)
		_stageTxt.img->render(getMemDC(), WINSIZEX / 2 - (_stageTxt.img->getWidth() / 2), 200);

	if (_fox->getClearCount() > 0)
	{
		_bossRoad.img->render(getMemDC(), _bossRoad.x, _bossRoad.y);
		_bossPoint.img->frameRender(getMemDC(), _bossRoad.x - _bossPoint.img->getFrameWidth(), _bossRoad.y, _bossPoint.img->getFrameX(), _bossPoint.img->getFrameY());

	}

}
