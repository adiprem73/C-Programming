#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 60);

// 2D coordinate helper
struct Pt
{
    int x, y;
};
struct Edge
{
    int a, b;
    string dir;
};

// Dice state with six faces
struct Dice
{
    int top, bottom, left, right, front, back;
    Dice() {}
    Dice(int T, int L, int F)
    {
        top = T;
        bottom = 7 - T;
        left = L;
        right = 7 - L;
        front = F;
        back = 7 - F;
    }
    // pack into integer key (base 7 digits) unique for faces 1..6
    int pack() const
    {
        // order: top,bottom,left,right,front,back each in [1..6], encode base7
        int key = 0;
        key = key * 7 + top;
        key = key * 7 + bottom;
        key = key * 7 + left;
        key = key * 7 + right;
        key = key * 7 + front;
        key = key * 7 + back;
        return key;
    }
    // roll in direction: "U" (up/north), "D" (down/south), "L" (left/west), "R" (right/east)
    Dice roll(char mv) const
    {
        Dice d = *this;
        Dice r;
        if (mv == 'U')
        {
            // roll up (north): new_top = old_front
            r.top = front;
            r.bottom = back;
            r.front = bottom;
            r.back = top;
            r.left = left;
            r.right = right;
        }
        else if (mv == 'D')
        {
            // roll down (south): new_top = old.back
            r.top = back;
            r.bottom = front;
            r.front = top;
            r.back = bottom;
            r.left = left;
            r.right = right;
        }
        else if (mv == 'L')
        {
            // roll left (west): new_top = right
            r.top = right;
            r.bottom = left;
            r.left = top;
            r.right = bottom;
            r.front = front;
            r.back = back;
        }
        else
        { // 'R'
            // roll right (east): new_top = left
            r.top = left;
            r.bottom = right;
            r.left = bottom;
            r.right = top;
            r.front = front;
            r.back = back;
        }
        return r;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read number of placements
    int N;
    if (!(cin >> N))
        return 0;

    vector<Edge> edges;
    edges.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        string dir;
        cin >> a >> b >> dir;
        // unify direction words to a single char code
        // accepted words: "top","down","left","right"
        // store string dir as-is for sorting, but convert later
        edges.push_back({a, b, dir});
    }

    // sort edges by (existing, new)
    sort(edges.begin(), edges.end(), [](const Edge &e1, const Edge &e2)
         {
        if (e1.a != e2.a) return e1.a < e2.a;
        return e1.b < e2.b; });

    // read source and destination
    int src, dest;
    cin >> src >> dest;

    // initial dice top,left,front
    int T, L, F;
    cin >> T >> L >> F;
    Dice startDice(T, L, F);

    // Place cubes on integer grid
    // id -> position
    unordered_map<int, pair<int, int>> id2pos;
    // pos -> id
    map<pair<int, int>, int> pos2id;

    // choose root as the existing cube in the first edge after sorting
    if (!edges.empty())
    {
        int root = edges.front().a;
        id2pos[root] = {0, 0};
        pos2id[{0, 0}] = root;
    }
    else
    {
        // no placements - nothing to do, but still handle source==dest maybe single cube absent
    }

    // helper to map placement direction word to delta (dx,dy)
    auto getDelta = [&](const string &dir) -> pair<int, int>
    {
        // top => above existing => y-1
        // down => below => y+1
        // left => x-1
        // right => x+1
        string d = dir;
        for (char &c : d)
            c = tolower(c);
        if (d == "top" || d == "up")
            return {0, -1};
        if (d == "down" || d == "bottom")
            return {0, +1};
        if (d == "left")
            return {-1, 0};
        if (d == "right")
            return {+1, 0};
        // fallback (shouldn't happen)
        return {0, 0};
    };

