#pragma once

#ifndef ACTIONS_HPP
#define ACTIONS_HPP

namespace actions {

	void OnInGame() {

		api::trashtalker::Update();
	}

	void OnInLobby() {

	}

	void OnLoadingLobby() {

		api::trashtalker::hooks::b_on_kill_hook_updated = false;
	}

	void OnLoadingLevel() {

	}

	void OnPostGame() {

	}
}

#endif // !ACTIONS_HPP