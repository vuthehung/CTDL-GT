#include<bits/stdc++.h>
using namespace std;

// bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
//     return a.second.second > b.second.second;
// }
// int main() {
//     int t; cin >> t;
//     while(t--) {
//         int n; cin >> n;
//         int first_time[n] = {0}; // danh dau moc thoi gian da duoc thuc hien boi 1 cong viec
//         int res[n] = {0}; // danh dau id cv duoc lua chon o cac moc thoi gian
//         pair<int, pair<int, int>> job[n];
//         for(int i = 0; i < n; i++){
//             cin >> job[i].first >> job[i].second.first >> job[i].second.second;
//         }
//         sort(job, job + n, cmp);
//         int cnt = 0, profit_max = 0;
//         for(int i = 0; i < n; i++) {
//             for(int j = min(job[i].second.first - 1, n - 1); j >= 0; j--) {
//                 if(first_time[j] == 0) {
//                     first_time[j] = 1;
//                     res[j] = i;
//                     break;
//                 }
//             }
//         }
//         for(int i = 0; i < n; i++) {
//             if(first_time[i] == 1) {
//                 cnt++;
//                 profit_max += job[res[i]].second.second;
//             }
//         }
//         cout << cnt << " " << profit_max << endl;
//     }
// }
struct job{
    int jobl, deal, prof;
};
bool cmp(job a, job b) {
    return a.prof > b.prof;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        job a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i].jobl >> a[i].deal >> a[i].prof;
        }
        sort(a, a + n, cmp);
        int first_time[n] = {0};
        int res[n] = {0};
        int cnt = 0, prof_max = 0;
        for(int i = 0; i < n; i++) {
            for(int j = min(a[i].deal - 1, n - 1); j >= 0; j--) {
                if(first_time[j] == 0) {
                    first_time[j] = 1;
                    res[j] = i;
                    break;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(first_time[i] == 1) {
                cnt++;
                prof_max += a[res[i]].prof;
            }
        }
        cout << cnt << " " << prof_max << endl;
    }
}