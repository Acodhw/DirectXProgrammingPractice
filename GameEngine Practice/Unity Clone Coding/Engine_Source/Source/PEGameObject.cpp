#include "PEGameObject.h"
#include "PEInput.h"
#include "PETime.h"

namespace PracticeEngine
{
	GameObject::GameObject() : mx(0), my(0)
	{

	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update() {
		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left)) {
			mx -= speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right)) {
			mx += speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up)) {
			my -= speed * Time::DeltaTime;
		}
		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down)) {
			my += speed * Time::DeltaTime;
		} // Ű ó��
	}

	void GameObject::LateUpdate() {

	}

	void GameObject::Render(HDC hdc) { // ���� ������Ʈ�� �Ҵ�� �������� ó��
		HBRUSH br = CreateSolidBrush(RGB(255, 0, 255)); // �귯�� ����(� �귯���� �׸��� �׷�����)
		HBRUSH oldbr = (HBRUSH)SelectObject(hdc, br); // hdc���� �귯�� ���� ���� ������(������) �귯�� ����


		Rectangle(hdc, 100 + mx, 100 + my, 200 + mx, 200 + my); // �簢�� �׸��� �Լ�

		(HBRUSH)SelectObject(hdc, oldbr); // ������ �귯���� ��������
		DeleteObject(br); // ������ �귯���� ����

		// DC = ȭ�� ��¿� �ʿ��� ��� �����͸� ������ ����ü
		// GDI ��⿡ ���� ����
	}

}
