#pragma once

class SkinModelRender : public GameObject
{
public:
	SkinModelRender();
	~SkinModelRender();

	bool Start() override ;
	void Update() override ;
	void Render() override ;
	
	void Init(const wchar_t* filePath,
		AnimationClip* animationClips = nullptr,
		int numAnimationClips = 0,
		EnFbxUpAxis = enFbxUpAxisZ, const char* psmain = "PSMain", const char* vsmain = "VSMain");
		
	void InitAnimation(AnimationClip* animationClips, int numAnimationClips);

	void PlayAnimation(int animNo, float interpolateTime = 0.0f)
	{
		m_animation.Play(animNo, interpolateTime);
	}
	
	/*!
	* @brief	�A�j���[�V�����̍Đ����H
	*/


	bool IsPlayingAnimation() const
	{
		return m_animation.IsPlaying();
	}
	
	/*!
		*@brief	���W��ݒ�B
		*/
	void SetPosition(const CVector3& position)
	{
		m_pos = position;
	}
	/*!
	*@brief	��]��ݒ�B
	*/
	void SetRotation(const CQuaternion& rotation)
	{
		m_rot = rotation;
	}
	/*!
	*@brief	�g�嗦��ݒ�B
	*/
	void SetScale(const CVector3& scale)
	{
		m_scale = scale;
	}
	//SetFbxUp
	void SetFbxUpAxis(EnFbxUpAxis enFbxUpAxis) {
		m_enFbxUpAxis = enFbxUpAxis;
	}
	/*!
		*@brief	�X�L�����f���擾�B
		*/
	SkinModel& GetSkinModel()
	{
		return m_skinModel;
	}
	const SkinModel& GetSkinModel() const
	{
		return m_skinModel;
	}
	void SetUpdateAnimationFlag(bool flag)
	{
		m_isUpdateAnimation = flag;
	}

	CVector3 GetPosition() {
		return m_pos;
	}
private:
	SkinModel m_skinModel;
	EnFbxUpAxis m_enFbxUpAxis;
	const char* m_psmain;
	const char* m_vsmain;
	Animation m_animation;
	AnimationClip* m_animationClips = nullptr;
	int m_numAnimationClips = 0;
	CVector3 m_pos;
	CQuaternion m_rot = CQuaternion::Identity();
	CVector3 m_scale = CVector3::One();
	CVector4 m_dirCol = { 1.f,1.f,1.f,1.f };
	CVector4 m_dirLight = { 0.707,-0.707,0.0f,0.0f };
	const CVector4 m_defCol = { 1.f,1.f,1.f,1.f };
	const CVector4 m_defDir = { 0.707,-0.707,0.0f,0.0f };
	bool m_isUpdateAnimation = true;
};


