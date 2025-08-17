#pragma once
#include <algorithm>
#include <array>
#include <optional>

template <typename Key, typename Value>
struct Element {
    Key key;
    Value value;
};

template <typename Key, typename Value>
consteval bool operator==(const Element<Key, Value>& lhs,
                          const Element<Key, Value>& rhs) {
    return lhs.key == rhs.key;
}

namespace details {

template <typename Key, typename Value, size_t Size>
class CompileTimeMapImpl {
   public:
    template <typename... Args>
    consteval explicit CompileTimeMapImpl(Args... elements)
        : data{{std::move(elements)...}} {}

    [[nodiscard]] consteval bool allAreUnique() const {
        for(auto iter = data.begin(); iter < data.end(); iter++)
        {
            if(containsIter(iter + 1, iter->key))
            {
                return false;
            }
        }

        return true;
    }
    consteval bool contains(const Key& key) const {
        return std::find_if(data.begin(), data.end(), [&key](const auto& elt) {
                   return elt.key == key;
               }) != data.end();
    }
    consteval std::optional<Value> getValue(const Key& key) const {
        auto it = std::find_if(data.begin(), data.end(), [&key](const auto& elt) { return elt.key == key; });
        if (it != data.end()) {
            return it->value;
        }
        return std::nullopt;
    }

    consteval auto getSize() const { return Size; }

    consteval auto getKeys() const {
        std::array<Key, Size> temp;
        std::transform(data.begin(), data.end(), temp.begin(), [](const auto& val){
            return val.key;
        });
        return temp;
    }

    consteval auto getValues() const {
        std::array<Key, Size> temp;
        std::transform(data.begin(), data.end(), temp.begin(), [](const auto& val){
            return val.value;
        });
        return temp;
    }

   private:
    consteval bool containsIter(auto startIter, const Key& key) const {
        return std::find_if(startIter, data.end(), [&key](const auto& elt) {
                   return elt.key == key;
               }) != data.end();
    }
    std::array<Element<Key, Value>, Size> data{};
};
}  // namespace details

template <typename Key, typename Value, typename... Args>
consteval auto CompileTimeMap(Args... args) {
    return details::CompileTimeMapImpl<Key, Value, sizeof...(args)>(args...);
}
