#pragma once
#include <map>

class Skeleton;
/*!
*@brief	�X�L�����f���f�[�^�}�l�[�W���[�B�B
*@Flyweight�p�^�[����FlyweightFactory�N���X�A�B
*/
class SkinModelDataManager
{
public:
	/*!
	*@brief	���f�������[�h�B
	*@param[in]	filePath	�t�@�C���p�X�B
	*@param[in]	skeleton	�X�P���g���B
	*/
	DirectX::Model* Load(const wchar_t* filePath, const Skeleton& sketon, const char*,const char*);
	/*!
	*@brief	���f���f�[�^��S�J���B
	*/
	void Release();
private:
	std::map<
		std::wstring,					
		std::unique_ptr<DirectX::Model>	
	> m_directXModelMap;
};

extern SkinModelDataManager g_skinModelDataManager;

