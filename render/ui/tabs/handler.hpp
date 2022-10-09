#pragma once

#ifndef HANDLER_HPP_
#define HANDLER_HPP_

#include "../modules/chrono/sleep.hpp"
#include "helpers/drawhelper.hpp"

#include "classes/weapon.hpp"
#include "classes/player.hpp"
#include "classes/visuals.hpp"
#include "classes/aiming.hpp"
#include "classes/misc.hpp"
#include "classes/scripts.hpp"
#include "classes/settings.hpp"

class CTabsHandler {
public:

	void update(ImVec2 size, ImVec2 position, CFontsManager fm, CImagesManager im) {

		this->size = size;
		this->position = position;
		this->fontsManager = fm;
		this->imagesManager = im;
	}

	void worker() {

		for (auto it = g_tabs.begin(); it != g_tabs.end(); it++) {

			if (it->name == "Weapon" && it->variable) {

				if (this->weaponTab.create()) {
					this->weaponTab.update({ this->size, this->position, this->fontsManager, this->imagesManager });
					this->weaponTab.render();
				}
			}

			if (it->name == "Player" && it->variable) {

				if (this->playerTab.create()) {
					this->playerTab.update({ this->size, this->position, this->fontsManager, this->imagesManager });
					this->playerTab.render();
				}
			}

			if (it->name == "Visuals" && it->variable) {

				if (this->visualTab.create()) {
					this->visualTab.update({ this->size, this->position, this->fontsManager, this->imagesManager });
					this->visualTab.render();
				}
			}

			if (it->name == "Aiming" && it->variable) {

				if (this->aimingTab.create()) {
					this->aimingTab.update({ this->size, this->position, this->fontsManager, this->imagesManager });
					this->aimingTab.render();
				}
			}

			if (it->name == "Misc" && it->variable) {

				if (this->miscTab.create()) {
					this->miscTab.update({ this->size, this->position, this->fontsManager, this->imagesManager });
					this->miscTab.render();
				}
			}

			if (it->name == "Scripts" && it->variable) {

				if (this->scriptsTab.create()) {
					this->scriptsTab.update({ this->size, this->position, this->fontsManager, this->imagesManager });
					this->scriptsTab.render();
				}
			}

			if (it->name == "Settings" && it->variable) {

				if (this->settingsTab.create()) {
					this->settingsTab.update({ this->size, this->position, this->fontsManager, this->imagesManager });
					this->settingsTab.render();
				}
			}
		}
	}

private:

	ImVec2 size;
	ImVec2 position;

	CFontsManager fontsManager;
	CImagesManager imagesManager;

	CWeaponTab weaponTab;
	CPlayerTab playerTab;
	CVisualsTab visualTab;
	CAimingTab aimingTab;
	CMiscTab miscTab;
	CScriptsTab scriptsTab;
	CSettingsTab settingsTab;
};

#endif // !HANDLER_HPP_