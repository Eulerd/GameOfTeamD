#pragma once
#include "Character.h"
#include "Action.h"
#include "Field.h"

class Player :
	public Character<Circle>
{
public:
	Player(PlayerType p, Point pos);
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

	PlayerType GetPlayerType();

private:
	int m_score;
	PlayerType m_player_type;
};

