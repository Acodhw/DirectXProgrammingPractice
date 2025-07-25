#include "PEApplication.h"
#include "PEInput.h"
#include "PETime.h"

#define MAX_LOADSTRING 100

namespace PracticeEngine {

	Application::Application()
		: mHwmd(nullptr)
		, mHdc(nullptr)
	{
		title = new wchar_t[MAX_LOADSTRING];		
	}
	
	Application::~Application() {
		delete[] title;
	}
	void Application::Initialize(HWND hwmd) {
		mHwmd = hwmd;
		mHdc = GetDC(mHwmd);
		GetWindowText(mHwmd, title, MAX_LOADSTRING);

		mPlayer.SetPosition(0, 0);
		Input::Initailze();
		Time::Initailze();
	}

	void Application::Run() {
		Update();
		LateUpdate();
		Render();
		InfoTitle();
	}

	void Application::Update() {
		Time::Update(); // �ð� ó���� �� �տ���
		Input::Update(); // Ű ó���� �÷��̾� ó������ ������
		mPlayer.Update();
	}
	
	void Application::LateUpdate() {
		mPlayer.LateUpdate();
	}

	void Application::Render() {
		
		mPlayer.Render(mHdc);
	}

	void Application::InfoTitle() {
		float fps = 1.0f / Time::DeltaTime;	

		wchar_t str[MAX_LOADSTRING] = L"";
		swprintf(str, MAX_LOADSTRING, L"%ws \tFPS : %d", title, (int)fps);
		int len = wcsnlen_s(str, MAX_LOADSTRING);

		SetWindowText(mHwmd, str);
	}
}