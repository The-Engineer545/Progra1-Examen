#include "TomatoesRepository.h"
#include <stdexcept>


TomatoesRepository::TomatoesRepository() {
    auto data = DataLoader::LoadFromFile("tomatoes.txt");
    data_ = std::move(data);
}

int TomatoesRepository::GetAvailableQuantity(const std::string& tomatoType) const {
    auto it = data_.find(tomatoType);
    if (it == data_.end()) {
        throw std::invalid_argument("Unknown tomato type: " + tomatoType);
    }
    return std::stoi(it->second[0]);
}

void TomatoesRepository::UpdateQuantity(const std::string& meatType, int newQuantity) {
    auto it = data_.find(meatType);
    if (it == data_.end()) {
        throw std::invalid_argument("Unknown tomato type: " + meatType);
    }
    it->second[0] = std::to_string(newQuantity);
}