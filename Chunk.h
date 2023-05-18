#ifndef CHUNK_H_INCLUDED
#define CHUNK_H_INCLUDED

#include "Block.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include "Math.h"

class Chunk
{
    public:
        // Declarations.
        Math math;

        // Variables.
        Block chunk_Blocks[16][16][16];
        bool chunk_Generated = false;
        int chunk_Size = 16;
        int chunk_X;
        int chunk_Z;


        Block GetBlock(int x, int y, int z)
        {
            return chunk_Blocks[x][y][z];
        }

        bool IsAir(int x, int y, int z)
        {
            if(GetBlock(x - 1, y, z).block_Type == BlockType(Air) ||
               GetBlock(x + 1, y, z).block_Type == BlockType(Air) ||
               GetBlock(x, y - 1, z).block_Type == BlockType(Air) ||
               GetBlock(x, y + 1, z).block_Type == BlockType(Air) ||
               GetBlock(x, y, z - 1).block_Type == BlockType(Air) ||
               GetBlock(x, y, z + 1).block_Type == BlockType(Air))
            {
                return true;
            }
            else if(x >= chunk_Size - 1 || y >= chunk_Size - 1 || z >= chunk_Size - 1)
            {
                return true;
            }
            else if(x == 0 || y == 0 || z == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void RenderChunk()
        {
            for(int x = 1; x < chunk_Size; x++)
                {
                    for(int z = 1; z < chunk_Size; z++)
                    {
                        int height = 16;//math.GetNoise(x, z);

                        for(int y = 0; y < height; y++)
                        {
                            Block block = GetBlock(x, y, z);

                            if(y >= height - 1)
                            {
                                block.block_Type = BlockType(Grass);
                                block.SetBlockPosition(x + chunk_X, y, z + chunk_Z);
                            }
                            else if(y < height - 1 && y > height - 5)
                            {
                                block.block_Type = BlockType(Dirt);
                                block.SetBlockPosition(x + chunk_X, y, z + chunk_Z);
                            }
                            else if(y <= height - 5)
                            {
                                block.block_Type = BlockType(Stone);
                                block.SetBlockPosition(x + chunk_X, y, z + chunk_Z);
                            }

                            block.RenderBlock();
                        }
                    }
                }
        }

        void SetBlock(Block block, int x, int y, int z)
        {
            chunk_Blocks[x][y][z] = block;
        }

        void SetChunkPosition(int x, int z)
        {
            chunk_X = x;
            chunk_Z = z;
        }
};

#endif // CHUNK_H_INCLUDED
