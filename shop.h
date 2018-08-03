#pragma once
#include "gameNode.h"

struct tagShopBox
{
	float _x, _y;
	RECT _rc;
	image * _img;
	int _count;
	int _index;
};

class shop : public gameNode
{
private:

	tagShopBox _backImage;
	tagShopBox _Item[3];
	tagShopBox _selectOj;
	bool _kindShop;
	bool _isSelect;
	int _selectCount;
	int _selectNumber;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render();

	void ItemList();
	void frameImageMove();
	void selectObjectInIt();
	void selectObject();
	shop() {}
	~shop() {}
};

