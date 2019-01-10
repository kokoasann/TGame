#pragma once
enum enMouseEve {
	enLeftClick,
	enMiddleClick,
	enRightClick,
	enNumMouseEve
};
namespace Mouse {
	int GetMouseNotch();
	void UpdateMouseInput();
	bool isTrigger(enMouseEve);
	bool isPress(enMouseEve);
	CVector3 GetCursorPos();
}
