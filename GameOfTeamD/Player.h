#pragma once
#include "Character.h"
class Player :
	public Character<Circle>
{
public:
	Player(Point pos);
	virtual ~Player();

public:
	///<summary>
	///�v���C���[�̏ꏊ
	///</summary>
	Point Pos();

	///<summary>
	///�v���C���[�̓��_
	///</summary>
	int Score();

private:
	int m_score;
};

