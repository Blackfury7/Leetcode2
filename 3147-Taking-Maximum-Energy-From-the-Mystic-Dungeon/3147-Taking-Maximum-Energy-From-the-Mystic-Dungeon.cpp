class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int max_energy = INT_MIN;
        int n = energy.size();
        
        // Iterate backwards through the array
        for (int i = n - 1; i >= 0; --i) {
            // If there's a next position in the chain, add its accumulated energy
            if (i + k < n) {
                energy[i] += energy[i + k];
            }
            // Update maximum energy found so far
            max_energy = max(max_energy, energy[i]);
        }
        return max_energy;
    }
};