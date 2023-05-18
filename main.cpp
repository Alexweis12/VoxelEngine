#include <iostream>

// Declarations.
void GenerateWorld();
void StartRenderer(int argc, char** argv);

// Variables.


int main(int argc, char** argv)
{
    GenerateWorld();
    StartRenderer(argc, argv);
    return 0;
}
