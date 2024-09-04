#include<iostream>
using namespace std;
float fallingDistance(int time)
{
    const double g = 9.8; //value of gravity 
    double distanceCovred = 0.5 * g * time * time; //formula given in question
    return distanceCovred; //return the answer frome this function
}
int main()
{
    int totalIterations = 5; //acording to testdata given in question
    int totalTime = 0; //to store total time
    float averageDistance = 0.0;  //to store distance of all object

    for (int i = 0; i < totalIterations; i++)
    {
        int time; // Variable to store the falling time for each iteration
        cout << "Enter falling time for object " << i+1 << " (in seconds): ";
        cin >> time;

        float distance = fallingDistance(time);
        totalTime += time;
        averageDistance += distance;

      
    }

    averageDistance /= totalIterations; //calculated avrage by dividing total time values inputed

   
    cout << "Average distance covered: " << averageDistance << " m" << std::endl;

    return 0;
}
