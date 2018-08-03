#pragma once
#include "gameNode.h"

struct tagShopBox
{
	float _x, _y;
	RECT _rc;
	image * _img;
	int _count;
	int _index;
	int price;
};


class shop : public gameNode
{
private:

	tagShopBox _backImage;
	tagShopBox _Item[3];
	tagShopBox _ItemInfo[3];
	tagShopBox _selectOj;
	tagShopBox _priceNum[4];
	int num[4];
	bool _kindShop;
	bool _isSelect;
	int _selectCount;
	int _selectNumber;
	float _x, _y;
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

