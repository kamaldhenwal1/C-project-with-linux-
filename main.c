#include <stdio.h>

// Function prototypes
void displayWelcomeMessage();
int topUpAccount();
void displayProductMenu();
void handleProductPurchase(char input, int *remaining_soap, int *remaining_shampoo, int *remaining_conditioner,
                          int *remaining_wheat,  int *remaining_oil, int *remaining_chocolate,
                          int *remaining_milk, int *remaining_bread, float *total_cost, int *amount, int *hasPurchased);
void handleSoapPurchase(int *remaining_soap, float *total_cost, int *amount);
void handleShampooPurchase(int *remaining_shampoo, float *total_cost, int *amount);
void handleConditionerPurchase(int *remaining_conditioner, float *total_cost, int *amount);
void handleWheatPurchase(int *remaining_wheat, float *total_cost, int *amount);
void handleOilPurchase(int *remaining_oil, float *total_cost, int *amount);
void handleChocolatePurchase(int *remaining_chocolate, float *total_cost, int *amount);
void handleMilkPurchase(int *remaining_milk, float *total_cost, int *amount);
void handleBreadPurchase(int *remaining_bread, float *total_cost, int *amount);
void displayDenominationBreakdown(int amount);
void displayUpdatedStock(int remaining_soap, int remaining_shampoo, int remaining_conditioner,
                         int remaining_wheat,  int remaining_oil,
                         int remaining_chocolate, int remaining_milk, int remaining_bread);
void applyDiscountAndFinalize(float total_cost, int *amount);

void handleItemRemoval(float *total_cost, int *amount, int *remaining_soap, int *remaining_shampoo,
    int *remaining_conditioner, int *remaining_wheat,  int *remaining_oil,
    int *remaining_chocolate, int *remaining_milk, int *remaining_bread, int *hasPurchased);

int main() {
    displayWelcomeMessage();
    int amount = topUpAccount();
    char input;
    float total_cost = 0.0;
    int hasPurchased = 0;

    // Initialize stock quantities
    int remaining_soap = 10, remaining_shampoo = 5, remaining_conditioner = 8;
    int remaining_wheat = 20,  remaining_oil = 12;
    int remaining_chocolate = 10, remaining_milk = 15, remaining_bread = 20;

    // Main shopping loop
    while (1) {
        displayProductMenu();
        scanf(" %c", &input);

        // Handle purchase
        if (input != 'e' && input != 'E' && input != 'r' && input != 'R') {
            handleProductPurchase(input, &remaining_soap, &remaining_shampoo, &remaining_conditioner,
                                  &remaining_wheat, &remaining_oil, &remaining_chocolate,
                                  &remaining_milk, &remaining_bread, &total_cost, &amount, &hasPurchased);
        }

        // Exit condition
        if (input == 'e' || input == 'E') {
            break;  // Exit if user chooses to exit
        }

        // Remove product
        else if (input == 'r' || input == 'R') {
            handleItemRemoval(&total_cost, &amount, &remaining_soap, &remaining_shampoo, &remaining_conditioner,
                              &remaining_wheat,  &remaining_oil, &remaining_chocolate,
                              &remaining_milk, &remaining_bread, &hasPurchased);
        }
    }
    // Display final outputs
    displayDenominationBreakdown(amount);
    displayUpdatedStock(remaining_soap, remaining_shampoo, remaining_conditioner,
                        remaining_wheat, remaining_oil,
                        remaining_chocolate, remaining_milk, remaining_bread);
    applyDiscountAndFinalize(total_cost, &amount);

    return 0;
}

