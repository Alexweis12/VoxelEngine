#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include <cstdlib>

class Math
{
    public:
        // Variables.
        int noise_Addition = 8;
        double noise_Final = -1;
        double noise_LastX = -1;
        double noise_LastZ = -1;
        float noise_Multiplier = 2.5;
        float noise_Scale = 6;


        int GetNoise(int x, int z)
        {
            double aa = RandomI(0, x) / noise_Scale;
            double ab = RandomI(0, z) / noise_Scale;

            if(noise_LastX != -1)
            {
                if(aa > noise_LastX + 1)
                {
                    aa = noise_LastX + 1;
                }
                else if(aa < noise_LastX - 1)
                {
                    aa = noise_LastX - 1;
                }
            }

            if(noise_LastZ != -1)
            {
                if(ab > noise_LastZ + 1)
                {
                    ab = noise_LastZ + 1;
                }
                else if(ab < noise_LastZ - 1)
                {
                    ab = noise_LastZ - 1;
                }
            }

            noise_LastX = aa;
            noise_LastZ = ab;

            double ba = aa + ab;
            ba *= noise_Multiplier;

            if(noise_Final > -1)
            {
                if(ba > noise_Final + 1)
                {
                    ba = noise_Final + 1;
                }
                else if(ba < noise_Final - 1)
                {
                    ba = noise_Final - 1;
                }
            }

            noise_Final = ba;
            return (int)ba + noise_Addition;
        }

        int RandomI(int minI, int maxI)
        {
            int result;
            if(minI > 0)
            {
                result = rand() % maxI + minI;
            }
            else if(minI < 0)
            {
                result = rand() % maxI - minI;
            }
            else
            {
                result = rand() % maxI;
            }

            return result;
        }
};

#endif // MATH_H_INCLUDED
