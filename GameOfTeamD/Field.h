#pragma once

#include <Siv3D.hpp>
#include <map>
#include "Block.h"
#include "PlayerLib.h"
#include "Action.h"
#include "PieceType.h"

class Block;

class Field
{
public:
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	///<param name="field_heigt">�t�B�[���h�̍���[zk]</param>
	///<param name="puzzle_width">�p�Y���t�B�[���h�̕�[zk]</param>
	///<param name="player_width">�v���C���[�t�B�[���h�̕�[zk]</param>
	///<param name="is_mirrors">�e�v���C���[�̃t�B�[���h�𔽓]���邩</param>
	Field(int32 field_height = 8, int32 puzzle_width = 10, int32 player_width = 3,
		std::map<PlayerType, bool> is_mirrors = { {PlayerType::One, false}, {PlayerType::Two, true } });

	///<summary>
	/// �R���X�g���N�^
	///</summary>
	Field(const Field& other);
	void operator=(const Field& other);

	///<summary>
	/// �f�X�g���N�^
	///</summary>
	~Field();

public:
	std::map<PlayerType, Array<std::pair<Block, int>>> BlackBlocks;

public:
	///<summary>
	/// �t�B�[���h��`�悷��
	///</summary>
	void Draw() const;

	///<summary>
	/// �t�B�[���h�̏�Ԃ��X�V����
	///</summary>
	void Update();

	///<summary>
	/// �t�B�[���h�Ƀu���b�N��ǉ�����
	///</summary>
	void SetBlock(PlayerType p, Block block);

	///<summary>
	/// �t�B�[���h�̍������擾����
	///</summary>
	int32 Height() const;

	int32 HeightCount() const;

	///<summary>
	/// �p�Y���t�B�[���h�ƃv���C���[�t�B�[���h�̕������킹���傫�����擾����
	///</summary>
	int32 Width() const;

	///<summary>
	/// �p�Y���t�B�[���h�̕����擾����
	///</summary>
	int32 PuzzleWidth() const;

	///<summary>
	/// �v���C���[�t�B�[���h�̕����擾����
	///</summary>
	int32 PlayerWidth() const;

	///<summary>
	/// �u���b�N���ړ�����t�B�[���h�̕����擾����
	///</summary>
	int32 SpaceWidth() const;

	///<summary>
	/// �p�Y���t�B�[���h�̍���̍��W
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Point PuzzleOrigin(PlayerType p) const;
	///<summary>
	/// �v���C���[�t�B�[���h�̍���̍��W
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Point PlayerOrigin(PlayerType p) const;
	///<summary>
	/// �u���b�N���ړ�����t�B�[���h�̍���̍��W
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Point SpaceOrigin(PlayerType p) const;

	///<summary>
	/// �p�Y���t�B�[���h�̉E���̍��W
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Point PuzzleEndPos(PlayerType p) const;
	///<summary>
	/// �v���C���[�t�B�[���h�̉E���̍��W
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Point PlayerEndPos(PlayerType p) const;
	///<summary>
	/// �u���b�N���ړ�����t�B�[���h�̉E���̍��W
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Point SpaceEndPos(PlayerType p) const;

	///<summary>
	/// �t�B�[���h�̃X�R�A�{�[�h�Ƃ̋��E�ł��鍶���̍��W
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Point LeftBorder(PlayerType p) const;

	///<summary>
	/// �t�B�[���h�̃X�R�A�{�[�h�Ƃ̋��E�ł���E���̍��W
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Point RightBorder(PlayerType p) const;

	///<summary>
	/// �v���C���[�t�B�[���h��Space�t�B�[���h�̋��E�̏�̍��W
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Point PlayerTopBorder(PlayerType p) const;

	///<summary>
	/// �v���C���[�t�B�[���h�̒��_
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Point PlayerCenter(PlayerType p) const;

	///<summary>
	/// �u���b�N���ړ�����t�B�[���h�̒[�A����̍��W
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Point BlockStartPos(PlayerType p) const;