// New Function to handle item removal
void handleItemRemoval(float *total_cost, int *amount, int *remaining_soap, int *remaining_shampoo, int *remaining_conditioner,
    int *remaining_wheat,  int *remaining_oil, int *remaining_chocolate,
    int *remaining_milk, int *remaining_bread, int *hasPurchased) {
char item;
int quantity;
int f;
float price = 0.0;
printf("Enter the product you want to remove:\n");
printf("d - soap\ns - Shampoo\nc - Conditioner\nw - Wheat\no - Oil\nC - Chocolate\nm - Milk\nb - Bread\n");
printf("Enter your choice: ");
scanf(" %c", &item);

switch (item) {
    case 'd':
    while (1) {
        printf("Enter the quantity of soap you want to remove: ");
        printf("1 - Santoor (Price: 47 rupees)\n");
        printf("2 - Dettol (Price: 40 rupees)\n");
        printf("3 - Lifebuoy (Price: 35 rupees)\n");
        printf("4 - Joy (Price: 43 rupees)\n");
        printf("5 - Dove (Price: 50 rupees)\n");
        printf("6 - Cinthol (Price: 85 rupees)\n");
        printf("Enter your choice (1-6) or '0' to exit: ");

        scanf("%d", &quantity);
        if (quantity == 0) break;  // Exit loop if user inputs 0

        switch (quantity) {
            case 1: price = 47.0; break;
            case 2: price = 40.0; break;
            case 3: price = 35.0; break;
            case 4: price = 43.0; break;
            case 5: price = 50.0; break;
            case 6: price = 85.0; break;
            default:
                printf("Invalid choice! Please select a valid Soap type.\n");
                continue;  // Continue asking for valid input
        }

        printf("Please enter the quantity: ");
        scanf("%d", &f);

        if (f > *remaining_soap) {
            printf("You have less than %d soap(s) in stock. You can only remove up to %d.\n", f, *remaining_soap);
            continue;  // Retry the operation without exiting the loop
        }

        *remaining_soap -= f;  // Correctly decrease stock
        *total_cost -= (price * f);  // Adjust the total cost
        *amount += (price * f);  // Update the balance

        printf("Removed %d soap(s). New total cost: %.2f, New balance: %.2f.\n", f, *total_cost, *amount);
        break;  // Exit the while loop after successful operation
    }
    break;
    case 's':
    while (1) {
        printf("Enter the quantity of shampoo you want to remove: \n");
        printf("1 - Dettol Shampoo (Price: 120 rupees)\n");
        printf("2 - Clinic Plus (Price: 130 rupees)\n");
        printf("3 - Sunsilk (Price: 140 rupees)\n");
        printf("4 - Head & Shoulders (Price: 160 rupees)\n");
        printf("5 - Pantene (Price: 180 rupees)\n");
        printf("6 - Himalaya (Price: 110 rupees)\n");
        printf("7 - Patanjali (Price: 100 rupees)\n");
        printf("Enter your choice (1-7) or '0' to exit: ");

        scanf("%d", &quantity);
        if (quantity == 0) break;  // Exit loop if user inputs 0

        switch (quantity) {
            case 1: price = 120.0; break;
            case 2: price = 130.0; break;
            case 3: price = 140.0; break;
            case 4: price = 160.0; break;
            case 5: price = 180.0; break;
            case 6: price = 110.0; break;
            case 7: price = 100.0; break;
            default:
                printf("Invalid choice! Please select a valid Shampoo type.\n");
                continue;  // Continue asking for valid input
        }

        printf("Please enter the quantity: ");
        scanf("%d", &f);

        if (f > *remaining_shampoo) {
            printf("You have less than %d shampoo(s) in stock. You can only remove up to %d.\n", f, *remaining_shampoo);
            continue;  // Retry the operation without exiting the loop
        }

        *remaining_shampoo -= f;  // Correctly decrease stock
        *total_cost -= (price * f);  // Adjust the total cost
        *amount += (price * f);  // Update the balance

        printf("Removed %d shampoo(s). New total cost: %.2f, New balance: %.2f.\n", f, *total_cost, *amount);
        break;  // Exit the while loop after successful operation
    }
    break;

case 'm':
    while (1) {
        printf("Enter the quantity of milk you want to remove: \n");
        printf("1 - Flavored Milk (Price: 50 rupees)\n");
        printf("2 - Toned Milk (Price: 47 rupees)\n");
        printf("3 - Full Cream Milk (Price: 60 rupees)\n");
        printf("Enter your choice (1-3) or '0' to exit: ");

        scanf("%d", &quantity);
        if (quantity == 0) break;  // Exit loop if user inputs 0

        switch (quantity) {
            case 1: price = 50.0; break;
            case 2: price = 47.0; break;
            case 3: price = 60.0; break;
            default:
                printf("Invalid choice! Please select a valid milk type.\n");
                continue;  // Continue asking for valid input
        }

        printf("Please enter the quantity: ");
        scanf("%d", &f);

        if (f > *remaining_milk) {
            printf("You have less than %d milk(s) in stock. You can only remove up to %d.\n", f, *remaining_milk);
            continue;  // Retry the operation without exiting the loop
        }

        *remaining_milk -= f;  // Correctly decrease stock
        *total_cost -= (price * f);  // Adjust the total cost
        *amount += (price * f);  // Update the balance

        printf("Removed %d milk(s). New total cost: %.2f, New balance: %.2f.\n", f, *total_cost, *amount);
        break;  // Exit the while loop after successful operation
    }
    break;

case 'b':
    while (1) {
        printf("Enter the quantity of bread you want to remove: \n");
        printf("1 - White Bread (Price: 30 rupees)\n");
        printf("2 - Wheat Bread (Price: 40 rupees)\n");
        printf("3 - Brown Bread (Price: 50 rupees)\n");
        printf("4 - Multigrain Bread (Price: 60 rupees)\n");
        printf("Enter your choice (1-4) or '0' to exit: ");

        scanf("%d", &quantity);
        if (quantity == 0) break;  // Exit loop if user inputs 0

        switch (quantity) {
            case 1: price = 30.0; break;
            case 2: price = 40.0; break;
            case 3: price = 50.0; break;
            case 4: price = 60.0; break;
            default:
                printf("Invalid choice! Please select a valid Bread type.\n");
                continue;  // Continue asking for valid input
        }

        printf("Please enter the quantity: ");
        scanf("%d", &f);

        if (f > *remaining_bread) {
            printf("You have less than %d bread(s) in stock. You can only remove up to %d.\n", f, *remaining_bread);
            continue;  // Retry the operation without exiting the loop
        }

        *remaining_bread -= f;  // Correctly decrease stock
        *total_cost -= (price * f);  // Adjust the total cost
        *amount += (price * f);  // Update the balance

        printf("Removed %d bread(s). New total cost: %.2f, New balance: %.2f.\n", f, *total_cost, *amount);
        break;  // Exit the while loop after successful operation
    }
    break;

case 'C':
    while (1) {
        printf("Enter the quantity of chocolate you want to remove: \n");
        printf("1 - Dark Chocolate (Price: 200 rupees)\n");
        printf("2 - Milk Chocolate (Price: 150 rupees)\n");
        printf("3 - White Chocolate (Price: 180 rupees)\n");
        printf("4 - Cocoa Powder (Price: 250 rupees)\n");
        printf("Enter your choice (1-4) or '0' to exit: ");

        scanf("%d", &quantity);
        if (quantity == 0) break;  // Exit loop if user inputs 0

        switch (quantity) {
            case 1: price = 200.0; break;
            case 2: price = 150.0; break;
            case 3: price = 180.0; break;
            case 4: price = 250.0; break;
            default:
                printf("Invalid choice! Please select a valid chocolate type.\n");
                continue;  // Continue asking for valid input
        }

        printf("Please enter the quantity: ");
        scanf("%d", &f);

        if (f > *remaining_chocolate) {
            printf("You have less than %d chocolate(s) in stock. You can only remove up to %d.\n", f, *remaining_chocolate);
            continue;  // Retry the operation without exiting the loop
        }

        *remaining_chocolate -= f;  // Correctly decrease stock
        *total_cost -= (price * f);  // Adjust the total cost
        *amount += (price * f);  // Update the balance

        printf("Removed %d chocolate(s). New total cost: %.2f, New balance: %.2f.\n", f, *total_cost, *amount);
        break;  // Exit the while loop after successful operation
    }
    break;

case 'c':
    while (1) {
        printf("Enter the quantity of conditioner you want to remove: \n");
        printf("1. Pantene (Price: 150 rupees)\n");
        printf("2. Dove (Price: 170 rupees)\n");
        printf("3. TRESemme (Price: 200 rupees)\n");
        printf("4. MamaEarth (Price: 850 rupees)\n");
        printf("5. Pilgrim (Price: 350 rupees)\n");
        printf("Enter your choice (1-5) or '0' to exit: ");

        scanf("%d", &quantity);
        if (quantity == 0) break;  // Exit loop if user inputs 0

        switch (quantity) {
            case 1: price = 150.0; break;
            case 2: price = 170.0; break;
            case 3: price = 200.0; break;
            case 4: price = 850.0; break;
            case 5: price = 350.0; break;
            default:
                printf("Invalid choice! Please select a valid conditioner type.\n");
                continue;  // Continue asking for valid input
        }

        printf("Please enter the quantity: ");
        scanf("%d", &f);

        if (f > *remaining_conditioner) {
            printf("You have less than %d conditioner(s) in stock. You can only remove up to %d.\n", f, *remaining_conditioner);
            continue;  // Retry the operation without exiting the loop
        }

        *remaining_conditioner -= f;  // Correctly decrease stock
        *total_cost -= (price * f);  // Adjust the total cost
        *amount += (price * f);  // Update the balance

        printf("Removed %d conditioner(s). New total cost: %.2f, New balance: %.2f.\n", f, *total_cost, *amount);
        break;  // Exit the while loop after successful operation
    }
    break;

case 'w':
    while (1) {
        printf("Enter the quantity of wheat you want to remove: \n");
        printf("1. Hard Red Wheat (Price: 35 rupees per kg)\n");
        printf("2. Hard Red Spring Wheat (Price: 40 rupees per kg)\n");
        printf("3. Soft Red Wheat (Price: 30 rupees per kg)\n");
        printf("4. Durum Wheat (Price: 50 rupees per kg)\n");
        printf("5. Hard White Wheat (Price: 45 rupees per kg)\n");
        printf("6. Soft White Wheat (Price: 40 rupees per kg)\n");
        printf("Enter your choice (1-6) or '0' to exit: ");

        scanf("%d", &quantity);
        if (quantity == 0) break;  // Exit loop if user inputs 0

        switch (quantity) {
            case 1: price = 35.0; break;
            case 2: price = 40.0; break;
            case 3: price = 30.0; break;
            case 4: price = 50.0; break;
            case 5: price = 45.0; break;
            case 6: price = 40.0; break;
            default:
                printf("Invalid choice! Please select a valid wheat type.\n");
                continue;  // Continue asking for valid input
        }

        printf("Please enter the quantity: ");
        scanf("%d", &f);

        if (f > *remaining_wheat) {
            printf("You have less than %d wheat(s) in stock. You can only remove up to %d.\n", f, *remaining_wheat);
            continue;  // Retry the operation without exiting the loop
        }

        *remaining_wheat -= f;  // Correctly decrease stock
        *total_cost -= (price * f);  // Adjust the total cost
        *amount += (price * f);  // Update the balance

        printf("Removed %d wheat(s). New total cost: %.2f, New balance: %.2f.\n", f, *total_cost, *amount);
        break;  // Exit the while loop after successful operation
    }
    break;



case 'o':
    while (1) {
        printf("Enter the quantity of oil you want to remove: \n");
        printf("1. Sunflower Oil (Price: 200 rupees per liter)\n");
        printf("2. Groundnut Oil (Price: 220 rupees per liter)\n");
        printf("3. Mustard Oil (Price: 180 rupees per liter)\n");
        printf("4. Olive Oil (Price: 500 rupees per liter)\n");
        printf("Enter your choice (1-4) or '0' to exit: ");

        scanf("%d", &quantity);
        if (quantity == 0) break;  // Exit loop if user inputs 0

        switch (quantity) {
            case 1: price = 200.0; break;
            case 2: price = 220.0; break;
            case 3: price = 180.0; break;
            case 4: price = 500.0; break;
            default:
                printf("Invalid choice! Please select a valid oil type.\n");
                continue;  // Continue asking for valid input
        }

        printf("Please enter the quantity: ");
        scanf("%d", &f);

        if (f > *remaining_oil) {
            printf("You have less than %d oil(s) in stock. You can only remove up to %d.\n", f, *remaining_oil);
            continue;  // Retry the operation without exiting the loop
        }

        *remaining_oil -= f;  // Correctly decrease stock
        *total_cost -= (price * f);  // Adjust the total cost
        *amount += (price * f);  // Update the balance

        printf("Removed %d oil(s). New total cost: %.2f, New balance: %.2f.\n", f, *total_cost, *amount);
        break;  // Exit the while loop after successful operation
    }
    break;

    
default:
printf("Invalid product choice.\n");
break;
}
*hasPurchased = 1;
}

