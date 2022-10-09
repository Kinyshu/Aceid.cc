#pragma once

#ifndef CACTORSYSTEM_HPP
#define CACTORSYSTEM_HPP

#include "CActor.hpp"
#include "../interfaces/IActorSystem.hpp"

using M_ACTORS = std::map<unsigned int, CActor*, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, CActor*>>>;

class CActorSystem :
	IActorSystem {
public:

	CActor* FindActorById(EntityId id) {
		auto pActor = this->m_actors.find(id)->second;
		return pActor != nullptr ? pActor : nullptr;
	}

	CActor* FindActorByName(const char* name) {
		for (auto it : this->m_actors) {

			auto m_name = reinterpret_cast<IActor*>(it.second)->m_pEntity->GetName();
			if (strstr(m_name, name)) {
				return it.second;
			}
		}

		return nullptr;
	}
public:

	ACEID_API CREATE_FUNCTOR(M_ACTORS, m_actors, 0x30);
};

#endif // !CACTORSYSTEM_HPP