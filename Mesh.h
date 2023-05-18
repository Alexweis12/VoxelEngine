#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

class Mesh
{
    public:
        void CreateCube(float cubeSize, float x, float y, float z)
        {
            //front
            glVertex3f(x - cubeSize, y + cubeSize, z + cubeSize);
            glVertex3f(x - cubeSize, y - cubeSize, z + cubeSize);
            glVertex3f(x + cubeSize, y - cubeSize, z + cubeSize);
            glVertex3f(x + cubeSize, y + cubeSize, z + cubeSize);

            //back
            glVertex3f(x + cubeSize, y + cubeSize, z - cubeSize);
            glVertex3f(x + cubeSize, y - cubeSize, z - cubeSize);
            glVertex3f(x - cubeSize, y - cubeSize, z - cubeSize);
            glVertex3f(x - cubeSize, y + cubeSize, z - cubeSize);

            //right
            glVertex3f(x + cubeSize, y + cubeSize, z + cubeSize);
            glVertex3f(x + cubeSize, y - cubeSize, z + cubeSize);
            glVertex3f(x + cubeSize, y - cubeSize, z - cubeSize);
            glVertex3f(x + cubeSize, y + cubeSize, z - cubeSize);

            //left
            glVertex3f(x - cubeSize, y + cubeSize, z - cubeSize);
            glVertex3f(x - cubeSize, y - cubeSize, z - cubeSize);
            glVertex3f(x - cubeSize, y - cubeSize, z + cubeSize);
            glVertex3f(x - cubeSize, y + cubeSize, z + cubeSize);

            //top
            glVertex3f(x - cubeSize, y + cubeSize, z - cubeSize);
            glVertex3f(x - cubeSize, y + cubeSize, z + cubeSize);
            glVertex3f(x + cubeSize, y + cubeSize, z + cubeSize);
            glVertex3f(x + cubeSize, y + cubeSize, z - cubeSize);

            //bottom
            glVertex3f(x - cubeSize, y - cubeSize, z - cubeSize);
            glVertex3f(x - cubeSize, y - cubeSize, z + cubeSize);
            glVertex3f(x + cubeSize, y - cubeSize, z + cubeSize);
            glVertex3f(x + cubeSize, y - cubeSize, z - cubeSize);
        }
};

#endif // MESH_H_INCLUDED
