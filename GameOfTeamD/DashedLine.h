#pragma once
#include <Siv3D.hpp>

class DashedLine
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="start">�n�_</param>
	/// <param name="end">�I�_</param>
	/// <param name="count">�j���̉�</param>
	/// <param name="origin">���������n�߂�ꏊ</param>
	DashedLine(Point start, Point end, int count, Point origin);
	~DashedLine();

	void Draw(Color color) const;

private:
	Point m_start, m_end, m_origin;
	int m_count;
};

