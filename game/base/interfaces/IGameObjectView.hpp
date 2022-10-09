#pragma once

#ifndef IGAMEOBJECTVIEW_HPP
#define IGAMEOBJECTVIEW_HPP

#include "../structures/SViewParams.hpp"

interface IGameObjectView {

	virtual void vecDelDtor() = 0;
	virtual void UpdateView(SViewParams* viewParams) = 0;
	virtual void PostUpdateView(SViewParams* viewParams) = 0;
};

#endif // !IGAMEOBJECTVIEW_HPP
