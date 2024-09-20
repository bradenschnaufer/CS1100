#include "testdata.h"


const char* testSuite = "Online Ordering Simulator Tests";

const UnitTestData testData[] = {
    { .name = "Garbage Input",
      .input = "jacket\nflipflops\nleggings\nexit\nVenus\nfast",
      .method = string,
      .expected =
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "\n"
        "Enter the shipping destination (USA, Mexico, Canada): Enter the shipping method (standard, expedited): Invalid shipping destination. Defaulting to USA standard shipping.\n"
        "\n"
        "Clothing Item	Quantity	Price		Total\n"
        "-------------------------------------------------------\n"
        "Shirts		0		$19.99		$0.00\n"
        "Shoes		0		$49.99		$0.00\n"
        "Pants		0		$29.99		$0.00\n"
        "-------------------------------------------------------\n"
        "Subtotal:					$0.00\n"
        "Shipping Destination: USA\n"
        "Shipping Method: Standard to USA\n"
        "Shipping Cost:					$5.99\n"
        "Tax (8.00%):					$0.00\n"
        "-------------------------------------------------------\n"
        "Total Cost (including tax and shipping):	$5.99\n"
    },
    { .name = "Order Shirts",
      .input = "shirt\n3\nshirt\n1\nexit\nCanada\nstandard",
      .method = string,
      .expected = 
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Enter the quantity of shirts needed: Clothing item 'shirt' successfully added to your cart.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Enter the quantity of shirts needed: Clothing item 'shirt' successfully added to your cart.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "\n"
        "Enter the shipping destination (USA, Mexico, Canada): Enter the shipping method (standard, expedited): \n"
        "Clothing Item	Quantity	Price		Total\n"
        "-------------------------------------------------------\n"
        "Shirts		1		$19.99		$19.99\n"
        "Shoes		0		$49.99		$0.00\n"
        "Pants		0		$29.99		$0.00\n"
        "-------------------------------------------------------\n"
        "Subtotal:					$19.99\n"
        "Shipping Destination: Canada\n"
        "Shipping Method: Standard to Canada\n"
        "Shipping Cost:					$6.99\n"
        "Tax (12.00%):					$2.40\n"
        "-------------------------------------------------------\n"
        "Total Cost (including tax and shipping):	$29.38\n"
    },
    { .name = "Order Shoes",
      .input = "shoes\n5\nshoes\n3\nexit\nMexico\nexpedited",
      .method = string,
      .expected =
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Enter the quantity of shoes needed: Clothing item 'shoes' successfully added to your cart.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Enter the quantity of shoes needed: Clothing item 'shoes' successfully added to your cart.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "\n"
        "Enter the shipping destination (USA, Mexico, Canada): Enter the shipping method (standard, expedited): \n"
        "Clothing Item	Quantity	Price		Total\n"
        "-------------------------------------------------------\n"
        "Shirts		0		$19.99		$0.00\n"
        "Shoes		3		$49.99		$149.97\n"
        "Pants		0		$29.99		$0.00\n"
        "-------------------------------------------------------\n"
        "Subtotal:					$149.97\n"
        "Shipping Destination: Mexico\n"
        "Shipping Method: Expedited to Mexico\n"
        "Shipping Cost:					$12.99\n"
        "Tax (16.00%):					$24.00\n"
        "-------------------------------------------------------\n"
        "Total Cost (including tax and shipping):	$186.96\n"
    },
    { .name = "Order Pants",
      .input = "pants\n2\npants\n4\nexit\nUSA\nstandard",
      .method = string,
      .expected =
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Enter the quantity of pants needed: Clothing item 'pants' successfully added to your cart.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Enter the quantity of pants needed: Clothing item 'pants' successfully added to your cart.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "\n"
        "Enter the shipping destination (USA, Mexico, Canada): Enter the shipping method (standard, expedited): \n"
        "Clothing Item	Quantity	Price		Total\n"
        "-------------------------------------------------------\n"
        "Shirts		0		$19.99		$0.00\n"
        "Shoes		0		$49.99		$0.00\n"
        "Pants		4		$29.99		$119.96\n"
        "-------------------------------------------------------\n"
        "Subtotal:					$119.96\n"
        "Shipping Destination: USA\n"
        "Shipping Method: Standard to USA\n"
        "Shipping Cost:					$5.99\n"
        "Tax (8.00%):					$9.60\n"
        "-------------------------------------------------------\n"
        "Total Cost (including tax and shipping):	$135.55\n"
    },
    { .name = "New Wardrobe",
      .input = "shirt\n1\nshoes\n1\npants\n1\nexit\nUSA\nexpedited",
      .method = string,
      .expected =
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Enter the quantity of shirts needed: Clothing item 'shirt' successfully added to your cart.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Enter the quantity of shoes needed: Clothing item 'shoes' successfully added to your cart.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "Enter the quantity of pants needed: Clothing item 'pants' successfully added to your cart.\n"
        "Enter the type of clothing needed (shirt, shoes, pants).\n"
        "Type 'exit' to quit and proceed to shipping details.\n"
        "\n"
        "Enter the shipping destination (USA, Mexico, Canada): Enter the shipping method (standard, expedited): \n"
        "Clothing Item	Quantity	Price		Total\n"
        "-------------------------------------------------------\n"
        "Shirts		1		$19.99		$19.99\n"
        "Shoes		1		$49.99		$49.99\n"
        "Pants		1		$29.99		$29.99\n"
        "-------------------------------------------------------\n"
        "Subtotal:					$99.97\n"
        "Shipping Destination: USA\n"
        "Shipping Method: Expedited to USA\n"
        "Shipping Cost:					$9.99\n"
        "Tax (8.00%):					$8.00\n"
        "-------------------------------------------------------\n"
        "Total Cost (including tax and shipping):	$117.96\n"
    },
};

const size_t testCount = sizeof(testData) / sizeof(UnitTestData);
