#include "stdafx.h"
#include "enemy.h"

void dragonFly::init()
{
	for (int i = 0; i < 5; i++)
	{
		_bodyImage[i] = new image;
	}

	//_bodyImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("���ڸ�spawn");
	_bodyImage[ENEMY_SPAWN] = IMAGEMANAGER->findImage("���ڸ�spawn");
	_bodyImage[ENEMY_WALK]= IMAGEMANAGER->findImage("���ڸ�move");
	//_bodyImage[ENEMY_FIRE]= IMAGEMANAGER->findImage("���ڸ�move");
	_bodyImage[ENEMY_DEAD]= IMAGEMANAGER->findImage("���ڸ�dead");
	_bfx = IMAGEMANAGER->findImage("��������1 �ȼ�");


	//_gunImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("������");
	_speed = 3.f;
	_angle = 0;
	_gravity = 0.f;
	_count = 0, _indexX = 0;
	_animationSpeed = 5.f;
	_isActived = true;
	_state = ENEMY_SPAWN;
	_type = DRAGONFLY;
	_x = 0.f;
	_y = 0.f;
	_isLeft = true;
	//����
	_gold = 0;
	_silver = 1;
	_bronze = 1;

}

void dragonFly::idle()
{
	//cout << "���� ����" << endl;
	
}

void dragonFly::spawn()
{
	if (_isLeft)
	{
		if (_indexX >= _bodyImage[_state]->getMaxFrameX())
			_state = ENEMY_WALK;
	}
	else
	{
		if (_indexX <= 0)
			_state = ENEMY_WALK;
	}
}

void dragonFly::attack()
{
}

void dragonFly::move()
{
	if (_count % 100 < 50)
	{
		_y -= 1;
	}
	else if (_count % 100 <= 100)
	{
		_y += 1;
	}
	_angle += 0.08f;
	_y += -sinf(_angle)*_speed;

	_collisionRc = RectMakeCenter(_x, _y, _bodyImage[_state]->getFrameWidth() * 2 / 3, _bodyImage[_state]->getFrameHeight() * 2 / 3);

}

void dragonFly::dead()
{

}

void vineMan::init()
{
	_bodyImage[ENEMY_SPAWN] = IMAGEMANAGER->findImage("�����ΰ�spawn");
	_bodyImage[ENEMY_WALK] = IMAGEMANAGER->findImage("�����ΰ�move");
	_bodyImage[ENEMY_ATTACK] = IMAGEMANAGER->findImage("�����ΰ�attack");
	_bodyImage[ENEMY_DEAD] = IMAGEMANAGER->findImage("�����ΰ�dead");

	_bfx = IMAGEMANAGER->findImage("��������1 �ȼ�");

	_speed = 3.f;
	_angle = 270.f * 3.14f / 180;
	_gravity = 0.f;
	_count = 0, _indexX = 0;
	_animationSpeed = 3.f;
	_isActived = true;
	_state = ENEMY_SPAWN;
	_type = VINEMAN;
	_x = 3480.f;
	_y = 900.f;
	_isLeft = true;
	_gold = 0;
	_silver = 1;
	_bronze = 1;

}

void vineMan::idle()
{
	//cout << "���� ��κ�" << endl;
}

void vineMan::spawn()
{
	_attRc = RectMake(_x, _y -10 , 0, 20);


	if (_isLeft)
	{
		if (_indexX >= _bodyImage[_state]->getMaxFrameX())
			_state = ENEMY_WALK;
	}
	else
	{
		if (_indexX <= 0)
			_state = ENEMY_WALK;
	}
}

void vineMan::attack()
{
	_attRc = RectMake(_x, _y , 0, 20);

	_animationSpeed = 4.f;

	if (_isLeft)
	{
		if (_attRc.right - _attRc.left < 130)
		{
			_attRc.left -= 130;

		}
	}
	else
	{
		if (_attRc.right - _attRc.left < 150)
		{
			_attRc.right += 150;

		}
	}




	_collisionRc = RectMakeCenter(_x, _y, _bodyImage[ENEMY_WALK]->getFrameWidth() * 2 / 3, _bodyImage[ENEMY_WALK]->getFrameHeight());

}

void vineMan::move()
{
	_attRc = RectMake(_x, _y -10 , 0, 20);

	if (_count % 200 < 100)
	{
		_x -= 1;
		_isLeft = true;
	}
	else if (_count % 200 <= 200)
	{
		_x += 1;
		_isLeft = false;
	}

	_gravity += 3.0f;
	_y += _gravity;
	_collisionRc = RectMakeCenter(_x, _y, _bodyImage[ENEMY_WALK]->getFrameWidth() * 2 / 3, _bodyImage[ENEMY_WALK]->getFrameHeight());

}

