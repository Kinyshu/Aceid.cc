#pragma once

#ifndef ICOMPOUNDCHARACTER_HPP
#define ICOMPOUNDCHARACTER_HPP

interface ICompoundCharacter {

	enum EFlags {

		eFlag_Default = 0x0,
		eFlag_CommitOnCache = 0x1,
		eFlag_NonPlayer = 0x2,
	};

	enum ECloneFlags {

		eCloneFlag_Default = 0x0,
		eCloneFlag_CloneAttachmentEntity = 0x1,
		eCloneFlag_CloneAttachmentLight = 0x2,
		eCloneFlag_CloneAttachmentEffect = 0x4,
	};

	enum ECacheStatus {

		eCS_None = 0x0,
		eCS_InProcess = 0x1,
		eCS_Failed = 0x2,
		eCS_Complete = 0x3,
	};

	enum EGender {
		GENDER_MALE = 0x0,
		GENDER_FEMALE = 0x1,
		SerGENDER_FIRST = 0x0,
		SerGENDER_LAST = 0x1,
		SerGENDER_UNKNOWN = 0x2,
	};

	enum EVisibilityMask {

		VISIBLE_THIRD_PERSON = 0x1,
		VISIBLE_FIRST_PERSON = 0x2,
		VISIBLE_HIGHQUALITY_THIRD_PERSON = 0x4,
		VISIBLE_SHADOW_GENERATION = 0x8,
	};

	enum EDecalFlags {
		eDecalFlag_Default = 0x0,
		eDecalFlag_SkinOnly = 0x1,
	};
};


#endif // !ICOMPOUNDCHARACTER_HPP
