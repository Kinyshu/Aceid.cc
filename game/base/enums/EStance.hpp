#pragma once

#ifndef ESTANCE_HPP
#define ESTANCE_HPP

enum EStance {

	STANCE_NULL = 0xFFFFFFFF,
	STANCE_STAND = 0x0, // стоя
	STANCE_CROUCH = 0x1, // сидя
	STANCE_PRONE = 0x2, // лёжа, подкат
	STANCE_STEALTH = 0x3,
	STANCE_LOW_COVER = 0x4,
	STANCE_HIGH_COVER = 0x5,
	STANCE_PATROL = 0x6,
	STANCE_RANGE = 0x7,
	STANCE_LAST = 0x8,
};

#endif // !ESTANCE_HPP