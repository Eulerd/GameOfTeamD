﻿#include "Player.h"



Player::Player(PlayerType p, Point pos)
{
	this->Shape.setPos(pos);
	m_player_type = p;
	m_score = 0;
}


Player::~Player()
{ }

Point Player::Pos()
{
	return Point(this->Shape.x, this->Shape.y);
}

void Player::SetPos(Point pos)
{
	this->Shape.setPos(pos);
}

void Player::Move(Action action, const Field & field)
{
	Vec2 v = Vec2::Zero;

	switch (action)
	{
	case Action::Up:
		v = { 0, -Speed() };
		break;
	case Action::Right:
		v = { Speed(), 0 };
		break;
	case Action::Down:
		v = { 0, Speed() };
		break;
	case Action::Left:
		v = { -Speed(), 0 };
		break;
	}
	
	if (field.IsInPlayerField(m_player_type, this->Shape.movedBy(v)))
	{
		this->Shape.moveBy(v);
	}
}

int Player::Score()
{
	return m_score;
}

void Player::AddScore()
{
	m_score++;
}

PlayerType Player::GetPlayerType()
{
	return m_player_type;
}

void Player::SetWinner()
{
	m_is_winner = true;
}

bool Player::IsWinner()
{
	return m_is_winner;
}
