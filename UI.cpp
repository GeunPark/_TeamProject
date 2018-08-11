#include "stdafx.h"
#include "UI.h"
#include "foxPlayer.h"

HRESULT UI::init(void)
{
	// 현재 HP 
	_arrowNum = 2;
	_isManaWarning = false;
	_isManaUse = false;
	_goldNum = 0;
	_number[0] = IMAGEMANAGER->findImage("숫자");
	_number[1] = IMAGEMANAGER->findImage("숫자");
	_number[2] = IMAGEMANAGER->findImage("숫자");
	_number[3] = IMAGEMANAGER->findImage("숫자");
	_goldImage = IMAGEMANAGER->findImage("골드");
	_arrowNum = 0;
	_arrowNumChk = 0;
	for (int i = 0; i < 4; i++)
	{
		frameNumChk[i] = false;
	}

	heart();
	mana();
	nowArrow();
	nowMagic();

	return S_OK;
}

void UI::release(void)
{
}

void UI::update(void)
{
	nowGold();
	nowHeart();
	nowArrow();
	// 하트 갯수만큼 표시

	for (int i = 0; i < maxHeart; i++)
	{
		_heart[i]._rc = RectMakeCenter(_heart[i]._x, _heart[i]._y, 48, 48);
	}
	// 현재 마나가 일정수치 도달하면 경고표시
	if (_mana._now  > 30 || _mana._now <= 0) _isManaWarning = false;
	else _isManaWarning = true;


	_mana._now = _player->getMana();
	_mana._MaxNum = _player->getMaxMana();
}

void UI::render()
{
	// 하트 이미지
	for (int i = 0; i < maxHeart; i++)
	{
		_heart[i]._img->render(getMemDC(), _heart[i]._x, _heart[i]._y);
		if (KEYMANAGER->isToggleKey(VK_F4))Rectangle(getMemDC(), _heart[i]._rc);
	}
	// 마나 이미지
	_manaBar._img->render(getMemDC(), _manaBar._x, _manaBar._y);
	_manaUp._img->render(getMemDC(), _manaUp._x + (_player->getMaxMana() - 100), _manaUp._y, 0, 0, 126 - (_player->getMaxMana() - 90), 24);
	if (!_isManaWarning)_mana._img->render(getMemDC(), _mana._x, _mana._y, 0, 0, _mana._now, 24);
	else if (_isManaWarning)_manaWa->render(getMemDC(), _mana._x, _mana._y, 0, 0, _mana._now, 24);
	_warningLine->render(getMemDC(), 527, 39);
	// 현재 화살 이미지
	_nowState[0]->render(getMemDC(), 330, 20);
	_nowArrow._img->render(getMemDC(), 340, 30);
	for (int i = 0; i < _arrowNum; i++)
	{
		_ArrowChoice[i]._img->render(getMemDC(), _ArrowChoice[i]._x, _ArrowChoice[i]._y);
	}
	// 마법 이미지
	_nowState[1]->render(getMemDC(), 800, 20);

	for (int i = 0; i < _magicNum; i++)
	{
		_MagicChoice[i]._img->render(getMemDC(), _MagicChoice[i]._x, _MagicChoice[i]._y);
	}
	// 현재 골드 이미지
	_goldImage->render(getMemDC(), 1124, 20);
	for (int i = 0; i < 4; i++)
	{
		if (frameNumChk[i] == true)_number[i]->frameRender(getMemDC(), 1100 + (24 * i), 50, _frameNum[i], 0);
	}

}

