#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point {
    double x, y;
};
struct Human {
    int id;
    Point pos;
};
struct Zombie {
    int id;
    Point pos;
    Point nextPos;
};
double distancePoint(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
double scorePosition(const Point& p, const vector<Zombie>& zombies) {
    if (zombies.empty()) return 0.0;
    double s = 0.0;
    for (const auto& z : zombies) {
        double d = distancePoint(p, z.pos);
        s -= d;
    }
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const double ASH_SPEED = 1000.0;
    const double ZOMBIE_SPEED = 400.0;
    const double ASH_RANGE = 2000.0;
    while (true) {
        int ax, ay;
        if (!(cin >> ax >> ay)) return 0;
        cin.ignore();
        Point ash = { (double)ax, (double)ay };
        int humanCount;
        cin >> humanCount; 
        cin.ignore();
        vector<Human> humans;
        humans.reserve(humanCount);
        for (int i = 0; i < humanCount; i++) {
            int id, x, y;
            cin >> id >> x >> y;
            cin.ignore();
            humans.push_back({ id, { (double)x, (double)y } });
        }
        int zombieCount;
        cin >> zombieCount;
        cin.ignore();
        vector<Zombie> zombies;
        zombies.reserve(zombieCount);
        for (int i = 0; i < zombieCount; i++) {
            int id, x, y, nx, ny;
            cin >> id >> x >> y >> nx >> ny;
            cin.ignore();
            zombies.push_back({ id, { (double)x, (double)y }, { (double)nx, (double)ny } });
        }
        Point target = { 8000.0, 4500.0 };
        if (humans.empty() || zombies.empty()) {
            cout << (int)target.x << " " << (int)target.y << endl;
            continue;
        }
        double bestUrgency = 1e18;
        int bestZombieIdx = -1;
        for (int hi = 0; hi < (int)humans.size(); ++hi) {
            const Human& h = humans[hi];
            double minDistHZ = 1e18;
            int threatIdx = -1;
            for (int zi = 0; zi < (int)zombies.size(); ++zi) {
                const Zombie& z = zombies[zi];
                double d = distancePoint(h.pos, z.pos);
                if (d < minDistHZ) {
                    minDistHZ = d;
                    threatIdx = zi;
                }
            }
            if (threatIdx == -1) continue;
            const Zombie& threat = zombies[threatIdx];
            double T_zombie = minDistHZ / ZOMBIE_SPEED;
            double distAshZ = distancePoint(ash, threat.pos);
            double T_ash = 0.0;
            if (distAshZ > ASH_RANGE) T_ash = (distAshZ - ASH_RANGE) / ASH_SPEED;
            if (T_ash < T_zombie && T_zombie < bestUrgency) {
                bestUrgency = T_zombie;
                bestZombieIdx = threatIdx;
            }
        }
        target = zombies[bestZombieIdx].pos;
        Point bestPoint = target;
        double bestScore = scorePosition(target, zombies);
        int offsets[] = { -800, -400, 0, 400, 800 };
        for (int dx : offsets) {
            for (int dy : offsets) {
                Point cand = { target.x + dx, target.y + dy };
                cand.x = max(0.0, min(15999.0, cand.x));
                cand.y = max(0.0, min(8999.0, cand.y));
                double sc = scorePosition(cand, zombies);
                if (sc > bestScore) {
                    bestScore = sc;
                    bestPoint = cand;
                }
            }
        }
        cout << (int)bestPoint.x << " " << (int)bestPoint.y << endl;
    }
}
