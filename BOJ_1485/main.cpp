#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

class Point {
public:
	ll x{};
	ll y{};
};

using vP = vector<Point>;

ll dist2(const Point& p, const Point& q) {
	const auto dx = p.x - q.x;
	const auto dy = p.y - q.y;

	return pow(dx, 2) + pow(dy, 2);
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--)) {
		auto pts = vP(4);
		for (auto&& p : pts) {
			cin >> p.x >> p.y;
		}

		auto lengths = vl{};
		lengths.reserve(6);
		for (auto i = 0; i < 4; ++i) {
			for (auto j = i + 1; j < 4; ++j) {
				lengths.push_back(dist2(pts[i], pts[j]));
			}
		}

		sort(lengths.begin(), lengths.end());

		if ((lengths[0] == lengths[1] &&
			lengths[0] == lengths[2] &&
			lengths[0] == lengths[3]) &&
			(lengths[4] == lengths[5])) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

	return 0;
}