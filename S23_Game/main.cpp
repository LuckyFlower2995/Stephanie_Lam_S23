#include <iostream>
#include "CheckMate.h"
#include <functional>

class S23_Game_App : public CheckMate::CheckMateApp {
public:
	S23_Game_App() {
		SetKeyPressedCallback([this](const CheckMate::KeyPressed& e) {MyKeyPressedFunc(e); });
	}

	virtual void OnUpdate() override {
		renderer.Clear();
		
		renderer.Draw(back, { 0,0 });

		renderer.Draw(wall4);
		renderer.Draw(wall5);
		renderer.Draw(wall1);
		renderer.Draw(wall2);
		renderer.Draw(wall3);
		renderer.Draw(wall6);
		renderer.Draw(wall9);
		renderer.Draw(wall11);
		renderer.Draw(wall7);
		renderer.Draw(wall8);
		
		renderer.Draw(barrier1);
		renderer.Draw(barrier2);
		renderer.Draw(barrier3);
		renderer.Draw(barrier4);

		renderer.Draw(wall10);

		renderer.Draw(unit);
	}

	void MyKeyPressedFunc(const CheckMate::KeyPressed& e) {
		if (e.GetKeyCode() == CHECKMATE_KEY_RIGHT) {
			unit.UpdateXCoord(10);
		}
		else if (e.GetKeyCode() == CHECKMATE_KEY_LEFT) {
			unit.UpdateXCoord(-10);
		}
		else if (e.GetKeyCode() == CHECKMATE_KEY_UP) {
			unit.UpdateYCoord(10);
		}
		else if (e.GetKeyCode() == CHECKMATE_KEY_DOWN) {
			unit.UpdateYCoord(-10);
		}
		
		if (UnitsOverlap(unit, barrier1) == 1 or UnitsOverlap(unit, barrier2) == 1 or
			UnitsOverlap(unit, barrier3) == 1 or UnitsOverlap(unit, barrier4) == 1) {
			unit.SetCoords({ 440,80 });
		}

		if (UnitsOverlap(unit, wall1) == 1 or UnitsOverlap(unit, wall2) == 1 or
			UnitsOverlap(unit, wall3) == 1 or UnitsOverlap(unit, wall4) == 1 or
			UnitsOverlap(unit, wall5) == 1 or UnitsOverlap(unit, wall6) == 1 or 
			UnitsOverlap(unit, wall7) == 1 or UnitsOverlap(unit, wall8) == 1 or 
			UnitsOverlap(unit, wall9) == 1 or UnitsOverlap(unit, wall10) == 1 or 
			UnitsOverlap(unit, wall11) == 1) {
			unit.SetCoords({ 440,80 });
		}

	}

	
private:
	CheckMate::Renderer renderer;
	
	CheckMate::Image back{ "../Assets/Images/Grass.png" };

	//walls
	CheckMate::Unit barrier1{ "../Assets/Images/XWall.PNG", {0,0} };
	CheckMate::Unit barrier2{ "../Assets/Images/XShortWall.PNG", {0,577} };
	CheckMate::Unit barrier3{ "../Assets/Images/YWall.PNG", {0,0} };
	CheckMate::Unit barrier4{ "../Assets/Images/YShortWall.PNG", {597,0} };

	CheckMate::Unit wall1{ "../Assets/Images/YThreeBlock.PNG", {398,0} };
	CheckMate::Unit wall2{ "../Assets/Images/YThreeBlock.PNG", {498,145} };
	CheckMate::Unit wall3{ "../Assets/Images/XThreeBlock.PNG", {0,133} };
	CheckMate::Unit wall4{ "../Assets/Images/XThreeBlock.PNG", {298,133} };
	CheckMate::Unit wall5{ "../Assets/Images/XThreeBlock.PNG", {398,423} };
	CheckMate::Unit wall6{ "../Assets/Images/YTwoBlock.PNG", {398,290} };
	CheckMate::Unit wall7{ "../Assets/Images/XThreeBlock.PNG", {200,290} };
	CheckMate::Unit wall8{ "../Assets/Images/YThreeBlock.PNG", {100,290} };
	CheckMate::Unit wall9{ "../Assets/Images/YThreeBlock.PNG", {200,290} };
	CheckMate::Unit wall10{ "../Assets/Images/YThreeBlock.PNG", {299,443} };
	CheckMate::Unit wall11{ "../Assets/Images/XTwoBlock.PNG", {100,423} };
	
	CheckMate::Unit unit{ "../Assets/Images/Sheep.PNG", {440,80} };
	
};

CHECKMATE_GAME_START(S23_Game_App);