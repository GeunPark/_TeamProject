#include "stdafx.h"
#include "foxPlayer.h"
#include "enemyManager.h"

#include "UI.h"


//ToDo : init
HRESULT foxPlayer::init(void)
{
	imageSetting();

	// 형 UI 설정좀 하께  웅웅
	_ui = new UI;
	_ui->init();

	_state = IDLE;
	
	_player.x = 200;
	_player.y = MAX_HEIGHT - 200;
	_player.speed = 30.f;
	_player.gravity = 0.f;
	_player.angle = PI / 2;
	_player.arrowAngle = 0;
	_player.radian = 90;
	_player.isJump = _player.isLeft = _player.isUp = _player.isDown = _player.isRight = _player.isAtt = _player.isChange = false;

	
	index = count = actionCount = actionIndex = jumpCount = hitCount = unDamage = weatherIndex = effectIndex = effectCount = 0;

	_player.maxMana = _player.mana = 100;
	_player.HP = _player.MaxHp = 50;
	_player.gold = 0;
	index = count = actionCount = actionIndex = jumpCount = 0;


	_arrow = new arrow;
	_arrow->init(3, 600);

	_camera.x = _player.x;
	_camera.y = _player.y;

	_bfx = IMAGEMANAGER->findImage("스테이지1 픽셀");

	
	return S_OK;
}

void foxPlayer::release(void)
{
	//_arrow->release();
	
}

//ToDo : update
void foxPlayer::update(void)
{
	/*if (KEYMANAGER->isOnceKeyDown('S'))
	{
		if (!ang)
		{
			ang = true;
		}
		else
		{
			ang = false;
		}
		_state = WEATHER;

	}*/
	if (ang)
	{
		_player.mana -= 0.1f;
		if (_player.mana <= 0)ang = false;
	}
	else
	{
		if (_player.maxMana > _player.mana)_player.mana += 0.3f;
		else if (_player.maxMana < _player.mana)_player.mana -= 0.3f;
	}
	// 테스트 함수
	//test();

	this->keySetting();	  //키셋팅 함수 호출

	this->foxState();		//플레이어 상태 함수 호출

	this->frameMove();		//프레임 움직이는 함수 호출
	
	this->camera();			//카메라 움직이는 함수 호출

	_player.rc = RectMakeCenter(_player.x, _player.y, nick[_state]->getFrameWidth(), nick[_state]->getFrameHeight());
	

	//충돌렉트 위치 보정   완벽하지않아ㅜㅜ 일단 다른것들 진도좀 빼두고 수정할께!ㅎㅎ
	this->collisionRcChange();

	

	//적과 충돌
	if (KEYMANAGER->isToggleKey(VK_F3))
	{
		this->enemyCollision();
		this->enemyAttCollision();
	}


	//_player.collisionRc = RectMakeCenter(_player.x , _player.y , _player.radian, 110);
	this->pixelCollision();		//픽셀충돌 함수 호출

	//공격렉트 생성
	if (_player.isAtt && _state == JUMPATT)
	{
		attRc = RectMakeCenter(_player.x, _player.y, 200, 30);
		//attRc2 = RectMakeCenter(_player.x - _player.radian - 50, _player.y, 50, 50);
	}
	else if (_player.isAtt && _state == JUMPATT2)
	{
		//EllipseMakeCenter(getMemDC(), _player.x - _camera.rc.left, _player.y-_camera.rc.top, 300-_camera.rc.left, 300-_camera.rc.top);
		attRc = RectMakeCenter(_player.x, _player.y, 200, 200);
	}
	else if (_player.isAtt && _state == SITATT)
	{ 
		if (_player.isLeft)
		{
			attRc = RectMakeCenter(_player.x - 55, _player.y + 50, 90, 30);
		}
		else
		{
			attRc = RectMakeCenter(_player.x + 55, _player.y + 50, 90, 30);
		}
		
	}
	else if (_player.isAtt && _state == UPATT)
	{
		if (_player.isLeft)
		{
			attRc = RectMakeCenter(_player.x, _player.y - 30, 100, 30);
			attRc2 = RectMakeCenter(_player.x - 70, _player.y + 20, 30, 100);
		}
		else
		{
			attRc = RectMakeCenter(_player.x, _player.y - 30, 100, 30);
			attRc2 = RectMakeCenter(_player.x + 70, _player.y + 20, 30, 100);
		}
	}
	else
	{
		attRc = RectMakeCenter(-10000,-10000 , 300, 300);
		attRc2 = RectMakeCenter(-100000, -10000, 30, 100);
	}

	_arrow->update();

	_ui->update();

	
	twinkleRc = RectMakeCenter(_player.x, _player.y, _twinkle->getFrameWidth(), _twinkle->getFrameHeight());

	_camera.rc = RectMakeCenter(_camera.x, _camera.y, WINSIZEX, WINSIZEY);
}