// 하트(체력)
void UI::heart()
{

	maxHeart = 5;
	for (int i = 0; i < MAXHEART; i++)
	{
		_heart[i]._numChk = 2;												// 이 변수값에 따라서 하트모양이 달라림, 풀 하트, 반 하트, 빈 하트
		_heart[i]._img = IMAGEMANAGER->findImage("fullHP");

		_heart[i]._rc = RectMakeCenter(_heart[i]._x, _heart[i]._y, 48, 48);
	}
	_heartNum = 0;
}
void UI::nowHeart()
{
	maxHeart = _player->getMaxHp() / 10;
	_heartNum = _player->getHp();
	if (maxHeart == 6)_heart[6]._numChk = 2;
	for (int i = 0; i < maxHeart; i++)
	{
		if (_heart[i]._numChk == 2)											// 이 변수값에 따라서 하트모양이 달라림, 풀 하트, 반 하트, 빈 하트
		{
			_heart[i]._img = IMAGEMANAGER->findImage("fullHP");
		}
		else if (_heart[i]._numChk == 1)
		{
			_heart[i]._img = IMAGEMANAGER->findImage("halfHP");
		}
		else if (_heart[i]._numChk == 0)
		{
			_heart[i]._img = IMAGEMANAGER->findImage("zeroHP");
		}

		if (i < 5)
		{
			_heart[i]._x = 25 + 40 * i;
			_heart[i]._y = 20;
		}
		else if (i > 4)
		{
			_heart[i]._x = 25 + 40 * i - 200;
			_heart[i]._y = 68;
		}

		_heart[i]._rc = RectMakeCenter(_heart[i]._x, _heart[i]._y, 48, 48);
	}
	for (int i = 0; i < maxHeart; i++)
	{
		if (_heartNum / 10 > i)_heart[i]._numChk = 2;
		else if (_heartNum / 10 == i && _heartNum % 10 == 5)_heart[i]._numChk = 1;
		else if (_heartNum / 10 <= i || _heartNum == 0)_heart[i]._numChk = 0;


	}
}
// 마나관련 초기화 함수
void UI::mana()
{
	manaUpNum = 0;
	// 마나 바 
	_manaBar._img = IMAGEMANAGER->findImage("마나 바");
	_manaBar._x = WINSIZEX / 3;
	_manaBar._y = 20;
	// 현재 마나
	_mana._img = IMAGEMANAGER->findImage("마나");
	_mana._x = 510;
	_mana._y = 59;

	_mana._MaxNum = 100;	// 초기 100, 마나 업그레이드 시키면 증가
	_mana._MaxNum += manaUpNum;
	_mana._now = _mana._MaxNum;

	// 마나 업글 바
	_manaUp._img = IMAGEMANAGER->findImage("마나 업글바");
	_manaUp._x = 610;
	_manaUp._y = 59;

	// 마나를 거의 따 쓰면 마나색이 빨간색으로 바뀜"
	_manaWa = IMAGEMANAGER->findImage("마나 경고");
	manaWarning = (_mana._MaxNum / 100) * 20;
	_warningLine = IMAGEMANAGER->findImage("경고선");
}

void UI::nowArrow()
{
	// a는 몇번째 화살을 선택했다는 값? 입니다
	_arrowNum = 2;
	_nowState[0] = IMAGEMANAGER->findImage("현재상태");
	for (int i = 0; i < _arrowNum; i++)
	{
		if (_arrowNumChk == i)
		{
			_ArrowChoice[i]._img = IMAGEMANAGER->findImage("선택L");

		}
		else if (_arrowNumChk != i)_ArrowChoice[i]._img = IMAGEMANAGER->findImage("노선택L");

		//		_ArrowChoice[0]._img = IMAGEMANAGER->findImage("선택L");
		//		_ArrowChoice[1]._img = IMAGEMANAGER->findImage("노선택L");
		_ArrowChoice[i]._x = 300;
		_ArrowChoice[i]._y = 20 + i * 24;
	}
	if (_arrowNumChk == 0)_nowArrow._img = IMAGEMANAGER->findImage("일반화살");
	else if (_arrowNumChk == 1)_nowArrow._img = IMAGEMANAGER->findImage("초록화살");
}

void UI::nowMagic()
{
	_magicNum = 3;
	_nowState[1] = IMAGEMANAGER->findImage("현재상태");
	for (int i = 0; i < _magicNum; i++)
	{
		if (b == i)
		{
			_MagicChoice[i]._img = IMAGEMANAGER->findImage("선택R");
		}
		else if (b != i)_MagicChoice[i]._img = IMAGEMANAGER->findImage("노선택R");
		_MagicChoice[i]._x = 920;
		_MagicChoice[i]._y = 20 + i * 24;
	}

}

void UI::nowGold()
{
	_goldNum = _player->getGold();
	_frameNum[0] = _goldNum / 1000;
	_frameNum[1] = (_goldNum % 1000) / 100;
	_frameNum[2] = (_goldNum % 100) / 10;
	_frameNum[3] = _goldNum % 10;


	if (_goldNum > 9) frameNumChk[2] = true;
	else if (_goldNum <= 9) frameNumChk[2] = false;
	if (_goldNum > 99) frameNumChk[1] = true;
	else if (_goldNum <= 99) frameNumChk[1] = false;
	if (_goldNum > 999) frameNumChk[0] = true;
	else if (_goldNum <= 999) frameNumChk[0] = false;
}
