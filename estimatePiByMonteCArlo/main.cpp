//
//  main.cpp
//  minimal
//
//  Created by kudret akcapinar on 30.05.2021.
//

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace  std;

double calculatePi(const int);


int main(int argc, const char * argv[])
{
    const int Number_Of_Points = pow(10.0, 6.0);
    
    const clock_t begin_time = clock();
    
    double estimated_value =  calculatePi(Number_Of_Points);
    cout<< "Estimated value of pi : " << estimated_value <<  endl<< endl;
    cout << "Number of Monte Carlo Samples: " <<Number_Of_Points << "\n\n";
    cout << "Time elapsed : " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << " seconds" << endl << endl ;
}

double calculatePi(const int Number_Of_Points)
{
    
    int number_of_points_in_quarter_circle = 0;
    double estimated_pi_value;
    
    
    
    for(int i = 0; i<Number_Of_Points-1; i++)
    {
        double x = ((double) rand() / (RAND_MAX));
        double y = ((double) rand() / (RAND_MAX));
        double radius = pow(x,2) + pow(y,2);
        
        if(radius < 1)
            number_of_points_in_quarter_circle++;
    }
    estimated_pi_value = 4.0 * number_of_points_in_quarter_circle / Number_Of_Points;
    
    return estimated_pi_value;
    
}


