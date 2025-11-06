#include "PizzaBuilder.h"
#include <iostream>

PizzaBuilder::PizzaBuilder() {
}

void PizzaBuilder::BuildPizza() {
    std::cout << "=== Pizza Builder ===" << std::endl;
    std::cout << "Let's build your pizza!" << std::endl;

    SelectTomatoes();

    // TODO
    SelectCheese();
   // SelectHerb();
   // SelectMeat();
}

void PizzaBuilder::DisplayFinalPizza() const {
    std::cout << "\n=== Your Pizza ===" << std::endl;
    if (selectedIngredients_.empty()) {
        std::cout << "No ingredients selected." << std::endl;
    } else {
        std::cout << "Your pizza contains:" << std::endl;
        for (const auto& ingredient : selectedIngredients_) {
            std::cout << "- " << ingredient << std::endl;
        }
    }
}

void PizzaBuilder::SelectTomatoes() {

    std::cout << "\n--- Selecting Tomatoes ---" << std::endl;

    // TODO: Reusar esta linea, pero con su propio Repositorio.
    IngredientSelector<TomatoesRepository> selector(tomatoRepo_, availableTomatoes_, "tomato");


    while (true) {
        selector.DisplayAvailableIngredients();

        std::cout << "\nEnter tomato type (or 'done' to finish): ";
        std::string userChoice;
        std::getline(std::cin, userChoice);

        if (userChoice == "done" || userChoice == "DONE") {
            break;
        }

        selector.AddIngredientToPizza(userChoice, selectedIngredients_);
    }
}

// TODO:  Crear cada uno su parte. ☝️ toma el ejemplo de  SelectTomatoes y crea tu propia implementación.


void PizzaBuilder::SelectCheese() {

    std::cout << "\n--- Selecting Cheese ---" << std::endl;

    IngredientSelector<CheeseRepository> selector(cheeseRepo_, availableCheeses_, "cheese");



    while (true) {
        selector.DisplayAvailableIngredients();

        std::cout << "\nEnter Cheese type (or 'done' to finish): ";
        std::string userChoice;
        std::getline(std::cin, userChoice);

        if (userChoice == "done" || userChoice == "DONE") {
            break;
        }

        selector.AddIngredientToPizza(userChoice, selectedIngredients_);
    }
// // Resolver.    
}
//
//void PizzaBuilder::SelectHerb() {
//    // Resolver.    
//}
//
//void PizzaBuilder::SelectMeat() {
//    // Resolver.    
//}