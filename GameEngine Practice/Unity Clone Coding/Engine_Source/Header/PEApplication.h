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

	private:
		HWND mHwmd; // �ɹ� ���� �ڵ�
		HDC mHdc; // hdc ������

		// �÷��̾�
		GameObject mPlayer; // ���ӿ�����Ʈ ����
	};
}

