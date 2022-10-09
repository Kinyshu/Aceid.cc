#pragma once

#ifndef RPC_HPP
#define RPC_HPP

namespace rpc {

	void Create(std::string applicationId) {

		DiscordEventHandlers handler;
		::memset(&handler, 0, sizeof DiscordEventHandlers);
		{
			Discord_Initialize(applicationId.c_str(), &handler, 1, 0);
		}

		DiscordRichPresence presence;
		::memset(&presence, 0, sizeof DiscordRichPresence);
		{
			presence.state = "https://vk.com/aceid.cheats";
			presence.details = u8"Присоединяйся к Aceid.cc!";
			presence.largeImageKey = "aceid_logo";
			presence.largeImageText = "Aceid.cc";

			Discord_UpdatePresence(&presence);
		}
	}
}

#endif // !RPC_HPP