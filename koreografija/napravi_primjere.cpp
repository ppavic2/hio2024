#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

string task_name = "koreografija";
string code_name = "nezmah";
int subtask_cnt[10];

void call_system (string tmp) {
    int n = tmp.size();
    char char_array[n + 1];
    strcpy(char_array, tmp.c_str());
    system(char_array);
}

void gen_dummy () {
    for (int i = 1; i <= 3; i++) {
        string tmp = "gen.exe DUMMY_" + to_string(i) + " > test/" + task_name + ".dummy.in." + to_string(i);
        call_system(tmp);
    }
}

void add_input (int subtask, string s) {
    string tmp = "gen.exe " + s + " > test/" + task_name + ".in." + to_string(subtask) + string(1, 'a' + subtask_cnt[subtask]);
    subtask_cnt[subtask]++;
    call_system(tmp);
}

void gen_dummy_output () {
    for (int i = 1; i <= 3; i++) {
        string tmp = code_name + ".exe < test/" + task_name + ".dummy.in." + to_string(i) + " > test/" + task_name + ".dummy.out." + to_string(i);
        call_system(tmp);
    }
}

void gen_input () {
    system("rmdir test /s /q");
    system("mkdir test");

    //dummy
    //gen_dummy();

    //subtask 1
    add_input(1, "RASTE 1 1");
    add_input(1, "PADA 1 2");
    add_input(1, "RANDOM 1 3");
    add_input(1, "RANDOM 1 4");
    add_input(1, "RANDOM 1 5");
    add_input(1, "RANDOM 1 6");
    add_input(1, "RANDOM 1 7");
    add_input(1, "RANDOM 1 8");
    add_input(1, "RANDOM 1 9");
    add_input(1, "RANDOM 1 10");
    add_input(1, "PADA_PA_RASTE 1 11");
    add_input(1, "RASTE_PA_PADA 1 12");
    add_input(1, "PADA_PA_PADA 1 13");
    add_input(1, "RASTE_PA_RASTE 1 14");
    add_input(1, "JEDAN_SWAP 1 15");
    add_input(1, "JEDAN_SWAP 1 16");
    add_input(1, "DVA_SWAPA 1 17");
    add_input(1, "DVA_SWAPA 1 18");
    add_input(1, "SUSJEDNI 1 19");
    add_input(1, "KORIJEN 1 20");
}

void gen_output () {
    gen_dummy_output();
    for (int i = 1; i < 10; i++) {
        if (subtask_cnt[i] == 0) continue;
        for (int j = 0; j < subtask_cnt[i]; j++) {
            string tmp = code_name + ".exe < test/" + task_name + ".in." + to_string(i) + string(1, 'a' + j);
            tmp += " > test/" + task_name + ".out." + to_string(i) + string(1, 'a' + j);
            call_system(tmp);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    gen_input();
    //gen_output();
    return 0;
}
