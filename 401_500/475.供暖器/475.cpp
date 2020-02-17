// 两个差不多，主要是最后求最大值方法不一样
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {    
        // 两个输入都是排序好的
        // sort(houses.begin(), houses.end());
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
                    // if(heaters[mid] == i) {
                    //     lo = mid;
                    //     break;
                    // } else if(heaters[mid] < i) {
                    //     lo = mid + 1;
                    // } else {
                    //     hi = mid;
                    // }
                    if(heaters[mid] < i) {
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

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {    
        // 两个输入都是排序好的
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int nearest_heater_distance = 0;        
        for(auto i : houses) {
            int min_heater_distance = 0;
            int lo = 0;
            int hi = heaters.size() - 1;
            if(i <= heaters[lo]) {
                // house在heater的左侧
                nearest_heater_distance = std::max(nearest_heater_distance, heaters[lo] - i);
            } else if (i >= heaters[hi]) {
                // house在heater的右侧
                nearest_heater_distance = std::max(nearest_heater_distance, i - heaters[hi]);
            } else {
                // house在heater中间，二分查找每一个house最近的heater
                while(lo < hi) {
                    int mid = (hi - lo) / 2 + lo;
                    // if(heaters[mid] == i) {
                    //     lo = mid;
                    //     break;
                    // } else if(heaters[mid] < i) {
                    //     lo = mid + 1;
                    // } else {
                    //     hi = mid;
                    // }
                    if(heaters[mid] < i) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }                    
                }
                if(heaters[lo] == i) {
                    // 恰好在同一位置
                    nearest_heater_distance = std::max(nearest_heater_distance, 0);
                } else {
                    // 落在lo-1与lo之间
                    nearest_heater_distance = std::max(nearest_heater_distance, std::min(i - heaters[lo-1], heaters[lo] - i));
                }
            }
        }
        return nearest_heater_distance;
    }
};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {    
        // 排序heater
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
                    if(heaters[mid] < i) {
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