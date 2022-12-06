#include <string>
#include <iostream>

#define debug(M,...) fprintf(stderr, "DEBUG: %s: %d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

using namespace std;

/*
bool reg_exp_match(std::string s, std::string p, unsigned int s_pos, unsigned int p_pos) {
    debug("Calling %d %d", s_pos, p_pos);
    bool p_end = p.length() <= p_pos;
    bool s_end = s.length() <= s_pos;
    if (p_end) {
        debug("P depleted");
        return s_end;
    } 
    bool first_match = (!s_end && (s[s_pos] == p[p_pos] || p[p_pos] == '.'))? true : false;
    debug("first_match: %d", first_match);
    if (p[p_pos+1] == '*') {
        debug("* detected");
        return reg_exp_match(s, p, s_pos, p_pos+2) || (first_match && reg_exp_match(s, p, s_pos+1, p_pos));
    } else {
        return (first_match && reg_exp_match(s,p,s_pos+1,p_pos+1));
    }
}
*/

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        return ismatch(&s,&p,0,0);
    }
    bool ismatch(std::string* s, std::string* p, unsigned int s_pos, unsigned int p_pos);
};

bool Solution::ismatch(std::string* s, std::string* p, unsigned int s_pos, unsigned int p_pos) {
    bool p_end = p->length() <= p_pos;
    bool s_end = s->length() <= s_pos;
    if (p_end) {
        return s_end;
    } 
    bool first_match = (!s_end && ((*s)[s_pos] == (*p)[p_pos] || (*p)[p_pos] == '.'))? true : false;
    if ((*p)[p_pos+1] == '*') {
        return ismatch(s, p, s_pos, p_pos+2) || (first_match && ismatch(s, p, s_pos+1, p_pos));
    } else {
        return (first_match && ismatch(s,p,s_pos+1,p_pos+1));
    }
}
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        unsigned int s_size = s.length() + 1;
        unsigned int p_size = p.length() + 1;
        int** dp = new int*[s_size];
        for (unsigned int i = 0; i < s_size; i++) {
            dp[i] = new int[p_size];
            std::fill_n(dp[i],p_size, -1);
        }
        for (unsigned int i = 0; i < s_size; i++) {
            for (unsigned int j = 0; j < p_size; j++) {
                cout << dp[i][j] << '\t';
            }
            cout << endl;
        }
        bool answer = ismatch(&s, &p, 0, 0, dp);
        for (unsigned int i = 0; i < s_size; i++) {
            for (unsigned int j = 0; j < p_size; j++) {
                cout << dp[i][j] << '\t';
            }
            cout << endl;
        }
        for (unsigned int i = 0; i < s_size; i++) {
            delete [] dp[i];
        }
        delete [] dp;
        return answer;
    }
    bool ismatch(std::string* s, std::string* p, unsigned int s_pos, unsigned int p_pos, int** dp);
};

bool Solution::ismatch(std::string* s, std::string* p, unsigned int s_pos, unsigned int p_pos, int** dp) {
    debug("Calling %d %d", s_pos, p_pos);
    if (s_pos < s->length() && p_pos < p->length() && dp[s_pos][p_pos] >= 0 ) {
        debug("Found %d %d", s_pos, p_pos);
        return (dp[s_pos][p_pos] == 1)? true : false;
    }
    bool p_end = p->length() <= p_pos;
    bool s_end = s->length() <= s_pos;
    if (p_end) {
        debug("P depleted");
        dp[s_pos][p_pos] = s_end? 1 : 0;
    } else {
        bool first_match = (!s_end && ((*s)[s_pos] == (*p)[p_pos] || (*p)[p_pos] == '.'))? true : false;
        debug("first_match: %d", first_match);
        if ((*p)[p_pos+1] == '*') {
            dp[s_pos][p_pos] = (ismatch(s, p, s_pos, p_pos+2, dp) || (first_match && ismatch(s, p, s_pos+1, p_pos, dp)))? 1: 0;
        } else {
            dp[s_pos][p_pos] = ((first_match && ismatch(s,p,s_pos+1,p_pos+1, dp)))? 1 : 0;
        }
    }
    return (dp[s_pos][p_pos] == 1)? true : false;
}


int main(void) {
    std::string s;
    std::string p;

    std::cin >> s;
    std::cin >> p;
    Solution solution;
    std::cout << solution.isMatch(s,p) << std::endl;
        
    return 0;
}


