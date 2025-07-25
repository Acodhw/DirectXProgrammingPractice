#include "PEGameObject.h"

namespace PracticeEngine
{
	GameObject::GameObject() : mx(0), my(0)
	{

	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update() {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			mx -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			mx += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			my -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			my += 0.01f;
		}
	}

	void GameObject::LateUpdate() {

	}

	void GameObject::Render(HDC hdc) {
		HBRUSH br = CreateSolidBrush(RGB(255, 0, 255)); // �귯�� ����(� �귯���� �׸��� �׷�����)
		HBRUSH oldbr = (HBRUSH)SelectObject(hdc, br); // hdc���� �귯�� ���� ���� ������(������) �귯�� ����


		Rectangle(hdc, 100 + mx, 100 + my, 200 + mx, 200 + my); // �簢�� �׸��� �Լ�

		(HBRUSH)SelectObject(hdc, oldbr); // ������ �귯���� ��������
		DeleteObject(br); // ������ �귯���� ����

		// DC = ȭ�� ��¿� �ʿ��� ��� �����͸� ������ ����ü
		// GDI ��⿡ ���� ����
	}

}
