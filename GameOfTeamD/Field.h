#pragma once

#include <Siv3D.hpp>
#include "PlayerLib.h"

class Field
{
public:
	Field(Size size, int32 field_height = 8, int32 puzzle_width = 10, int32 player_width = 3, int32 zk_size = 25);
	Field(const Field& other);
	void operator=(const Field& other);
	~Field();

public:
	void Draw() const;

	int32 Height() const;
	int32 Width() const;
	int32 PuzzleWidth() const;
	int32 PlayerWidth() const;
	int32 Zk() const;

	bool IsInPuzzleField(Players p, Point pos) const;
	bool IsInPlayerField(Players p, Point pos) const;
	bool IsInOtherField(Players p, Point pos) const;

private:
	/// <summary>
	/// �E�B���h�E�̃T�C�Y
	/// </summary>
	Size m_window_size;

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

	/// <summary>
	/// 1[zk]������̑傫��
	/// </summary>
	int32 m_zk;

	Grid<Rect> m_p1_puzzles;
	Grid<Rect> m_p2_puzzles;
};

