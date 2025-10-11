#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Seg
{
    double x1, y1, x2, y2;
};

inline bool dbl_eq(double a, double b) { return fabs(a - b) < EPS; }

bool on_segment(double x1, double y1, double x2, double y2, double x, double y)
{
    // check collinear
    double cross = (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
    if (fabs(cross) > 1e-8)
        return false;
    if (x + EPS < min(x1, x2) || x - EPS > max(x1, x2))
        return false;
    if (y + EPS < min(y1, y2) || y - EPS > max(y1, y2))
        return false;
    return true;
}

string key_of(double x, double y)
{
    // snap to integer if very close, otherwise format to fixed decimals
    double rx = round(x), ry = round(y);
    if (fabs(x - rx) < 1e-9 && fabs(y - ry) < 1e-9)
    {
        long long ix = (long long)llround(rx);
        long long iy = (long long)llround(ry);
        return to_string(ix) + "_" + to_string(iy);
    }
    else
    {
        // format with 9 decimals
        char buf[64];
        snprintf(buf, sizeof(buf), "%.9f_%.9f", x, y);
        return string(buf);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N))
        return 0;
    vector<Seg> segs;
    segs.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segs.push_back({(double)x1, (double)y1, (double)x2, (double)y2});
    }
    long long hx_ll, hy_ll;
    cin >> hx_ll >> hy_ll;
    double hx = (double)hx_ll, hy = (double)hy_ll;

    // Step 1: collect intersection points + endpoints
    unordered_map<string, pair<double, double>> pts_map; // key -> point coords
    auto add_point = [&](double x, double y)
    {
        string k = key_of(x, y);
        pts_map.emplace(k, make_pair(x, y));
    };

    for (auto &s : segs)
    {
        add_point(s.x1, s.y1);
        add_point(s.x2, s.y2);
    }

    // Pairwise intersections
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            double x1 = segs[i].x1, y1 = segs[i].y1, x2 = segs[i].x2, y2 = segs[i].y2;
            double x3 = segs[j].x1, y3 = segs[j].y1, x4 = segs[j].x2, y4 = segs[j].y2;
            double denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
            if (fabs(denom) < EPS)
            {
                // parallel or collinear: add endpoints that lie on the other segment
                pair<double, double> cand[4] = {{x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}};
                for (int k = 0; k < 4; ++k)
                {
                    double px = cand[k].first, py = cand[k].second;
                    if (on_segment(x1, y1, x2, y2, px, py) && on_segment(x3, y3, x4, y4, px, py))
                    {
                        add_point(px, py);
                    }
                }
            }
            else
            {
                double numx = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
                double numy = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
                double px = numx / denom;
                double py = numy / denom;
                // check if lies on both segments
                if (on_segment(x1, y1, x2, y2, px, py) && on_segment(x3, y3, x4, y4, px, py))
                {
                    add_point(px, py);
                }
            }
        }
    }

    // Check if house lies on any segment; if not -> 0 routes
    bool house_on_any = false;
    for (auto &s : segs)
    {
        if (on_segment(s.x1, s.y1, s.x2, s.y2, hx, hy))
        {
            house_on_any = true;
            break;
        }
    }
    if (!house_on_any)
    {
        cout << 0 << '\n';
        return 0;
    }
    add_point(hx, hy);

    // build list of points and map to indices
    vector<pair<double, double>> points;
    points.reserve(pts_map.size());
    for (auto &kv : pts_map)
        points.push_back(kv.second);
    // sort to have deterministic indices
    sort(points.begin(), points.end(), [](const pair<double, double> &a, const pair<double, double> &b)
         {
        if (fabs(a.first - b.first) > 1e-9) return a.first < b.first;
        return a.second < b.second - 1e-9; });
    unordered_map<string, int> p2id;
    for (size_t i = 0; i < points.size(); ++i)
    {
        p2id[key_of(points[i].first, points[i].second)] = (int)i;
    }
    int V = (int)points.size();
    vector<set<int>> adj(V);

    // For each segment, find points on it, sort along segment and connect consecutive
    for (auto &s : segs)
    {
        vector<pair<double, double>> pts_on;
        for (auto &p : points)
        {
            if (on_segment(s.x1, s.y1, s.x2, s.y2, p.first, p.second))
                pts_on.push_back(p);
        }
        if (pts_on.size() < 2)
            continue;
        // sort pts_on along the segment direction
        double dx = s.x2 - s.x1, dy = s.y2 - s.y1;
        if (fabs(dx) >= fabs(dy))
        {
            // sort by x (increasing or decreasing)
            if (s.x1 <= s.x2)
            {
                sort(pts_on.begin(), pts_on.end(), [](auto &a, auto &b)
                     {
                    if (fabs(a.first - b.first) > 1e-9) return a.first < b.first;
                    return a.second < b.second - 1e-9; });
            }
            else
            {
                sort(pts_on.begin(), pts_on.end(), [](auto &a, auto &b)
                     {
                    if (fabs(a.first - b.first) > 1e-9) return a.first > b.first;
                    return a.second > b.second + 1e-9; });
            }
        }
        else
        {
            // sort by y
            if (s.y1 <= s.y2)
            {
                sort(pts_on.begin(), pts_on.end(), [](auto &a, auto &b)
                     {
                    if (fabs(a.second - b.second) > 1e-9) return a.second < b.second;
                    return a.first < b.first - 1e-9; });
            }
            else
            {
                sort(pts_on.begin(), pts_on.end(), [](auto &a, auto &b)
                     {
                    if (fabs(a.second - b.second) > 1e-9) return a.second > b.second;
                    return a.first > b.first + 1e-9; });
            }
        }
        // connect consecutive
        for (size_t i = 0; i + 1 < pts_on.size(); ++i)
        {
            string ka = key_of(pts_on[i].first, pts_on[i].second);
            string kb = key_of(pts_on[i + 1].first, pts_on[i + 1].second);
            int ia = p2id[ka], ib = p2id[kb];
            if (ia == ib)
                continue;
            adj[ia].insert(ib);
            adj[ib].insert(ia);
        }
    }

    // find start index
    string startk = key_of(hx, hy);
    if (!p2id.count(startk))
    {
        cout << 0 << '\n';
        return 0;
    }
    int start = p2id[startk];

    // If start has no neighbors => no cycle
    if (adj[start].empty())
    {
        cout << 0 << '\n';
        return 0;
    }

    // DFS enumerating simple cycles that start and end at 'start'
    vector<char> visited(V, 0);
    visited[start] = 1;
    long long found = 0;

    function<void(int, int)> dfs = [&](int u, int depth)
    {
        for (int v : adj[u])
        {
            if (v == start)
            {
                // requires at least two edges before closing: exclude trivial back-and-forth start->A->start
                if (depth >= 2)
                    found++;
            }
            else if (!visited[v])
            {
                visited[v] = 1;
                dfs(v, depth + 1);
                visited[v] = 0;
            }
        }
    };

    dfs(start, 0);

    // each cycle counted twice (once each direction)
    cout << (found / 2) << '\n';
    return 0;
}
