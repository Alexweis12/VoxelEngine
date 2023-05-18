#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Mesh.h"

// Enums.
enum BlockType
{
    Dirt = 0,
    Grass = 1,
    Stone = 2,
    Air = 3
};

class Block
{
    public:
        // Variables.
        float block_Size = 0.5;
        BlockType block_Type;
        bool block_IsActive = true;
        int block_X;
        int block_Y;
        int block_Z;


        bool GetActive()
        {
            return block_IsActive;
        }

        BlockType GetBlockType()
        {
            return block_Type;
        }

        void RenderBlock()
        {
            if(block_IsActive && block_Type != BlockType(Air))
            {
                if(block_Type == 0)
                {
                    glColor3f(0.5, 0.5, 0.35);
                }
                else if(block_Type == 1)
                {
                    glColor3f(0.0, 0.5, 0.0);
                }
                else if(block_Type == 2)
                {
                    glColor3f(0.25, 0.25, 0.25);
                }

                Mesh mesh;
                mesh.CreateCube(block_Size, block_X, block_Y, block_Z);
            }
        }

        void SetActive(bool active)
        {
            block_IsActive = active;
        }

        void SetBlockPosition(int x, int y, int z)
        {
            block_X = x;
            block_Y = y;
            block_Z = z;
        }

        void SetBlockSize(float sizeOfBlock)
        {
            block_Size = sizeOfBlock;
        }

        void SetBlockType(BlockType bt)
        {
            block_Type = bt;
        }
};

#endif // BLOCK_H_INCLUDED
