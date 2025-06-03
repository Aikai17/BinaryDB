#pragma once
#include <string>
#include <optional>
#include <unordered_map>
#include <shared_mutex>

namespace BinaryDB {
class Storage {
public:
    void set(const std::string& key, const std::string& value);
    std::optional<std::string> get(const std::string& key) const;

private:
    mutable std::shared_mutex mutex_;
    std::unordered_map<std::string, std::string> data_;
};
}