//void foxPlayer::render(float FX, float FY)
//{
//	Rectangle(getMemDC(), _player.rc.left -FX , _player.rc.top -FY , _player.rc.right - FX, _player.rc.bottom - FY);
//}

//ToDo : render
void foxPlayer::render()
{
	Rectangle(getMemDC(), _player.collisionRc.left - _camera.rc.left, _player.collisionRc.top - _camera.rc.top, _player.collisionRc.right - _camera.rc.left, _player.collisionRc.bottom - _camera.rc.top);
	Rectangle(getMemDC(), attRc.left - _camera.rc.left, attRc.top - _camera.rc.top, attRc.right - _camera.rc.left, attRc.bottom - _camera.rc.top);
	Rectangle(getMemDC(), attRc2.left - _camera.rc.left, attRc2.top - _camera.rc.top, attRc2.right - _camera.rc.left, attRc2.bottom - _camera.rc.top);
	nick[_state]->frameRender(getMemDC(), _player.rc.left - _camera.rc.left, _player.rc.top - _camera.rc.top, nick[_state]->getFrameX(), nick[_state]->getFrameY());

	/*if (_player.isChange)
	{
		Rectangle(getMemDC(), twinkleRc.left - _camera.rc.left, twinkleRc.top - _camera.rc.top, twinkleRc.right - _camera.rc.left, twinkleRc.bottom - _camera.rc.top);
		_twinkle->frameRender(getMemDC(), twinkleRc.left - _camera.rc.left, twinkleRc.top - _camera.rc.top, _twinkle->getFrameX(), _twinkle->getFrameY());
	}*/
	
	//Rectangle(getMemDC(), attRc.left - _camera.rc.left, attRc.top - _camera.rc.top, attRc.right - _camera.rc.left, attRc.bottom - _camera.rc.top);
	//Rectangle(getMemDC(), attRc2.left - _camera.rc.left, attRc2.top - _camera.rc.top, attRc2.right - _camera.rc.left, attRc2.bottom - _camera.rc.top);

	if (KEYMANAGER->isToggleKey('O'))
	{
		Rectangle(getMemDC(), _player.rc.left - _camera.rc.left, _player.rc.top - _camera.rc.top, _player.rc.right - _camera.rc.left, _player.rc.bottom - _camera.rc.top);
		//Rectangle(getMemDC(), _player.collisionRc.left - _camera.rc.left, _player.collisionRc.top - _camera.rc.top, _player.collisionRc.right - _camera.rc.left, _player.collisionRc.bottom - _camera.rc.top);
	}

	_ui->render();

	//_arrow->render();
	

	

	for (int i = 0; i < _arrow->getVArrow().size(); i++)
	{
		//Rectangle(getMemDC(), _arrow->getArrow()[i].rc.left - _camera.rc.left, _arrow->getArrow()[i].rc.top - _camera.rc.top, _arrow->getArrow()[i].rc.right - _camera.rc.left, _arrow->getArrow()[i].rc.bottom - _camera.rc.top);
		_arrow->getVArrow()[i].arrowImage->frameRender(getMemDC(), _arrow->getVArrow()[i].rc.left - _camera.rc.left, _arrow->getVArrow()[i].rc.top - _camera.rc.top);
	}
	if (KEYMANAGER->isToggleKey(VK_F1))
	{

		for (int i = 0; i < _enemyManger->getEnemy().size(); ++i)
		{
			Rectangle(getMemDC(), _enemyManger->getEnemy()[i]->getRc().left - _camera.rc.left, _enemyManger->getEnemy()[i]->getRc().top - _camera.rc.top, _enemyManger->getEnemy()[i]->getRc().right - _camera.rc.left, _enemyManger->getEnemy()[i]->getRc().bottom - _camera.rc.top);
		}
	}

	char str[128];
	sprintf(str, "중력 : %f, 점프카운터 : %d, 상태 : %d", _player.gravity, jumpCount,_state);
	TextOut(getMemDC(), 100, 600, str,strlen(str));
}

