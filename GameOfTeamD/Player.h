#pragma once
#include "Character.h"
#include "Action.h"
#include "Field.h"

class Player :
	public Character<Circle>
{
public:
	Player(Players p, Point pos);
	virtual ~Player();

public:
	///<summary>
	///�v���C���[�̏ꏊ
	///</summary>
	Point Pos();

	void SetPos(Point pos);

	void Move(Action action, const Field & field);

	///<summary>
	///�v���C���[�̓��_
	///</summary>
	int Score();

private:
	int m_score;
	Players m_players;
};

