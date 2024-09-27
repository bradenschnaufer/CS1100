/*
 * File: clothing_store_simulator.c
 *
 * Description:
 *   This program simulates a clothing store experience where the user can interactively
 *   select clothing items (shirts, shoes, or pants) and specify the quantity of each item
 *   they want to purchase. The program continuously prompts the user to enter the clothing
 *   type and quantity until the user chooses to exit. Upon exiting, the program calculates
 *   the total cost of the selected items based on predefined prices and displays a formatted
 *   bill showing the quantity, price, and total cost for each clothing item, along with the
 *   overall total cost.
 *
 * Features:
 *   - Interactive menu-based interface for selecting clothing items and quantities
 *   - Supports three clothing types: shirts, shoes, and pants
 *   - Predefined prices for each clothing type
 *   - Validates user input for clothing type and handles invalid inputs
 *   - Calculates the total cost based on the selected quantities and predefined prices
 *   - Displays a formatted bill with detailed information for each clothing item and the total cost
 *
 * Usage:
 *   1. Run the program.
 *   2. Enter the desired clothing type (shirt, shoes, or pants) when prompted.
 *   3. Enter the quantity for the selected clothing type when prompted.
 *   4. Repeat steps 2-3 to add more clothing items as needed.
 *   5. Enter 'exit' when prompted to quit the program and view the generated bill.
 *
 * Author: Braden Schnaufer
 * Date: 09/24/24
 */

// Include necessary header files
#include <stdio.h>   // Provides input/output functions
#include <string.h>  // Provides string manipulation functions
#include <ctype.h> 
#include <strings.h>

// Define constants for clothing item prices using macros
#define SHIRT_PRICE 19.99
#define SHOE_PRICE 49.99
#define PANTS_PRICE 29.99

//ship rate
#define USA_STANDARD_SHIPPING 5.99
#define USA_EXPEDITED_SHIPPING 9.99
#define MEXICO_STANDARD_SHIPPING 7.99
#define MEXICO_EXPEDITED_SHIPPING 12.99
#define CANADA_STANDARD_SHIPPING 6.99
#define CANADA_EXPEDITED_SHIPPING 11.99

//tax rate
#define USA_TAX_RATE .08
#define MEXICO_TAX_RATE .16
#define CANADA_TAX_RATE .12


int main(void) {
    // Declare variables
    char userInput[20];  // Array to store user input for clothing type
    char countryInput[20];// Array to store country
    char shipInput[20];
    int shirtQuantity = 0, shoeQuantity = 0, pantsQuantity = 0;  // Variables to store quantities of each clothing item
    float totalCost;
    char *country1 = "USA";
    char *ship1 = "Standard";

    while (strcasecmp(userInput, "exit") != 0) 
    {
        // Display menu options to the user
        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and calculate the total cost.\n");
        scanf("%s", userInput); // Read user input for clothing type
       
        // If user input is not 'exit', display a success message for adding the clothing item
      
       
    
            if (strcasecmp(userInput, "shirt") == 0) 
            {
            printf("Enter the quantity of shirts needed: ");
            scanf("%d", &shirtQuantity);
            printf("Clothing item '%s' added successfully.\n", userInput);
             }
           
            else if (strcasecmp(userInput, "shoes") == 0) 
            {
            printf("Enter the quantity of shoes needed: ");
            scanf("%d", &shoeQuantity);
            printf("Clothing item '%s' added successfully.\n", userInput);
             }

            else if (strcasecmp(userInput, "pants") == 0) {
            printf("Enter the quantity of pants needed: ");
            scanf("%d", &pantsQuantity);
            printf("Clothing item '%s' added successfully.\n", userInput);
            }

            else if (strcasecmp(userInput, "exit") == 0) {
              break;
            }

            else {
            // If user input is not a valid clothing type or 'exit', display an error message and continue the loop
            printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n"); 
            }

    }
       
        while (strcasecmp(countryInput, "exit") != 0) 
        {
            printf("Enter the shipping destination (USA, Mexico, Canada):");
            scanf("%s", countryInput);
            float taxrate = 0.0;
            float shipcost = 0.0;
        }
          switch(countryInput[0])
{
            case 'U': 
                country1 = "USA";
                float taxrate = USA_TAX_RATE;
                  printf("Enter the shipping method (standard, expedited):");
                 scanf("%s", shipInput);
                 printf("\n"); 
                 if (strcasecmp(shipInput, "Standard") == 0) {
                float shipcost = USA_STANDARD_SHIPPING;
                ship1 = "Standard";
                  }
                 else {
                float shipcost = USA_EXPEDITED_SHIPPING;               
                      } //usa
              break;
            
              case 'M': 
                country1 = "Mexico";
                taxrate = MEXICO_TAX_RATE;
              printf("Enter the shipping method (standard, expedited):");
              scanf("%s", shipInput);
              printf("\n");  //mexico
              if (strcasecmp(shipInput, "Standard") == 0) {
                float shipcost = MEXICO_STANDARD_SHIPPING;
                ship1 = "Standard";
              }
              else {
               float shipcost = MEXICO_EXPEDITED_SHIPPING;
              }
              break;

            case 'C': 
                country1 = "Canada";
                taxrate = CANADA_TAX_RATE;
              printf("Enter the shipping method (standard, expedited):");
              scanf("%s", shipInput);
              printf("\n"); //canada
              if (strcasecmp(shipInput, "Standard") == 0) {
                float shipcost = CANADA_STANDARD_SHIPPING;
                ship1 = "Standard";
              }
              else 
              {
                float shipcost = CANADA_EXPEDITED_SHIPPING;
              }
            break;

            default:
            printf("Invalid shipping destination. Defaulting to USA standard shipping.\n");
                taxrate = USA_STANDARD_SHIPPING;
                float shipcost = USA_STANDARD_SHIPPING;
            
            break;
}
  // Calculate the total cost based on quantities and prices of each clothing item
  totalCost = (shirtQuantity * SHIRT_PRICE) + (shoeQuantity * SHOE_PRICE) + (pantsQuantity * PANTS_PRICE);

    // Display the formatted bill
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Total Cost:\t\t\t\t\t$%.2f\n", totalCost);

    return 0; // Indicate successful program execution//
    }