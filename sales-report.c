#include <stdio.h>
#include <stdlib.h>

// Defining a constant for number of months in a year
#define MONTHS 12

// Function declarations
void printMonthlyReport(double sales[]);
void printSalesSummary(double sales[]);
void printMovingAverages(double sales[]);
void printSalesHighToLow(double sales[]);

    // Array of month names
const char *months[MONTHS] = {"January", "February", "March", "April", "May", "June", 
                                  "July", "August", "September", "October", "November", "December"};

// Function to get the month's name from its index
const char* getMonthName(int index) {
    return months[index];
}

// Main function
int main() {
    // Open the input file for reading
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read sales data from file
    double sales[MONTHS];
    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]);
    }
    fclose(file);

    // Print the various sales reports
    printMonthlyReport(sales);
    printSalesSummary(sales);
    printMovingAverages(sales);
    printSalesHighToLow(sales);
    return 0;
}

// Function to print the monthly sales report
void printMonthlyReport(double sales[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month Sales\n");
    // Array of month names
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", months[i], sales[i]);
    }
    printf("\n");
}

// Function to print a summary of sales including min, max, and average sales
void printSalesSummary(double sales[]) {
    double min = sales[0], max = sales[0], total = 0.0;
    int minMonth = 0, maxMonth = 0;
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        total += sales[i];
    }
    printf("Sales summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", min, getMonthName(minMonth));
    printf("Maximum sales: $%.2lf (%s)\n", max, getMonthName(maxMonth));
    printf("Average sales: $%.2lf\n\n", total / MONTHS);
}

// Function to print six-month moving averages of sales
void printMovingAverages(double sales[]) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < MONTHS - 5; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s - %s $%.2lf\n", getMonthName(i), getMonthName(i+5), sum / 6.0);
    }
    printf("\n");
}

// Function to print sales from highest to lowest
void printSalesHighToLow(double sales[]) {
    typedef struct {
        double value;
        int index;
    } SaleData;

    // Create an array of sales data structures
    SaleData sortedSales[MONTHS];
    for (int i = 0; i < MONTHS; i++) {
        sortedSales[i].value = sales[i];
        sortedSales[i].index = i;
    }

    // Sort the sales in descending order
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            if (sortedSales[j].value < sortedSales[j + 1].value) {
                SaleData temp = sortedSales[j];
                sortedSales[j] = sortedSales[j + 1];
                sortedSales[j + 1] = temp;
            }
        }
    }

    // Print the sorted sales
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", getMonthName(sortedSales[i].index), sortedSales[i].value);
    }
    printf("\n");
}
