class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        std::vector<std::vector<int>> result;
        // Maps group_size -> list of person IDs currently being grouped
        std::unordered_map<int, std::vector<int>> groups;

        for (int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            groups[size].push_back(i);

            // If the group is full, move it to the result and clear it
            if (groups[size].size() == size) {
                result.push_back(std::move(groups[size]));
                groups[size].clear(); // Resets for the next group of the same size
            }
        }

        return result;
    }
};