#include "stdafx.h"
#include "foxPlayer.h"


//ToDo : init
HRESULT foxPlayer::init(void)
{
	imageSetting();

	_state = IDLE;
	_player.x = 100;
	_player.y = MAX_HEIGHT - 180;
	_player.speed = 15.f;
	_player.gravity = 0.f;
	_player.angle = PI / 2;
	_player.bulletAngle = 0;
	_player.radian = 90;
	_player.isJump = _player.isLeft = _player.isUp = _player.isDown = _player.isRight = _player.isAtt = false;
	
	index = count = actionCount = actionIndex = jumpCount = 0;

	_camera.x = _player.x;
	_camera.y = _player.y;

	_bfx = IMAGEMANAGER->findImage("��������1 �ȼ�");
	
	return S_OK;
}

void foxPlayer::release(void)
{
}

//ToDo : update
void foxPlayer::update(void)
{
	this->keySetting();	  //Ű���� �Լ� ȣ��

	this->foxState();		//�÷��̾� ���� �Լ� ȣ��

	this->frameMove();		//������ �����̴� �Լ� ȣ��
	
	this->camera();			//ī�޶� �����̴� �Լ� ȣ��

	_player.rc = RectMakeCenter(_player.x, _player.y, nick[_state]->getFrameWidth(), nick[_state]->getFrameHeight());

	this->pixelCollision();		//�ȼ��浹 �Լ� ȣ��

	if (_player.isAtt)
	{
		attRc = RectMakeCenter(_player.x + _player.radian + 50, _player.y, 50, 50);
	}
	else
	{
		attRc = RectMakeCenter(-10000,-10000 , 50, 50);
	}
	
	_camera.rc = RectMakeCenter(_camera.x, _camera.y, WINSIZEX, WINSIZEY);
}

//void foxPlayer::render(float FX, float FY)
//{
//	Rectangle(getMemDC(), _player.rc.left -FX , _player.rc.top -FY , _player.rc.right - FX, _player.rc.bottom - FY);
//}

//ToDo : render
void foxPlayer::render()
{
	
	nick[_state]->frameRender(getMemDC(), _player.rc.left - _camera.rc.left, _player.rc.top - _camera.rc.top, nick[_state]->getFrameX(), nick[_state]->getFrameY());
	
	Rectangle(getMemDC(), attRc.left - _camera.rc.left, attRc.top - _camera.rc.top, attRc.right - _camera.rc.left, attRc.bottom - _camera.rc.top);

	if (KEYMANAGER->isToggleKey('O'))
	{
		Rectangle(getMemDC(), _player.rc.left - _camera.rc.left, _player.rc.top - _camera.rc.top, _player.rc.right - _camera.rc.left, _player.rc.bottom - _camera.rc.top);
	}
	
	char str[128];
	sprintf(str, "�߷� : %f, ����ī���� : %d, ���� : %d", _player.gravity, jumpCount, _state);
	TextOut(getMemDC(), 100, 600, str,strlen(str));
}

