/*  An example of how to compile and use the checker:
 *    $ g++ checker.cpp -o checker
 *    $ checker < yourOutput.txt
 *
 *  The checker reads the test case from the standard input (stdin) and
 *  prints an informative message with the results of the heuristics to
 *  the standard ouput (stdout).
 *
 *
 *  # Description of the solutions.
 *
 *  0. 'struct CorrectSolution' implements the intended solution using
 *     matroid intersection, which is described in the editorial of CNNCT2.
 *
 *  1. 'struct Solution1' implements the following randomized heuristic:
 *        a) Select a random permutation of the edges;
 *        b) Start with both graphs empty and consider the edges one by one
 *           in the selected order;
 *        c) If the considered edge can be added to both graphs without
 *           creating any cycles - add it, otherwise discard it;
 *        d) If at the end of the process 'k' edges were added to the
 *           graphs, update the answer with the value of '2 * n - 2 - k';
 *        e) Repeat steps (a) through (d) '30000000 / m' times and return
 *           the best (minimal) answer found.
 *
 *  2. 'struct Solution2' implements the following randomized heuristic:
 *        a) Select a random permutation of the edges;
 *        b) Start with both graphs empty and consider the edges one by one
 *           in the selected order;
 *        c) If the considered edge connects two different connected
 *           components in at least one of the graph - add it, otherwise
 *           discard it;
 *        d) Denote the list of added edges with 'L', preserving order;
 *        e) Consider each edge from the list 'L', if it is a bridge in at
 *           least of the graphs - move it to the beginning of the list 'L',
 *           otherwise leave it at its previous position;
 *        f) If the size of the list 'L' is 'k' and all the 'k' edges were
 *           moved during step (e), return 'k' as the answer;
 *        g) Otherwise, go back to step (b) using the list 'L' instead of
 *           the initial permutation generated during step (a);
 *        h) Repeat steps (a) through (g) until the total size of the graphs
 *           (vertices + edges) considered during step (b) reaches 20000000
 *           and return the best answer found;
 *
 *  3. 'struct Solution3' implements the following randomized heuristic:
 *        a) Start with a parameter 'ee = 1.0';
 *        b) Select a random permutation of the edges 'P';
 *        c) Execute steps (b) and (c) from the solution (1) using the per-
 *           mutation 'P' and denote the number of added edges with 'curr';
 *        d) Select a pair of permutation elements 'x' and 'y' at random;
 *           and swap the edges 'P[x]' and 'P[y]';
 *        e) Execute steps (b) and (c) from the solution (1) using the per-
 *           mutation 'P' and denote the number of added edges with 'cnt';
 *        f) If 'cnt > curr' go to step (i);
 *        g) Otherwise with probability 'pow(ee, curr - cnt)' go to step (i);
 *        h) Otherwise swap the edges 'P[x]' and 'P[y]' back and go to
 *           step (j);
 *        i) Update 'ee := ee * 0.991' and update the answer with the value
 *           '2 * n - 2 - cnt';
 *        j) Finish one iteration;
 *        k) Repeat the steps (c) through (j) '6000000 / m' times on each
 *           iteration using the permutations 'P' obtained after the
 *           previous iteration;
 *        l) Steps (a) through (k) are repeated 5 times and the best answer
 *           found is returned.
 *
 *  4. 'struct Solution4' implements the following randomized heuristic:
 *        a) Start with a parameter 'ee = 1.0';
 *        b) Select a random spanning tree in the first graph and consider
 *           these edges to be initially enabled and all other - disabled;
 *        c) Count the number of connected components in the second graph,
 *           including only enabled edges, and denote the count with 'curr';
 *        d) Choose an edge 'x' at random among currently disabled edges;
 *        e) Choose an edge 'y' at random from the path connecting the
 *           endpoints of 'x' in the tree formed by enabled edges;
 *        f) Mark edge 'x' as disabled and edge 'y' as enabled;
 *        g) Count the number of connected components in the second graph,
 *           including only enabled edges, and denote the count with 'cnt';
 *        h) If 'cnt < curr' go to step (k);
 *        i) Otherwise with probability 'pow(ee, cnt - curr)' go to step (k);
 *        j) Otherwise mark the edge 'x' as enabled and edge 'y' as disabled,
 *           reverting the step (f) and go to the step (l);
 *        k) Update 'ee := ee * 0.988' and update the answer with the value
 *           'n - 1 + cnt - 1';
 *        l) Finish one iteration;
 *        m) Repeat the steps (c) through (l) '300000 / m' times on each
 *           itertion using the enabled edges obtained after the previous
 *           iteration;
 *        n) Steps (a) through (m) are repeated 50 times with the two graphs
 *           in their original order and 50 times with the graphs being
 *           swapped. The best answer found is returned.
 */

