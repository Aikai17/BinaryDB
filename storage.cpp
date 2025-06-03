#include "storage.hpp"
#include <mutex>
namespace BinaryDB {

void Storage::set(const std::string& key, const std::string& value) {
    std::unique_lock lock(mutex_); // блокируем запись
    data_[key] = value;
}

std::optional<std::string> Storage::get(const std::string& key) const {
    std::shared_lock lock(mutex_); // допускаем множественные чтения
    if (auto it = data_.find(key); it != data_.end()) {
        return it->second;
    }
    return std::nullopt;
}

} // namespace BinaryDB