    // Process placements in sorted order
    for (const auto &e : edges)
    {
        int a = e.a;
        int b = e.b;
        auto delta = getDelta(e.dir);

        // Ensure existing 'a' has a position; if not, place it at origin (0,0).
        // (Problem description implies existing is always present when placing, but this is defensive.)
        if (id2pos.find(a) == id2pos.end())
        {
            // If (0,0) is already occupied by someone else, we remove that occupant (per overlap rule)
            pair<int, int> rootpos = {0, 0};
            if (pos2id.count(rootpos))
            {
                int old = pos2id[rootpos];
                id2pos.erase(old);
                pos2id.erase(rootpos);
            }
            id2pos[a] = rootpos;
            pos2id[rootpos] = a;
        }

        auto posA = id2pos[a];
        pair<int, int> posB = {posA.first + delta.first, posA.second + delta.second};

        // If b is already placed somewhere else, remove old placement (move it)
        if (id2pos.find(b) != id2pos.end())
        {
            auto oldpos = id2pos[b];
            pos2id.erase(oldpos);
            id2pos.erase(b);
        }

        // If posB is occupied by someone else, remove that occupant
        if (pos2id.count(posB))
        {
            int old = pos2id[posB];
            id2pos.erase(old);
            pos2id.erase(posB);
        }

        // Place b at posB
        id2pos[b] = posB;
        pos2id[posB] = b;
    }

    // If source or dest not in final structure, impossible
    if (id2pos.find(src) == id2pos.end() || id2pos.find(dest) == id2pos.end())
    {
        cout << -1 << '\n';
        return 0;
    }

    // Build adjacency: for each placed cube check four neighbors
    unordered_map<int, array<int, 4>> adj; // order: 0=U,1=D,2=L,3=R, store neighbour id or -1
    for (auto &kv : id2pos)
    {
        int id = kv.first;
        auto [x, y] = kv.second;
        array<int, 4> neigh;
        neigh.fill(-1);
        pair<int, int> up = {x, y - 1}, down = {x, y + 1}, left = {x - 1, y}, right = {x + 1, y};
        if (pos2id.count(up))
            neigh[0] = pos2id[up];
        if (pos2id.count(down))
            neigh[1] = pos2id[down];
        if (pos2id.count(left))
            neigh[2] = pos2id[left];
        if (pos2id.count(right))
            neigh[3] = pos2id[right];
        adj[id] = neigh;
    }

    // Dijkstra: states are (cube id, dice orientation packed)
    // We'll use dist map: dist[node][pack] = min cost
    using State = tuple<ll, int, int>; // (cost, node, pack)
    // priority_queue min-heap
    priority_queue<State, vector<State>, greater<State>> pq;
    unordered_map<int, unordered_map<int, ll>> dist; // dist[node][pack] = cost

    int startPack = startDice.pack();
    dist[src][startPack] = 0;
    pq.emplace(0LL, src, startPack);

    auto unpackDice = [&](int pack) -> Dice
    {
        // decode base7 back to faces
        int p = pack;
        array<int, 6> a;
        for (int i = 5; i >= 0; --i)
        {
            a[i] = p % 7;
            p /= 7;
        }
        Dice d;
        d.top = a[0];
        d.bottom = a[1];
        d.left = a[2];
        d.right = a[3];
        d.front = a[4];
        d.back = a[5];
        return d;
    };
    auto packDice = [&](const Dice &d) -> int
    { return d.pack(); };

    ll answer = -1;
    // If source == dest, cost 0 (no roll needed)
    if (src == dest)
    {
        cout << 0 << '\n';
        return 0;
    }

    while (!pq.empty())
    {
        auto [cost, node, pk] = pq.top();
        pq.pop();
        // If this state is not current best, skip
        if (dist[node].find(pk) == dist[node].end() || dist[node][pk] != cost)
            continue;

        // If reached destination node, first time we pop any dest-state it's minimal overall
        if (node == dest)
        {
            answer = cost;
            break;
        }

        // unpack dice
        Dice cur = unpackDice(pk);
        // check four moves: U,D,L,R -> correspond to up/down/left/right
        static const array<char, 4> mvch = {'U', 'D', 'L', 'R'};
        for (int mv = 0; mv < 4; ++mv)
        {
            int nei = adj[node][mv];
            if (nei == -1)
                continue; // no adjacent cube in that direction
            // roll dice
            Dice nd = cur.roll(mvch[mv]);
            ll ncost = cost + nd.top; // cost of move is new top face
            int npk = packDice(nd);
            if (!dist[nei].count(npk) || ncost < dist[nei][npk])
            {
                dist[nei][npk] = ncost;
                pq.emplace(ncost, nei, npk);
            }
        }
    }

    cout << answer << '\n';
    return 0;
}