#include <vector>

using namespace std;

extern "C" {
	int scanf(const char*, ...);
	int printf(const char*, ...);
	void exit(int);
	double pow(double, double);
}

const unsigned seed = 0x12345678;

//////////////////////////////////////////////////////////////////////////
// The part below is an exact copy from the checker used on the server! //

struct random_t {
	unsigned state;
	random_t() : state(seed) { }
	unsigned next() {
		state ^= state << 13;
		state ^= state >> 17;
		state ^= state << 5;
		return state;
	}
	void permute(int* permutation, int n) {
		for (int k = 0; k < n; k++) {
			permutation[k] = k;
			int p = next() % (k + 1);
			int tmp = permutation[p];
			permutation[p] = k;
			permutation[k] = tmp;
		}
	}
};

const int MX = 300;

struct DSU {
	int p[MX];
	
	void init(int n) {
		for (int i = 0; i < n; i++) p[i] = i;
	}
	
	int get(int v) {
		if (p[v] != v) p[v] = get(p[v]);
		return p[v];
	}
	
	void merge(int u, int v) {
		u = get(u);
		v = get(v);
		p[u] = v;
	}
};

int n, m;
int u1[MX], v1[MX], u2[MX], v2[MX];

struct Graph {
	int lastEdge[MX], ee;
	struct { int v, id, next; } e[2 * MX];
	
	void init() {
		ee = 0;
		for (int i = 0; i < n; i++) lastEdge[i] = -1;
	}
	
	void addEdge(int u, int v, int id) {
		e[ee].v = v;
		e[ee].id = id;
		e[ee].next = lastEdge[u];
		lastEdge[u] = ee++;
		
		e[ee].v = u;
		e[ee].id = id;
		e[ee].next = lastEdge[v];
		lastEdge[v] = ee++;
	}
	
	bool vis[MX];
	int up[MX], dep[MX];
	bool* bridge;
	
	void dfs(int v, int edgeToParent, int depth) {
		vis[v] = true;
		dep[v] = depth;
		up[v] = depth;
		for (int i = lastEdge[v]; i != -1; i = e[i].next) {
			if (e[i].id == edgeToParent) continue;
			
			int u = e[i].v;
			if (vis[u] == false) {
				dfs(u, e[i].id, depth + 1);
				if (up[u] > depth) bridge[e[i].id] = true;
			}
			
			if (up[u] < up[v]) up[v] = up[u];
		}
	}
	
	void markBridges(bool* isBridge) {
		for (int i = 0; i < n; i++) vis[i] = false;
		
		bridge = isBridge;
		dfs(0, -1, 0);
	}
};

int getBothAcyclic(int* permutation) {
	static DSU dsu1, dsu2;
	
	dsu1.init(n);
	dsu2.init(n);
	
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int e = permutation[i];
		int x1 = dsu1.get(u1[e]);
		int y1 = dsu1.get(v1[e]);
		if (x1 == y1) continue;
		int x2 = dsu2.get(u2[e]);
		int y2 = dsu2.get(v2[e]);
		if (x2 != y2) {
			cnt++;
			dsu1.merge(x1, y1);
			dsu2.merge(x2, y2);
		}
	}
	
	return cnt;
}

struct ExchangeGraph {
	vector<int> G[MX];
	