	///<summary>
	/// �t�B�[���h�𔽓]���邩�ݒ肷��
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	///<param name="is_mirror">���]���邩</param>
	void SetMirror(PlayerType p, bool is_mirror);

	///<summary>
	/// �v���C���[�̃t�B�[���h�����]���Ă��邩�擾����
	///</summary>
	bool GetMirror(PlayerType p) const;

	///<summary>
	/// �u���b�N���i�ނׂ��������擾����
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	Action FieldDirection(PlayerType p) const;

	///<summary>
	/// �p�Y���t�B�[���h����pos�����邩
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	///<param name="pos>���肷����W</param>
	bool IsInPuzzleField(PlayerType p, Point pos) const;

	///<summary>
	/// �v���C���[�t�B�[���h����pos�����邩
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	///<param name="pos>���肷����W</param>
	bool IsInPlayerField(PlayerType p, Point pos) const;

	///<summary>
	/// �u���b�N���ړ�����t�B�[���h����pos�����邩
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	///<param name="pos>���肷����W</param>
	bool IsInSpaceField(PlayerType p, Point pos) const;

	///<summary>
	/// �t�B�[���h����pos�����邩
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	///<param name="pos>���肷����W</param>
	bool IsInField(PlayerType p, Point pos) const;

	///<summary>
	/// �p�Y���t�B�[���h����shape�����邩
	///</summary>
	///<param name="p">�ǂ̃v���C���[������t�B�[���h��</param>
	///<param name="pos>���肷��}�`</param>
	template <class Type>
		bool IsInPlayerField(PlayerType p, Type shape) const;

	///<summary>
	/// �u���b�N���ړ�����̈�ɂ��̐}�`�����邩���肷��
	///</summary>
	template<class Type>
		bool IsInBlockField(PlayerType p, Type shape) const;

private:
	///<summary>
	/// ��ʂ̑傫���̃f�[�^
	///</summary>
	Point m_window = Window::Size();

	/// <summary>
	/// �v���C���[��l���̃t�B�[���h�̍���[zk]
	/// </summary>
	int32 m_field_height;

	/// <summary>
	/// �v���C���[��l���̃p�Y���t�B�[���h�̕�[zk]
	/// </summary>
	int32 m_puzzle_width;

	/// <summary>
	/// �v���C���[��l���̃v���C���[�t�B�[���h�̕�[zk]
	/// </summary>
	int32 m_player_width;

	///<summary>
	/// �v���C���[�̃p�Y���}�`
	///</summary>
	std::map<PlayerType, Grid<Rect>> m_puzzles;

	///<summary>
	/// �v���C���[�̃p�Y���F
	///</summary>
	std::map<PlayerType, Grid<PieceType>> m_colors;

	///<summary>
	/// �e�v���C���[�̃t�B�[���h�����]���Ă��邩�Ǘ�����
	///</summary>
	std::map<PlayerType, bool> m_is_mirror;

	EventTimer m_event_timer[2];

private:
		///<summary>
		/// pos����q�����Ă��铯���F�̃s�[�X�����擾����
		///</summary>
		Array<Point> connectedPieceCount(PlayerType p, Point pos);

		///<summary>
		/// 4�ȏ�Ȃ����Ă���s�[�X�𔻒肵�A����
		///</summary>
		void clearPieces();

		void updateFieldState();

		void createBlackBlock(PlayerType p, Array<Point> points);
};

template<class Type>
bool Field::IsInPlayerField(PlayerType p, Type shape) const
{
	return Rect(PlayerOrigin(p), Size(PlayerWidth(), Height())).contains(shape);
}

template<class Type>
bool Field::IsInBlockField(PlayerType p, Type shape) const
{
	Point origin;
	if (m_is_mirror.at(p))
	{
		origin = SpaceOrigin(p);
	}
	else
	{
		origin = PlayerOrigin(p);
	}

	return Rect(origin, Size(PlayerWidth() + SpaceWidth(), Height())).contains(shape);
}