void vineMan::dead()
{
}


void bug::init()
{
	//_bodyImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("����spawn");
	_bodyImage[ENEMY_WALK] = IMAGEMANAGER->findImage("����move");
	_bodyImage[ENEMY_DEAD] = IMAGEMANAGER->findImage("����dead");

	_bfx = IMAGEMANAGER->findImage("��������1 �ȼ�");

	_speed = 3.f;
	_angle = 270.f * 3.14f / 180;
	_gravity = 0.f;
	_count = 0, _indexX = 0;
	_animationSpeed = 3.f;
	_isActived = true;
	_state = ENEMY_WALK;
	_type = BUG;
	_x = 3480.f;
	_y = 900.f;
	_isLeft = false;
	_gold = 0;
	_silver = 1;
	_bronze = 1;
}

void bug::idle()
{
}

void bug::spawn()
{
}

void bug::attack()
{
}

void bug::move()
{
	if (_count % 100 < 50)
	{
		_x -= 2;
		_isLeft = true;
	}
	else if (_count % 100 <= 100)
	{
		_x += 2;
		_isLeft = false;
	}
	_collisionRc = RectMakeCenter(_x, _y, _bodyImage[ENEMY_WALK]->getFrameWidth(), _bodyImage[ENEMY_WALK]->getFrameHeight());

}

void bug::dead()
{
}

void treeMan::init()
{
	//_bodyImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("����spawn");
	_bodyImage[ENEMY_WALK] = IMAGEMANAGER->findImage("�볪��move");
	_bodyImage[ENEMY_DEAD] = IMAGEMANAGER->findImage("�볪��dead");

	_bfx = IMAGEMANAGER->findImage("��������1 �ȼ�");

	_speed = 3.f;
	_angle = 270.f * 3.14f / 180;
	_gravity = 0.f;
	_count = 0, _indexX = 0;
	_animationSpeed = 3.f;
	_isActived = true;
	_state = ENEMY_WALK;
	_type = TREEMAN;
	_x = 3480.f;
	_y = 900.f;
	_isLeft = false;
	_gold = 3;
	_silver = 0;
	_bronze = 0;
	isStrong = false;
}

void treeMan::idle()
{
}

void treeMan::spawn()
{
}

void treeMan::attack()
{
}

void treeMan::move()
{
	if (_count % 200 < 100)
	{
		_x -= 1;
		_isLeft = true;
	}
	else if (_count % 200 <= 200)
	{
		_x += 1;
		_isLeft = false;
	}
	_collisionRc = RectMakeCenter(_x, _y, _bodyImage[ENEMY_WALK]->getFrameWidth(), _bodyImage[ENEMY_WALK]->getFrameHeight());

}

void treeMan::dead()
{
}

void plantFrog::init()
{
	//_bodyImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("����spawn");
	_bodyImage[ENEMY_SPAWN] = IMAGEMANAGER->findImage("�β���spawn");
	_bodyImage[ENEMY_WALK] = IMAGEMANAGER->findImage("�β���move");
	_bodyImage[ENEMY_ATTACK] = IMAGEMANAGER->findImage("�β���attack");
	_bodyImage[ENEMY_DEAD] = IMAGEMANAGER->findImage("�β���dead");

	_bfx = IMAGEMANAGER->findImage("��������1 �ȼ�");

	_speed = 5.f;
	_angle = PI/4;
	_gravity = 0.f;
	_count = 0, _indexX = 0;
	_animationSpeed = 11.f;
	_isActived = true;
	_state = ENEMY_WALK;
	_type = PLANTFROG;
	_x = 3480.f;
	_y = 900.f;
	_isLeft = false;
	_gold = 1;
	_silver = 1;
	_bronze = 0;
	_moveCount = 0;
	isJump = false;
	isTongue = false;
}

void plantFrog::idle()
{
}