	void clear() {
		for (int i = 0; i < m; i++) G[i].clear();
	}

	void addEdge(int u, int v) {
		G[u].push_back(v);
	}
	
	bool findAugmentalPath(vector<int> from, vector<int> to, bool* enabled) {
		vector<int> par(m, -1), dist(m), queue;
		for (size_t i = 0; i < from.size(); i++) {
			int v = from[i];
			queue.push_back(v);
			par[v] = -2;
			dist[v] = 0;
		}
		
		for (size_t i = 0; i < queue.size(); i++) {
			int v = queue[i];
			for (size_t j = 0; j < G[v].size(); j++) {
				int u = G[v][j];
				if (par[u] == -1) {
					queue.push_back(u);
					par[u] = v;
					dist[u] = dist[v] + 1;
				}
			}
		}
		
		int target = -1;
		for (size_t i = 0; i < to.size(); i++) {
			int v = to[i];
			if (par[v] == -1) continue;
			if (target == -1 || dist[v] < dist[target]) target = v;
		}
		
		if (target != -1) {
			while (target != -2) {
				enabled[target] = not enabled[target];
				target = par[target];
			}
			
			return true;
		}
		
		return false;
	}
};

struct CorrectSolution {
	ExchangeGraph exchangeGraph;
	bool enabled[MX];
	
	int solve() {
		for (int i = 0; i < m; i++) enabled[i] = true;
		
		int ans = m;
		while (true) {
			exchangeGraph.clear();
			
			vector<int> Y1 = getNonBridges(u1, v1);
			vector<int> Y2 = getNonBridges(u2, v2);
			
			if (exchangeGraph.findAugmentalPath(Y1, Y2, enabled)) {
				ans--;
				continue;
			}
			
			for (int e = 0; e < m; e++) {
				if (enabled[e]) continue;
				
				enabled[e] = true;
				
				vector<int> edgesTo = getNonBridges(u1, v1);
				vector<int> edgesFrom = getNonBridges(u2, v2);
				
				enabled[e] = false;
				
				for (size_t i = 0; i < edgesTo.size(); i++) {
					exchangeGraph.addEdge(e, edgesTo[i]);
				}
				for (size_t i = 0; i < edgesFrom.size(); i++) {
					exchangeGraph.addEdge(edgesFrom[i], e);
				}
			}
			
			if (exchangeGraph.findAugmentalPath(Y1, Y2, enabled)) {
				ans--;
			}
			else {
				break;
			}
		}
		
		return ans;
	}
	
	Graph G;
	bool isBridge[MX];
	vector<int> getNonBridges(int* u, int* v) {
		G.init();
		for (int i = 0; i < m; i++) {
			if (enabled[i]) {
				G.addEdge(u[i], v[i], i);
				isBridge[i] = false;
			}
		}
		
		G.markBridges(isBridge);
		
		vector<int> result;
		for (int i = 0; i < m; i++) {
			if (enabled[i] && isBridge[i] == false) {
				result.push_back(i);
			}
		}
		
		return result;
	}
};

struct Solution1 {
	int permutation[MX];
	
	double solve(int correct) {
		const int limit = 30000000 / m;
		
		random_t rnd;
		for (int it = 1; it <= limit; it++) {
			rnd.permute(permutation, m);
			int cnt = getBothAcyclic(permutation);
			int ans = 2 * (n - 1 - cnt) + cnt;
			if (ans == correct) return it / (double)limit;
		}
		
		return -1;
	}
};

struct Solution2 {
	int permutation[MX], selected[MX], timeSpent;
	bool isBridge[MX];
	
	double solve(int correct) {
		const int limit = 20000000;
		timeSpent = 0;
		
		random_t rnd;
		
		while (timeSpent < limit) {
			rnd.permute(permutation, m);
			int ans = solveOne(m);
			if (ans == correct) return timeSpent / (double)limit;
		}
		
		return -1;
	}
	
