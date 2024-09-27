// Include necessary header files
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define constants for clothing item prices using macros
#define SHIRT_PRICE 19.99
#define SHOE_PRICE 49.99
#define PANTS_PRICE 29.99

// ship rate
#define USA_STANDARD_SHIPPING 5.99
#define USA_EXPEDITED_SHIPPING 9.99
#define MEXICO_STANDARD_SHIPPING 7.99
#define MEXICO_EXPEDITED_SHIPPING 12.99
#define CANADA_STANDARD_SHIPPING 6.99
#define CANADA_EXPEDITED_SHIPPING 11.99

// tax rate
#define USA_TAX_RATE 0.08
#define MEXICO_TAX_RATE 0.16
#define CANADA_TAX_RATE 0.12

int main(void) {
    // Declare variables
    char userInput[20];    // Array to store user input for clothing type
    char countryInput[20]; // Array to store country
    char shipInput[20];    // Array to store shipping method
    int shirtQuantity = 0, shoeQuantity = 0, pantsQuantity = 0; // Variables to store quantities of each clothing item
    float taxrate = 0;
    float shipcost = 0;
    char *country1 = "USA";  // Default country
    char *ship1 = "Standard"; // Default shipping method

    while (strcasecmp(userInput, "exit") != 0) {
        // Display menu options to the user
        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and proceed to shipping details.\n");
        scanf("%s", userInput); // Read user input for clothing type

	// If user input is not ‘exit’, display a success message for adding the clothing item
        if (strcasecmp(userInput, "shirt") == 0) {
            printf("Enter the quantity of shirts needed: ");
            scanf("%d", &shirtQuantity);
            printf("Clothing item '%s' successfully added to your cart.\n", userInput);
        } else if (strcasecmp(userInput, "shoes") == 0) {
            printf("Enter the quantity of shoes needed: ");
            scanf("%d", &shoeQuantity);
            printf("Clothing item '%s' successfully added to your cart.\n", userInput);
        } else if (strcasecmp(userInput, "pants") == 0) {
            printf("Enter the quantity of pants needed: ");
            scanf("%d", &pantsQuantity);
            printf("Clothing item '%s' successfully added to your cart.\n", userInput);
        } else if (strcasecmp(userInput, "exit") == 0) {
            break;
        } else {
	// If user input is not a valid clothing type or ‘exit’, display an error message and continue the loop
            printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
        }
    }

    while (1) {
        printf("\n");
        printf("Enter the shipping destination (USA, Mexico, Canada): ");
        scanf("%s", countryInput);

        switch (tolower(countryInput[0])) {
            case 'u':  // USA case
                country1 = "USA";
                taxrate = USA_TAX_RATE;

                printf("Enter the shipping method (standard, expedited): ");
                scanf("%s", shipInput);

                if (strcasecmp(shipInput, "standard") == 0) {
                    shipcost = USA_STANDARD_SHIPPING;
                    ship1 = "Standard";
                } else if (strcasecmp(shipInput, "expedited") == 0) {
                    shipcost = USA_EXPEDITED_SHIPPING;
                    ship1 = "Expedited";
                } else {
                    printf("Invalid shipping method. Defaulting to USA standard shipping.\n");
                    shipcost = USA_STANDARD_SHIPPING;
                    ship1 = "Standard";
                }
                break;

            case 'm':  // Mexico case
                country1 = "Mexico";
                taxrate = MEXICO_TAX_RATE;

                printf("Enter the shipping method (standard, expedited): ");
                scanf("%s", shipInput);

                if (strcasecmp(shipInput, "standard") == 0) {
                    shipcost = MEXICO_STANDARD_SHIPPING;
                    ship1 = "Standard";
                } else if (strcasecmp(shipInput, "expedited") == 0) {
                    shipcost = MEXICO_EXPEDITED_SHIPPING;
                    ship1 = "Expedited";
                } else {
                    printf("Invalid shipping method. Defaulting to USA standard shipping.\n");
                    shipcost = MEXICO_STANDARD_SHIPPING;
                    ship1 = "Standard";
                }
                break;

            case 'c':  // Canada case
                country1 = "Canada";
                taxrate = CANADA_TAX_RATE;

                printf("Enter the shipping method (standard, expedited): ");
                scanf("%s", shipInput);

                if (strcasecmp(shipInput, "standard") == 0) {
                    shipcost = CANADA_STANDARD_SHIPPING;
                    ship1 = "Standard";
                } else if (strcasecmp(shipInput, "expedited") == 0) {
                    shipcost = CANADA_EXPEDITED_SHIPPING;
                    ship1 = "Expedited";
                } else {
                    printf("Invalid shipping method. Defaulting to USA standard shipping.\n");
                    shipcost = CANADA_STANDARD_SHIPPING;
                    ship1 = "Standard";
                }
                break;
            case 'v': //venus
                country1 = "USA";
                taxrate = USA_TAX_RATE;

                printf("Enter the shipping method (standard, expedited): ");
                scanf("%s", shipInput);

                if (strcasecmp(shipInput, "standard") == 0) {
                    shipcost = USA_STANDARD_SHIPPING;
                    ship1 = "Standard";
                } else if (strcasecmp(shipInput, "expedited") == 0) {
                    shipcost = USA_EXPEDITED_SHIPPING;
                    ship1 = "Expedited";
                } else {
                    printf("Invalid shipping destination. Defaulting to USA standard shipping.\n");
                    shipcost = USA_STANDARD_SHIPPING;
                    ship1 = "Standard";
                }
                break;

            default:
                printf("Enter the shipping method (standard, expedited): Invalid shipping destination. Defaulting to USA standard shipping.\n");
                country1 = "USA";
                ship1 = "Standard";
                taxrate = USA_TAX_RATE;
                shipcost = USA_STANDARD_SHIPPING;
                break;
        }
        break;
    }

    // Calculate the total cost based on quantities and prices of each clothing item
    float subtotal = (shirtQuantity * SHIRT_PRICE) + (shoeQuantity * SHOE_PRICE) + (pantsQuantity * PANTS_PRICE);
    float tax = subtotal * taxrate;
    float totalCost = subtotal + shipcost + tax;

    // Display the formatted bill
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Subtotal:\t\t\t\t\t$%.2f\n", subtotal);
    printf("Shipping Destination: %s\n", country1);
    printf("Shipping Method: %s to %s\n", ship1, country1);
    printf("Shipping Cost:\t\t\t\t\t$%.2f\n", shipcost);
    printf("Tax (%.2f%%):\t\t\t\t\t$%.2f\n", taxrate * 100, tax);
    printf("-------------------------------------------------------\n");
    printf("Total Cost (including tax and shipping):\t$%.2f\n", totalCost);

    return 0;
}
