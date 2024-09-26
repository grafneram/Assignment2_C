//Ashley Grafner
//CS 2060
//Assignment 2
/*
 * This program displays special offer details and calculates total price.
 * For each item: "Walmart has special offer on <item name> for price <n>, when you buy <x>, you get <y> % off on next two".
 * It then calculates and displays the total price for each item in the format:
 * "I bought <Quantity> of the <item name> for <N> each on offer buy <X> get <Y> off on next two for a total price of <total price>".
 */

#include <stdio.h>

int main() { // main method, type int

    char* item_names[] = {"Live Basil plant", "Lodge Cast Iron Skillet", "Ninja Foodi"}; // item names
    float item_prices[] = {6.99, 29.99, 65.99}; // item prices
    int buy_x[] = {3, 1, 2}; // x number to get discount
    int discount_y[] = {75, 25, 35}; // discount percentage
    int quantities[] = {5, 3, 2}; // amount bought

    // Process each item
    for (int i = 0; i < 3; i++) { // Loop through the first three items (0, 1, and 2)
        double price = item_prices[i]; // Get the price of the current item from the item_prices array
        int x = buy_x[i]; // Get the number of units to buy for the current item from the buy_x array
        int y = discount_y[i]; // Get the discount amount for the current item from the discount_y array
        int quantity = quantities[i]; // Get the quantity of the current item being purchased from the quantities array

        // Calculate full price items
        int full_price_qty = quantity > x ? x : quantity; // Only x items are full price or less if quantity < x

        // Calculate discounted items
        int discount_qty = quantity - full_price_qty > 2 ? 2 : quantity - full_price_qty; // Only next two items get a discount

        // Calculate discount price
        float discount = price * (y / 100.0); // Calculate the discount amount per discounted item
        float discounted_price = price - discount; // Calculate the discounted price per item

        // Calculate total price
        float total_price = (full_price_qty * price) + (discount_qty * discounted_price) + ((quantity - full_price_qty - discount_qty) * price);

        // Print offer details for each item
        printf("Walmart has special offer on %s for price $%.2f, when you buy %d, you get %d%% off on next two.\n",
               item_names[i], price, x, y);

        // Print total price details for each item
        printf("I bought %d of the %s for $%.2f each on offer buy %d get %d%% off on next 2 with a total price $%.2f\n\n",
               quantity, item_names[i], price, x, y, total_price);
    }
    return 0; // return 0 because main is type int
}


