template<typename Tvertex, typename Tweight>
unordered_map<Tvertex, Tweight> shortestDist(vector<tuple<Tvertex, Tvertex, Tweight>> edges, vector<Tvertex> vertices, Tvertex start) {
    unordered_map<Tvertex, vector<pair<Tvertex, Tweight>>> neighbors;
    for (auto [src, dst, weight] : edges) {
        neighbors[src].push_back(make_pair(dst, weight));
    }
    priority_queue<pair<Tweight, Tvertex>, vector<pair<Tweight, Tvertex>>, greater<pair<Tweight, Tvertex>>> pq;
    pq.push(make_pair(Tweight(), start));
    unordered_map<Tvertex, Tweight> dists;
    for (auto v : vertices) {
        dists[v] = numeric_limits<Tweight>::max();
    }
    dists[start] = Tweight();
    while (!pq.empty()) {
        auto [dist, curr] = pq.top();
        pq.pop();
        if (dist > dists[curr]) {
            continue;
        }
        for (auto [neighbor, weight] : neighbors[curr]) {
            if (dist + weight < dists[neighbor]) {
                dists[neighbor] = dist + weight;
                pq.push(make_pair(dist + weight, neighbor));
            }
        }
    }
    return dists;
}