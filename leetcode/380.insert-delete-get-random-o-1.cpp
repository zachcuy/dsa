/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

#include "includes.h"
// @lc code=start
class RandomizedSet
{
   public:
    // AC
    RandomizedSet()
    {
        std::random_device rand_seed;
        this->gen = std::mt19937(rand_seed());
        this->generator = std::uniform_int_distribution<>(0, 2 * pow(10, 5) + 1);
    }

    bool insert(int val)
    {
        return data.insert(val).second;
    }

    bool remove(int val)
    {
        return data.erase(val);
    }

    int getRandom()
    {
        auto it = data.begin();
        std::size_t uniform_idx = generator(gen) % data.size();
        std::advance(it, uniform_idx);

        return *it;
    }

   private:
    std::unordered_set<int> data;
    std::mt19937 gen;
    std::uniform_int_distribution<> generator;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

int main(int argc, char const *argv[])
{
    RandomizedSet obj;

    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.insert(6);

    dump(obj.getRandom());
    dump(obj.getRandom());
    dump(obj.getRandom());
    dump(obj.getRandom());
    dump(obj.getRandom());
    dump(obj.getRandom());
    dump(obj.getRandom());
    return 0;
}