void plantFrog::spawn()
{
	_animationSpeed = 20.f;

	_attRc = RectMake(_x, _y + 18, 0, 9);

	isTongue = false;
	if (isJump)
	{
		_gravity += 0.2f;

	}

	_y += _gravity;


	
	if (_count % 800 < 400 && _gravity == 0)
	{
		_isLeft = true;
	}
	else if (_count % 800 <= 800 && _gravity == 0)
	{
		_isLeft = false;
	}

	if (_isLeft)
	{
		if (_indexX == _bodyImage[_state]->getMaxFrameX())
		{
			_state = ENEMY_WALK;
			_indexX = 0;
		}
		
	}
	else
	{
		if (_indexX == 0)
		{
			_state = ENEMY_WALK;
			_indexX = _bodyImage[_state]->getMaxFrameX();
		}

	}

	_collisionRc = RectMakeCenter(_x, _y + _bodyImage[ENEMY_WALK]->getFrameHeight() / 4, _bodyImage[ENEMY_WALK]->getFrameWidth() * 2 / 3, _bodyImage[ENEMY_WALK]->getFrameHeight() / 2);


}

void plantFrog::attack()
{

	if (_isLeft)
	{
		_attRc = RectMake(_x-60, _y + 18, 0, 9);
		_animationSpeed = 5.f;

		if (_indexX == 7)
		{
			_attRc.left -= 170;
			isTongue = true;

		}
		else
		{
			isTongue = false;

		}
	}
	else
	{
		_attRc = RectMake(_x+30, _y + 18, 0, 9);
		_animationSpeed = 5.f;

		if (_indexX == 1)
		{
			_attRc.right += 170;
			isTongue = true;

		}
		else
		{
			isTongue = false;

		}
	}



	if (isJump)
	{
		_gravity += 0.02f;
	}

	_y += _gravity;





	if (_isLeft)
	{
		if (_indexX == _bodyImage[_state]->getMaxFrameX())
		{
			_state = ENEMY_SPAWN;
			_indexX = 0;

		}
	}
	else
	{
		if (_indexX == 0)
		{
			_state = ENEMY_SPAWN;
			_indexX = _bodyImage[_state]->getMaxFrameX();

		}
	}

	_collisionRc = RectMakeCenter(_x, _y + _bodyImage[ENEMY_WALK]->getFrameHeight() / 4, _bodyImage[ENEMY_WALK]->getFrameWidth() * 2 / 3, _bodyImage[ENEMY_WALK]->getFrameHeight() / 2);


}

void plantFrog::move()
{
	_animationSpeed = 11.f;

	_attRc = RectMake(_x, _y + 18, 0, 9);

	isJump = true;

	isTongue = false;

	if (_count % 800 < 400 && _gravity == 0)
	{
		_isLeft = true;
	}
	else if (_count % 800 <= 800 && _gravity == 0)
	{
		_isLeft = false;
	}

	if (_isLeft)
	{
		if (_indexX == _bodyImage[_state]->getMaxFrameX())
		{
			_state = ENEMY_SPAWN;
			_indexX = 0;

		}
	}
	else
	{
		if (_indexX == 0)
		{
			_state = ENEMY_SPAWN;
			_indexX = _bodyImage[_state]->getMaxFrameX();

		}
	}

	_gravity = 0;
	_gravity += 0.02f;

	if (_isLeft)
	{
		_x -= cosf(_angle)*_speed;

		if (_indexX < 3)
		{
			_y += -sinf(_angle)*_speed + _gravity;
		}
		else
		{
			_y += sinf(_angle)*_speed + _gravity;
		}
	}
	else
	{
		_x += cosf(_angle)*_speed;

		if (_indexX > 3)
		{
			_y += -sinf(_angle)*_speed + _gravity;

		}
		else
		{
			_y += sinf(_angle)*_speed + _gravity;

		}
	}
	




	_collisionRc = RectMakeCenter(_x, _y,  _bodyImage[ENEMY_WALK]->getFrameWidth()*2/3, _bodyImage[ENEMY_WALK]->getFrameHeight()/2);

}

void plantFrog::dead()
{
}

void electriceel::init()
{
	_bodyImage[ENEMY_SPAWN] = IMAGEMANAGER->findImage("�����spawn");
	_bodyImage[ENEMY_WALK] = IMAGEMANAGER->findImage("�����move");
	//_bodyImage[ENEMY_FIRE] = IMAGEMANAGER->findImage("�β���attack");
	_bodyImage[ENEMY_DEAD] = IMAGEMANAGER->findImage("�����dead");

	_bfx = IMAGEMANAGER->findImage("��������1 �ȼ�");

	_speed = 3.f;
	_angle = PI / 2;
	_gravity = 0.f;
	_count = 0, _indexX = 0;
	_animationSpeed = 4.f;
	_isActived = true;
	_state = ENEMY_SPAWN;
	_type = ELECTRICEEL;
	_x = 3480.f;
	_y = 900.f;
	_isLeft = true;
	_gold = 0;
	_silver = 1;
	_bronze = 1;

	ang = true;
}

