#pragma once

#ifndef FONTS_HPP
#define FONTS_HPP

class CFontsManager {
public:

	void init() {

		ImGuiIO& io = ImGui::GetIO();
		{
			ImFontConfig config;
			{
				config.PixelSnapH = 1;
				config.OversampleH = 3;
				config.OversampleV = 1;
			}

			this->path(io, "GothamPro-Light", "c:\\Aceid.cc\\assets\\fonts\\bahnschrift.ttf", 72.f, config);

			for (float i = 2.f; i != 32.f; i += 1.f) {

				this->path(io, "__MAIN__", "c:\\Aceid.cc\\assets\\fonts\\bahnschrift.ttf", i, config);
				this->path(io, "GothamPro-Light", "c:\\Aceid.cc\\assets\\fonts\\GothamPro-Light.ttf", i, config);
				this->path(io, "GothamPro-Medium", "c:\\Aceid.cc\\assets\\fonts\\GothamPro-Medium.ttf", i, config);
				this->path(io, "Gypsy Killer Laser", "c:\\Aceid.cc\\assets\\fonts\\gypsykillerlaserital.ttf", i, config);
			}
		}
	}

	ImFont* get(std::string name, float size) {
		return this->fonts.find(name + "_" + std::to_string(size))->second;
	}

private:

	std::map< std::string, ImFont* > fonts;

	void path(ImGuiIO& io, std::string name, std::string path, float size, ImFontConfig config) {

		static const ImWchar ranges[] = { 0x0020, 0x00FF, 0x0400, 0x044F, 0 };

		auto font = io.Fonts->AddFontFromFileTTF(path.c_str(), size, &config, ranges);
		this->fonts.insert(std::pair(name + "_" + std::to_string(size), font));
	}

	void bytes(void* data, int dataSize, ImGuiIO& io, std::string name, float size, ImFontConfig config) {

		static const ImWchar ranges[] = { 0x0020, 0x00FF, 0x0400, 0x044F, 0 };

		auto font = io.Fonts->AddFontFromMemoryTTF(data, dataSize, size, &config, ranges);
		this->fonts.insert(std::pair(name + "_" + std::to_string(size), font));
	}
};

#endif // !FONTS_HPP