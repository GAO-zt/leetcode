// class Solution {
// public:
//     int findRadius(vector<int>& houses, vector<int>& heaters) {    
//         int l_distance = std::abs(heaters[0] - houses[0]); 
//         int r_distance = std::abs(houses[houses.size()-1] - heaters[heaters.size()-1]);
//         vector<int> distance;     
//         if(heaters.size() == 1) {
//             distance.push_back(0);
//         }            
//         for (int i = 0; i < heaters.size() - 1; ++i) {           
//             distance.push_back((heaters[i+1] - heaters[i]) / 2); 
//         }
    
//         return std::max(*(std::max_element(distance.begin(), distance.end())), std::max(l_distance, r_distance));
//     }
// };

// 结果是对的，但运行速度不可接受（超出时间限制）
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {    
        vector<int> nearest_heater_distance;
        for(auto i : houses) {
            vector<int> heater_distance;
            for(auto j : heaters) {
                heater_distance.push_back(std::abs(i - j));
            }
            nearest_heater_distance.push_back(*(std::min_element(heater_distance.begin(), heater_distance.end())));
        }
        return *(std::max_element(nearest_heater_distance.begin(), nearest_heater_distance.end()));
    }
};

// 时间比上面稍好，但还是不能接受（超出时间限制）
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {    
        vector<int> nearest_heater_distance;
        for(auto i : houses) {
            int min_heater_distance = INT_MAX;
            for(auto j : heaters) {
                min_heater_distance = std::min(min_heater_distance, std::abs(i - j));
            }
            nearest_heater_distance.push_back(min_heater_distance);
        }
        return *(std::max_element(nearest_heater_distance.begin(), nearest_heater_distance.end()));
    }
};

// （超出时间限制）
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {    
        int nearest_heater_distance = 0;
        for(auto i : houses) {
            int min_heater_distance = INT_MAX;
            for(auto j : heaters) {
                min_heater_distance = std::min(min_heater_distance, std::abs(i - j));
            }
            nearest_heater_distance = std::max(nearest_heater_distance, min_heater_distance);
        }
        return nearest_heater_distance;
    }
};

// 时间比上面稍好，但还是不能接受（超出时间限制）
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {    
        // 两个输入都是排序好的
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> nearest_heater_distance;
        for(auto i : houses) {
            int min_heater_distance = 0;
            int lo = 0;
            int hi = heaters.size() - 1;
            if(i <= heaters[lo]) {
                // house在heater的左侧
                nearest_heater_distance.push_back(heaters[lo] - i);
            } else if (i >= heaters[hi]) {
                // house在heater的右侧
                nearest_heater_distance.push_back(i - heaters[hi]);
            } else {
                // house在heater中间，二分查找每一个house最近的heater，上一次用从0开始遍历的方法会很慢
                while(lo < hi) {
                    int mid = (hi - lo) / 2 + lo;
                    if(heaters[mid] == i) {
                        lo = mid;
                        break;
                    } else if(heaters[mid] < i) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }
                }
                if(heaters[lo] == i) {
                    // 恰好在同一位置
                    nearest_heater_distance.push_back(0);
                } else {
                    // 落在lo-1与lo之间
                    nearest_heater_distance.push_back(std::min(i - heaters[lo-1], heaters[lo] - i));
                }
            }
        }
        return *(std::max_element(nearest_heater_distance.begin(), nearest_heater_distance.end()));
    }
};