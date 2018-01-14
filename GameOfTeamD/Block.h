#pragma once

#include <Siv3D.hpp>
#include "Player.h"
#include "Action.h"
#include "PieceType.h"

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

	///<summary>
	/// �u���b�N�̈�ӂ̒����̍ő�l
	///</summary>
	static int MaxLength();

public:
	///<summary>
	/// �u���b�N�̐F���擾����
	///</summary>
	Grid<Color> GetColor() const;

	///<summary>
	/// �u���b�N�̊e�s�[�X���擾����
	///</summary>
	Array<Rect> GetPieces(int32 zk) const;

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
	void SetPos(const Point &pos);

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
	/// zk���w�肵�ău���b�N��`�悷��
	///</summary>
	///<param name="zk">��}�X������̑傫��</param>
	///<param name="origin">�p�Y���t�B�[���h�̌��_</param>
	void Draw(Point origin, int32 zk) const;

private:
	///<summary>
	/// �u���b�N�̈�ӂ̍ő�l
	///</summary>
	static const int length = 2;

	///<summary>
	/// �u���b�N�̐F�f�[�^
	///</summary>
	Grid<PieceType> m_pieces{ length, length };

	///<summary>
	/// �u���b�N�̍���̍��W
	///</summary>
	Point m_pos;
};
