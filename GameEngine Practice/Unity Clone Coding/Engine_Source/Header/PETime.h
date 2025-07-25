#pragma once
#include "CommonInclude.h"

namespace PracticeEngine {

	class Time
	{
	public:
		static void Initailze();
		static void Update();

		static const float& DeltaTime;

	private:
		static LARGE_INTEGER cpuFrequency; //cpu ���������� 
		static LARGE_INTEGER prevFrequency; //������ ������ üũ�ϱ� ���� ������
		static LARGE_INTEGER currentFrequency; // ���α׷� ���۽� ���� ������
		static float deltaTime; // ���� �ð� ��ȭ��
	};
}

