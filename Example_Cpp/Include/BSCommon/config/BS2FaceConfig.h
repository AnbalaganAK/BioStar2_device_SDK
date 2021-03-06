#ifndef __BS2_FACE_CONFIG_H__
#define __BS2_FACE_CONFIG_H__

#include "../BS2Types.h"

/**
 *	Face Security Level
 */
enum {
	BS2_FACE_SECURITY_NORMAL,
	BS2_FACE_SECURITY_SECURE,
	BS2_FACE_SECURITY_MORE_SECURE,

	BS2_FACE_SECURITY_DEFAULT = BS2_FACE_SECURITY_NORMAL,

	BS2_FACE_ENROLL_TIMEOUT_MIN = 30,
	BS2_FACE_ENROLL_TIMEOUT_MAX = 60,
	BS2_FACE_ENROLL_TIMEOUT_DEFAULT = 60,

	BS2_FACE_EX_ENROLL_TIMEOUT_MIN = 10,
	BS2_FACE_EX_ENROLL_TIMEOUT_MAX = 20,
	BS2_FACE_EX_ENROLL_TIMEOUT_DEFAULT = 20,

	BS2_MAX_ROTATION_DEFAULT = 15,

	BS2_FACE_WIDTH_MIN_DEFAULT = 66,
	BS2_FACE_WIDTH_MAX_DEFAULT = 250,

	BS2_FACE_SEARCH_RANGE_X_DEFAULT = 144,
	BS2_FACE_SEARCH_RANGE_WIDTH_DEFAULT = 432,
};

typedef uint8_t BS2_FACE_SECURITY_LEVEL;

/**
 *	Face Enrollment Threshold
 */
enum {
	BS2_FACE_ENROLL_THRESHOLD_0,
	BS2_FACE_ENROLL_THRESHOLD_1,
	BS2_FACE_ENROLL_THRESHOLD_2,
	BS2_FACE_ENROLL_THRESHOLD_3,
	BS2_FACE_ENROLL_THRESHOLD_4,
	BS2_FACE_ENROLL_THRESHOLD_5,
	BS2_FACE_ENROLL_THRESHOLD_6,
	BS2_FACE_ENROLL_THRESHOLD_7,
	BS2_FACE_ENROLL_THRESHOLD_8,
	BS2_FACE_ENROLL_THRESHOLD_9,

	BS2_FACE_ENROLL_THRESHOLD_DEFAULT = BS2_FACE_ENROLL_THRESHOLD_4,
};

typedef uint8_t BS2_FACE_ENROLL_THRESHOLD;

/**
 *	Ambient Lighting Condition
 */
enum {
	BS2_FACE_LIGHT_CONDITION_INDOOR,
	BS2_FACE_LIGHT_CONDITION_OUTDOOR,
	BS2_FACE_LIGHT_CONDITION_AUTO,
	BS2_FACE_LIGHT_CONDITION_DARK,

	BS2_FACE_LIGHT_CONDITION_DEFAULT = BS2_FACE_LIGHT_CONDITION_INDOOR,
};

typedef uint8_t BS2_FACE_LIGHT_CONDITON;

/**
 *	Auto-On Sensitivity
 */
enum {
	BS2_FACE_DETECT_SENSITIVITY_OFF,
	BS2_FACE_DETECT_SENSITIVITY_LOW,
	BS2_FACE_DETECT_SENSITIVITY_MIDDLE,
	BS2_FACE_DETECT_SENSITIVITY_HIGH,

	BS2_FACE_DETECT_SENSITIVITY_DEFAULT = BS2_FACE_DETECT_SENSITIVITY_MIDDLE,
};

typedef uint8_t BS2_FACE_DETECT_SENSITIVITY;

enum {
	BS2_FACE_LFD_LEVEL_OFF,
	BS2_FACE_LFD_LEVEL_LOW,
	BS2_FACE_LFD_LEVEL_MIDDLE,
	BS2_FACE_LFD_LEVEL_HIGH,

	BS2_FACE_LFD_LEVEL_DEFAULT = BS2_FACE_LFD_LEVEL_OFF,		// FS2, FL
	BS2_FACE_EX_LFD_LEVEL_DEFAULT = BS2_FACE_LFD_LEVEL_LOW,		// F2
};

typedef uint8_t BS2_FACE_LFD_LEVEL;

enum {
	BS2_FACE_PREVIEW_NONE,
	BS2_FACE_PREVIEW_HALF,
	BS2_FACE_PREVIEW_FULL,

	BS2_FACE_PREVIEW_DEFAULT = BS2_FACE_PREVIEW_HALF,
};

typedef uint8_t BS2_FACE_PREVIEW_OPTION;

enum {
	BS2_FACE_OPERATION_MODE_FUSION,
	BS2_FACE_OPERATION_MODE_VISUAL_ONLY,
	BS2_FACE_OPERATION_MODE_VISUAL_AND_IR_FD_ONLY,

	BS2_FACE_OPERATION_MODE_DEFAULT = BS2_FACE_OPERATION_MODE_FUSION,
};

typedef uint8_t BS2_FACE_OPERATION_MODE;

typedef struct {
	BS2_FACE_SECURITY_LEVEL securityLevel;	///< 1 byte
	BS2_FACE_LIGHT_CONDITON lightCondition;			///< 1 byte
	BS2_FACE_ENROLL_THRESHOLD enrollThreshold;			///< 1 byte
	BS2_FACE_DETECT_SENSITIVITY detectSensitivity;	///< 1 byte

	uint16_t enrollTimeout;						///< 2 bytes
	BS2_FACE_LFD_LEVEL lfdLevel;		///< 1 byte
	BS2_BOOL quickEnrollment;			///< 1 byte

	BS2_FACE_PREVIEW_OPTION previewOption;			///< 1 byte
	BS2_BOOL checkDuplicate;			///< 1 byte
	BS2_FACE_OPERATION_MODE operationMode;			///< 1 byte
	uint8_t maxRotation;						///< 1 byte

	struct {
		uint16_t min;
		uint16_t max;
	} faceWidth;		///< 4 bytes

	struct {
		uint16_t x;
		uint16_t width;
	} searchRange;		///< 4 bytes

	uint8_t unused[18];						///< 18 bytes (reserved)
} BS2FaceConfig;

#endif	// __BS2_FACE_CONFIG_H__
