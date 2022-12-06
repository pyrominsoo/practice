
#include <iostream>
#include <vector>
#include <algorithm>

int min_height_diff(int K, std::vector<int>& input_seq);

int main(void) {

    // Iterate to find max, min
    // calculate max - min
    // if (max - min) <= k, return max - min
    // else if (max - min) >= 4K,  return (max - min - 2k)
    // else
    //  calculate (max + min) / 2
    //  iterate over the towers
    //      if above mean, subtract k
    //      else add k
    //      keep max, min
    //  return (max - min)

    int T;
    std::cin >> T;
    while (T--) {
        int K, N;
        std::cin >> K >> N;
        std::vector<int> input_seq(N);
        for (int i = 0; i < N; i++) {
            std::cin >> input_seq[i];
        }

        int result = min_height_diff(K, input_seq);
        std::cout << result << std::endl;    


    }

    return 0;
}

int min_height_diff(int K, std::vector<int>& input_seq) {
    int max = *std::max_element(input_seq.begin(),input_seq.end());
    int min = *std::min_element(input_seq.begin(),input_seq.end());
    int diff = max - min;
    if (diff <= K) {
        return diff;
    } else if (diff >= 4 * K) {
        return (diff - (2 * K));
    } else {
        int mean = (max + min) / 2;
        std::vector<int>::iterator it;
        for (it = input_seq.begin(); it != input_seq.end(); it++) {
            if (*it > mean) {
                *it -= K;    
            } else {
                *it += K;    
            }
        }
        max = *std::max_element(input_seq.begin(),input_seq.end());
        min = *std::min_element(input_seq.begin(),input_seq.end());
        return max - min;
    }
}


