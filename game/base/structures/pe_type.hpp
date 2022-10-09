#pragma once

#ifndef PE_TYPE_HPP
#define PE_TYPE_HPP

enum pe_type {

	PE_NONE = 0x0,
	PE_STATIC = 0x1, 			// CPhysicalEntity
	PE_RIGID = 0x2, 			// CRigidEntity
	PE_WHEELEDVEHICLE = 0x3,	// CWheeledVehicleEntity
	PE_LIVING = 0x4,			// CLivingEntity
	PE_PARTICLE = 0x5,			// CParticleEntity
	PE_ARTICULATED = 0x6,		// CArticulatedEntity
	PE_ROPE = 0x7,				// CRopeEntity
	PE_SOFT = 0x8,				// CSoftEntity
	PE_AREA = 0x9,
};

#endif // !PE_TYPE_HPP