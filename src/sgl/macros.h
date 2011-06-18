/**
 * @file   macros.h
 *
 * Copyright (C) 2011 - SGL Authors <aitjcize@gmail.com>
 * All Rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __SGL_MACROS_H__
#define __SGL_MACROS_H__

/* Clamp X to [MIN,MAX] */
#define CLAMP( X, MIN, MAX )  ( (X)<(MIN) ? (MIN) : ((X)>(MAX) ? (MAX) : (X)) )

/* Minimum of two values: */
#define MIN2( A, B )   ( (A)<(B) ? (A) : (B) )

/* Maximum of two values: */
#define MAX2( A, B )   ( (A)>(B) ? (A) : (B) )

/* Dot product of two 2-element vectors */
#define DOT2( a, b )  ( (a)[0]*(b)[0] + (a)[1]*(b)[1] )

/* Dot product of two 3-element vectors */
#define DOT3( a, b )  ( (a)[0]*(b)[0] + (a)[1]*(b)[1] + (a)[2]*(b)[2] )

/* Dot product of two 4-element vectors */
#define DOT4( a, b )  ( (a)[0]*(b)[0] + (a)[1]*(b)[1] + \
            (a)[2]*(b)[2] + (a)[3]*(b)[3] )

/* Dot product of two 4-element vectors */
#define DOT4V(v,a,b,c,d) (v[0]*(a) + v[1]*(b) + v[2]*(c) + v[3]*(d))


/* Cross product of two 3-element vectors */
#define CROSS3(n, u, v)             \
do {                        \
   (n)[0] = (u)[1]*(v)[2] - (u)[2]*(v)[1];  \
   (n)[1] = (u)[2]*(v)[0] - (u)[0]*(v)[2];  \
   (n)[2] = (u)[0]*(v)[1] - (u)[1]*(v)[0];  \
} while (0)


/* Normalize a 3-element vector to unit length. */
#define NORMALIZE_3FV( V )          \
do {                        \
   GLfloat len = (GLfloat) LEN_SQUARED_3FV(V);  \
   if (len) {                   \
      len = INV_SQRTF(len);         \
      (V)[0] = (GLfloat) ((V)[0] * len);    \
      (V)[1] = (GLfloat) ((V)[1] * len);    \
      (V)[2] = (GLfloat) ((V)[2] * len);    \
   }                        \
} while(0)

#define LEN_3FV( V ) (SQRTF((V)[0]*(V)[0]+(V)[1]*(V)[1]+(V)[2]*(V)[2]))
#define LEN_2FV( V ) (SQRTF((V)[0]*(V)[0]+(V)[1]*(V)[1]))

#define LEN_SQUARED_3FV( V ) ((V)[0]*(V)[0]+(V)[1]*(V)[1]+(V)[2]*(V)[2])
#define LEN_SQUARED_2FV( V ) ((V)[0]*(V)[0]+(V)[1]*(V)[1])

#define COLOR_FF(c)                                  \
  (((GLuint)(CLAMP(c[3], 0, 1.0) * 255) << 24) |     \
   ((GLuint)(CLAMP(c[0], 0, 1.0) * 255) << 16) |     \
   ((GLuint)(CLAMP(c[1], 0, 1.0) * 255) <<  8) |     \
   ((GLuint)(CLAMP(c[2], 0, 1.0) * 255)))

#define COLOR_FE(r, g, b, a)                      \
  (((GLuint)(CLAMP(a, 0, 1.0) * 255) << 24) |     \
   ((GLuint)(CLAMP(r, 0, 1.0) * 255) << 16) |     \
   ((GLuint)(CLAMP(g, 0, 1.0) * 255) <<  8) |     \
   ((GLuint)(CLAMP(b, 0, 1.0) * 255)))

/* Framebuffer access related */
#define BUF_SET_C(buf, x, y, cc) \
    ((GLuint*)(buf)->data)[((buf)->height-y-1)*(buf)->width+x-1] = cc;

#define BUF_SET_D(buf, x, y, d) \
    ((GLfloat*)(buf)->data)[((buf)->height-y-1)*(buf)->width+x-1] = d;

#define BUF_GET_C(buf, x, y) \
  (((GLuint*)(buf)->data)[((buf)->height-(y)-1)*(buf)->width+(x)-1])

#define BUF_GET_D(buf, x, y) \
  (((GLfloat*)(buf)->data)[((buf)->height-(y)-1)*(buf)->width+(x)-1])

#define NORMALIZE_Z(ctx, z) \
  ((z - ctx->drawbuffer->depth_max * ctx->viewport.near) / \
   (ctx->drawbuffer->depth_max * (ctx->viewport.far - ctx->viewport.near)))

#define MOVE_FLOAT_4(dst, src) \
  do {                         \
    ((GLfloat*)(dst))[0] = ((GLfloat*)(src))[0];           \
    ((GLfloat*)(dst))[1] = ((GLfloat*)(src))[1];           \
    ((GLfloat*)(dst))[2] = ((GLfloat*)(src))[2];           \
    ((GLfloat*)(dst))[3] = ((GLfloat*)(src))[3];           \
  } while (0)

#endif /* __SGL_MACROS_H__ */
