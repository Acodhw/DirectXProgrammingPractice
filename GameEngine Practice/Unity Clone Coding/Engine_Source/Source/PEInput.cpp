#include "PEInput.h"

namespace PracticeEngine
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initailze()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::Update() {
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++) {
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) {
				if (mKeys[i].bPressed) mKeys[i].state = eKeyState::Pressed; // ������ �����־��� = ���� ����
				else mKeys[i].state = eKeyState::Down; // ������ �ȴ����־��� = ������ �ִ� ��
				mKeys[i].bPressed = true;
			}
			else {
				if (mKeys[i].bPressed) mKeys[i].state = eKeyState::Up; // ������ ���� �־��� = Ű�� ���� ����
				else mKeys[i].state = eKeyState::None; // ������ �ȴ����־��� = �ȴ����� ����
				mKeys[i].bPressed = false;
			}
		}
	}
}