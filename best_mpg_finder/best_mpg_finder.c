  //////////////////////////////////////////////////////////////////////////////
    //  Filename:    best_mpg_finder.c
    //  Description: Determine which car is the most economical based on its 
    //               average miles per gallon (MPG) given ten sets of mileage and 
    //               gasoline consumption data (to one decimal place) for three 
    //               cars using multi-dimensional arrays.
    //////////////////////////////////////////////////////////////////////////////
    #include <stdio.h>
    
    #define NUM_CARS 3
    #define NUM_SAMPLES 10
    
    int main(void) {
    //////////////////////////////////////////////////////////////////////////////
    // Mileage data for each car (in miles)
    //////////////////////////////////////////////////////////////////////////////
        float mileage[NUM_CARS][NUM_SAMPLES] = {
            // row 0 is car 1, 10 columns of miles
            {120.5, 130.2, 135.1, 140.7, 145.3, 150.0, 155.6, 160.8, 165.4, 170.1},
            // row 1 is car 2, 10 columns of miles
            {110.3, 115.7, 120.4, 125.2, 130.9, 135.5, 140.2, 145.8, 150.3, 155.1},
            // row 2 is car 3, 10 columns of miles 
            {130.2, 145.1, 110.3, 115.0, 120.6, 135.3, 130.7, 135.4, 130.2, 125.9}
            //{100.2, 105.1, 110.3, 115.0, 120.6, 125.3, 130.7, 135.4, 140.2, 145.9}  
        };
    //////////////////////////////////////////////////////////////////////////////
    // Gasoline consumption data for each car (in gallons)
    //////////////////////////////////////////////////////////////////////////////
        float gasoline[NUM_CARS][NUM_SAMPLES] = {
            // row 0 is car 1, 10 columns of gallons 
            {4.2, 4.5, 4.7, 4.9, 5.1, 5.3, 5.5, 5.7, 5.9, 6.1},
            // row 1 is car 2, 10 columns of gallons
            {3.8, 4.0, 4.2, 4.4, 4.6, 4.8, 5.0, 5.2, 5.4, 5.6},
            // row 2 is car 3, 10 columns of gallons
            {3.5, 3.7, 3.9, 4.1, 4.3, 4.5, 4.7, 4.9, 5.1, 5.3} 
        };
    //////////////////////////////////////////////////////////////////////////////
    // Calculate the average miles per gallon for each car
    //////////////////////////////////////////////////////////////////////////////
        // there will be 3 average MPG in the end, 1 for each of 3 cars
        float avg_mpg[NUM_CARS] = {0.0};
        // the outer loop, will loop over rows representing cars
        for (int car_idx = 0; car_idx < NUM_CARS; car_idx++) {
            // clear the totals needed to compute average for every car
            float total_miles = 0.0;
            float total_gallons = 0.0;
            // the inner loop, loops over columns to accumulate miles and gallons
            for (int sample_idx = 0; sample_idx < NUM_SAMPLES; sample_idx++) {
                total_miles += mileage[car_idx][sample_idx];
                total_gallons += gasoline[car_idx][sample_idx];
            }
            //for each car, compute the average MPG and store
            avg_mpg[car_idx] = total_miles / total_gallons;
        }
    //////////////////////////////////////////////////////////////////////////////
    // Find the car with the highest average miles per gallon
    //////////////////////////////////////////////////////////////////////////////
        int most_economical_car = 0; // store the index of the best MPG car
        float max_avg_mpg = avg_mpg[0]; //start off assuming car 1 has the max
        // start the for loop and index car_idx = 1  to compare car 2 
        for (int car_idx = 1; car_idx < NUM_CARS; car_idx++) {
            if (avg_mpg[car_idx] > max_avg_mpg) {
                most_economical_car = car_idx; // better gas mileage! save index
                max_avg_mpg = avg_mpg[car_idx]; // store new maximum for next compare
            }
        }
    //////////////////////////////////////////////////////////////////////////////
    // Display the results
    //////////////////////////////////////////////////////////////////////////////
        printf("Average Miles per Gallon (MPG) for each car:\n");
        printf("Car 1: %.1f\n", avg_mpg[0]);
        printf("Car 2: %.1f\n", avg_mpg[1]);
        printf("Car 3: %.1f\n", avg_mpg[2]);
        
        // display the best MPG car
        printf("\nThe most economical car is Car %d with an average MPG of %.1f\n",
            // the car number is not the same as car index! have to add 1
            (most_economical_car+1), max_avg_mpg); 
    
        return 0;
    }
	https://github.com/bradenschnaufer/CS1100.git