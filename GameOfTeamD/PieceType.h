#pragma once
#include <Siv3D.hpp>

///<summary>
/// �s�[�X�̐F�܂��͎��
///</summary>
enum class PieceType
{
	None, Red, Blue, Yellow, Green, Purple, Black
};

namespace Piece
{
	///<summary>
	/// �s�[�X�̎�ނ���F�ɕϊ�����
	///</summary>
	///<param name="p">���ɂȂ�s�[�X�̎��</param>
	Color ColorParse(PieceType p);
}