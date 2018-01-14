#pragma once

#include <Siv3D.hpp>

template <class Type>
class Character
{
public:
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	///<param name="speed">�L�����N�^�̓�������</param>
	Character(double speed = 2.0);

	///<summary>
	/// �f�X�g���N�^
	///</summary>
	virtual ~Character();

public:
	///<summary>
	/// �X�s�[�h���擾����
	///</summary>
	double Speed();

public:
	///<summary>
	/// �L�����N�^�̐}�`���擾����
	///</summary>
	Type Shape;

private:
	///<summary>
	/// �����̃f�[�^
	///</summary>
	double m_speed;
};

template<class Type>
Character<Type>::Character(double speed)
{
	Shape = Type();
	m_speed = speed;
}

template<class Type>
Character<Type>::~Character()
{}

template<class Type>
inline double Character<Type>::Speed()
{
	return m_speed;
}
