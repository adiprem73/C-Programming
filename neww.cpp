#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    const double PI     = acos(-1.0);
    const double TWO_PI = 2 * PI;

    // f'(x) and f''(x)
    auto f1 = [&](double x) {
        double s = 0;
        for (int i = 0; i < n; i++)
            s += A[i] * cos(A[i] * x + B[i]);
        return s;
    };
    auto f2 = [&](double x) {
        double s = 0;
        for (int i = 0; i < n; i++)
            s -= double(A[i]) * A[i] * sin(A[i] * x + B[i]);
        return s;
    };

    // 1) Find brackets where f'(x) changes sign (or hits zero)
    vector<pair<double, double>> brackets;
    const double dx = 1e-4;
    double x_lo = 0, f_lo = f1(x_lo);
    for (double x = dx; x <= TWO_PI + 1e-12; x += dx) {
        double x_hi = min(x, TWO_PI);
        double f_hi = f1(x_hi);
        if (f_lo * f_hi < 0 || fabs(f_lo) < 1e-14 || fabs(f_hi) < 1e-14) {
            brackets.emplace_back(x_lo, x_hi);
        }
        x_lo = x_hi;
        f_lo = f_hi;
    }

    // 2) Bisection to refine each bracket into a critical point
    vector<double> crit;
    for (auto &pr : brackets) {
        double l = pr.first, r = pr.second;
        double fl = f1(l), fr = f1(r);

        if (r - l < 1e-12) {
            crit.push_back(l);
            continue;
        }

        for (int it = 0; it < 60; it++) {
            double m  = 0.5 * (l + r);
            double fm = f1(m);
            if (fabs(fm) < 1e-14) {
                l = r = m;
                break;
            }
            if (fl * fm <= 0) {
                r = m;
                fr = fm;
            } else {
                l = m;
                fl = fm;
            }
        }
        crit.push_back(0.5 * (l + r));
    }

    // 3) Deduplicate and sort the critical points
    sort(crit.begin(), crit.end());
    vector<double> uniq;
    for (double x : crit) {
        if (uniq.empty() || fabs(x - uniq.back()) > 1e-6)
            uniq.push_back(x);
    }

    // 4) Pick out the local maxima (f''(x) < 0), strictly in (0, 2π)
    vector<double> peaks;
    for (double x : uniq) {
        if (x > 1e-8 && x < TWO_PI - 1e-8 && f2(x) < 0)
            peaks.push_back(x);
    }
    sort(peaks.begin(), peaks.end());

    // 5) Compute valley widths between consecutive peaks,
    //    treating x = 2π as an extra “peak” at the right boundary
    int  k = peaks.size();
    if (k == 0) {
        cout << 0;
        return 0;
    }

    double bestWidth = -1.0;
    int    bestValley = 1;
    for (int i = 0; i < k; i++) {
        double right = (i + 1 < k ? peaks[i + 1] : TWO_PI);
        double width = right - peaks[i];
        int    valleyIndex = i + 1;  // 1-based
        if (width > bestWidth + 1e-12) {
            bestWidth   = width;
            bestValley = valleyIndex;
        }
    }

    cout << bestValley;
    return 0;
}
