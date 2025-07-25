#pragma once
#include "CommonInclude.h"

namespace PracticeEngine
{
	//Actor : ���� �� ���� ������Ʈ�� ������ ��� Ŭ����
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mx = x;
			my = y;
		}

		float GetPositionX() { return mx; }
		float GetPositionY() { return my; }
		
	private:
		// ���� ������Ʈ�� ��ǥ
		float mx;
		float my;
	};
}