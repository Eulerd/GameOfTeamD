#pragma once
#include "Character.h"
#include "Action.h"
#include "Field.h"

class Player :
	public Character<Circle>
{
public:
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	///<param name="p">�ԍ�</param>
	///<param name="pos">�������W</param>
	Player(PlayerType p, Point pos);

	///<summary>
	/// �f�X�g���N�^
	///</summary>
	virtual ~Player();

public:
	///<summary>
	///�v���C���[�̏ꏊ���擾����
	///</summary>
	Point Pos();

	///<summary>
	/// �v���C���[�̏ꏊ��ݒ肷��
	///</summary>
	void SetPos(Point pos);

	///<summary>
	/// �v���C���[�𓮂���
	///</summary>
	///<param name="action">���삳����s���̌���</param>
	///<param name="field">�v���C���[�̂���t�B�[���h</param>
	void Move(Action action, const Field & field);

	///<summary>
	///�v���C���[�̓��_
	///</summary>
	int Score();

	///<summary>
	/// �v���C���[�ԍ����擾����
	///</summary>
	PlayerType GetPlayerType();

private:
	///<summary>
	/// �X�R�A�̃f�[�^
	///</summary>
	int m_score;

	///<summary>
	/// �ԍ��̃f�[�^
	///</summary>
	PlayerType m_player_type;
};

