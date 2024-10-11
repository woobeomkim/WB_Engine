#pragma once
#include "CommonInclude.h"

namespace wb
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode
	{
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode KeyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();
		
		static bool GetKeyDown(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Up; }
		static bool GetKey(eKeyCode key) { return mKeys[(UINT)key].state == eKeyState::Pressed; }

	private:
		
	private:
		static std::vector<Key> mKeys;
	};
}
