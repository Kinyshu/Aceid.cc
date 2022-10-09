#pragma once

#ifndef ERMIATTACHMENTTYPE_HPP
#define ERMIATTACHMENTTYPE_HPP

enum ERMIAttachmentType {

	eRAT_PreAttach = 0x0,
	eRAT_PostAttach = 0x1,
	eRAT_NoAttach = 0x2,
	eRAT_NumAttachmentTypes = 0x3
};

#endif // !ERMIATTACHMENTTYPE_HPP