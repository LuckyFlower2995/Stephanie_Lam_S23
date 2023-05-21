#pragma once

#include "CheckMateUtil.h"
#include "Image.h"
#include "RendererTypes.h"

namespace CheckMate {
	class CHECKMATE_API Unit {
	public:
		Unit(const std::string& image, ScreenCoord coords);
		Unit(std::string&& image, ScreenCoord coords);

		int GetWidth() const;
		int GetHeight() const;

		ScreenCoord GetCoords() const;
		void SetCoords(ScreenCoord newCoords);
		void UpdateXCoord(int amount);
		void UpdateYCoord(int amount);
	private:
		Image mImage;
		ScreenCoord mPosition;

		friend class Renderer;
		friend CHECKMATE_API bool UnitsOverlap(const Unit& a, const Unit& b);
	};

	CHECKMATE_API bool UnitsOverlap(const Unit& a, const Unit& b);

}