//ToDo : 이미지 셋팅
void foxPlayer::imageSetting()
{
	nick[IDLE] = IMAGEMANAGER->findImage("Idle");		//아이들
	nick[RUN] = IMAGEMANAGER->findImage("Run");			//달리기
	nick[JUMP] = IMAGEMANAGER->findImage("Jump");		//점프
	nick[DOUBLEJUMP] = IMAGEMANAGER->findImage("Jump2");	//이단점프
	nick[FALL] = IMAGEMANAGER->findImage("Fall");		//떨어지는
	nick[FALL2] = IMAGEMANAGER->findImage("Fall2");		//이단점프하고 떨어지는
	nick[FIRE] = IMAGEMANAGER->findImage("Fire");		//발사
	nick[UPATT] = IMAGEMANAGER->findImage("UpAtt");		//상단베기
	nick[SITATT] = IMAGEMANAGER->findImage("SitAtt");	//앉아공격
	nick[SIT] = IMAGEMANAGER->findImage("Sit");			//앉기
	nick[JUMPATT] = IMAGEMANAGER->findImage("JumpAtt");	//점프공격
	nick[JUMPATT2] = IMAGEMANAGER->findImage("JumpAtt2");	//점프공격2 회전회오리~!
	nick[DOWNATT] = IMAGEMANAGER->findImage("DownAtt");	//내려찍기
	nick[HIT] = IMAGEMANAGER->findImage("Hurt");		//맞는이미지
	nick[WEATHER] = IMAGEMANAGER->findImage("Weather");		//날씨 바꾸는 모션
	_twinkle = IMAGEMANAGER->findImage("Twinkle");			//반짝이
}
//ToDo : 프레임 움직임
void foxPlayer::frameMove()
{
	if (_state == SITATT || _state == UPATT || _state == JUMPATT || _state == JUMPATT2 || _state == DOWNATT)
	{
		++actionCount;
		if (_player.isLeft)
		{
			nick[_state]->setFrameY(1);
			if (actionCount % 4 == 0)
			{
				actionIndex--;
				if (actionIndex < 0)
				{
					actionIndex = nick[_state]->getMaxFrameX();
				}
				nick[_state]->setFrameX(actionIndex);
			}
		}
		else
		{
			nick[_state]->setFrameY(0);
			if (actionCount % 4 == 0)
			{
				actionIndex++;
				if (actionIndex > nick[_state]->getMaxFrameX())
				{
					actionIndex = 0;
				}
				nick[_state]->setFrameX(actionIndex);
			}
		}
	}
	if (_state == FIRE)
	{
		++actionCount;
		if (_player.isLeft)
		{
			nick[FIRE]->setFrameY(1);
			if (actionCount % 1 == 0)
			{
				actionIndex--;
				if (actionIndex < 0)
				{
					actionIndex = nick[FIRE]->getMaxFrameX();
				}
				nick[FIRE]->setFrameX(actionIndex);
			}
		}
		else
		{
			nick[FIRE]->setFrameY(0);
			if (actionCount % 1 == 0)
			{
				actionIndex++;
				if (actionIndex > nick[FIRE]->getMaxFrameX())
				{
					actionIndex = 0;
				}
				nick[FIRE]->setFrameX(actionIndex);
			}
		}
	}

	if(_state == RUN || _state == IDLE || _state == JUMP || _state == DOUBLEJUMP || _state == SIT || _state == FALL || _state == HIT)
	{
		++count;
		if (_player.isLeft)
		{
			nick[_state]->setFrameY(1);
			if (count % 8 == 0)
			{
				index--;
				if (index < 0)
				{
					index = nick[_state]->getMaxFrameX();
				}
				nick[_state]->setFrameX(index);
			}
		}
		else
		{
			nick[_state]->setFrameY(0);
			if (count % 8 == 0)
			{
				index++;
				if (index > nick[_state]->getMaxFrameX())
				{
					index = 0;
				}
				nick[_state]->setFrameX(index);
			}
		}
	}
	if (_state == WEATHER)
	{
		++count;
		if (_player.isLeft)
		{
			nick[WEATHER]->setFrameY(1);
			if (count % 15 == 0)
			{
				weatherIndex--;
				if (weatherIndex < 0)
				{
					weatherIndex = nick[WEATHER]->getMaxFrameX();
				}
				nick[WEATHER]->setFrameX(weatherIndex);
			}
		}
		else
		{
			nick[WEATHER]->setFrameY(0);
			if (count % 15 == 0)
			{
				weatherIndex++;
				if (weatherIndex > nick[WEATHER]->getMaxFrameX())
				{
					weatherIndex = 0;
				}
				nick[WEATHER]->setFrameX(weatherIndex);
			}
		}
		if (_player.isChange)
		{
			++effectCount;
			_twinkle->setFrameY(0);
			if (effectCount % 5 == 0)
			{
				effectIndex++;
				if (effectIndex > _twinkle->getMaxFrameX())
				{
					effectIndex = 0;
				}
				_twinkle->setFrameX(effectIndex);
			}
		}
	}

	
		
	
	
}
//충돌 렉트 크기 변환
void foxPlayer::collisionRcChange()
{
	if (_player.isRight && !_player.isLeft)
	{
		_player.collisionRc = RectMakeCenter(_player.x - 10, _player.y + 35, _player.radian, 110);
	}
	else if (_player.isLeft && !_player.isRight)
	{
		_player.collisionRc = RectMakeCenter(_player.x + 10, _player.y + 35, _player.radian, 110);
	}
	else if (!_player.isLeft && _player.isDown)		//오른쪽으로만 앉을때만 렉트 바뀜ㅜㅜ
	{
		_player.collisionRc = RectMakeCenter(_player.x - 10, _player.y + 53, _player.radian, 75);
	}
	else if (!_player.isRight && _player.isLeft &&_player.isDown)		//이게 왼쪽 앉는건데 얼른 해결해볼께ㅜ
	{
		_player.collisionRc = RectMakeCenter(_player.x + 10, _player.y + 53, _player.radian, 75);
	}
	else if (_player.isJump)
	{
		_player.collisionRc = RectMakeCenter(_player.x - 10, _player.y + 10, _player.radian, 110);
	}
	else if (!_player.isRight && _player.isJump)
	{
		_player.collisionRc = RectMakeCenter(_player.x + 10, _player.y + 10, _player.radian, 110);
	}
	else
	{
		_player.collisionRc = RectMakeCenter(_player.x - 10, _player.y + 35, _player.radian, 110);
	}
}
//ToDo : 여우 상태
void foxPlayer::foxState()
{
	if (_state == IDLE)
	{
		_player.gravity = 0.f;
		jumpCount = 0;
		unDamage++;
		//_player.isUp = _player.isDown = false;
		/*if (_player.isLeft)
		{
			actionIndex = index = nick[_state]->getMaxFrameX();
		}
		else
		{
			actionIndex = index = 0;
		}*/
	
	}

	if (_state == RUN)
	{
		jumpCount = 0;
		unDamage++;
		if (_player.isLeft)
		{
			_player.x -= _player.speed / 3;
		}
		else
		{
			_player.x += _player.speed / 3;
		}
	}

	if (_state == JUMP || _state == DOUBLEJUMP)
	{
		unDamage++;
		_player.gravity += 0.7f;
		_player.x += cosf(_player.angle)*_player.speed;
		_player.y += -sinf(_player.angle)*_player.speed + _player.gravity;
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player.isLeft = true;
			_player.x -= _player.speed / 3;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player.isLeft = false;
			_player.x += _player.speed / 3;
		}
		if (-sinf(_player.angle)*_player.speed + _player.gravity > 0)
		{
			//_player.gravity = 0;
			_state = FALL;
		}
		/*else if (_state == DOUBLEJUMP && -sinf(_player.angle)*_player.speed + _player.gravity > 0)
		{
			_state = FALL2;
		}*/
	}

	if (_state == FALL || _state == FALL2)
	{
		unDamage++;
		_player.gravity = 0.f;
		_player.gravity += 0.7f;
		_player.y += _player.gravity;
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player.isLeft = true;
			_player.x -= _player.speed / 3;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player.isLeft = false;
			_player.x += _player.speed / 3;
		}
	}
	
	if (_state == FIRE)
	{
		if (_player.isLeft)
		{
			if (actionIndex <= 0)
			{
				actionIndex = nick[FIRE]->getMaxFrameX();
				_state = IDLE;
			}
		}
		else
		{
			if (actionIndex >= nick[FIRE]->getMaxFrameX())
			{
				actionIndex = 0;
				_state = IDLE;
			}
		}
	}
	if (_state == SITATT)
	{
		if (_player.isLeft)
		{
			if (actionIndex <= 0)
			{
				actionIndex = nick[SITATT]->getMaxFrameX();
				_state = SIT;
			}
		}
		else
		{
			if (actionIndex >= nick[SITATT]->getMaxFrameX())
			{
				actionIndex = 0;
				_state = SIT;
			}
		}
	}
	if (_state == UPATT)
	{
		if (_player.isLeft)
		{
			if (actionIndex <= 0)
			{
				actionIndex = nick[UPATT]->getMaxFrameX();
				_state = IDLE;
			}
		}
		else
		{
			if (actionIndex >= nick[UPATT]->getMaxFrameX())
			{
				actionIndex = 0;
				_state = IDLE;
			}
		}
	}
	if (_state == JUMPATT || _state == JUMPATT2)
	{
		if (_player.isLeft)
		{
			if (actionIndex <= 0)
			{
				actionIndex = nick[_state]->getMaxFrameX();
				_state = FALL;
			}
		}
		else 
		{
			if (actionIndex >= nick[_state]->getMaxFrameX())
			{
				actionIndex = 0;
				_state = FALL;
			}
		}
	}
	
	if (_state == DOWNATT)
	{

	}
	if (_state == HIT)
	{
		hitCount++;
		if (hitCount > 25)
		{
			chk = false;
			_state = IDLE;
			hitCount = 0;
		}
	}

	if (_state == WEATHER)
	{
		if (_player.isLeft)
		{
			if (weatherIndex <= 0)
			{
				weatherIndex = nick[WEATHER]->getMaxFrameX();
				_state = IDLE;
			}
		}
		else
		{
			if (weatherIndex >= nick[WEATHER]->getMaxFrameX())
			{
				weatherIndex = 0;
				_state = IDLE;
			}
		}
	}
}

