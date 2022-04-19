/* *************************************************************************************** */
/* 						ORION GRAPHICS LIBRARY AND RENDERING ENGINE						   */
/* *************************************************************************************** */
/* Copyright (c) 2022 Jack Bennett														   */
/* --------------------------------------------------------------------------------------- */
/* THE  SOFTWARE IS  PROVIDED "AS IS",  WITHOUT WARRANTY OF ANY KIND, EXPRESS  OR IMPLIED, */
/* INCLUDING  BUT  NOT  LIMITED  TO  THE  WARRANTIES  OF  MERCHANTABILITY,  FITNESS FOR  A */
/* PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN  NO EVENT SHALL  THE  AUTHORS  OR COPYRIGHT */
/* HOLDERS  BE  LIABLE  FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF */
/* CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR */
/* THE USE OR OTHER DEALINGS IN THE SOFTWARE.											   */
/* *************************************************************************************** */

#pragma once
#ifndef __ORI_INTERNAL_H
#define __ORI_INTERNAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

// Orion errors
#define ORERR_MULTIPLE_CALLS 	0x001, 	"Illegal call of function that has already been called; this function can not be called more than once.", 		"ORERR_MULTIPLE_CALLS"
#define ORERR_GL_INVALID_VERS 	0x002, 	"Attempted to load invalid OpenGL version.", 																	"ORERR_GL_INVALID_VERS"
#define ORERR_GL_ABOVE_MAX 		0x003, 	"Attempted to load invalid OpenGL version; maximum OpenGL version supported by Orion is 4.6.", 					"ORERR_GL_ABOVE_MAX"
#define ORERR_GL_BELOW_MIN 		0x004, 	"Attempted to load invalid OpenGL version; versions earlier than 1.1 are not supported by Orion.", 				"ORERR_GL_BELOW_MIN"
#define ORERR_NOT_INIT 			0x005, 	"A function was called that requires Orion to be initialised, but Orion has not been initialised!", 			"ORERR_NOT_INIT"
#define ORERR_NULL_RECIEVED 	0x006, 	"A function recieved NULL but it was not able to accept this argument.", 										"ORERR_NULL_RECIEVED"
#define ORERR_GLFW_FAIL 		0x007, 	"GLFW failed to initialise.", 																					"ORERR_GLFW_FAIL"
#define ORERR_GL_VERS_TOO_LOW	0x008, 	"A function was called that requires OpenGL to be of a higher version than was specified.", 					"ORERR_GL_VERS_TOO_LOW"
#define ORERR_GL_FAIL			0x009, 	"Failed to load OpenGL.", 																						"ORERR_GL_FAIL"
#define ORERR_MULTIPLE_DEBUG	0x00A, 	"Illegal attempt to enable a debug context after a debug context has already been enabled.", 					"ORERR_MULTIPLE_DEBUG"
#define ORERR_GLFW_WIN_FAIL		0x00B, 	"GLFW failed to create a window.", 																				"ORERR_GLFW_WIN_FAIL"
#define ORERR_ACCESS_DENIED		0x00C, 	"Couldn't execute a necessary function; access denied.", 														"ORERR_ACCESS_DENIED"
#define ORERR_ACCESS_PHANTOM	0x00D, 	"Attempted to access resource that didn't exist.", 																"ORERR_ACCESS_PHANTOM"
#define ORERR_UNSUPPORTED_TYPE	0x00E, 	"Unsupported type given to function", 																			"ORERR_UNSUPPORTED_TYPE"
#define ORERR_BUFFER_INVALID	0x00F, 	"Invalid type given to buffer", 																				"ORERR_BUFFER_INVALID"

// all orion objects are added to a global linked list (stored in _orion)
typedef struct _orionObject {
	struct _orionObject *next;
	union {
		oriBuffer *bufferData;
	} data;
} _orionObject;

// global mutable data is stored here
typedef struct _orionState {
	bool initialised;

	unsigned int glVersion;
	unsigned int glProfile;

	char *execDir; // will be freed

	_orionObject *objectListHead;
} _orionState;
extern _orionState _orion;

/**
 * @brief throw an exception to stdout and break the program
 * 
 * @param code the code of the exception
 * @param msg a helpful message for debugging
 * @param label the label of the error
 */
void _orionThrowError(const int code, const char *msg, const char *label);

// ======================================================================================
// ***** 				   		 ORION OPAQUE DATA TYPES 							*****
// ======================================================================================

typedef struct oriBuffer {
	oriBuffer *next;
} oriBuffer;

#ifdef __cplusplus
}
#endif

#endif // include guard