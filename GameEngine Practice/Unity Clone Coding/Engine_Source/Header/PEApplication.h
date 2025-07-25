#pragma once
#include "CommonInclude.h"
#include "PEGameObject.h"

namespace PracticeEngine {
	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND hwmd);
		void Run();

		void Update();
		void LateUpdate();

		void Render();
		void InfoTitle(); // Ÿ��Ʋ�� ���� ǥ��

	private:
		HWND mHwmd; // �ɹ� ���� �ڵ�
		HDC mHdc; // hdc ������

		// �÷��̾�
		GameObject mPlayer; // ���ӿ�����Ʈ ����
		wchar_t * title; // Ÿ��Ʋ ����
	};
}