//ToDo : �̹��� ����
void foxPlayer::imageSetting()
{
	nick[IDLE] = IMAGEMANAGER->findImage("Idle");		//���̵�
	nick[RUN] = IMAGEMANAGER->findImage("Run");			//�޸���
	nick[JUMP] = IMAGEMANAGER->findImage("Jump");		//����
	nick[DOUBLEJUMP] = IMAGEMANAGER->findImage("Jump2");	//�̴�����
	nick[FALL] = IMAGEMANAGER->findImage("Fall");		//��������
	nick[FIRE] = IMAGEMANAGER->findImage("Fire");		//�߻�
	nick[UPATT] = IMAGEMANAGER->findImage("UpAtt");		//��ܺ���
	nick[SITATT] = IMAGEMANAGER->findImage("SitAtt");	//�ɾư���
	nick[SIT] = IMAGEMANAGER->findImage("Sit");			//�ɱ�
	nick[JUMPATT] = IMAGEMANAGER->findImage("JumpAtt");	//��������
	nick[JUMPATT2] = IMAGEMANAGER->findImage("JumpAtt2");	//��������2 ȸ��ȸ����~!
	nick[DOWNATT] = IMAGEMANAGER->findImage("DownAtt");	//�������
}
//ToDo : ������ ������
void foxPlayer::frameMove()
{
	if (_state == FIRE || _state == SITATT || _state == UPATT || _state == JUMPATT || _state == JUMPATT2 || _state == DOWNATT)
	{
		++actionCount;
		if (_player.isLeft)
		{
			nick[_state]->setFrameY(1);
			if (actionCount % 3 == 0)
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
			if (actionCount % 3 == 0)
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
	else
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
	
}
//ToDo : ���� ����
void foxPlayer::foxState()
{
	if (_state == IDLE)
	{
		_player.gravity = 0.f;
		jumpCount = 0;
		_player.isDown = _player.isUp = false;
	
	}
	if (_state == RUN)
	{
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
			_state = FALL;
		}
	}
	if (_state == FALL)
	{
		_player.y += 9.f;
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
				_state = IDLE;
			}
		}
		else
		{
			if (actionIndex >= nick[_state]->getMaxFrameX())
			{
				_state = IDLE;
			}
		}

	}
	if (_state == UPATT && _state == SITATT)
	{

	}
	if (_state == JUMPATT)
	{

	}
	if (_state == JUMPATT2)
	{

	}
	if (_state == DOWNATT)
	{

	}
}
//ToDo : Ű ����
void foxPlayer::keySetting()
{
	if (_state == IDLE && KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_player.isRight = true;
		_player.isLeft = false;
		_state = RUN;
	}
	if (_player.isJump == false && KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_player.isRight = false;
		_state = IDLE;
	}
	if (_state == IDLE && KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player.isLeft = true;
		_state = RUN;
	}
	if (_player.isJump == false && KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_state = IDLE;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_player.isUp = true;
	}
	if (_player.isJump == false && KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_player.isDown = true;
		_state = SIT;
	}
	if (_player.isJump == false && KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_state = IDLE;
	}
	if (jumpCount < 2)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			++jumpCount;
			_player.isJump = true;
			_state = JUMP;
			if (jumpCount >=2)
			{
				_player.gravity = 0.f;
				_state = DOUBLEJUMP;
			}
		}
	}
	if (_state != JUMPATT && _state != JUMPATT2 && KEYMANAGER->isOnceKeyDown('A'))
	{
		_player.isAtt = true;
		if (_state == SIT)
		{
			_state = SITATT;
		}
		else if (_state == JUMP)
		{
			_state = JUMPATT;
		}
		else if (_state == DOUBLEJUMP)
		{
			_state = JUMPATT2;

		}
		else if (_player.isUp)
		{
			_state = UPATT;
		}
		else
		{
			_state = FIRE;
		}
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_player.isAtt = false;
	}
	/*if (KEYMANAGER->isOnceKeyDown('S'))
	{
		_state = WEATHER1;
	}*/
	
}
//ToDo : ī�޶�
void foxPlayer::camera()		//ī�޶� �����̴� �Լ�
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
//ToDo : �ȼ��浹
void foxPlayer::pixelCollision()		//�ȼ� �浹
{
	//�÷��̾� ��Ʈ bottom �ȼ��浹
	for (int i = _player.rc.bottom - _player.speed; i < _player.rc.bottom+30; ++i)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), _player.x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 0 && g == 255 && b == 255 && (_state == FALL || !_player.isJump))
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
		else if (!(r == 0 && g == 255 && b == 255) && !_player.isJump)
		{
			_player.y += 0.2f;
		}
	}
	
	//�÷��̾� ��Ʈ right �ȼ� �浹
	for (int i = _player.rc.right - _player.speed; i < _player.rc.right+5 ; i++ )
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), i, _player.y);
	
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
	
		if (r == 0 && g == 255 && b == 255)
		{
			_player.x = i - nick[_state]->getFrameWidth() / 2;
			_player.isRight = false;
			break;
		}
		
	}

	//�÷��̾� ��Ʈ left �ȼ� �浹
	for (int i = _player.rc.left + _player.speed; i > _player.rc.left; --i)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), i, _player.y);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 0 && g == 255 && b == 255)
		{
			_player.x = i + nick[_state]->getFrameWidth() / 2;
			_player.isLeft = false;			//���� ��������
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
