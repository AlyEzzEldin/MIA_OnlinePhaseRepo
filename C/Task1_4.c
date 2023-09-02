#include <stdio.h>

float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
float bno55[10] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};


float Avg_Measure(float measure1, float measure2, float accuracy1, float accuracy2) {
    float scale1 = accuracy1 / (accuracy1 + accuracy2);
    float scale2 = accuracy2 / (accuracy1 + accuracy2);
    return ((scale1 * measure1) + (scale2 * measure2));
}

int main() {
    float Out_Measure_Arr[10];

    for (int i=0; i<10;i++)
	{
        float measurement1 = mpu6050[i];
        float measurement2 = bno55[i];
        float accuracy1 = 0.79;
        float accuracy2 = 0.92;
        float Out_Measure = Avg_Measure(measurement1, measurement2, accuracy1, accuracy2);
        Out_Measure_Arr[i] = Out_Measure;
    }

    printf("Average Measurements:\n");
    for (int i = 0; i < 10;i++) 
	{
        printf("%.2f ", Out_Measure_Arr[i]);
    }
    printf("\n");

    return 0;
}