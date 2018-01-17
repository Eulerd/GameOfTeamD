#pragma once

#include <Siv3D.hpp>
#include "Player.h"
#include "Action.h"
#include "PieceType.h"
#include "GameLib.h"

class Block
{
public:
	///<summary>
	/// �f�t�H���g�R���X�g���N�^
	///</summary>
	Block();

	///<summary>
	/// �s�[�X�����Ƀu���b�N���쐬����
	///</summary>
	///<param name="pieces">Length*Length�̓񎟌��z��̃s�[�X</param>
	Block(Grid<PieceType> pieces);

	///<summary>
	/// �f�X�g���N�^
	///</summary>
	~Block();

public:
	///<summary>
	/// �u���b�N�̐F���擾����
	///</summary>
	Grid<Color> GetColor() const;

	///<summary>
	/// �u���b�N�̊e�s�[�X���擾����
	///</summary>
	Array<Rect> GetAllPieces() const;

	Array<PieceType> GetPieces(int heigt) const;

	///<summary>
	/// �u���b�N���E��90�x��]����
	///</summary>
	void TurnRight();

	///<summary>
	/// �u���b�N������90�x��]����
	///</summary>
	void TurnLeft();

	///<summary>
	/// �u���b�N�̍���̍��W��ݒ肷��
	///</summary>
	void SetPos(int height, const Point &pos);

	///<summary>
	/// �t�B�[���h���̃u���b�N�̂��鍂�����擾����
	///</summary>
	int GetHeight();

	Size GetSize();

	///<summary>
	/// �u���b�N�̍����̍��W���擾����
	///</summary>
	Point GetBottomLeft();

	///<summary>
	/// �u���b�N���t�B�[���h�ɉ����ē�����
	///</summary>
	///<param name="p">����������[Action::Left, Action::Right]�̂�</param>
	void Move(Action action);

	///<summary>
	/// �u���b�N��`�悷��
	///</summary>
	///<param name="origin">�p�Y���t�B�[���h�̌��_</param>
	void Draw(Point origin) const;

	template <class Shape>
	bool Intersects(const Shape& shape) const;

	template <class Shape>
	bool Contains(const Shape& shape) const;

private:
	///<summary>
	/// �u���b�N�̐F�f�[�^
	///</summary>
	Grid<PieceType> m_pieces;

	///<summary>
	/// �u���b�N�̍���̍��W
	///</summary>
	Point m_pos;

	int m_height;
	Size m_size;
};

template<class Shape>
inline bool Block::Intersects(const Shape & shape) const
{
	for (auto piece : GetAllPieces())
	{
		if (piece.intersects(shape))
		{
			return true;
		}
	}

	return false;
}

template<class Shape>
inline bool Block::Contains(const Shape & shape) const
{
	for (auto piece : GetAllPieces())
	{
		if (piece.contains(shape))
		{
			return true;
		}
	}

	return false;
}