//ToDo : 키 셋팅
void foxPlayer::keySetting()
{
	if (_state == IDLE && KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player.isRight = true;
		_player.isLeft = false;
		_player.arrowAngle = 0;
		//_player.arrowAngle2 = PI / 4;
		//_player.arrowAngle3 = PI / 3;
		
		_state = RUN;
	}
	if (_player.isJump == false && _state != HIT && KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_player.isRight = false;
		_state = IDLE;
	}
	if (_state == IDLE && KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player.isLeft = true;
		_player.isRight = false;

		_player.arrowAngle = PI;
		//_player.arrowAngle2 = PI / 4;
		//_player.arrowAngle3 = PI / 3;
		_state = RUN;
	}
	if (_player.isJump == false && _state != HIT && KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		//_player.isLeft = false;

		_state = IDLE;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_player.isUp = true;
		_player.isAtt = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_player.isUp = false;
		_player.isAtt = false;
	}
	if (_player.isJump == false && KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_player.isDown = true;
		_state = SIT;
	}
	if (_player.isJump == false && KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_player.isDown = false;
		_state = IDLE;
	}
	if (jumpCount < 2)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			SOUNDMANAGER->play("점프사운드");
			++jumpCount;
			_player.isJump = true;
			_state = JUMP;
			if (jumpCount >=2)
			{
				SOUNDMANAGER->play("2단점프사운드");
				//jumpCount = 0;
				_player.gravity = 0.f;
				_state = DOUBLEJUMP;
			}
		}
	}
	if (_state != JUMPATT && _state != JUMPATT2 && KEYMANAGER->isOnceKeyDown('A'))
	{	
		if (_state == SIT && _player.isDown)
		{
			_player.isAtt = true;
			_state = SITATT;
		}
		else if (_state == JUMP)
		{
			_player.isAtt = true;
			_state = JUMPATT;
			SOUNDMANAGER->play("1단점프공격사운드");
		}
		else if (_state == DOUBLEJUMP)
		{
			_player.isAtt = true;
			_state = JUMPATT2;
			SOUNDMANAGER->play("2단점프공격사운드");
		}
		else if (_player.isUp)
		{
			_state = UPATT;
		}
		else if (_state == IDLE)
		{
			SOUNDMANAGER->play("화살발사사운드");
			_state = FIRE;
			_arrow->fire(_player.x, _player.y + 30, _player.arrowAngle);
			//_arrow->fire2(_player.x, _player.y + 30, _player.arrowAngle, _player.arrowAngle2, _player.arrowAngle3);
		}
		
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_player.isAtt = false;
	}

	if (!_player.isJump && KEYMANAGER->isOnceKeyDown('S'))
	{
		if (!ang)
		{
			ang = true;
		}
		else
		{
			ang = false;
		}
		_player.isChange = true;
		_state = WEATHER;
		if (_player.isChange)
		{
			Rectangle(getMemDC(), twinkleRc.left - _camera.rc.left, twinkleRc.top - _camera.rc.top, twinkleRc.right - _camera.rc.left, twinkleRc.bottom - _camera.rc.top);
			_twinkle->frameRender(getMemDC(), twinkleRc.left - _camera.rc.left, twinkleRc.top - _camera.rc.top, _twinkle->getFrameX(), _twinkle->getFrameY());
		}
	}

	/*if (KEYMANAGER->isOnceKeyDown('S'))
	{
		_state = WEATHER1;
	}*/
	
}

