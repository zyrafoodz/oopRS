#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the Inventory structure
struct Inventory 
{
    int id;
    string name;
    float quantity;
    string unit;
};

struct Recipe
{
    int id;
    string name;
    int serving;
    vector<int> ingredientsIds;
};

//class declaration
class Restaurant {
private:
    vector<Inventory> inventory;
    vector<Recipe> recipes;

public:
    // Constructor to initialize inventory and recipes
    Restaurant(const vector<Inventory>& initialInventory, const vector<Recipe>& initialRecipes)
        : inventory(initialInventory), recipes(initialRecipes) {}

    // Display all recipes
    void displayAllRecipes() {
        cout << "All Recipes:" << endl;
        for (const Recipe& recipe : recipes) {
            printRecipe(recipe);
            cout << endl;
        }
    }

    void displayAllInventory() {
        cout << "All Inventory:" << endl;
        for (const Inventory& inventory : inventory) {
            printInventory(inventory);
            cout << endl;
        }
    }

private:
    // Print recipe details
    void printRecipe(const Recipe& recipe) {
        cout << "Recipe: " << recipe.name << endl;
        cout << "Serving: " << recipe.serving << " people" << endl;
        cout << "Ingredients:" << endl;

        for (int ingredientId : recipe.ingredientsIds) {
            for (const Inventory& item : inventory) {
                if (item.id == ingredientId) {
                    cout << "- " << item.name << ": " << item.quantity << " " << item.unit << endl;
                    break;
                }
            }
        }
    }

    void printInventory(const Inventory& inventory) {
        cout << "Inventory Items:" << endl;
        for (const Inventory& item : inventory) {
            cout << item.id << ": " << item.name << " - "
                << item.quantity << " " << item.unit << endl;
        }
    }

};

int main() {
    vector<Inventory> initialInventory =
    {
        {1, "Lean Pork", 1.5, "lbs"},
        {2, "Pork Fat", 0.75, "lbs"},
        {3, "Duck Legs", 0.5, "cups"},
        {4, "Water", 0.75, "tspns"},
        {5, "Thyme", 1.5, "tspns"},
        {6, "Salt", 1.25, "tspns"},
        {7, "Black Pepper", 0.75, "tspns"},
        {8, "Bay Leaf", 1, "pcs"},
        {9, "Crab Meat", 1, "lbs"},
        {10, "Saltine Crackers", 8, "pcs"},
        {11, "Eggs", 1, "pcs"},
        {12, "Mayonnaise", 2, "tbsps"},
        {13, "Dijon Mustard", 1, "tspns"},
        {14, "Old Bay Seasoning", 0.5, "tspns"},
        {15, "Worcestershire Sauce", 0.25, "tspns"},
        {16, "Vegetable Oil", 1, "tbsps."},
        {17, "Lemon", 1, "pcs"},
        {18, "Tartar Sauce", 1, "pcs"},
        {19, "Mussels", 4, "lbs"},
        {20, "White Wine", 0.5, "cups"},
        {21, "Garlic", 1, "pcs"},
        {22, "Shallots", 0.25, "cups"},
        {23, "Unsalted Butter", 4, "tbsps."},
        {24, "Parsley", 2, "tbsps"},
        {25, "Lemon Juice", 0.25, "cups"},
        {26, "Oysters", 2, "cups"},
        {27, "Cornmeal", 1.5, "cups"},
        {28, "All - Purpose Flour", 2, "tbsps"},
        {29, "Granulated Sugar", 1, "tspns"},
        {30, "Shrimp", 1, "lbs"},
        {31, "Lime Juice", 0.5, "cups"},
        {32, "Tomatoes", 2, "pcs"},
        {33, "Cucumber", 0.5, "pcs"},
        {34, "Red Onion", 0.5, "pcs"},
        {35, "Avocado", 0.5, "pcs"},
        {36, "Serrano Chile", 1, "pcs"},
        {37, "Cilantro", 0.5, "cups"},
        {38, "Olive Oil", 7, "tbsps"},
        {39, "Tortillas", 12, "pcs"}
    };

    vector<Recipe> initialRecipes =
    {
        {1, "French Pork Rillettes", 8, {1, 2, 3, 4, 5, 6, 7, 8}},
        {2, "Maryland Crab Cakes", 6, {9, 10, 11, 12, 13, 14, 15, 6, 16, 17, 18}},
        {3, "Steamed Mussels in White Wine", 4, {19, 20, 21, 22, 7, 23, 24, 25}},
        {4, "Fried Oysters With Cornmeal Batter",6, {26, 11, 16, 27, 28, 6, 7, 29}},
        {5, "Shrimp Ceviche",6, {30, 31, 32, 33, 34, 35, 36, 37, 38, 6, 39}}
    };

    // Create a Restaurant instance
    Restaurant myRestaurant(initialInventory, initialRecipes);

    // Display all recipes
    myRestaurant.displayAllRecipes();

    // Display inventory
    myRestaurant.displayAllInventory();

    // Display empty inventory (optional)
    if (initialInventory.empty()) {
        cout << "Inventory is empty." << endl;
    }

    if (initialRecipes.empty()) {
        cout << "Recipes are empty." << endl;
    }


    return 0;
}
