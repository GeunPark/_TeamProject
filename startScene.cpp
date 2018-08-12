#include "stdafx.h"
#include "startScene.h"


startScene::startScene()
{
}


startScene::~startScene()
{
}

HRESULT startScene::init(void)
{
	_backGround = IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À ¹è°æ");
	_logo = IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À ·Î°í");
	_button = IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À ¹öÆ°");
		
	_selectBg = IMAGEMANAGER->findImage("¼¿·ºÆ®¾À ¹è°æ");
	_selectWindow = IMAGEMANAGER->findImage("¼¿·ºÆ®¾À ¼¿·ºÃ¢");

	ZeroMemory(&_selectBox, sizeof(tagWindow));
	_selectBox.img = IMAGEMANAGER->findImage("¼¿·ºÆ®¾À ¼¿·º¹Ú½º");
	_selectBox.pos.x = WINSIZEX / 2 - 240;
	_selectBox.pos.y = START;
	_selectBox.rc = RectMake(_selectBox.pos.x, _selectBox.pos.y, _selectBox.img->getWidth(), _selectBox.img->getHeight());

	_fox.img = IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À ¿©¿ì");
	_fox.pos.x = 850;
	_fox.pos.y = 15;
	_fox.rc = RectMake(_fox.pos.x, _fox.pos.y, _fox.img->getWidth(), _fox.img->getHeight());
	_fox.count = 0;
	_fox.turn = false;


	_bird.img = IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À ºñµÑ±â");
	_bird.pos.x = 195;
	_bird.pos.y = 250;
	_bird.rc = RectMake(_bird.pos.x, _bird.pos.y, _bird.img->getWidth(), _bird.img->getHeight());
	_bird.turn = false;

	SOUNDMANAGER->play("½ºÅ¸Æ®¾ÀBGM",0.3f);

	alpha = alpha2 = 255;
	count = _enterCount = 0;
	return S_OK;
}

void startScene::release(void)
{
}

void startScene::update(void)
{
	this->move();

	count++;
	if (count % 50 == 0)
	{
		alpha = 0;
	}
	if (count % 100 == 0)
	{
		alpha = 255;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->play("¼¿·ºÆ®È¿°úÀ½");
		alpha2 = 180;
		_enterCount++;
		if (_enterCount > 1)
		{
			if (_selectBox.pos.y == START)
			{
				SCENEMANAGER->loadScene("Å¸¿î¾À");
				SOUNDMANAGER->stop("½ºÅ¸Æ®¾ÀBGM");
			}
			else if (_selectBox.pos.y == SETTING)
			{

			}
		}
	}

	
	this->selectMove();

	


	_fox.rc = RectMake(_fox.pos.x, _fox.pos.y, _fox.img->getWidth(), _fox.img->getHeight());
	_bird.rc = RectMake(_bird.pos.x, _bird.pos.y, _bird.img->getWidth(), _bird.img->getHeight());
	_selectBox.rc = RectMake(_selectBox.pos.x, _selectBox.pos.y, _selectBox.img->getWidth(), _selectBox.img->getHeight());
}

void startScene::render(void)
{
	if (_enterCount == 0)
	{
		_backGround->render(getMemDC());
		_fox.img->render(getMemDC(), _fox.pos.x, _fox.pos.y, 0, 0, _fox.img->getWidth(), _fox.img->getHeight());
		_bird.img->render(getMemDC(), _bird.pos.x, _bird.pos.y, 0, 0, _bird.img->getWidth(), _bird.img->getHeight());
		_logo->render(getMemDC(), 315, 110, 0, 0, 650, 274);
		_button->alphaRender(getMemDC(), WINSIZEX / 2 - 65, 500, 0, 0, _button->getWidth(), _button->getHeight(), alpha);
	}
	if (_enterCount > 0)
	{
		_selectBg->alphaRender(getMemDC(), alpha2);
		_fox.img->render(getMemDC(), _fox.pos.x, _fox.pos.y, 0, 0, _fox.img->getWidth(), _fox.img->getHeight());
		_bird.img->render(getMemDC(), _bird.pos.x, _bird.pos.y, 0, 0, _bird.img->getWidth(), _bird.img->getHeight());
		_selectWindow->render(getMemDC(), WINSIZEX / 2 - _selectWindow->getWidth() / 2, 200, 0, 0, _selectWindow->getWidth(), _selectWindow->getHeight());
		_selectBox.img->render(getMemDC(), _selectBox.rc.left, _selectBox.rc.top);
	}
	
	
}

void startScene::move()
{
	_fox.count++;
	if (_fox.count % 5 == 0)
	{
		if (!_fox.turn)
		{
			_fox.pos.y--;
			if (_fox.pos.y < 10)
			{
				_fox.turn = true;
			}
		}
		else
		{
			_fox.pos.y++;
			if (_fox.pos.y > 30)
			{
				_fox.turn = false;
			}
		}
	}
	_bird.count++;
	if (_bird.count % 2 == 0)
	{
		if (!_bird.turn)
		{
			_bird.pos.y--;
			if (_bird.pos.y < 240)
			{
				_bird.turn = true;
			}
		}
		else
		{
			_bird.pos.y++;
			if (_bird.pos.y > 270)
			{
				_bird.turn = false;
			}
		}
	}
}

void startScene::selectMove()
{
	if (_enterCount > 0 && KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		SOUNDMANAGER->play("¼¿·ºÀÌµ¿»ç¿îµå");
		if (_selectBox.pos.y == START)
		{
			_selectBox.pos.y = SETTING;
		}
		else
		{
			_selectBox.pos.y = START;
		}
	}
	if (_enterCount > 0 && KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		SOUNDMANAGER->play("¼¿·ºÀÌµ¿»ç¿îµå");
		if (_selectBox.pos.y == START)
		{
			_selectBox.pos.y = SETTING;
		}
		else
		{
			_selectBox.pos.y = START;
		}
	}
}