//ToDo : 카메라
void foxPlayer::camera()		//카메라 움직이는 함수
{
	_camera.x = _player.x;
	_camera.y = _player.y;

	if (_camera.x - WINSIZEX / 2 < 0)
	{
		_camera.x = WINSIZEX / 2;
	}
	if (_camera.x + WINSIZEX / 2 > MAX_WIDTH)
	{
		_camera.x = MAX_WIDTH - WINSIZEX / 2;
	}
	if (_camera.y - WINSIZEY / 2 < 0)
	{
		_camera.y = WINSIZEY / 2;
	}
	if (_camera.y + WINSIZEY / 2 > MAX_HEIGHT)
	{
		_camera.y = MAX_HEIGHT - WINSIZEY / 2;
	}
}
//ToDo : 픽셀충돌
void foxPlayer::pixelCollision()		//픽셀 충돌
{
	//플레이어 렉트 bottom 픽셀충돌
	for (int i = _player.collisionRc.bottom - _player.speed; i < _player.collisionRc.bottom +20; ++i)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), _player.x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 0 && g == 255 && b == 255 && (_state == FALL || _state == FALL2 ||_state == HIT ||!_player.isJump))
		{
			
			_player.y = i - nick[_state]->getFrameHeight() / 2;
			_player.gravity = 0.f;
			_player.isJump = false;
			//_state = IDLE;
			if (_state == FALL)
			{
				_state = IDLE;
			}
			break; 
		}
		else if (r == 255 && g == 255 && b == 0)
		{
			_player.y = i - nick[_state]->getFrameHeight() / 2;
			_player.gravity = 0.f;
			_player.isJump = false;
			if (_state == FALL)
			{
				_state = IDLE;
			}
			break;
		}
		else //if (!(r == 0 && g == 255 && b == 255) && !_player.isJump)
		{
			_player.y += 0.2f;
		}
	}
	//플레이어 충돌렉트 top 픽셀 충돌
	for (int i = _player.collisionRc.top + _player.speed; i > _player.collisionRc.top + 5; --i)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), _player.x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 0 && g == 255 && b == 255 && (_state != FALL || _state != FALL2 || _state == HIT ||  _state == RUN || _player.isJump))
		{
			_player.y = i + (_player.collisionRc.bottom - _player.collisionRc.top) / 2 + 15;
			_state = FALL;
			//_player.speed = 0.f;
			_player.gravity += 0.7f;
			_player.x += cosf(_player.angle)*_player.speed;
			_player.y += -sinf(_player.angle)*_player.speed + _player.gravity;
			
			break;
		}
	}

	//플레이어 렉트 right 픽셀 충돌
	for (int i = _player.collisionRc.right - _player.speed; i < _player.collisionRc.right; i++)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), i, _player.y + 60);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 0 && g == 255 && b == 255)
		{
			_player.x = i - (_player.collisionRc.right - _player.collisionRc.left) / 2;
			_player.isRight = false;
			
			break;
		}
		if (r == 255 && g == 255 && b == 0)
		{
			_player.x = i - (_player.collisionRc.right - _player.collisionRc.left) / 2;
			_player.isRight = false;

			break;
		}

	}

	//플레이어 렉트 left 픽셀 충돌  
	for (int i = _player.collisionRc.left + _player.speed; i > _player.collisionRc.left; --i)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), i, _player.y + 60);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 0 && g == 255 && b == 255)
		{
			_player.x = i + (_player.collisionRc.right - _player.collisionRc.left) / 2;
			//_player.isLeft = false;			//여기 문제있음
			break;
		}
		if (r == 255 && g == 255 && b == 0)
		{
			_player.x = i + (_player.collisionRc.right - _player.collisionRc.left) / 2;
			break;
		}
	}

	//for (int i = _player.rc.top; i < _player.rc.bottom; i += (_player.rc.bottom - _player.rc.top) / 2)
	//{
	//	for (int j = _player.rc.right; j < _player.rc.right; ++j)
	//	{
	//		COLORREF color = GetPixel(_bfx->getMemDC(), j, i);
	//
	//		int r = GetRValue(color);
	//		int g = GetGValue(color);
	//		int b = GetBValue(color);
	//
	//		if (r == 0 && g == 255 && b == 255 )
	//		{
	//			_player.x = j - _player.radian;
	//			_player.isJump = false;
	//			break;
	//		}
	//	}
	//}

	//for (int i = _player.rc.top-10; i < _player.rc.top; ++i)
	//{
	//	COLORREF color = GetPixel(_bfx->getMemDC(), _player.x, i);
	//
	//	int r = GetRValue(color);
	//	int g = GetGValue(color);
	//	int b = GetBValue(color);
	//
	//	if (r == 0 && g == 255 && b == 255)
	//	{
	//		_player.y = i + _player.radian;
	//		
	//		break;
	//	}
	//	else
	//	{
	//		//			_player.y += 0.2f;
	//	}
	//}
}
//ToDo : 적과의 충돌
void foxPlayer::enemyCollision()
{
	for (int i = 0; i < _enemyManger->getEnemy().size(); ++i)
	{
		RECT tempRc;
		if (unDamage > 15)
		{
			if (IntersectRect(&tempRc, &_player.collisionRc, &_enemyManger->getEnemy()[i]->getCollisionRc()) && _enemyManger->getEnemy()[i]->getState() != ENEMY_SPAWN && _state != HIT)
			{
				if (chk == false)
				{
					_player.HP -= 5;
					chk = true;
				}
				int width = (tempRc.right - tempRc.left) + 50;
				int height = (tempRc.bottom - tempRc.top) + 50;

				if (_player.x < _enemyManger->getEnemy()[i]->getCollisionRc().left)
				{
					_player.x -= width;
					_player.y -= height;
				}
				else if (_player.x > _enemyManger->getEnemy()[i]->getCollisionRc().right)
				{
					_player.x += width;
					_player.y += height;
				}
				else if (_player.y < _enemyManger->getEnemy()[i]->getCollisionRc().top)
				{
					_player.x -= width;
					_player.y -= height;
				}
				else if (_player.y > _enemyManger->getEnemy()[i]->getCollisionRc().bottom)
				{
					_player.x += width;
					_player.y += height;
				}
				_state = HIT;
				unDamage = 0;
			}

			
			
		}
	}
}

