#include "IngredientSelector.h"
#include <iostream>

template<typename TRepository>
IngredientSelector<TRepository>::IngredientSelector(TRepository& repository, const std::vector<std::string>& availableItems, const std::string& ingredientType)
    : repository_(repository), availableItems_(availableItems), ingredientType_(ingredientType) {
}

template<typename TRepository>
void IngredientSelector<TRepository>::DisplayAvailableIngredients() {
    std::cout << "\nAvailable " << ingredientType_ << " types:" << std::endl;
    for (const auto& item : availableItems_) {
        try {
            int quantity = repository_.GetAvailableQuantity(item);
            std::cout << "- " << item << " (Available: " << quantity << ")" << std::endl;
        } catch (const std::invalid_argument&) {
            std::cout << "- " << item << " (Not available)" << std::endl;
        }
    }
}

template<typename TRepository>
bool IngredientSelector<TRepository>::AddIngredientToPizza(const std::string& ingredientName, std::vector<std::string>& selectedIngredients) {
    try {
        int quantity = repository_.GetAvailableQuantity(ingredientName);
        if (quantity > 0) {
            selectedIngredients.push_back(ingredientName);
            repository_.UpdateQuantity(ingredientName, quantity - 1);
            std::cout << "Added " << ingredientName << " to your pizza!" << std::endl;
            return true;
        } else {
            std::cout << "Sorry, " << ingredientName << " " << ingredientType_ << " can't be added at this time. Please choose another one." << std::endl;
            return false;
        }
    } catch (const std::invalid_argument&) {
        std::cout << "Sorry, " << ingredientName << " is not a valid " << ingredientType_ << " type. Please choose from the available options." << std::endl;
        return false;
    }
}

#include "TomatoesRepository.h"
#include "meatRepository.h"
template class IngredientSelector<TomatoesRepository>;
template class IngredientSelector<meatRepository>;