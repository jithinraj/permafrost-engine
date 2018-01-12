/*
 *  This file is part of Permafrost Engine. 
 *  Copyright (C) 2017 Eduard Permyakov 
 *
 *  Permafrost Engine is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Permafrost Engine is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "pf_math.h"

struct camera;
extern const unsigned g_sizeof_camera;

#define DECL_CAMERA_STACK(_name)        \
    char _name[g_sizeof_camera]         \

struct camera *Camera_New (void);
void           Camera_Free(struct camera *cam);

void           Camera_SetPos       (struct camera *cam, vec3_t pos);
void           Camera_SetPitchAndYaw(struct camera *cam, float pitch, float yaw);
void           Camera_SetSpeed     (struct camera *cam, float speed);
void           Camera_SetSens      (struct camera *cam, float sensitivity);
float          Camera_GetYaw       (const struct camera *cam);

/* These should be called once per tick, at most. The amount moved depends 
 * on the camera speed. 
 */
void           Camera_MoveLeftTick     (struct camera *cam);
void           Camera_MoveRightTick    (struct camera *cam);
void           Camera_MoveFrontTick    (struct camera *cam);
void           Camera_MoveBackTick     (struct camera *cam);
void           Camera_MoveDirectionTick(struct camera *cam, vec3_t dir);
void           Camera_ChangeDirection  (struct camera *cam, int dx, int dy);

/* Should be called once per frame, after all movements have been set, but 
 * prior to rendering.
 */
void           Camera_TickFinish(struct camera *cam);

#endif
