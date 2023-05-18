#include "Chunk.h"
#include <iostream>

// Declarations.


// Variables.
Chunk world_Chunks[16][16];
int world_Size = 256;

void GenerateWorld()
{
    for(int x = 0; x < 4; x++)
    {
        for(int z = 0; z < 4; z++)
        {
            Chunk currentChunk = world_Chunks[x][z];
            currentChunk.SetChunkPosition(x * 16, z * 16);

            std::cout << "Generated chunk - X:" << x * 8 << " Z: " << z * 8 << std::endl;
        }
    }

    std::cout << "Generated " << world_Size / 16 << " chunks" << std::endl;
}

Chunk GetChunk(int x, int z)
{
    return world_Chunks[x][z];
}