void electriceel::idle()
{
}

void electriceel::spawn()
{
	if (ang)
	{
		if (_isLeft)
		{
			if (_indexX >= _bodyImage[_state]->getMaxFrameX())
				_state = ENEMY_WALK;
		}
		else
		{
			if (_indexX <= 0)
				_state = ENEMY_WALK;
		}
	}
	//else
	//{
	//	if (_isLeft)
	//	{
	//		if (_indexX >= _bodyImage[_state]->getMaxFrameX())
	//			_state = ENEMY_WALK;
	//	}
	//	else
	//	{
	//		if (_indexX <= 0)
	//			_state = ENEMY_WALK;
	//	}
	//}


	_collisionRc = RectMakeCenter(_x, _y + 50, _bodyImage[_state]->getFrameWidth() * 2 / 3, _bodyImage[_state]->getFrameHeight() / 2);

}

void electriceel::attack()
{
}

void electriceel::move()
{

	if (_indexX >= 7 && _indexX <= 11)
	{
		_y -= 7;
	}
	else if (_indexX >= 21 && _indexX <= 25)
	{
		_y += 8.05f;

	}

	if (_indexX == 25)
	{
		_indexX = 0;
		_animationSpeed = 3.0f;
		_state = ENEMY_SPAWN;
	}



	_collisionRc = RectMakeCenter(_x, _y, _bodyImage[_state]->getFrameWidth() * 2 / 3, _bodyImage[_state]->getFrameHeight() / 2);
}

void electriceel::dead()
{
}


void ghost::init()
{
	//_bodyImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("����spawn");
	_bodyImage[ENEMY_SPAWN] = IMAGEMANAGER->findImage("����spawn");
	_bodyImage[ENEMY_WALK] = IMAGEMANAGER->findImage("����dead"); // ������ �𸣰����� dead������ �ȵǴµ� walk�� ���� ��!? ��򰡿��� dead�϶� �ȵǰ� �س�����?
	_bodyImage[ENEMY_ATTACK] = IMAGEMANAGER->findImage("����attack");
	//_bodyImage[ENEMY_DEAD] = IMAGEMANAGER->findImage("����dead");

	_bfx = IMAGEMANAGER->findImage("��������1 �ȼ�");

	_speed = 3.f;
	_angle = PI / 2;
	_gravity = 0.f;
	_count = 0, _indexX = 0, _indexY = 0;
	_animationSpeed = 3.f;
	_isActived = true;
	_state = ENEMY_SPAWN;
	_type = GHOST;
	_x = 0.f;
	_y = 0.f;
	_isLeft = true;
	isFire = false;
	_gold = 0;
	_silver = 0;
	_bronze = 0;
}

void ghost::idle()
{
}

void ghost::spawn()
{
	_animationSpeed = 20.f;

	if (_isLeft)
	{
		if (_indexX >= _bodyImage[_state]->getMaxFrameX())
		{
			_state = ENEMY_ATTACK;
		}
	}
	else
	{
		if (_indexX <= 0)
		{
			_state = ENEMY_ATTACK;

		}
	}
}

void ghost::attack()
{
	_animationSpeed = 20.f;
	
		if (_indexX == _bodyImage[_state]->getMaxFrameX())
		{
			isFire = true;
			
			//deadCount++;
			//if (deadCount == 28)
			//{
			//	_isActived = false;
			//}
		}
	
	

}

void ghost::move()
{
	_animationSpeed = 13.f;

}

void ghost::dead()
{

}


//����/�������������������������Һ�Һ꽺����//

void bee::init()
{
	//_bodyImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("����spawn");
	//_bodyImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("��idle");
	_bodyImage[ENEMY_WALK] = IMAGEMANAGER->findImage("��idle");   //���긦 ���̵��!!!
	_bodyImage[ENEMY_SPAWN] = IMAGEMANAGER->findImage("��dizzy"); // ������ ������!!
	_bodyImage[ENEMY_ATTACK] = IMAGEMANAGER->findImage("��attack");
	_bodyImage[ENEMY_IDLE] = IMAGEMANAGER->findImage("��hurt"); //���̵��� ��Ʈ��!!

	_bullet = new beeBullet;
	_bullet->init(500);
	//_bodyImage[ENEMY_DEAD] = IMAGEMANAGER->findImage("����dead");

	_isFire = false;
	_fireCount = 0;

	_bfx = IMAGEMANAGER->findImage("��������1 �ȼ�");

	_speed = 2.f;
	_angle = PI / 2;
	_gravity = 0.f;
	_count = 0, _indexX = 0, _indexY = 0;
	_animationSpeed = 10.f;
	_isActived = true;
	_state = ENEMY_WALK;
	_type = GHOST;
	_x = 800.f;
	_y = 200.f;
	_isLeft = true;
	isFire = false;
	_gold = 0;
	_silver = 0;
	_bronze = 0;
	dizzyCount = 0;
	hp = 7;
	attackStartCount = 0;
	attackCount = 0;
	_fireCount = 0;

}