	DSU dsu1, dsu2;
	int solveOne(int cnt) {
		timeSpent += n + cnt;
		
		dsu1.init(n);
		dsu2.init(n);
		
		int used = 0;
		for (int i = 0; i < cnt; i++) {
			int e = permutation[i];
			int x1 = dsu1.get(u1[e]);
			int y1 = dsu1.get(v1[e]);
			int x2 = dsu2.get(u2[e]);
			int y2 = dsu2.get(v2[e]);
			if (x1 != y1 || x2 != y2) {
				selected[used++] = e;
				isBridge[e] = false;
				dsu1.merge(x1, y1);
				dsu2.merge(x2, y2);
			}
		}
		
		getBridges(used, u1, v1);
		getBridges(used, u2, v2);
		
		int bridges = 0;
		for (int i = 0; i < used; i++) {
			int e = selected[i];
			if (isBridge[e]) {
				permutation[bridges++] = e;
			}
		}
		
		for (int i = 0, j = bridges; i < used; i++) {
			int e = selected[i];
			if (isBridge[e] == false) {
				permutation[j++] = e;
			}
		}
		
		if (bridges == used) return used;
		return solveOne(used);
	}
	
	Graph G;
	void getBridges(int cnt, int* u, int* v) {
		G.init();
		for (int i = 0; i < cnt; i++) {
			int e = selected[i];
			G.addEdge(u[e], v[e], e);
		}
		
		G.markBridges(isBridge);
	}
};

struct Solution3 {
	random_t rnd;
	
	double solve(int correct) {
		if (m == n - 1) return 0;
		
		for (int it = 0; it < 5; it++) {
			double result = solveOne(correct);
			if (result < -0.5) continue;
			return (it + result) / 5;
		}
		
		return -1;
	}
	
	int permutation[MX];
	double solveOne(int correct) {
		const int limit = 6000000 / m;
		
		rnd.permute(permutation, m);
		
		double ee = 1.0;
		int best = getBothAcyclic(permutation), curr = best;
		for (int it = 1; it <= limit; it++) {
			int x, y;
			do {
				x = rnd.next() % m;
				y = rnd.next() % m;
			} while (x == y);
			
			int tmp = permutation[x];
			permutation[x] = permutation[y];
			permutation[y] = tmp;
			
			int cnt = getBothAcyclic(permutation);
			if (cnt > curr || rnd.next() < (1LL << 32) * pow(ee, curr - cnt)) {
				curr = cnt;
				ee *= 0.991;
				if (cnt > best) best = cnt;
			}
			else {
				tmp = permutation[x];
				permutation[x] = permutation[y];
				permutation[y] = tmp;
			}
			
			int ans = 2 * (n - 1 - best) + best;
			if (ans == correct) return it / (double)limit;
		}
		
		return -1;
	}
};

struct Solution4 {
	random_t rnd;
	
	double solve(int correct) {
		if (m == n - 1) return 0;
		
		for (int it = 0; it < 100; it++) {
			double result = solveOne(correct, it < 50);
			if (result < -0.5) continue;
			return (it + result) / 100;
		}
		
		return -1;
	}
	
	int *u1, *v1, *u2, *v2;
	int permutation[MX];
	bool enabled[MX];
	DSU dsu;
	
	void getrandom_tSubst(int& x, int& y) {
		int k = rnd.next() % (m - n + 1);
		for (int i = 0; i < m; i++) {
			if (enabled[i] == false) {
				if (k == 0) y = i;
				else k--;
			}
		}
		
		rnd.permute(permutation, m);
		
		dsu.init(n);
		dsu.merge(u1[y], v1[y]);
		for (int i = 0; i < m; i++) {
			int e = permutation[i];
			if (enabled[e]) {
				int a = dsu.get(u1[e]);
				int b = dsu.get(v1[e]);
				if (a == b) x = e;
				dsu.merge(a, b);
			}
		}
	}
	
	int countComponents() {
		dsu.init(n);
		for (int i = 0; i < m; i++) {
			if (enabled[i] == false) continue;
			dsu.merge(u2[i], v2[i]);
		}
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (dsu.get(i) == i) cnt++;
		}
		