// Function to display the welcome message
void displayWelcomeMessage() {
    printf("Welcome to Kampal General Store.\n");
}

// Function to top up the account balance
int topUpAccount() {
    int amount;
    printf("Please top up your account balance, please enter amount to add: \n");
    scanf("%d", &amount);
    return amount;
}

// Function to display the product menu
void displayProductMenu() {
    printf("\nEnter the product you want to buy (or 'e' to exit) (or 'r' to remove):\n");
    printf("d - soap\ns - Shampoo\nc - Conditioner\nw - Wheat\no - Oil\nC - Chocolate\nm - Milk\nb - Bread\n");
    printf("Enter 'e' to exit (or 'r' to remove).\n");
}

// Function to handle product purchase based on user input
void handleProductPurchase(char input, int *remaining_soap, int *remaining_shampoo, int *remaining_conditioner,
                          int *remaining_wheat,  int *remaining_oil, int *remaining_chocolate,
                          int *remaining_milk, int *remaining_bread, float *total_cost, int *amount,int *hasPurchased) {
    switch (input) {
        case 'd':
            handleSoapPurchase(remaining_soap, total_cost, amount);
            break;
        case 's':
        handleShampooPurchase(remaining_shampoo, total_cost, amount);
            break;
        case 'c':
        handleConditionerPurchase(remaining_conditioner, total_cost, amount);
            break;
        case 'w':
            handleWheatPurchase(remaining_wheat, total_cost, amount);
            break;
        /*case 'r':
            handleRicePurchase(remaining_rice, total_cost, amount);
            break;*/
        case 'o':
            handleOilPurchase(remaining_oil, total_cost, amount);
            break;
        case 'C':
            handleChocolatePurchase(remaining_chocolate, total_cost, amount);
            break;
        case 'm':
            handleMilkPurchase(remaining_milk, total_cost, amount);
            break;
        case 'b':
            handleBreadPurchase(remaining_bread, total_cost, amount);
            break;
        default:
            printf("Product not available.\n");
            break;
    }
}