void bee::idle()
{
	_animationSpeed = 30.f;
	if (_isLeft)
	{
		if (_indexX >= _bodyImage[_state]->getMaxFrameX())
		{
			_state = ENEMY_WALK;
			_indexX = 0;
			_y = 200;
		}
	}
	else
	{
		if (_indexX <= 0)
		{
			_state = ENEMY_WALK;
			_indexX = _bodyImage[_state]->getMaxFrameX();
			_y = 200;
		}
	}
}

void bee::spawn()
{
	if (_isLeft)
	{
		if (_indexX >= _bodyImage[_state]->getMaxFrameX())
		{
			_indexX = 0;
		}
	}
	else
	{
		if (_indexX <= 0)
		{
			_indexX = _bodyImage[_state]->getMaxFrameX();
		}
	}



}

void bee::attack()
{


	if (dizzyCount == 5)
	{
		_state = ENEMY_SPAWN;
		dizzyCount = 0;
		_bullet->release();
	}


}

void bee::move()
{

	if (_x >= 1000)
	{
		_isLeft = true;
		attackStartCount++;
	}
	else if (_x <= 450)
	{
		_isLeft = false;
	}

	if (_isLeft)
	{
		_x -= 10;
	}

	else if (!_isLeft)
	{
		_x += 10;

	}

	if (_isLeft)
	{
		if (_indexX >= _bodyImage[_state]->getMaxFrameX())
		{
			//_state = ENEMY_IDLE;
			_indexX = 0;
		}
	}
	else
	{
		if (_indexX <= 0)
		{
			_indexX = _bodyImage[_state]->getMaxFrameX();
	
		}
	}

	if (attackStartCount == 1)
	{
		_state = ENEMY_ATTACK;
		attackStartCount = 0;
	}



}

void bee::dead()
{
}





void enemy::update()
{
	_count++;


	if (_count % _animationSpeed == 0)
	{
		if (_isLeft)
		{
			_indexX++;
			if (_indexX > _bodyImage[_state]->getMaxFrameX())
			{
				_indexX = 0;
			}
		}
		else
		{
			_indexX--;
			if (_indexX <0)
			{
				_indexX = _bodyImage[_state]->getMaxFrameX();
				
			}
		}

		_bodyImage[_state]->setFrameX(_indexX);

	}

	if (_isLeft)
	{
		_indexY = 0;
	}
	else
	{
		_indexY = 1;
	}

	_bodyImage[_state]->setFrameY(_indexY);

	this->pixelCollision();

	switch (_state)
	{
	case ENEMY_IDLE:
		idle();
		break;
	case ENEMY_SPAWN:
		spawn();
		break;
	case ENEMY_WALK:
		move();
		break;
	case ENEMY_ATTACK:
		attack();
		break;
	case ENEMY_DEAD:
		dead();
		break;
	default:
		//������ ��?
		break;
	}


	_rc = RectMakeCenter(_x, _y, _bodyImage[_state]->getFrameWidth(), _bodyImage[_state]->getFrameHeight());

	if (_isLeft)
	{
		_sensorRc = RectMake(_x - _bodyImage[ENEMY_WALK]->getFrameWidth() * 2, _y - _bodyImage[ENEMY_WALK]->getFrameHeight() / 2, _bodyImage[ENEMY_WALK]->getFrameWidth() * 2, _bodyImage[ENEMY_WALK]->getFrameHeight());

	}
	else
	{
		_sensorRc = RectMake(_x, _y - _bodyImage[ENEMY_WALK]->getFrameHeight() / 2, _bodyImage[ENEMY_WALK]->getFrameWidth() * 2, _bodyImage[ENEMY_WALK]->getFrameHeight());

	}
}

void enemy::pixelCollision()
{
	for (int j = _rc.bottom - 4; j < _rc.bottom; j += 2)
	{
		COLORREF color = GetPixel(_bfx->getMemDC(), _x, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255))
		{
			_y = j - _bodyImage[_state]->getFrameHeight() / 2;
			_gravity = 0;
			isJump = false;

			break;
		}
	}
}
