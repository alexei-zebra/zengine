#ifndef PHYSICS_VOXEL_H_
#define PHYSICS_VOXEL_H_

#include <stdint.h>

struct Voxel {
	uint8_t id;
	uint8_t states;
	uint8_t type;
	uint8_t x;
	uint8_t y;
};

#endif /* PHYSICS_VOXEL_H_ */
