#include <stdio.h>

int main() {
    int customer_id;
    char customer_name[50];
    float units_consumed, bill_amount, surcharge;

    // Input the customer ID, name, and units consumed
    printf("Enter Customer ID: ");
    scanf("%d", &customer_id);
    getchar(); // To consume the newline character after entering customer ID

    printf("Enter Customer Name: ");
    scanf("%s",customer_name);

    printf("Enter Units Consumed: ");
    scanf("%f", &units_consumed);

    // Calculate bill based on the unit consumption
    if (units_consumed <= 199) {
        bill_amount = units_consumed * 1.20;
    } else if (units_consumed >= 200 && units_consumed < 400) {
        bill_amount = units_consumed * 1.50;
    } else if (units_consumed >= 400 && units_consumed < 600) {
        bill_amount = units_consumed * 1.80;
    } else {
        bill_amount = units_consumed * 2.00;
    }

    // Apply surcharge if the bill exceeds Rs. 400
    if (bill_amount > 400) {
        surcharge = bill_amount * 0.15;
        bill_amount += surcharge;
    }

    // Ensure the minimum bill is Rs. 100
    if (bill_amount < 100) {
        bill_amount = 100;
    }

    // Display the final bill amount
    printf("\nElectricity Bill Details:\n");
    printf("Customer ID: %d\n", customer_id);
    printf("Customer Name: %s\n", customer_name);
    printf("Units Consumed: %.2f\n", units_consumed);
    printf("Total Bill Amount: Rs. %.2f\n", bill_amount);

    return 0;
}

		    
		   