void foxPlayer::enemyAttCollision()
{
	
		for (int i = 0; i < _enemyManger->getEnemy().size(); ++i)
		{
			RECT tempRc2;
			
			if (unDamage > 16)
			{
				if (IntersectRect(&tempRc2, &_player.collisionRc, &_enemyManger->getEnemy()[i]->getAttRc()))
				{
					if (chk == false)
					{
						_player.HP -= 5;
						chk = true;
					}
					int width = (tempRc2.right - tempRc2.left) + 50;
					int height = (tempRc2.bottom - tempRc2.top) + 50;

					if (_player.x < _enemyManger->getEnemy()[i]->getAttRc().left)
					{
						_player.x -= width;
						_player.y -= height;
					}
					else if (_player.x > _enemyManger->getEnemy()[i]->getAttRc().right)
					{
						_player.x += width;
						_player.y += height;
					}
					else if (_player.y < _enemyManger->getEnemy()[i]->getAttRc().top)
					{
						_player.x -= width;
						_player.y -= height;
					}
					else if (_player.y > _enemyManger->getEnemy()[i]->getAttRc().bottom)
					{
						_player.x += width;
						_player.y += height;
					}
					_state = HIT;
					unDamage = 0;

				}
			}
			
		}

	

	
	
	
}

void foxPlayer::removeArrow(int index)
{
	_arrow->removeArrow(index);
}

void foxPlayer::test()
{
	if (KEYMANAGER->isOnceKeyDown('F') && _player.MaxHp < 100)
	{
		_player.MaxHp += 10;
	}
	if (KEYMANAGER->isOnceKeyDown('G') && _player.MaxHp > 10)
	{
		_player.MaxHp -= 10;
	}
	if (KEYMANAGER->isOnceKeyDown('H') && _player.HP < _player.MaxHp)
	{
		_player.HP += 5;
	}
	if (KEYMANAGER->isOnceKeyDown('J') && _player.HP > 0)
	{
		_player.HP -= 5;
	}
	if (KEYMANAGER->isOnceKeyDown('K') && _player.maxMana < 200)
	{
		_player.maxMana += 5;
	}
	if (KEYMANAGER->isOnceKeyDown('L') && _player.maxMana > 100)
	{
		_player.maxMana -= 5;
	}
	if (KEYMANAGER->isStayKeyDown('N') && _player.gold < 1000)
	{
		_player.gold += 1;
	}
	if (KEYMANAGER->isStayKeyDown('M') && _player.gold > 0)
	{
		_player.gold -= 1;
	}
}

