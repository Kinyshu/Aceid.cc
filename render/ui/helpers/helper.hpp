#pragma once

#ifndef HELPER_HPP
#define HELPER_HPP

namespace helper {

	bool cursorInBox(float x, float y, float w, float h) {
		return ImGui::GetMousePos().x >= x && ImGui::GetMousePos().x <= x + w && ImGui::GetMousePos().y >= y && ImGui::GetMousePos().y <= y + h;
	}
}

#endif // !HELPER_HPP