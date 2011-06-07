#include <GL/gl.h>
#include <math.h>

static void _sglu_set_identitiy(GLfloat* m)
{
#define M(row, col) m[(col<<2)+row]
  M(0, 0) = 1;   M(0, 1) = 0;   M(0, 2) = 0;  M(0, 3) = 0;
  M(1, 0) = 0;   M(1, 1) = 1;   M(1, 2) = 0;  M(1, 3) = 0;
  M(2, 0) = 0;   M(2, 1) = 0;   M(2, 2) = 1;  M(2, 3) = 0;
  M(3, 0) = 0;   M(3, 1) = 0;   M(3, 2) = 0;  M(3, 3) = 1;
#undef M
}

static void normalize(float v[3])
{
    float norm;
    norm = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    
    if (norm != 0.0)
    {
        v[0] /= norm;
        v[1] /= norm;
        v[2] /= norm;
    }
}

static void cross(float v1[3], float v2[3], float result[3])
{
    result[0] = v1[1] * v2[2] - v1[2] * v2[1];
    result[1] = v1[2] * v2[0] - v1[0] * v2[2];
    result[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void gluLookAt(GLdouble eyex, GLdouble eyey, GLdouble eyez, 
               GLdouble cenx, GLdouble ceny, GLdouble cenz, 
               GLdouble upx,  GLdouble upy,  GLdouble upz)
{
    float forward[3], side[3], up[3];
    GLfloat m[16];

    forward[0] = cenx - eyex;
    forward[1] = ceny - eyey;
    forward[2] = cenz - eyez;
    normalize(forward);

    up[0] = upx;
    up[1] = upy;
    up[2] = upz;

    /* Side = forward x up */
    cross(forward, up, side);
    normalize(side);
    /* Recompute up as: up = side x forward */
    cross(side, forward, up);
    
    /* get M metrix */
    _sglu_set_identitiy(m);

    m[0] = side[0];
    m[1] = side[1];
    m[2] = side[2];    

    m[4] = up[0];
    m[5] = up[1];
    m[6] = up[2];

    m[8] = -forward[0];
    m[9] = -forward[1];
    m[10]= -forward[2];

    glMultMatrixf(m);
    glTranslated(-eyex, -eyey, -eyez);
}

