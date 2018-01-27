#pragma once
#include <Siv3D.hpp>
#include <algorithm>
#include "Block.h"
#include "PlayerLib.h"
#include "Field.h"
#include "BlockTemplate.h"

class BlockManager
{
public:
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	BlockManager();

	///<summary>
	/// �f�X�g���N�^
	///</summary>
	~BlockManager();

public:
	///<summary>
	/// �u���b�N�𐶐����A�Ǘ�����
	///</summary>
	///<param name="p">�ǂ̃t�B�[���h�Ƀu���b�N�𐶐����邩</param>
	///<param name="height">�u���b�N�𐶐����鍂��[zk]</param>
	///<param name="block">��������u���b�N���</param>
	///<param name="field">�t�B�[���h���</param>
	void CreateBlock(PlayerType p, int height, Block block, const Field & field);

	///<summary>
	/// �Ǘ����Ă���u���b�N�̏����X�V����
	///</summary>
	///<returns>�Q�[���I����Ԃ�</returns>
	bool Update(Field & field, Player * players, Level level);

	///<summary>
	/// �Ǘ����Ă���u���b�N��`�悷��
	///</summary>
	void DrawBlocks() const;

	/// <summary>
	/// �ʏ�u���b�N�̃X�s�[�h
	/// </summary>
	/// <param name="speed">�ݒ肷��X�s�[�h</param>
	void SetBlocksSpeed(int speed);

private:
	///<summary>
	/// �v���C���[���Ƃ̃u���b�N
	///</summary>
	std::map<PlayerType, Array<Block>> m_blocks;

	Stopwatch m_block_sw{ true };
	std::map<PlayerType, Stopwatch> m_bb_sw;

	int m_blocks_speed = 1;
};

