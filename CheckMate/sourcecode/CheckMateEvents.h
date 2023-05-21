#pragma once

#include "CheckMateUtil.h"


namespace CheckMate {
	class CHECKMATE_API KeyPressed {
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class CHECKMATE_API KeyReleased {
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class CHECKMATE_API WindowClosed {
		
	};
}