		return cnt;
	}
	
	double solveOne(int correct, bool swapGraphs) {
		const int limit = 300000 / m;
		
		if (swapGraphs) {
			u1 = ::u2;
			v1 = ::v2;
			u2 = ::u1;
			v2 = ::v1;
		}
		else {
			u1 = ::u1;
			v1 = ::v1;
			u2 = ::u2;
			v2 = ::v2;
		}
		
		rnd.permute(permutation, m);
		
		dsu.init(n);
		for (int i = 0; i < m; i++) {
			int x = dsu.get(u1[i]);
			int y = dsu.get(v1[i]);
			if (x != y) {
				dsu.merge(x, y);
				enabled[i] = true;
			}
			else {
				enabled[i] = false;
			}
		}
		
		double ee = 1.0;
		int best = countComponents(), curr = best;
		for (int it = 1; it <= limit; it++) {
			int x, y;
			getrandom_tSubst(x, y);
			
			enabled[x] = false;
			enabled[y] = true;
			
			int cnt = countComponents();
			if (cnt < curr || rnd.next() < (1LL << 32) * pow(ee, cnt - curr)) {
				curr = cnt;
				ee *= 0.988;
				if (cnt < best) best = cnt;
			}
			else {
				enabled[x] = true;
				enabled[y] = false;
			}
			
			int ans = n - 1 + best - 1;
			if (ans == correct) return it / (double)limit;
		}
		
		return -1;
	}
};

// The part above is an exact copy from the checker used on the server! //
//////////////////////////////////////////////////////////////////////////

void invalidInput() {
	printf("%s\n", "Invalid input!");
	exit(0);
}

int failed = 0;
void process(int id, double result) {
	printf("Solution #%d: ", id);
	if (result < -0.5) {
		printf("%s\n", "produced an incorrect answer (success).");
		failed++;
	}
	else {
		if (result < 0) result = 0;
		if (result > 1) result = 1;
		printf("produced a correct answer using %6.2f%% of the time limit (failure).\n", 100 * result);
	}
}

int main() {
	if (scanf("%d %d", &n, &m) != 2) invalidInput();
	if (n < 2 || n > MX) invalidInput();
	if (m < n - 1 || m > MX) invalidInput();
	for (int i = 0; i < m; i++) {
		if (scanf("%d %d", u1 + i, v1 + i) != 2) invalidInput();
		if (u1[i] < 1 || u1[i] > n) invalidInput();
		if (v1[i] < 1 || v1[i] > n) invalidInput();
		u1[i]--;
		v1[i]--;
	}
	for (int i = 0; i < m; i++) {
		if (scanf("%d %d", u2 + i, v2 + i) != 2) invalidInput();
		if (u2[i] < 1 || u2[i] > n) invalidInput();
		if (v2[i] < 1 || v2[i] > n) invalidInput();
		u2[i]--;
		v2[i]--;
	}
	
	DSU dsu1, dsu2;
	dsu1.init(n);
	dsu2.init(n);
	for (int i = 0; i < m; i++) {
		dsu1.merge(u1[i], v1[i]);
		dsu2.merge(u2[i], v2[i]);
	}
	
	for (int i = 0; i < n; i++) {
		if (dsu1.get(i) != dsu1.get(0)) invalidInput();
		if (dsu2.get(i) != dsu2.get(0)) invalidInput();
	}
	
	printf("The input is valid! N = %d; M = %d.\n\n", n, m);
	
	CorrectSolution sol;
	int correct = sol.solve();
	
	Solution1 sol1;
	process(1, sol1.solve(correct));
	
	Solution2 sol2;
	process(2, sol2.solve(correct));
	
	Solution3 sol3;
	process(3, sol3.solve(correct));
	
	Solution4 sol4;
	process(4, sol4.solve(correct));
	
	int score = 21 * failed;
	if (failed > 0) score += 2400 / (m < 100 ? 100 : m) - 8;
	printf("\nScore: %d points.\n", score);
	
	return 0;
}