// Function to handle soap purchase
void handleSoapPurchase(int *remaining_soap, float *total_cost, int *amount) {
    int choice, quantity;
    float price = 0.0;

    printf("Select a soap:\n");
    printf("1 - Santoor (Price: 47 rupees)\n");
    printf("2 - Dettol (Price: 40 rupees)\n");
    printf("3 - Lifebuoy (Price: 35 rupees)\n");
    printf("4 - Joy (Price: 43 rupees)\n");
    printf("5 - Dove (Price: 50 rupees)\n");
    printf("6 - Cinthol (Price: 85 rupees)\n");
    printf("Enter your choice (1-6) or 'e' to exit: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            price = 47.0;
            break;
        case 2:
            price = 40.0;
            break;
        case 3:
            price = 35.0;
            break;
        case 4:
            price = 43.0;
            break;
        case 5:
            price = 50.0;
            break;
        case 6:
            price = 85.0;
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("Please enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity > *remaining_soap) {
        printf("Sorry, we don't have enough soap in stock. You can buy up to %d soap.\n", *remaining_soap);
        return;
    }

    *remaining_soap -= quantity;
    *total_cost += price * quantity;
    *amount -= price * quantity;

    printf("You bought %d soap(s) for %.2f rupees. Remaining balance: %d rupees.\n", quantity, price * quantity, *amount);
}

// Similar functions for other products (handleShampooPurchase, handleConditionerPurchase, etc.) should be implemented similarly.

void handleShampooPurchase(int *remaining_shampoo, float *total_cost, int *amount) {
    int choice, quantity;
    float price = 0.0;

printf("Select a shampoo:\n");
printf("1 - Dettol Shampoo (Price: 120 rupees)\n");
printf("2 - Clinic Plus (Price: 130 rupees)\n");
printf("3 - Sunsilk (Price: 140 rupees)\n");
printf("4 - Head & Shoulders (Price: 160 rupees)\n");
printf("5 - Pantene (Price: 180 rupees)\n");
printf("6 - Himalaya (Price: 110 rupees)\n");
printf("7 - Patanjali (Price: 100 rupees)\n");
printf("Enter your choice (1-7) or 'e' to exit: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
    price = 120.0;
    break;
    case 2:
    price = 130.0;
     break;
    case 3:
    price = 140.0;
    break;
    case 4:
    price = 160.0;
    break;
    case 5:
    price = 180.0;
    break;
    case 6:
    price = 110.0;
    break;
    case 7:
    price = 100.0;
    break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("Please enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity > *remaining_shampoo) {
        printf("Sorry, we don't have enough shampoo in stock. You can buy up to %d shampoo.\n", *remaining_shampoo);
        return;
    }

    *remaining_shampoo -= quantity;
    *total_cost += price * quantity;
    *amount -= price * quantity;

    printf("You bought %d shampoo(s) for %.2f rupees. Remaining balance: %d rupees.\n", quantity, price * quantity, *amount);
}

void handleConditionerPurchase(int *remaining_conditioner, float *total_cost, int *amount) {
    int choice, quantity;
    float price = 0.0;

printf("Select a Conditioner:\n");
    printf("1. Pantene (Price: 150 rupees)\n");
    printf("2. Dove (Price: 170 rupees)\n");
    printf("3. TRESemme (Price: 200 rupees)\n");
    printf("4. MamaEarth (Price: 850 rupees)\n");
    printf("5. Pilgrim (Price: 350 rupees)\n");
    printf("Enter your choice (1-5) or 'e' to exit: ");
    scanf("%d", &choice);

    switch (choice) {
 case 1:
price = 150.0;
break;
        case 2:
price = 170.0;
break;
        case 3:
price = 200.0;
break;
        case 4:
        price = 850.0;
break;
        case 5:
        price = 350.0;
break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("Please enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity > *remaining_conditioner) {
        printf("Sorry, we don't have enough Conditioner in stock. You can buy up to %d soap.\n", *remaining_conditioner);
        return;
    }

    *remaining_conditioner -= quantity;
    *total_cost += price * quantity;
    *amount -= price * quantity;

    printf("You bought %d Conditioner(s) for %.2f rupees. Remaining balance: %d rupees.\n", quantity, price * quantity, *amount);
}

void handleWheatPurchase(int *remaining_wheat, float *total_cost, int *amount) {
    int choice, quantity;
    float price = 0.0;

printf("Select a Wheat Type:\n");
                printf("1. Hard Red Wheat (Price: 35 rupees per kg)\n");
                printf("2. Hard Red Spring Wheat (Price: 40 rupees per kg)\n");
                printf("3. Soft Red Wheat (Price: 30 rupees per kg)\n");
                printf("4. Durum Wheat (Price: 50 rupees per kg)\n");
                printf("5. Hard White Wheat (Price: 45 rupees per kg)\n");
                printf("6. Soft White Wheat (Price: 40 rupees per kg)\n");
                printf("Enter your choice (1-6) or 'e' to exit: ");
    scanf("%d", &choice);

    switch (choice) {
case 1:
                        price = 35.0;
                        break;
                    case 2:
                        price = 40.0;
                        break;
                    case 3:
                        price = 30.0;
                        break;
                    case 4:
                        price = 50.0;
                        break;
                    case 5:
                       price = 45.0;
                        break;
                    case 6:
                       price = 40.0;

                        break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("Please enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity > *remaining_wheat) {
        printf("Sorry, we don't have enough wheat in stock. You can buy up to %d wheat.\n", *remaining_wheat);
        return;
    }

    *remaining_wheat -= quantity;
    *total_cost += price * quantity;
    *amount -= price * quantity;

    printf("You bought %d wheat(s) for %.2f rupees. Remaining balance: %d rupees.\n", quantity, price * quantity, *amount);
}


void handleOilPurchase(int *remaining_oil, float *total_cost, int *amount) {
    int choice, quantity;
    float price = 0.0;

printf("Select an oil:\n");
                    printf("1 - Coconut Oil (Price: 150 rupees)\n");
                    printf("2 - Vegetable Oil (Price: 90 rupees)\n");
                    printf("3 - Til Oil (Price: 120 rupees)\n");
                    printf("4 - Hair Oil (Price: 200 rupees)\n");
                    printf("5 - Olive Oil (Price: 300 rupees)\n");
                    printf("6 - Ghee (Price: 500 rupees)\n");
                    printf("7 - Peanut Oil (Price: 100 rupees)\n");
                    printf("8 - Walnut Oil (Price: 250 rupees)\n");
                    printf("Enter your choice (1-8) or 'e' to exit: ");
    scanf("%d", &choice);

    switch (choice) {
   case 1:
                            price = 150.0;
                            break;
                        case 2:
                            price = 90.0;
                            break;
                        case 3:
                            price = 120.0;
                            break;
                        case 4:
                            price = 200.0;
                            break;
                        case 5:
                            price = 300.0;
                            break;
                        case 6:
                            price = 500.0;
                            break;
                        case 7:
                           price = 100.0;
                            break;
                        case 8:
                            price = 250.0;
                            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("Please enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity > *remaining_oil) {
        printf("Sorry, we don't have enough oil in stock. You can buy up to %d oil.\n", *remaining_oil);
        return;
    }

    *remaining_oil -= quantity;
    *total_cost += price * quantity;
    *amount -= price * quantity;

    printf("You bought %d oil(s) for %.2f rupees. Remaining balance: %d rupees.\n", quantity, price * quantity, *amount);
}

void handleChocolatePurchase(int *remaining_chocolate, float *total_cost, int *amount) {
    int choice, quantity;
    float price = 0.0;

 printf("Select a chocolate:\n");
printf("1 - Dark Chocolate (Price: 200 rupees)\n");
printf("2 - Milk Chocolate (Price: 150 rupees)\n");
printf("3 - White Chocolate (Price: 180 rupees)\n");
printf("4 - Cocoa Powder (Price: 250 rupees)\n");
printf("Enter your choice (1-4) or 'e' to exit: ");
    scanf("%d", &choice);

    switch (choice) {
case 1:
                            price = 200.0;
                            break;
                        case 2:
                            price = 150.0;
                            break;
                        case 3:
                            price = 180.0;
                            break;
                        case 4:
                            price = 250.0;
                            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("Please enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity > *remaining_chocolate) {
        printf("Sorry, we don't have enough chocolate in stock. You can buy up to %d chocolate.\n", *remaining_chocolate);
        return;
    }

    *remaining_chocolate -= quantity;
    *total_cost += price * quantity;
    *amount -= price * quantity;

    printf("You bought %d chocolate(s) for %.2f rupees. Remaining balance: %d rupees.\n", quantity, price * quantity, *amount);
}

void handleMilkPurchase(int *remaining_milk, float *total_cost, int *amount) {
    int choice, quantity;
    float price = 0.0;

printf("Choose the type of Milk:\n");
printf("1 - Flavored Milk (Price: 50 rupees)\n");
printf("2 - Toned Milk (Price: 47 rupees)\n");
printf("3 - Full Cream Milk (Price: 60 rupees)\n");
printf("Enter your choice (1-3) or 'e' to exit: ");
    scanf("%d", &choice);

    switch (choice) {
   case 1:
                            price = 50.0;
                            break;
                        case 2:
                           price = 47.0;
                            break;
                        case 3:
                            price = 60.0;
                            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("Please enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity > *remaining_milk) {
        printf("Sorry, we don't have enough milk in stock. You can buy up to %d milk.\n", *remaining_milk);
        return;
    }

    *remaining_milk -= quantity;
    *total_cost += price * quantity;
    *amount -= price * quantity;

    printf("You bought %d milk(s) for %.2f rupees. Remaining balance: %d rupees.\n", quantity, price * quantity, *amount);
}

void handleBreadPurchase(int *remaining_bread, float *total_cost, int *amount) {
    int choice, quantity;
    float price = 0.0;

printf("Select a bread:\n");
printf("1 - White Bread (Price: 30 rupees)\n");
printf("2 - Wheat Bread (Price: 40 rupees)\n");
printf("3 - Brown Bread (Price: 50 rupees)\n");
printf("4 - Multigrain Bread (Price: 60 rupees)\n");
printf("Enter your choice (1-4) or 'e' to exit: ");
    scanf("%d", &choice);

    switch (choice) {
case 1:
                            price = 30.0;
                            break;
                        case 2:
                            price = 40.0;
                            break;
                        case 3:
                            price = 50.0;
                            break;
                        case 4:
                            price = 60.0;
                            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("Please enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity > *remaining_bread) {
        printf("Sorry, we don't have enough bread in stock. You can buy up to %d bread.\n", *remaining_bread);
        return;
    }

    *remaining_bread -= quantity;
    *total_cost += price * quantity;
    *amount -= price * quantity;

    printf("You bought %d bread(s) for %.2f rupees. Remaining balance: %d rupees.\n", quantity, price * quantity, *amount);
}

// Function to display the denomination breakdown
void displayDenominationBreakdown(int amount) {
    int denominations[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int count[9] = {0};

    for (int i = 0; i < 9; i++) {
        if (amount >= denominations[i]) {
            count[i] = amount / denominations[i];
            amount %= denominations[i];
        }
    }

    printf("\nDenomination breakdown:\n");
    for (int i = 0; i < 9; i++) {
        if (count[i] > 0) {
            printf("%d rupees: %d\n", denominations[i], count[i]);
        }
    }
}

// Function to display updated stock
void displayUpdatedStock(int remaining_soap, int remaining_shampoo, int remaining_conditioner,
                         int remaining_wheat,  int remaining_oil,
                         int remaining_chocolate, int remaining_milk, int remaining_bread) {
    printf("\nUpdated available products:\n");
    printf("Soap: %d\n", remaining_soap);
    printf("Shampoo: %d\n", remaining_shampoo);
    printf("Conditioner: %d\n", remaining_conditioner);
    printf("Wheat: %d\n", remaining_wheat);
    
    printf("Oil: %d\n", remaining_oil);
    printf("Chocolate: %d\n", remaining_chocolate);
    printf("Milk: %d\n", remaining_milk);
    printf("Bread: %d\n", remaining_bread);
}

// Function to apply discount and finalize the transaction
void applyDiscountAndFinalize(float total_cost, int *amount) {
    float discount_percentage = 0.0;
    int vip_months = 0;

    if (total_cost >= 10000) {
        discount_percentage = 20.0;
        vip_months = 5;
    } else if (total_cost >= 8000) {
        discount_percentage = 30.0;
    } else if (total_cost >= 5000) {
        discount_percentage = 20.0;
    } else if (total_cost >= 2000) {
        discount_percentage = 10.0;
    }

    float discount_amount = (discount_percentage / 100) * total_cost;
    float final_amount = total_cost - discount_amount;
    *amount -= final_amount;

    printf("******BILL!!******\nThank you for shopping with us!\n");
    printf("Total amount spent: %.2f rupees.\n", total_cost);
    printf("Discount applied: %.2f%%\n", discount_percentage);
    printf("Amount after discount: %.2f rupees.\n", final_amount);
    printf("The remaining balance is %d rupees.\n", *amount);

    if (vip_months > 0) {
        printf("Congratulations! You've earned a %d-month VIP membership with exclusive benefits like additional discounts, free products, and early access to new stock.\n", vip_months);
    }
}
