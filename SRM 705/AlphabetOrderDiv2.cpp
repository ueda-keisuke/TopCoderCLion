#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

class AlphabetOrderDiv2 {
public:

    void aa()
    {
        int dx = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy = {0, 1, 1, 1, 0, -1, -1, -1};

        for( int direction = 0; direction < 8; direction++ )
        {
            for( int m = 0; m < M; m++ )
                for( int n = 0; n < N; n++ )
                    if( board[m][n] == )
        }
    }



    string isOrdered(vector<string> words) {
        int mat[26][26] = {};
        int i, x, y, z;
        for (int i = 0; i < 26; i++)
            mat[i][i] = 1;

        for (auto w : words)
            for (int y = 0; y < w.size(); y++)
                for (int x = 0; x < y; x++)
                    mat[w[x] - 'a'][w[y] - 'a'] = 1;

        for (int z = 0; z < 26; z++)
            for (int x = 0; x < 26; x++)
                for (int y = 0; y < 26; y++)
                    mat[x][y] |= mat[x][z] & mat[z][y];

        for (int y = 0; y < 26; y++)
            for (int x = 0; x < y; x++)
                if (mat[x][y] && mat[y][x])
                    return "Impossible";

        return "Possible";
    }
};

// CUT begin
ifstream data("AlphabetOrderDiv2.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template<typename T>
void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template<typename T>
void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template<typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<string> words, string __expected) {
    time_t startClock = clock();
    AlphabetOrderDiv2 *instance = new AlphabetOrderDiv2();
    string __result = instance->isOrdered(words);
    double elapsed = (double) (clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    } else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<string> words;
        from_stream(words);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(words, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1484982790;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "AlphabetOrderDiv2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
